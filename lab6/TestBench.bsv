import gcd::*;

(* synthesize *)
module mkTbGCD();
    Reg#(int) state <- mkReg(-1);
    Reg#(Int#(4)) c1 <-mkReg(0);
    Reg#(Int#(7)) c2 <-mkReg(0);
    GCDI gcd <- mkGCD();

    rule init (state==-1);
	state <= 0;
    endrule

    rule req (state==0);
      $display("gcd.start(%d, %d)", c1, c2);
      gcd.start(signExtend(c1), signExtend(c2));
      state <= 1;
    endrule

    rule resp (c2 < 63 && state==1);
      if (!gcd.busy)
      begin
      $display("gcd.result()= %d", gcd.result());
      //$display ("GCD of %d and %d =%d", c1, c2, gcd.getResult());
      if (c1==7) 
	begin 
	  c1 <= 0; 
	  c2 <= c2 + 1; 
          state <= 0; 
	end 
      else 
 	begin 
	  c1 <= c1 + 1; 
          state <= 0; 
        end
    end
    else
	state <= 2;
    endrule

    rule bounce ( state==2);
        state <= 1;
    endrule

    rule terminate (c2==63 && state == 0);
      //$display("gcd.getResult()= %d", gcd.result());
      $finish(0);
    endrule
endmodule


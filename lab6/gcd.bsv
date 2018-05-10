

/*
--------------------------------------
    NAME:   Jessica Redublo
    COURSE: CSE 140L B01
    WEEK:   LAB 6: GCD
    FILE:   gcd.bsv
    DATE:   March 4, 2018
---------------------------------------
*/



interface GCDI;
    method Action start(int a, int b);
    method int result();
    method Bool busy;
endinterface

module mkGCD (GCDI);
    // REGISTERS
    Reg#(int) x <- mkReg(0);        // input X
    Reg#(int) y <- mkReg(0);        // input Y
    Reg#(Bool) bz <- mkReg(False);  // busy val = currently computing


    // RULES    
    rule subtract if(bz==True);                           // Subtract LOGIC
	    if (x>y)              // x is greater: gcd(x-y,y)
            x <= x-y;
        else if (x<=y)        // y is eq/greater: gcd(x,y-x)
            y <= y-x;
       if (x==0 || y==0)    // STOP LOGIC HERE BC OF BUG WITH BSV RULES
            bz<=False;
    endrule

    /* rule stop if(bz==True);                               // Stop LOGIC
        if (x==0) begin
            leftOperand <= y;       // if x isZero, return y
            bz<=False;              // done, not busy anymore
        end else if (y==0) begin
            leftOperand <= x;       // if y isZero, return x
            bz<=False;              // done, not busy anymore
        end
    endrule*/

    // METHODS
    method Action start(int a, int b) if (bz==False);   // START: start new computation        ACTION
        if (a<=0 || b<=0) begin     // if zero/neg, ERROR
           bz <= False;
           $display ("ERROR");
        end else begin              // start new computation if valid
            x <= a;
            y <= b;
            bz <= True;
        end
    endmethod

    method int result() if(bz==False);                    // RESULT: return last computed GCD    INT
        if (x==0)
            return y;
        else
            return x;
        //return leftOperand;
    endmethod

    method Bool busy;                               // BUSY: returns True is busy          BOOL
        return bz;
    endmethod


endmodule


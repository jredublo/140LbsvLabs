import Vector::*;
import Processors::*;
import Top::*;

typedef 32 NUM;

module mkTbAdder();
	Processor adder <- mkAdder();
	Reg#(Bit#(2)) state <- mkReg(0);
	Reg#(Bit#(2)) state2 <- mkReg(0);
	
	rule r_send_adder(state==0);
		Request req = Request{op1:23, op2:12, oper:Add};
		$display(">>>> Request[%d] op1: %d, op2: %d; oper: Add", 0, req.op1, req.op2);
		adder.request(req);
		state <= 1;
	endrule
	rule r_send_adder2(state==1);
		Request req = Request{op1:11, op2:4, oper:Add};
		$display(">>>> Request[%d] op1: %d, op2: %d; oper: Add", 0, req.op1, req.op2);
		adder.request(req);
		state <= 2;
	endrule
	rule r_recv_adder(state2==0);
		
		let res <- adder.response();
		if(res.res==35) begin
			$display("<<<< Response[%d] result: %d, oper:Add", 0, res.res);
			$display("PASSED");
		end
		else begin 
			$display("FAILED! oper:Add Expected:%d Got:%d", 35, res.res);
		end
		state2 <= 1;
	endrule

	rule r_recv_adder2(state2==1);
		
		let res <- adder.response();
		if(res.res==15) begin
			$display("<<<< Response[%d] result: %d, oper:Add", 0, res.res);
			$display("PASSED");
			$finish(0);
		end
		else begin 
			$display("FAILED! oper:Add Expected:%d Got:%d", 15, res.res);
			$finish(0);
		end
	endrule
endmodule


module mkTbGCD();
	Processor gcd <- mkGCD();
	Reg#(Bit#(2)) state <- mkReg(0);
	Reg#(Bit#(2)) state2 <- mkReg(0);

	rule r_send_gcd(state==0);
		Request req = Request{op1:8, op2:2, oper:GCD};
		$display(">>>> Request[%d] op1: %d, op2: %d; oper: GCD", 0, req.op1, req.op2);
		gcd.request(req);
		state <= 1;
	endrule
	rule r_send_gcd2(state==1);
		Request req = Request{op1:8, op2:9, oper:GCD};
		$display(">>>> Request[%d] op1: %d, op2: %d; oper: GCD", 0, req.op1, req.op2);
		gcd.request(req);
		state <= 2;
	endrule
			
	rule r_recv_gcd(state2==0);
		
		let res <- gcd.response();
		if(res.res==2) begin
			$display("<<<< Response[%d] result: %d, oper:GCD", 0, res.res);
			$display("PASSED");
		end
		else begin 
			$display("FAILED! oper:GCD Expected:%d Got:%d", 2, res.res);
		end
		state2 <= 1;
	endrule

	rule r_recv_gcd2(state2==1);
		
		let res <- gcd.response();
		if(res.res==1) begin
			$display("<<<< Response[%d] result: %d, oper:GCD", 0, res.res);
			$display("PASSED");
			$finish(0);
		end
		else begin 
			$display("FAILED! oper:GCD Expected:%d Got:%d", 1, res.res);
			$finish(0);
		end
	endrule
	
endmodule


module mkTb();

	Vector#(NUM, Operation) opers = newVector;

	Vector#(28, Reg#(DataType)) resultsInt <- replicateM(mkReg(0));
	Vector#(6, DataType) resultsGCD = newVector;
	
	Integer i=0;
	opers[i+0] = Add;  opers[i+1] = Add; opers[i+2] = GCD;  opers[i+3] = GCD;
	i=i+4;
	opers[i+0] = GCD;   opers[i+1] = GCD;  opers[i+2] = Add;  opers[i+3] = Add;
	i=i+4;
	opers[i+0] = Add;  opers[i+1] = Add; opers[i+2] = Add; opers[i+3] = Add;
	i=i+4;
	opers[i+0] = Add;  opers[i+1] = Add; opers[i+2] = Add;  opers[i+3] = GCD;
	i=i+4;
	opers[i+0] = Add;  opers[i+1] = Add; opers[i+2] = GCD;  opers[i+3] = Add;
	i=i+4;
	opers[i+0] = Add;  opers[i+1] = Add;  opers[i+2] = Add; opers[i+3] = Add;
	i=i+4;
	opers[i+0] = Add;  opers[i+1] = Add;  opers[i+2] = Add; opers[i+3] = Add;
	i=i+4;
	opers[i+0] = Add;  opers[i+1] = Add; opers[i+2] = Add;  opers[i+3] = Add;

	resultsGCD[0] = 2;
	resultsGCD[1] = 1;
	resultsGCD[2] = 4;
	resultsGCD[3] = 1;
	resultsGCD[4] = 2;
	resultsGCD[5] = 1;
	Top top <- mkTop;


	Reg#(CounterType) reqCount <- mkReg(0);
	Reg#(CounterType) intReqCount <- mkReg(0);
	Reg#(CounterType) intResCount <- mkReg(0);
	Reg#(CounterType) gcdReqCount <- mkReg(0);
	Reg#(CounterType) gcdResCount <- mkReg(0);
	
	Reg#(CounterType) resCount <- mkReg(fromInteger(valueOf(NUM)));
	Reg#(Bool) done <- mkReg(False);
	Reg#(Bit#(64)) cycles <- mkReg(0);
	Reg#(DataType) int1 <- mkReg(1);
	Reg#(DataType) int2 <- mkReg(10);
	Reg#(DataType) gcd1 <- mkReg(8);
	Reg#(DataType) gcd2 <- mkReg(2);
		
	rule r_count_cycles;
		cycles <= cycles + 1;
	endrule

	rule r_send_req(reqCount!=fromInteger(valueOf(NUM)));
		Request req = Request{op1: 0, op2:0, oper:opers[reqCount]};
		if(req.oper==Add) begin
			req.op1 = int1; req.op2 = int2;
//			$display(">>>> Request[%d] op1: %d, op2: %d; oper: Add", reqCount, req.op1, req.op2);
			int1 <= int1 + 2; int2 <= int1 * int2;
			resultsInt[intReqCount] <= req.op1 + req.op2;
			intReqCount <= intReqCount + 1;
		end
		else begin
			req.op1 = gcd1; req.op2 = gcd2;
//			$display(">>>> Request[%d] op1: %d, op2: %d; oper: GCD", reqCount, req.op1, req.op2);	
			gcd1 <= gcd1 + 10; gcd2 <= gcd2 + 3;
			//resultsGCD[gcdReqCount] <=  ;
			gcdReqCount <= gcdReqCount + 1;
		end
		reqCount <= reqCount + 1;
		top.request(req);

	endrule
	rule r_recv_res;
		Response res <- top.response;
		resCount <= resCount - 1;
		CounterType c = fromInteger(valueOf(NUM))-resCount;
		if(res.oper==Add) begin
			$display("<<<< Response[%d] result: %d, oper:Add", c, res.res);
			if(resultsInt[intResCount]==res.res) 
				$display("PASSED");
			else begin
				$display("FAILED! oper:Add Expected:%d Got:%d", resultsInt[intResCount], res.res);
				//$finish(0);
			end
			intResCount <= intResCount + 1;
		end
		else begin 	
			$display("<<<< Response[%d] result: %d, oper:GCD", c, res.res);
			if(resultsGCD[gcdResCount]==res.res) 
				$display("PASSED");
			else begin
				$display("FAILED! oper:GCD Expected:%d Got:%d", resultsGCD[gcdResCount], res.res);
				//$finish(0);
			end
			gcdResCount <= gcdResCount + 1;

		end
		
	endrule	
	rule r_disp_count(resCount ==0);
		Counts cnts = top.getCounts;
		if(cnts.intCount==26 && cnts.gcdCount==6) begin 
			$display("AddOpers:%d, GCDOpers:%d",cnts.intCount, cnts.gcdCount);
			$display("NumCycles:%d",cycles);
		end
		else begin 
			$display("FAILED! Expected AddCount:%d GCDCount:%d, Got AddCount:%d GCDCount:%d",26,6,cnts.intCount, cnts.gcdCount);
		end
		
		done <= True;
	endrule
	rule r_finish(done);
		$finish(0);
	endrule
endmodule

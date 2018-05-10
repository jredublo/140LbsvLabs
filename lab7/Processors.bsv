


/*
 *   NAME:   Jessica Redublo
 *   COURSE: CSE 140L
 *   WEEK:   Lab 7 - FIFOs
 *   FILE:   Processors.bsv
 *   DATE:   March 10, 2018
*/

package Processors;


typedef Bit#(32) DataType;
typedef enum {Add, GCD} Operation deriving (Bits, Eq);
typedef struct{
	DataType op1;   // Operand 1
	DataType op2;   // Operand 2
	Operation oper; // Operation
} Request deriving (Bits, Eq);          // making request datatype
typedef struct{
	DataType res;   // Result
	Operation oper; // Operation
} Response deriving (Bits, Eq);         // making response datatype


interface Processor;                            
	method Action request(Request req);
	method ActionValue#(Response) response();
endinterface


//// mkAdder MODULE  ////
(* synthesize *)
module mkAdder(Processor);
	Reg#(DataType) x <- mkRegU;                     // operand 1    DATATYPE
	Reg#(DataType) y <- mkRegU;                     // operand 2    DATATYPE
	Reg#(DataType) result <- mkRegU;                // result       DATATYPE
	
	Reg#(Bool) input_valid <- mkReg(False);         // input valid  BOOLEAN
	Reg#(Bool) output_valid <- mkReg(False);        // output valid BOOLEAN

	// DO NOT make any change to rules
	rule r_add(!output_valid && input_valid);           // add LOGIC
		result <= x + y;
		output_valid <= True;
	endrule

	// add REQUEST method      operation is add, input is invalid
	method Action request(Request req) if ( !input_valid && !output_valid);             
        // adding operands and marking inputs as valid
        input_valid <= True;
        x <= req.op1;
        y <= req.op2;
	endmethod
    // add RESPONSE method      operation is add, out is valid
	method ActionValue#(Response) response() if ( output_valid ); 
            output_valid <= False;
	        Response finalR = Response{res: result, oper: Add};
            input_valid <= False;
            return finalR;
    endmethod
endmodule




//// mkGCD MODULE  ////
module mkGCD (Processor);
	Reg#(DataType) x <- mkReg(0);
	Reg#(DataType) y <- mkReg(0);
	Reg#(Bool) input_valid <- mkReg(False);
	Reg#(Bool) output_valid <- mkReg(False);
	
	// DO NOT make any change to rules
	rule swap (input_valid && !output_valid && x!=0 && x < y);
		y <= x;
		x <= y;
	endrule
	rule subtract (input_valid && !output_valid && x!=0 && x >= y);
		x <= x - y;
	endrule
	rule stop (input_valid && !output_valid && x==0);
		output_valid <= True;
	endrule

	// Complete the methods below with appropriate gaurd condition
	method Action request(Request req) if ( !input_valid && !output_valid);
        input_valid <= True;
        x <= req.op1;
        y <= req.op2;
	endmethod
	method ActionValue#(Response) response() if ( output_valid );
        output_valid <= False;   
        if (x==0) begin
            Response finalR = Response{res: y, oper: GCD};
            input_valid <= False;
            return finalR;
        end else begin
            Response finalR = Response{res: x, oper: GCD};
            input_valid <= False;
            return finalR;
        end
	endmethod
		
endmodule
endpackage

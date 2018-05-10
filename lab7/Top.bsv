
/*
 *   NAME:   Jessica Redublo
 *   COURSE: CSE 140L
 *   WEEK:   Lab 7 - FIFOs
 *   FILE:   Top.bsv
 *   DATE:   March 10, 2018
*/

package Top;
import Processors::*;
import FIFOF::*;

/* FOR REFERENCE ONLY. DO NOT UNCOMMENT.
interface FIFOF #(type element_type);
	method Action enq(element_type x1);
	method Action deq();
	method element_type first();
	method Bool notFull();
	method Bool notEmpty();
	method Action clear();
endinterface: FIFOF
*/

typedef 1 INPUT_REQUEST_FIFO_DEPTH;
typedef 1 ADDER_REQUEST_FIFO_DEPTH;
typedef 4 GCD_REQUEST_FIFO_DEPTH;
typedef 1 ADDER_RESPONSE_FIFO_DEPTH;
typedef 1 GCD_RESPONSE_FIFO_DEPTH;
typedef 1 OUTPUT_RESPONSE_FIFO_DEPTH;

typedef Bit#(16) CounterType;
typedef struct{
	CounterType intCount;
	CounterType gcdCount;
} Counts deriving (Bits, Eq);

interface Top;
	method Action request(Request req);
	method ActionValue#(Response) response;
	method Counts getCounts;
endinterface 

(* synthesize *)
module mkTop(Top);
	// Top FIFOs : request/response
	FIFOF#(Request) inputFIFO <- mkSizedFIFOF(valueOf(INPUT_REQUEST_FIFO_DEPTH));
	FIFOF#(Response) outputFIFO <- mkSizedFIFOF(valueOf(OUTPUT_RESPONSE_FIFO_DEPTH));
	
	// Adder FIFOs : request/response
	FIFOF#(Request) adderRequestFIFO <- mkSizedFIFOF(valueOf(ADDER_REQUEST_FIFO_DEPTH));
	FIFOF#(Response) adderResponseFIFO <- mkSizedFIFOF(valueOf(ADDER_RESPONSE_FIFO_DEPTH));

	// GCD FIFOs : request/response
	FIFOF#(Request) gcdRequestFIFO <- mkSizedFIFOF(valueOf(GCD_REQUEST_FIFO_DEPTH));
	FIFOF#(Response) gcdResponseFIFO <- mkSizedFIFOF(valueOf(GCD_RESPONSE_FIFO_DEPTH));

	// Processors : Adder/GCD
	Processor intAdder <- mkAdder;
	Processor gcd <- mkGCD;

	// Counters
	Reg#(CounterType) countIntOpers <- mkReg(0);
	Reg#(CounterType) countGCDOpers <- mkReg(0);

    
    
    (* descending_urgency = "one, oneb, two, three, four, five, six, seven" *)
    //---- RULES ----//
	// ONE: connect inputRequestFIFO -> adderReq and gcdReq
    rule one(inputFIFO.first().oper == Add);
        //let req <= inputFIFO.first(); 
        adderRequestFIFO.enq( inputFIFO.first()  );
        countIntOpers <= countIntOpers + 1;  
        inputFIFO.deq();
    endrule
    
	// ONEb: connect inputRequestFIFO -> adderReq and gcdReq
    rule oneb( inputFIFO.first().oper == GCD );
       //let req <= inputFIFO.first(); 
        
        gcdRequestFIFO.enq( inputFIFO.first() );
        countGCDOpers <= countGCDOpers + 1;
        inputFIFO.deq();
    endrule
    
    // TWO: connect adderReqFIFO -> mkAdder mod
	rule two;
        //let a_req <= adderRequestFIFO.first();
        intAdder.request(adderRequestFIFO.first());
        adderRequestFIFO.deq();
    endrule
    
    // THREE: connectgcdReqFIFO -> mkGCD mod
	rule three;
        Request g_req = gcdRequestFIFO.first();
        gcd.request(g_req);                   //TODO
        gcdRequestFIFO.deq();
    endrule
    
    // FOUR: connect mkAdder mod -> adderResFIFO
	rule four;
	    let a_res <- intAdder.response();
        adderResponseFIFO.enq(a_res);
        //adderResponseFIFO.enq(intAdder.response());
    endrule	
    
    // FIVE: connect mkGCD mod -> gcdResFIFO
    rule five ;
        let g_res <- gcd.response();
        gcdResponseFIFO.enq(g_res);
        //gcdResponseFIFO.enq( gcd.response() );
    endrule
    
    // SIX: connect addResFIFO -> outputFIFO  // will try to do add first before
    rule six;
        //let finalRes <= adderResponseFIFO.first();
        outputFIFO.enq(adderResponseFIFO.first());
        adderResponseFIFO.deq();
    endrule
    
    // SEVEN: connect gcdResFIFO -> outputFIFO
    rule seven;
        let finalRes = gcdResponseFIFO.first();    //TODO
        gcdResponseFIFO.deq();
        outputFIFO.enq( finalRes );
    endrule


    //---- METHODS ----//
	// REQUEST method                       // theres blank in input
    method Action request(Request req) if (inputFIFO.notFull());
        inputFIFO.enq(req);
	endmethod
    // RESPONSE method                          // theres something in output
    method ActionValue#(Response) response if (outputFIFO.notEmpty());	
		let results = outputFIFO.first();
        outputFIFO.deq();
        return results;
	endmethod
	// GETCOUNTS method
    method Counts getCounts; // guard?
		return Counts{intCount: countIntOpers, gcdCount: countGCDOpers};
	endmethod
endmodule
endpackage

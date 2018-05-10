
// Name: Jessica Redublo
// Course: CSE 140L
// File: SevenSegmentDriver.bsv

/*     parameter: 10bit number                7seg      10-bit location 
    0000000001      1 //  1 in zeroth place             0
    0000000010      2                                   1
    0000000100      3                                   2
    0000001000      4                                   3
    0000010000      5                                   4
    0000100000      6                                   5
    0001000000      7                                   6   
    0010000000      8                                   7
    0100000000      9 // 1 in eighth place              8
    1000000000      0 // 1 in ninth place               9
    else or mult    E
*/



/** Takes a 10-bit input and produces a 7-bit output, one for 
 *  each segment.
 */
function Bit#(7) sevenSegmentDriver(Bit#(10) number); 
    
    Bit#(7) result = 'b0000000;

    Bit#(1) zero = number[0];
    Bit#(1) one = number[1];
    Bit#(1) two = number[2];
    Bit#(1) three = number[3];
    Bit#(1) four = number[4];
    Bit#(1) five = number[5];
    Bit#(1) six = number[6];
    Bit#(1) seven = number[7];
    Bit#(1) eight = number[8];
    Bit#(1) nine = number[9];

    Bit#(1) exor = zero ^ one ^ two ^ three ^ four ^ five ^ six ^ seven ^ eight ^ nine;
    
    // nothing is pressed
    if (number == 'b0000000000) begin       // nothing is pressed
        result = 'b0000000;
    end
    
    // if one number is pressed, return the valid number display
    else if (exor == 1) begin
        Integer whichBit = 15;
        for(Integer i = 0; i < 10; i=i+1) begin
            if (number[i] == 1)
                whichBit = i;
        end
        
        if (whichBit == 1) begin            // press 1
            result = 'b0110000;
        end else if (whichBit == 2) begin   // press 2
            result = 'b1101101;
        end else if (whichBit == 3) begin   // press 3
            result = 'b1111001;
        end else if (whichBit == 4) begin   // press 4
            result = 'b0110011;
        end else if (whichBit == 5) begin   // press 5
            result = 'b1011011;
        end else if (whichBit == 6) begin   // press 6
            result = 'b1011111;
        end else if (whichBit == 7) begin   // press 7
            result = 'b1110000;
        end else if (whichBit == 8) begin   // press 8
            result = 'b1111111;
        end else if (whichBit == 9) begin   // press 9
            result = 'b1111011;
        end else if (whichBit == 0) begin   // press 0
            result = 'b1111110;
        end else begin
            result = 'b1001111;
        end
    end
    
    // else (more than one number is pressed), return E
    else begin
        result = 'b1001111;    
    end
        
    return result;

endfunction 

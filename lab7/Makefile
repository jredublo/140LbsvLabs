
top:
	mkdir -p build
	bsc -u -sim -simdir build -bdir build -info-dir build -keep-fires -p .:%/Prelude:%/Libraries:%/Libraries/BlueNoC -g mkTb Tb.bsv
	bsc -e mkTb -sim -o ./simTop -simdir build -p %/Prelude:%/Libraries:%/Libraries/BlueNoC -bdir build -keep-fires

gcd:
	mkdir -p build
	bsc -u -sim -simdir build -bdir build -info-dir build -keep-fires -p .:%/Prelude:%/Libraries:%/Libraries/BlueNoC -g mkTbGCD Tb.bsv
	bsc -e mkTbGCD -sim -o ./simGCD -simdir build -p %/Prelude:%/Libraries:%/Libraries/BlueNoC -bdir build -keep-fires

adder:
	mkdir -p build
	bsc -u -sim -simdir build -bdir build -info-dir build -keep-fires -p .:%/Prelude:%/Libraries:%/Libraries/BlueNoC -g mkTbAdder Tb.bsv
	bsc -e mkTbAdder -sim -o ./simAdder -simdir build -p %/Prelude:%/Libraries:%/Libraries/BlueNoC -bdir build -keep-fires

clean:
	rm -rf build sim* out verilog dump.vcd

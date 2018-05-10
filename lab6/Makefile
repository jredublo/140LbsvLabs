all: gcd run

compile:
	mkdir -p buildDir
	bsc -u -sim -bdir buildDir -info-dir buildDir -simdir buildDir -vdir buildDir -aggressive-conditions -keep-fires -no-warn-action-shadowing TestBench.bsv

gcd: compile
	bsc -sim -e mkTbGCD -bdir buildDir -info-dir buildDir -simdir buildDir -aggressive-conditions -keep-fires -o simGCD -show-range-conflict -no-warn-action-shadowing

run: gcd
	./simGCD

clean:
	rm -rf buildDir sim* gcd.vcd

.PHONY: clean all compile gcd run
.DEFAULT_GOAL := all

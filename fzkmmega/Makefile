all: hello test benchmark width

hello: hello.c
	/opt/fcc/bin/fcc -O2 -mz80 -c hello.c
	/opt/fcc/bin/fcc -O2 -mz80 hello.rel -o hello

test: test.c
	/opt/fcc/bin/fcc -O2 -mz80 -c test.c
	/opt/fcc/bin/fcc -O2 -mz80 test.rel -o test

benchmark: benchmark.c
	/opt/fcc/bin/fcc -O2 -mz80 -c benchmark.c
	/opt/fcc/bin/fcc -O2 -mz80 benchmark.rel -o benchmark

width: picinterface.rel width.rel
	/opt/fcc/bin/fcc -O2 -mz80 width.rel picinterface.rel -o width

picinterface.rel: picinterface.c picinterface.h
	/opt/fcc/bin/fcc -O2 -mz80 -c picinterface.c

width.rel: width.c
	/opt/fcc/bin/fcc -O2 -mz80 -c width.c

clean:
	rm -f *.rel
	rm -f *.map
	rm -f *.lk
	rm -f *.noi
	rm -f *.sym
	rm -f test
	rm -f hello
	rm -f benchmark
	rm -f width


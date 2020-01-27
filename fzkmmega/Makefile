all: hello test benchmark width color bgcolor palette put get

hello: hello.rel
	/opt/fcc/bin/fcc -O2 -mz80 hello.rel -o hello
hello.rel: hello.c
	/opt/fcc/bin/fcc -O2 -mz80 -c hello.c

test: test.rel
	/opt/fcc/bin/fcc -O2 -mz80 test.rel -o test
test.rel: test.c
	/opt/fcc/bin/fcc -O2 -mz80 -c test.c

benchmark: benchmark.rel
	/opt/fcc/bin/fcc -O2 -mz80 benchmark.rel -o benchmark
benchmark.rel: benchmark.c
	/opt/fcc/bin/fcc -O2 -mz80 -c benchmark.c

width: picinterface.rel width.rel
	/opt/fcc/bin/fcc -O2 -mz80 width.rel picinterface.rel -o width
width.rel: width.c
	/opt/fcc/bin/fcc -O2 -mz80 -c width.c

color: picinterface.rel color.rel
	/opt/fcc/bin/fcc -O2 -mz80 color.rel picinterface.rel -o color
color.rel: color.c
	/opt/fcc/bin/fcc -O2 -mz80 -c color.c

bgcolor: picinterface.rel bgcolor.rel
	/opt/fcc/bin/fcc -O2 -mz80 bgcolor.rel picinterface.rel -o bgcolor
bgcolor.rel: bgcolor.c
	/opt/fcc/bin/fcc -O2 -mz80 -c bgcolor.c

palette: picinterface.rel palette.rel
	/opt/fcc/bin/fcc -O2 -mz80 palette.rel picinterface.rel -o palette
palette.rel: palette.c
	/opt/fcc/bin/fcc -O2 -mz80 -c palette.c

put: picinterface.rel put.rel
	/opt/fcc/bin/fcc -O2 -mz80 put.rel picinterface.rel -o put
put.rel: put.c
	/opt/fcc/bin/fcc -O2 -mz80 -c put.c

get: picinterface.rel get.rel
	/opt/fcc/bin/fcc -O2 -mz80 get.rel picinterface.rel -o get
get.rel: get.c
	/opt/fcc/bin/fcc -O2 -mz80 -c get.c

picinterface.rel: picinterface.c picinterface.h
	/opt/fcc/bin/fcc -O2 -mz80 -c picinterface.c

clean:
	rm -f *.rel
	rm -f *.map
	rm -f *.lk
	rm -f *.noi
	rm -f *.sym

drive: hello.rel test.rel benchmark.rel width.rel color.rel bgcolor.rel palette.rel put.rel get.rel

	./ucp fuziximg.ide:1049600 "cd /root ; get hello"
	./ucp fuziximg.ide:1049600 "cd /root ; chmod 755 hello"
	./ucp fuziximg.ide:1049600 "cd /root ; get test"
	./ucp fuziximg.ide:1049600 "cd /root ; chmod 755 test"
	./ucp fuziximg.ide:1049600 "cd /bin ; get benchmark"
	./ucp fuziximg.ide:1049600 "cd /bin ; chmod 755 benchmark"
	./ucp fuziximg.ide:1049600 "cd /bin ; get width"
	./ucp fuziximg.ide:1049600 "cd /bin ; chmod 755 width"
	./ucp fuziximg.ide:1049600 "cd /bin ; get color"
	./ucp fuziximg.ide:1049600 "cd /bin ; chmod 755 color"
	./ucp fuziximg.ide:1049600 "cd /bin ; get bgcolor"
	./ucp fuziximg.ide:1049600 "cd /bin ; chmod 755 bgcolor"
	./ucp fuziximg.ide:1049600 "cd /bin ; get palette"
	./ucp fuziximg.ide:1049600 "cd /bin ; chmod 755 palette"
	./ucp fuziximg.ide:1049600 "cd /bin ; get put"
	./ucp fuziximg.ide:1049600 "cd /bin ; chmod 755 put"
	./ucp fuziximg.ide:1049600 "cd /bin ; get get"
	./ucp fuziximg.ide:1049600 "cd /bin ; chmod 755 get"

parser: lex.yy.c ass1.tab.o main.cc
		g++ -g -o comp ass1.tab.o lex.yy.c main.cc
ass1.tab.o: ass1.tab.cc
		g++ -g -c ass1.tab.cc
ass1.tab.cc: ass1.yy
		bison ass1.yy
lex.yy.c: ass1.ll ass1.tab.cc
		flex ass1.ll
clean:
		rm -f ass1.tab.* lex.yy.c* int
cpp:
	g++ target.cc -o ccode && ./ccode
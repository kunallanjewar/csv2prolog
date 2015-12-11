all : csv2prolog

csv2prolog: get2prolog.o stringlib.o
	g++ -o csv2prolog get2prolog.o stringlib.o

get2prolog.o: get2prolog.c
	g++ -x c get2prolog.c

stringlib.o: 
	gcc -c stringlib.c

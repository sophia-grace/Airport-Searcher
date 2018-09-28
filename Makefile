##Makefile


search: search.o Airport.o List.o node.o
	gcc -o search search.o Airport.o List.o node.o


search.o: search.c List.h node.h Airport.h
	gcc -c search.c


Airport.o: Airport.c Airport.h
	gcc -c Airport.c


List.o: List.c List.h node.h Airport.h
	gcc -c List.c


node.o: node.c node.h
	gcc -c node.c


clean:
	rm *.o search

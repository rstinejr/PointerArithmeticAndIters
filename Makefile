##############

MY_BIN_CFLAGS  = -std=c++11 -g -O0 
MY_BIN_LDFLAGS = -lstdc++ -lrt

.PHONY:	clean run 

all:	main

main.o:	main.cpp
	g++ -Wall $(MY_BIN_CFLAGS) -c main.cpp -o $@

main:	main.o
	g++ -o $@ main.o $(MY_BIN_LDFLAGS)

clean:
	rm -f  main main.o
		
run:	main
	./main

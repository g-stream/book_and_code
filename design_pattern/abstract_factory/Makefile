cxx=g++
cflag=-g -Wall -std=c++14
test.o:test.cpp 
	${cxx} -c ${cflag} $<
factory.o:factory.h
	${cxx} -c ${cflag} $<
product.o:product.h
	${cxx} -c ${cflag} $<
test:test.o product.o factory.o 
	g++ -o $@  $<
.PHONY:clean
clean:
	rm *.o test
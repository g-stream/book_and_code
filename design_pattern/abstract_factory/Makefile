cxx=g++
cflag=-g -Wall -std=c++14

test:test.o product.o factory.o
	${cxx} ${cflag} -o $@  $^
test.o:%.o:%.cpp
	${cxx} ${cflag}  -c  $<
factory.o : %.o:%.cpp product.h
	${cxx} ${cflag} -c  $< 
product.o : %.o:%.cpp product.h
	${cxx} ${cflag} -c  $< 


.PHONY:clean
clean:
	rm *.o test
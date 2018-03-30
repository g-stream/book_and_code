cxx=g++-7
cflag=-std=c++14 -g -Wall
target:main


main.o : main.cpp product.h factory.h
	${cxx} -c $<
product.o : product.cpp product.h
	${cxx} -c  product.cpp
factory.o:factory.cpp product.h
	${cxx} -c  factory.cpp
main:main.o product.o factory.o
	${cxx} -o $@ $^
.PHONY:clean
clean:
	rm main *.o
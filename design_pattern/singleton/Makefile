cxx=g++-7
cflag=-std=c++14 -g -Wall
main:main.o singleton.o
	${cxx} -o $@ $^ ${cflag}
main.o : main.cpp singleton.h
	${cxx} -c $< ${cflag}
singleton.o : singleton.cpp singleton.h
	${cxx} -c  $< ${cflag}
.PHONY:clean
clean:
	rm main *.o
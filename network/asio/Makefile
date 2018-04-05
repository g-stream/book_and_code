cxx=g++
cflag=-g -Wall -std=c++17 -lboost_system -lboost_thread
source=${wildcard *.cpp}
target=${patsubst %.cpp, %, ${source}}
.PHONY:all clean
all:${target}
${target}:%:%.cpp
	${cxx} -o $@  $< ${cflag}
clean:
	rm *.o ${target}
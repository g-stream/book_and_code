cxx=g++
cflag=-g -Wall -std=c++17 -lboost_system -lpthread
source=${wildcard *.cpp}
target=${patsubst %.cpp, %, ${source}}
.PHONY:all
all:${target}
${target}:%:%.cpp
	${cxx} -o $@  $< ${cflag}
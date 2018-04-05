cc=gcc
cflag=-g -Wall 
source=${wildcard *.c}
target=${patsubst %.c, %, ${source}}
.PHONY:all clean
all:${target}
${target}:%:%.c
	${cc} -o $@  $< ${cflag}
clean:
	rm ${target}
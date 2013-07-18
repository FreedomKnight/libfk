CC= gcc
CFLAGS = -ansi -Wall -pedantic
BIN = ../bin
LIB = ../lib
INC = ../include

test: ${LIB}/libfk.a
	${CC} -I${INC} -L${LIB}  testList.c -o ${BIN}/testList -lfk

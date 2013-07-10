CC= gcc
CFLAGS = -ansi -Wall -pedantic
LIB = lib
INC = include
SRC = src
OBJ = ${LIB}/fk_list.o ${LIB}/fk_string.o

.SUFFIXS: .c

main: libfk.a
	${CC} -I${INC} -L${LIB}  main.c -lfk

libfk.a: ${OBJ}
	ar cru ${LIB}/$@ $^

${LIB}/%.o: ${SRC}/%.c
	${CC} -c ${CFLAGS} $< -o $@

.PHONY: clean
clean:
	rm -rf lib/*.o lib/*.a



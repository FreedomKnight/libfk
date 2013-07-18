CC= gcc
CFLAGS = -ansi -Wall -pedantic
LIB = lib
INC = include
SRC = src
OBJ = ${LIB}/fk_list.o ${LIB}/fk_stack.o ${LIB}/fk_queue.o ${LIB}/fk_string.o

.SUFFIXS: .c



libfk.a: ${OBJ}
	ar cru ${LIB}/$@ $^
	rm -rf $^

${LIB}/%.o: ${SRC}/%.c
	${CC} -I${INC} -c ${CFLAGS} $< -o $@

.PHONY: clean test
clean:
	rm -rf lib/*.o lib/*.a
	rm -rf bin/test*

test:
	cd tests && make


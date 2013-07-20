CC= gcc
CFLAGS = -ansi -Wall -pedantic
LIB = lib
INC = include
SRC = src
OBJ = ${LIB}/fk_list.o ${LIB}/fk_stack.o ${LIB}/fk_queue.o ${LIB}/fk_string.o
type = static

.SUFFIXS: .c

ifeq (${type}, shared)
libfk.so: ${OBJ}
	gcc -shared $^ -o ${LIB}/$@

else 
libfk.a: ${OBJ}
	ar cru ${LIB}/$@ $^
	rm -rf $^
endif

${LIB}/%.o: ${SRC}/%.c
ifeq (${type}, shared)
	${CC} -fPIC -I${INC} -c ${CFLAGS} $< -o $@
else 
	${CC} -I${INC} -c ${CFLAGS} $< -o $@
endif

.PHONY: clean test
clean:
	rm -rf lib/*.o lib/*.a lib/*.so
	rm -rf bin/test*

test:
	cd tests && make


#ifndef FK_STRING_H
#define FK_STRING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef char *String;
String new_string(size_t size);
String string_read_file(FILE *fp);
String string_read();

#endif


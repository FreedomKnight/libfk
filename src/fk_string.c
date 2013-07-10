#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef char *String;

String new_string(size_t size)
{
    String ret_str = (String) malloc(sizeof(char) * size);
    memset(ret_str, '\0', sizeof(char) * size);
    return ret_str;
}

String string_read_file(FILE *fp)
{
    char ch = '\0';
    String tmp = new_string(BUFSIZ);
    String ret_str = NULL;
    size_t i = 0;
    do {
        ch = getc(fp);
    } while (isspace(ch));

    while (!isspace(ch)) {
        tmp[i] = ch;
        i++;
        if (i >= BUFSIZ) {
            String chk_str = realloc(tmp, ((i / BUFSIZ) + 2) * BUFSIZ);
            if (chk_str != tmp) {
                free(tmp);    
                tmp = NULL;
            }

            tmp = chk_str;
        }

        ch = getc(fp);
    }

    ret_str = new_string(strlen(tmp) + 1);
    strcpy(ret_str, tmp);
    free(tmp);
    return ret_str;
}

String string_read()
{
    return string_read_file(stdin);
}


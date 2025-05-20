//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *str;
    int len;
} string;

string *new_string(char *str) {
    string *s = malloc(sizeof(string));
    s->str = malloc(strlen(str)+1);
    strcpy(s->str, str);
    s->len = strlen(str);
    return s;
}

void free_string(string *s) {
    free(s->str);
    free(s);
}

string *read_line(FILE *fp) {
    char buf[MAX_LINE_LENGTH];
    if (fgets(buf, MAX_LINE_LENGTH, fp) == NULL) {
        return NULL;
    }

    if (strlen(buf) > 0 && buf[strlen(buf)-1] == '\n') {
        buf[strlen(buf)-1] = '\0';
    }

    return new_string(buf);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s binary_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = strlen(argv[1]);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (argv[1][i] == '1' || argv[1][i] == '0') {
            m++;
        }
    }

    if (m != n) {
        fprintf(stderr, "%s is not a binary number\n", argv[1]);
        return EXIT_FAILURE;
    }

    int num = 0;
    for (int i = n-1; i >= 0; i--) {
        if (argv[1][i] == '1') {
            num |= 1 << (n-1-i);
        }
    }

    printf("%d\n", num);

    return EXIT_SUCCESS;
}
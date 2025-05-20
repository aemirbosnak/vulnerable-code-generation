//Falcon-180B DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *fp;
    int line_number;
} FileContext;

char *read_line(FILE *fp) {
    char *line = malloc(MAX_LINE_LENGTH);
    char ch;
    int len = 0;

    while ((ch = fgetc(fp))!= '\n' && ch!= EOF) {
        if (len >= MAX_LINE_LENGTH - 1) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        line[len++] = ch;
    }

    if (ch == '\n') {
        line[len++] = '\0';
    } else {
        line[len] = '\0';
    }

    return line;
}

void print_line_number(int line_number) {
    printf("%d: ", line_number);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FileContext context = {
       .filename = argv[1],
       .fp = fopen(argv[1], "r"),
       .line_number = 1
    };

    if (context.fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    char *line;
    while ((line = read_line(context.fp))!= NULL) {
        print_line_number(context.line_number);
        printf("%s", line);
        context.line_number++;
        free(line);
    }

    fclose(context.fp);
    free(context.filename);

    return 0;
}
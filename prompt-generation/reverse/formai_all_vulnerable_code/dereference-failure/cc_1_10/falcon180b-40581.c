//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

char *read_line(FILE *file) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t read;

    while ((read = getline(&line, &capacity, file))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, read + 1);
            line[read] = '\0';
        }
        capacity += MAX_LINE_LENGTH;
    }

    return line;
}

char *tokenize(char *line) {
    char *token = strtok(line, ",.?!;:");
    while (token!= NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",.?!;:");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    char *line = read_line(file);
    if (line == NULL) {
        fprintf(stderr, "Error reading file: %s\n", argv[1]);
        return 1;
    }

    tokenize(line);

    free(line);
    fclose(file);

    return 0;
}
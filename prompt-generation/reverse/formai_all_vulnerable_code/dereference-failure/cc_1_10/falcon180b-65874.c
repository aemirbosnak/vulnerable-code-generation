//Falcon-180B DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    int line_number;
} ErrorInfo;

void error(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

void unexpected_error(char *message) {
    printf("Unexpected error: %s\n", message);
    exit(1);
}

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char ch;
    int length = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (length >= MAX_LINE_LENGTH) {
            printf("Error: Line too long in file.\n");
            exit(1);
        }
        line[length++] = ch;
    }
    line[length] = '\0';
    return line;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No filename provided.\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        exit(1);
    }

    int line_number = 1;
    char *line = read_line(file);

    while (line!= NULL) {
        printf("Line %d: %s", line_number, line);
        line_number++;
        line = read_line(file);
    }

    fclose(file);
    return 0;
}
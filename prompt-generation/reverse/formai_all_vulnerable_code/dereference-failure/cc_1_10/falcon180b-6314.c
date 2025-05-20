//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *result = line;

    int ch;
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            *result = '\0';
            return line;
        }

        if (result - line >= MAX_LINE_LENGTH - 1) {
            fprintf(stderr, "Line too long. ");
            exit(1);
        }

        *result++ = tolower(ch);
    }

    if (result - line >= MAX_LINE_LENGTH - 1) {
        fprintf(stderr, "Line too long. ");
        exit(1);
    }

    *result = '\0';
    return line;
}

void write_line(FILE *file, char *line) {
    fprintf(file, "%s\n", line);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> ", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Cannot open input file. ");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Cannot open output file. ");
        fclose(input_file);
        return 1;
    }

    char *line;
    while ((line = read_line(input_file))!= NULL) {
        char *word = strtok(line, " \t\n");
        while (word!= NULL) {
            if (strcmp(word, "the") == 0) {
                strcpy(word, "a");
            }

            write_line(output_file, line);

            word = strtok(NULL, " \t\n");
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
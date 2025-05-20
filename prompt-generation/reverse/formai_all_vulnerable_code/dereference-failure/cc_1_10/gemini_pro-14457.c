//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char *lines[MAX_LINES];
    int num_lines = 0;

    while (fgets(lines[num_lines], MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;
    }

    fclose(fp);

    for (int i = 0; i < num_lines; i++) {
        char *line = lines[i];

        // Remove leading and trailing whitespace
        while (*line == ' ' || *line == '\t') {
            line++;
        }

        char *end = line;
        while (*end != '\0' && *end != '\n') {
            end++;
        }

        *end = '\0';

        // Print the line in reverse order
        while (line < end) {
            putchar(*end--);
        }

        putchar('\n');
    }

    return EXIT_SUCCESS;
}
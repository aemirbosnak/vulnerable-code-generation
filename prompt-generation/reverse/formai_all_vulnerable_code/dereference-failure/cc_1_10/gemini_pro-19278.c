//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void beautify_html(char *input, char *output) {
    FILE *input_file = fopen(input, "r");
    if (input_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output, "w");
    if (output_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int indent_level = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        line_number++;

        // Remove leading and trailing whitespace
        char *trimmed_line = malloc(strlen(line) + 1);
        if (trimmed_line == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(trimmed_line, line);
        while (trimmed_line[strlen(trimmed_line) - 1] == '\n' || trimmed_line[strlen(trimmed_line) - 1] == '\r' || trimmed_line[strlen(trimmed_line) - 1] == '\t' || trimmed_line[strlen(trimmed_line) - 1] == ' ') {
            trimmed_line[strlen(trimmed_line) - 1] = '\0';
        }
        while (trimmed_line[0] == '\n' || trimmed_line[0] == '\r' || trimmed_line[0] == '\t' || trimmed_line[0] == ' ') {
            memmove(trimmed_line, trimmed_line + 1, strlen(trimmed_line));
        }

        // Determine the indent level
        int i = 0;
        while (trimmed_line[i] == '\t') {
            i++;
        }
        indent_level = i;

        // Beautify the line
        char *beautified_line = malloc(strlen(trimmed_line) + 1);
        if (beautified_line == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(beautified_line, trimmed_line);
        if (indent_level > 0) {
            for (i = 0; i < indent_level; i++) {
                beautified_line[i] = '\t';
            }
        }
        beautified_line[strlen(trimmed_line)] = '\n';

        // Write the line to the output file
        fprintf(output_file, "%s", beautified_line);

        free(trimmed_line);
        free(beautified_line);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input.html output.html\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    beautify_html(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
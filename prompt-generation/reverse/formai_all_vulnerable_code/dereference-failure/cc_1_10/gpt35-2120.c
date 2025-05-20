//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void beautify_html(FILE *input_file, FILE *output_file);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification complete!\n");
    return 0;
}

void beautify_html(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];
    int indentation_level = 0;
    char *indentation = "";

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Trim leading and trailing whitespace
        char *trimmed_line = strdup(line);
        int len = strlen(trimmed_line);
        while (len > 0 && (trimmed_line[len-1] == '\n' || trimmed_line[len-1] == ' ')) {
            trimmed_line[--len] = '\0';
        }
        while (*trimmed_line == ' ') {
            trimmed_line++;
        }

        if (strlen(trimmed_line) == 0) {
            // Ignore blank lines
            continue;
        }

        if (strstr(trimmed_line, "</") != NULL) {
            indentation_level--;
            indentation = "";
            for (int i = 0; i < indentation_level; i++) {
                indentation = strcat(indentation, "    ");
            }
        }

        fprintf(output_file, "%s%s\n", indentation, trimmed_line);

        if (strstr(trimmed_line, "<") != NULL && strstr(trimmed_line, "</") == NULL) {
            indentation_level++;
            indentation = "";
            for (int i = 0; i < indentation_level; i++) {
                indentation = strcat(indentation, "    ");
            }
        }
    }
}
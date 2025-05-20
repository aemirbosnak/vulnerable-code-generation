//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define INDENTATION_SIZE 4

void print_indentation(int indentation_level, FILE* output_file) {
    for (int i = 0; i < indentation_level * INDENTATION_SIZE; i++) {
        fprintf(output_file, " ");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Please provide an input file and an output file as arguments\n");
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[2], "w");

    if (input_file == NULL) {
        printf("Unable to open input file\n");
        return 1;
    }

    if (output_file == NULL) {
        printf("Unable to open output file\n");
        return 1;
    }

    char current_line[MAX_LINE_LENGTH];
    int indentation_level = 0;

    while (fgets(current_line, MAX_LINE_LENGTH, input_file)) {
        char* trimmed_line = strdup(current_line);
        int i = 0;
        while (trimmed_line[i] == ' ' || trimmed_line[i] == '\t') {
            i++;
        }
        trimmed_line += i;

        if (strlen(trimmed_line) == 0) {
            continue;
        }

        if (trimmed_line[0] == '}') {
            indentation_level--;
        }

        print_indentation(indentation_level, output_file);
        fprintf(output_file, "%s\n", trimmed_line);

        if (trimmed_line[strlen(trimmed_line) - 2] == '{') {
            indentation_level++;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
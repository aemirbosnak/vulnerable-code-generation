//Falcon-180B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char line[MAX_LINE_LENGTH];
    int length;
} Line;

int main() {
    FILE *input_file;
    FILE *output_file;
    Line *lines = (Line *)malloc(MAX_LINES * sizeof(Line));
    int num_lines = 0;
    int i = 0;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read lines from input file
    while (fgets(lines[i].line, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Remove newline character from end of line
        lines[i].line[strcspn(lines[i].line, "\n")] = '\0';
        lines[i].length = strlen(lines[i].line);
        i++;
        num_lines++;
    }

    // Sort lines alphabetically
    for (i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strcmp(lines[i].line, lines[j].line) > 0) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write sorted lines to output file
    for (i = 0; i < num_lines; i++) {
        fprintf(output_file, "%s\n", lines[i].line);
    }

    // Close files and free memory
    fclose(input_file);
    fclose(output_file);
    free(lines);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;

    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read lines from input file
    while (fgets(lines[num_lines].line, MAX_LINE_LENGTH, input_file)!= NULL) {
        lines[num_lines].length = strlen(lines[num_lines].line);
        num_lines++;
    }

    // Sort lines by length
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (lines[j].length < lines[i].length) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Write sorted lines to output file
    output_file = fopen("sorted_input.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(output_file, "%s\n", lines[i].line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
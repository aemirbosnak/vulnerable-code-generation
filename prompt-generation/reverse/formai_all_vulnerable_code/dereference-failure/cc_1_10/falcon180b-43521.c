//Falcon-180B DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *input_file;
    FILE *output_file;
    char *input_filename = "input.txt";
    char *output_filename = "output.txt";
    char line[MAX_LINE_LENGTH];
    char *line_copy = NULL;
    char *token;
    int line_number = 0;

    if ((input_file = fopen(input_filename, "r")) == NULL) {
        printf("Error: Could not open input file '%s'.\n", input_filename);
        exit(1);
    }

    if ((output_file = fopen(output_filename, "w")) == NULL) {
        printf("Error: Could not open output file '%s'.\n", output_filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_number++;

        // Make a copy of the line to avoid modifying the original
        if ((line_copy = strdup(line)) == NULL) {
            printf("Error: Could not allocate memory.\n");
            exit(1);
        }

        // Replace all spaces with underscores
        token = strtok(line_copy, " ");
        while (token!= NULL) {
            strcpy(token, "_");
            token = strtok(NULL, " ");
        }

        // Write the modified line to the output file
        fprintf(output_file, "%d: %s\n", line_number, line_copy);

        free(line_copy);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
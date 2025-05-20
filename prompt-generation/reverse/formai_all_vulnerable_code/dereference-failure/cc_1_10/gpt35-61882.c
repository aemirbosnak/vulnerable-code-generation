//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *input_file;
    FILE *output_file;

    char input_filename[50];
    char output_filename[50];

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    
    if (input_file == NULL) {
        printf("Error: could not open input file.");
        exit(1);
    }

    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error: could not open output file.");
        exit(1);
    }

    int indent_level = 0;
    char current_char, last_char;

    while ((current_char = fgetc(input_file)) != EOF) {
        if (current_char == '<') {
            if (last_char == '\n') {
                for (int i = 0; i < indent_level; i++) {
                    fprintf(output_file, "\t");
                }
            }

            if (fgetc(input_file) == '/') {
                indent_level--;
            }

            fprintf(output_file, "<%c", current_char);
            indent_level++;
        } else if (current_char == '>') {
            fprintf(output_file, ">%c", current_char);

            if (last_char == '/') {
                indent_level--;
            }

            fprintf(output_file, "\n");
        } else {
            fprintf(output_file, "%c", current_char);
        }

        last_char = current_char;
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
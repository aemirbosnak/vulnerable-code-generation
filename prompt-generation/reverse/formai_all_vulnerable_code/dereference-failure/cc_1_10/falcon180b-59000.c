//Falcon-180B DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_length;

    printf("Welcome to the Amazing Text File Conversion Program! \n");
    printf("Please enter the name of the input file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error: could not open input file '%s'. \n", input_filename);
        exit(EXIT_FAILURE);
    }

    printf("Please enter the name of the output file: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error: could not open output file '%s'. \n", output_filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }
        fprintf(output_file, "%s", line);
    }

    fclose(input_file);
    fclose(output_file);

    printf("The conversion is complete! \n");

    return 0;
}
//FormAI DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char input_file_name[MAX_LINE_LENGTH] = "input.txt";
    char output_file_name[MAX_LINE_LENGTH] = "output.txt";
    char line[MAX_LINE_LENGTH];
    FILE *input_file, *output_file;

    // handle command line arguments
    if (argc > 1) {
        strncpy(input_file_name, argv[1], MAX_LINE_LENGTH);
    }
    if (argc > 2) {
        strncpy(output_file_name, argv[2], MAX_LINE_LENGTH);
    }

    // open input file for reading
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: cannot open input file %s\n", input_file_name);
        exit(1);
    }

    // open output file for writing
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: cannot open output file %s\n", output_file_name);
        exit(1);
    }

    // read input file line by line and process each line
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // remove new line character
        line[strcspn(line, "\n")] = '\0';

        // convert to upper case
        for (int i = 0; line[i]; i++) {
            line[i] = toupper(line[i]);
        }

        // write processed line to output file
        fprintf(output_file, "%s\n", line);
    }

    // close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open input and output files
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    // Check if files were opened successfully
    if (!input_file ||!output_file) {
        fprintf(stderr, "Error opening files\n");
        exit(1);
    }

    // Read input file
    char line[1000];
    while (fgets(line, sizeof(line), input_file)) {
        // Skip empty lines
        if (strlen(line) == 0)
            continue;

        // Remove leading and trailing whitespace
        line[strcspn(line, "\r\n")] = '\0';

        // Split line into tokens
        char *token = strtok(line, ",");
        while (token!= NULL) {
            // Write token to output file
            fprintf(output_file, "%s\n", token);

            // Get next token
            token = strtok(NULL, ",");
        }
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
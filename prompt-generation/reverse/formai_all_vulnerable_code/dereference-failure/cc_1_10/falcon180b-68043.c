//Falcon-180B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    char *input_filename = NULL;
    char *output_filename = NULL;
    char *line = NULL;
    size_t line_length = 0;
    size_t line_count = 0;
    char *error_message = NULL;
    int error_code = 0;

    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Allocate memory for the input and output filenames
    input_filename = malloc(strlen(argv[1]) + 1);
    output_filename = malloc(strlen(argv[2]) + 1);

    // Copy the input and output filenames into the allocated memory
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    // Open the input file for reading
    input_file = fopen(input_filename, "r");

    // Check if the input file was opened successfully
    if (input_file == NULL) {
        error_code = errno;
        error_message = strerror(error_code);
        fprintf(stderr, "Error opening input file '%s': %s\n", input_filename, error_message);
        free(input_filename);
        free(output_filename);
        return 1;
    }

    // Allocate memory for the input line
    line = malloc(MAX_LINE_LENGTH);

    // Read the input file line by line
    while ((fgets(line, MAX_LINE_LENGTH, input_file))!= NULL) {
        // Increment the line count
        line_count++;

        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Convert the line to uppercase
        for (char *c = line; *c!= '\0'; c++) {
            *c = toupper(*c);
        }

        // Write the modified line to the output file
        fprintf(stdout, "%s\n", line);
    }

    // Close the input file
    fclose(input_file);

    // Open the output file for writing
    FILE *output_file = fopen(output_filename, "w");

    // Check if the output file was opened successfully
    if (output_file == NULL) {
        error_code = errno;
        error_message = strerror(error_code);
        fprintf(stderr, "Error opening output file '%s': %s\n", output_filename, error_message);
        free(input_filename);
        free(output_filename);
        return 1;
    }

    // Write the line count to the output file
    fprintf(output_file, "Total lines: %zu\n", line_count);

    // Close the output file
    fclose(output_file);

    // Free the allocated memory
    free(input_filename);
    free(output_filename);
    free(line);

    return 0;
}
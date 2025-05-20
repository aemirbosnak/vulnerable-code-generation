//Falcon-180B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define MAX_NUM_LINES 1000

// Function to read a line from the file and store it in a buffer
void read_line(FILE* file, char* buffer) {
    fgets(buffer, MAX_LINE_LENGTH, file);
    strtok(buffer, "\n");
}

// Function to write a line to the file
void write_line(FILE* file, char* buffer) {
    fprintf(file, "%s\n", buffer);
}

// Function to print a line to the console
void print_line(char* buffer) {
    printf("%s", buffer);
}

int main() {
    FILE* input_file = NULL;
    FILE* output_file = NULL;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char line_buffer[MAX_LINE_LENGTH];
    int num_lines = 0;

    // Get the input file name from the user
    printf("Enter the name of the input file: ");
    fgets(input_filename, MAX_LINE_LENGTH, stdin);
    strtok(input_filename, "\n");

    // Open the input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get the output file name from the user
    printf("Enter the name of the output file: ");
    fgets(output_filename, MAX_LINE_LENGTH, stdin);
    strtok(output_filename, "\n");

    // Open the output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read each line from the input file and write it to the output file
    while (fgets(line_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        num_lines++;

        // Reverse the line
        char* start_ptr = line_buffer;
        char* end_ptr = line_buffer + strlen(line_buffer) - 1;
        while (start_ptr < end_ptr) {
            char temp = *start_ptr;
            *start_ptr = *end_ptr;
            *end_ptr = temp;
            start_ptr++;
            end_ptr--;
        }

        // Write the reversed line to the output file
        write_line(output_file, line_buffer);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    // Print the number of lines in the input file
    printf("The input file had %d lines.\n", num_lines);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char** argv) {
    // Check for correct number of arguments
    if (argc!= 3) {
        error("Usage:./program input_file output_file");
    }

    // Open input file
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        error("Error opening input file");
    }

    // Open output file
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        error("Error opening output file");
    }

    // Read input file
    char input_buffer[1024];
    size_t bytes_read = 0;
    while ((bytes_read = fread(input_buffer, sizeof(char), sizeof(input_buffer), input_file)) > 0) {
        // Reverse the input buffer
        for (int i = 0; i < bytes_read / 2; i++) {
            char temp = input_buffer[i];
            input_buffer[i] = input_buffer[bytes_read - 1 - i];
            input_buffer[bytes_read - 1 - i] = temp;
        }

        // Write to output file
        if (fwrite(input_buffer, sizeof(char), bytes_read, output_file)!= bytes_read) {
            error("Error writing to output file");
        }
    }

    // Close files and exit
    if (fclose(input_file)!= 0 || fclose(output_file)!= 0) {
        error("Error closing file");
    }

    return 0;
}
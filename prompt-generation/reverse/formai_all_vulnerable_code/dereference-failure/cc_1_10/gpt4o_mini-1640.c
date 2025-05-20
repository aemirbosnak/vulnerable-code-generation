//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LITERAL 128

// Function to compress the data using a simple run-length encoding algorithm
void compress(const char *input, char *output) {
    int count, i, j = 0;
    int len = strlen(input);

    for (i = 0; i < len; i++) {
        // Count occurrences of the current character
        count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append the character and its count if more than 1
        if (count > 1) {
            output[j++] = input[i];
            output[j++] = count + '0'; // Convert int to char
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to decompress the data
void decompress(const char *input, char *output) {
    int i, j = 0;
    int len = strlen(input);

    for (i = 0; i < len; i++) {
        // If character is a digit, expand it
        if (input[i + 1] >= '1' && input[i + 1] <= '9') {
            int count = input[i + 1] - '0'; // Count from next character
            for (int k = 0; k < count; k++) {
                output[j++] = input[i];
            }
            i++; // Skip the count character
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Helper function to read input from a file
char *read_input_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(length + 1);
    fread(buffer, 1, length, file);
    buffer[length] = '\0'; // Null-terminate the buffer
    fclose(file);
    return buffer;
}

// Helper function to write output to a file
void write_output_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "%s", data);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the input file
    char *input_data = read_input_file(argv[1]);
    if (!input_data) {
        return EXIT_FAILURE;
    }

    // Allocate memory for compressed output
    char compressed_output[MAX_LITERAL * 2];
    compress(input_data, compressed_output);

    // Show compressed data
    printf("Compressed Output: %s\n", compressed_output);

    // Allocate memory for decompressed output
    char decompressed_output[MAX_LITERAL * 2];
    decompress(compressed_output, decompressed_output);

    // Show decompressed data
    printf("Decompressed Output: %s\n", decompressed_output);

    // Write compressed output to a file
    write_output_file(argv[2], compressed_output);
    
    // Free allocated memory
    free(input_data);

    return EXIT_SUCCESS;
}
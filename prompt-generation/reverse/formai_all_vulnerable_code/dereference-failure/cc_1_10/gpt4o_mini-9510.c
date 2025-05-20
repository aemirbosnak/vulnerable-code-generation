//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the function to compress the input data
void compress(const char *input, char *output) {
    int count = 1, j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output[j++] = input[i];
            output[j++] = count + '0'; // Convert count to character
            count = 1;
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to decompress the compressed string
void decompress(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i += 2) {
        char ch = input[i];
        int count = input[i + 1] - '0'; // Convert character back to number
        for (int k = 0; k < count; k++) {
            output[j++] = ch;
        }
    }
    output[j] = '\0'; // Null-terminate the decompressed string
}

// Function for file operations
void handle_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }

    // Read from the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    
    // Allocate memory for input and output
    char *input = (char *)malloc(file_size + 1);
    char *compressed = (char *)malloc((file_size * 2) + 1); // worst case: all chars are same
    char *decompressed = (char *)malloc(file_size + 1);
    
    if (input == NULL || compressed == NULL || decompressed == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    fread(input, 1, file_size, file);
    input[file_size] = '\0'; // Null-terminate the input string
    fclose(file);

    printf("Original: %s\n", input);

    // Perform compression
    compress(input, compressed);
    printf("Compressed: %s\n", compressed);

    // Perform decompression
    decompress(compressed, decompressed);
    printf("Decompressed: %s\n", decompressed);

    // Clean up
    free(input);
    free(compressed);
    free(decompressed);
}

// Main function kicks off the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    handle_file(argv[1]);

    return EXIT_SUCCESS;
}
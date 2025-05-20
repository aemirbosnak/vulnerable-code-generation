//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform run-length encoding
void runLengthEncode(const char *input, char *output) {
    int count = 1; // To count occurrences of a character
    int j = 0;     // Output index

    for (int i = 0; i < strlen(input); i++) {
        // If the current character matches the next one, increment count
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            // Append current char and its count to output
            output[j++] = input[i];
            output[j++] = count + '0'; // Convert number to char
            count = 1; // Reset count for new character
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to read file content
char *readFileContent(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *content = malloc(length + 1);
    if (content) {
        fread(content, 1, length, file);
        content[length] = '\0'; // Null-terminate the string
    }
    fclose(file);
    return content;
}

// Function to write compressed content to a file
void writeToFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }
    fputs(data, file);
    fclose(file);
}

// Main function to drive the program
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1; // Exit if insufficient arguments
    }

    char *input = readFileContent(argv[1]);
    if (!input) {
        return 1; // Exit if reading fails
    }

    // Allocate enough space for the output (worst case is input length * 2)
    char *output = malloc(strlen(input) * 2 + 1);
    runLengthEncode(input, output);
    
    // Write the compressed data to the output file
    writeToFile(argv[2], output);

    // Clean up
    free(input);
    free(output);

    printf("Compression completed! Output written to %s\n", argv[2]);
    return 0;
}
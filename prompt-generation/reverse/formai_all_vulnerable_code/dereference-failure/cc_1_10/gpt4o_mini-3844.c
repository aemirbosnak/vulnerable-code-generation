//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function prototypes
char* compress(const char* input);
void displayResults(const char* original, const char* compressed);

int main() {
    char input[MAX_LENGTH];

    printf("Welcome to the Run-Length Encoding Compression Program!\n");
    printf("Enter a string you'd like to compress (max %d characters): ", MAX_LENGTH - 1);
    
    // Getting user input
    fgets(input, MAX_LENGTH, stdin);
    // Removing newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Performing compression
    char* compressed = compress(input);
    
    // Displaying results
    displayResults(input, compressed);

    // Freeing the allocated memory
    free(compressed);

    return 0;
}

// Function to compress the input string using Run-Length Encoding
char* compress(const char* input) {
    int inputLen = strlen(input);
    if(inputLen == 0) return strdup(""); // Handle empty string

    // Allocate a buffer maximally sized for the worst-case scenario
    char* compressed = (char*)malloc(sizeof(char) * (2 * inputLen + 1));
    if (compressed == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int i = 0, j = 0;
    while (i < inputLen) {
        // Count occurrences of the current character
        char currentChar = input[i];
        int count = 1;
        while (i + 1 < inputLen && input[i + 1] == currentChar) {
            count++;
            i++;
        }

        // Write character and count to the compressed buffer
        j += sprintf(&compressed[j], "%c%d", currentChar, count);
        i++;
    }
    compressed[j] = '\0'; // Null-terminate the compressed string

    return compressed;
}

// Function to display original and compressed string
void displayResults(const char* original, const char* compressed) {
    printf("\n--- Compression Results ---\n");
    printf("Original string:  \"%s\"\n", original);
    printf("Compressed string: \"%s\"\n", compressed);
    printf("--- Compression Completed! ---\n");
}
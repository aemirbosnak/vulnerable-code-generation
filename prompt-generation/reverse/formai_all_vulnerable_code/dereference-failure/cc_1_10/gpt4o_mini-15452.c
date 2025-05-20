//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the string using Run-Length Encoding
char* compressRLE(const char* input) {
    int length = strlen(input);
    if (length == 0) return "";

    char* compressed = (char*)malloc(2 * length + 1); // Allocate maximum possible size
    int count = 1, index = 0;

    for (int i = 1; i <= length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            index += sprintf(compressed + index, "%c%d", input[i - 1], count); // Print char and count
            count = 1; // Reset count
        }
    }
    
    compressed[index] = '\0'; // Null-terminate the string
    return compressed;
}

// Function to decompress the string
char* decompressRLE(const char* input) {
    int length = strlen(input);
    char* decompressed = (char*)malloc(2 * length); // Allocate enough space for decompressed string
    int index = 0;

    for (int i = 0; i < length; i++) {
        char currentChar = input[i];
        i++;
        int count = input[i] - '0'; // Convert character digit to integer

        for (int j = 0; j < count; j++) {
            decompressed[index++] = currentChar; // Repeat currentChar 'count' times
        }
    }
    
    decompressed[index] = '\0'; // Null-terminate the string
    return decompressed;
}

// Main function to run the program
int main() {
    char input[100]; // Buffer for user input

    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    char* compressed = compressRLE(input);
    printf("Compressed string: %s\n", compressed);

    char* decompressed = decompressRLE(compressed);
    printf("Decompressed string: %s\n", decompressed);

    // Clean up dynamically allocated memory
    free(compressed);
    free(decompressed);
    
    return 0;
}
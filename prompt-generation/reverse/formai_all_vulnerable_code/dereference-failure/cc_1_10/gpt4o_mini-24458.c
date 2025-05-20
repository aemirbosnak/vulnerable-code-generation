//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Run-Length Encoding
char* runLengthEncoding(const char* input) {
    int length = strlen(input);
    // Maximum possible size after encoding 
    // (in the worst case, every character could be an individual character followed by '1')
    char* encoded = (char*)malloc(length * 2 + 1);
    
    if (!encoded) {
        printf("Memory allocation failed! Please try again.\n");
        return NULL;
    }

    int index = 0; // To keep track of our position in the encoded array

    for (int i = 0; i < length; i++) {
        // Count occurrences of input[i]
        int count = 1;
        while (i + 1 < length && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Store the character and its count in the encoded string
        index += sprintf(encoded + index, "%c%d", input[i], count);
    }
    
    encoded[index] = '\0'; // Null-terminate the encoded string
    return encoded;
}

// Main function
int main() {
    char input[100]; // Buffer for user input
    
    printf("🌟 Welcome to the Magical RLE Compressor! 🌟\n");
    printf("Enter a string to compress: ");
    
    // Read input string
    fgets(input, sizeof(input), stdin);
    // Remove newline character
    input[strcspn(input, "\n")] = 0;
    
    // Perform Run-Length Encoding
    char* compressed = runLengthEncoding(input);
    
    if (compressed) {
        printf("✨ Original String: %s\n", input);
        printf("✨ Compressed String: %s\n", compressed);
        // Free allocated memory
        free(compressed);
    }
    
    printf("🎉 Thank you for using the RLE Compressor! Have a fantastic day! 🎉\n");
    return 0;
}
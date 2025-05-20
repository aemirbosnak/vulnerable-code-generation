//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Run Length Encoding
char* runLengthEncode(const char* input) {
    int n = strlen(input);
    if (n == 0) return "";

    char* encoded = (char*)malloc(2 * n + 1); // Allocate maximum space needed
    int count = 1;
    int index = 0;

    for (int i = 1; i <= n; i++) {
        // Count occurrences of the same character
        if (i < n && input[i] == input[i - 1]) {
            count++;
        } else {
            // Store the current character and its count
            index += sprintf(encoded + index, "%c%d", input[i - 1], count);
            count = 1;
        }
    }

    encoded[index] = '\0'; // Null-terminate the string
    return encoded;
}

// Function to perform Run Length Decoding
char* runLengthDecode(const char* encoded) {
    int n = strlen(encoded);
    char* decoded = (char*)malloc(2 * n + 1); // Allocate maximum space needed
    int index = 0;

    for (int i = 0; i < n; i++) {
        char ch = encoded[i];
        i += 1; // Move to the digit(s)
        int count = 0;

        while (i < n && encoded[i] >= '0' && encoded[i] <= '9') {
            count = count * 10 + (encoded[i] - '0');
            i++;
        }
        i--; // Decrement back to last digit

        for (int j = 0; j < count; j++) {
            decoded[index++] = ch; // Repeat character 'count' times
        }
    }

    decoded[index] = '\0'; // Null-terminate the string
    return decoded;
}

int main() {
    char input[100];
    printf("🎉 Welcome to the Run Length Encoding (RLE) Compression Program! 🎉\n");
    
    // Get user input
    printf("Please enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input

    // Compress the input
    char* compressed = runLengthEncode(input);
    printf("\n✨ Compressed String: %s\n", compressed);

    // Decompress the compressed string
    char* decompressed = runLengthDecode(compressed);
    printf("🎈 Decompressed String: %s\n", decompressed);

    // Clean up allocated memory
    free(compressed);
    free(decompressed);

    printf("🌈 Thank you for using the RLE Compression Program! Have a fantastic day! 🌈\n");
    return 0;
}
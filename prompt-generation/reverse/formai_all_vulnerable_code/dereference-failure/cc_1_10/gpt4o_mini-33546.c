//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using RLE
char* compress(const char* input) {
    int len = strlen(input);
    char* result = malloc(len * 2 + 1); // Max compressed size
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    int count = 1, j = 0;
    for (int i = 0; i < len; i++) {
        if (i < len - 1 && input[i] == input[i + 1]) {
            count++;
        } else {
            // Write character and count to result
            j += sprintf(result + j, "%c%d", input[i], count);
            count = 1; // Reset for new character
        }
    }
    
    return result;
}

// Function to decompress the RLE compressed string
char* decompress(const char* input) {
    char* result = malloc(strlen(input) * 10 + 1); // Over-allocate space for decompression
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char character = input[i];
        i++;
        int count = 0;

        // Read the number that follows the character
        while (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // Adjust for the loop increment

        // Expand the character 'count' times in result
        for (int k = 0; k < count; k++) {
            result[j++] = character;
        }
    }
    result[j] = '\0'; // Null-terminate the string
    return result;
}

int main() {
    char input[100];

    printf("Enter a string to compress (max 99 characters): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Compress the input string
    char* compressed = compress(input);
    printf("Compressed output: %s\n", compressed);

    // Decompress the string
    char* decompressed = decompress(compressed);
    printf("Decompressed output: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}
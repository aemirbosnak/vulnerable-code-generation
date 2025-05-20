//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run-Length Encoding
char* rle_compress(const char* input) {
    int len = strlen(input);
    if (len == 0) return "";

    char* compressed = malloc(len * 2 + 1); // Allocate max possible size
    if (!compressed) return NULL;

    int index = 0;
    for (int i = 0; i < len; i++) {
        // Count occurrences of the current character
        int count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Store the character and its count
        index += sprintf(compressed + index, "%c%d", input[i], count);
    }
    compressed[index] = '\0'; // Null-terminate the string
    return compressed; 
}

// Function to decompress the RLE compressed string
char* rle_decompress(const char* input) {
    int len = strlen(input);
    if (len == 0) return "";

    char* decompressed = malloc(len * 2 + 1); // Allocate max possible size
    if (!decompressed) return NULL;

    int index = 0;
    for (int i = 0; i < len; i++) {
        char ch = input[i];
        i++;
        int count = 0;
        // Read the number which represents the count
        while (i < len && isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // To counter the outer loop increment
        // Append the character 'count' times
        for (int j = 0; j < count; j++) {
            decompressed[index++] = ch;
        }
    }
    decompressed[index] = '\0'; // Null-terminate the string
    return decompressed; 
}

int main() {
    char input[256];
    
    printf("Enter a string to compress (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    // Compression
    char* compressed = rle_compress(input);
    if (compressed) {
        printf("Compressed: %s\n", compressed);
        
        // Decompression
        char* decompressed = rle_decompress(compressed);
        if (decompressed) {
            printf("Decompressed: %s\n", decompressed);
            free(decompressed);
        }
        
        free(compressed);
    } else {
        printf("Compression failed!\n");
    }

    return 0;
}
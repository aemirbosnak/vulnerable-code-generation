//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Run-Length Encoding compression
char* compressRLE(const char* input) {
    int n = strlen(input);
    if (n == 0) {
        return "";
    }

    // Allocate memory for the worst case scenario
    // Input can be up to 2 * n in the worst case (like "AAA...A" -> "A25")
    char* compressed = (char*)malloc(2 * n + 1);
    if (compressed == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int count = 1;
    int index = 0;

    for (int i = 1; i <= n; i++) {
        if (i < n && input[i] == input[i - 1]) {
            count++;
        } else {
            // Append current character and its count to the compressed string
            index += sprintf(compressed + index, "%c%d", input[i - 1], count);
            count = 1; // Reset count for the next character
        }
    }

    compressed[index] = '\0'; // Null-terminate the string
    return compressed;
}

// Function to decompress the RLE string
char* decompressRLE(const char* input) {
    int n = strlen(input);
    
    // Allocate memory for the decompressed result
    char* decompressed = (char*)malloc(n * 9); // Assuming each count is at most 9
    if (decompressed == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        char ch = input[i]; // Current character
        i++; // Move to the digit character
        int count = input[i] - '0'; // Convert char digit to integer
        
        // If there's more than one digit
        while (i + 1 < n && input[i + 1] >= '0' && input[i + 1] <= '9') {
            count = count * 10 + (input[i + 1] - '0');
            i++;
        }

        // Append the character 'count' times
        for (int j = 0; j < count; j++) {
            decompressed[index++] = ch;
        }
    }
    decompressed[index] = '\0'; // Null-terminate the string
    return decompressed;
}

// Main function
int main() {
    char input[100];
    
    printf("Enter a string to compress: ");
    scanf("%s", input);

    char* compressed = compressRLE(input);
    printf("Compressed: %s\n", compressed);

    char* decompressed = decompressRLE(compressed);
    printf("Decompressed: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}
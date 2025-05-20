//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the given string
char* compress_string(char* str) {
    int n = strlen(str);
    char *compressed_str = (char*)malloc(sizeof(char) * n); // Initialize a new string

    int count = 1, index = 0;
    for (int i = 0; i < n; i++) {
        // If current character is same as the next character, increment count
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            compressed_str[index++] = str[i]; // Add the current character to the compressed string
            char count_string[10]; // Initialize a new string to store the count
            sprintf(count_string, "%d", count); // Convert the count to string
            strcat(compressed_str, count_string); // Add the count to the compressed string
            count = 1; // Reset the count
        }
    }

    return compressed_str;
}

// Function to decompress the given string
char* decompress_string(char* str) {
    int n = strlen(str);
    char *decompressed_str = (char*)malloc(sizeof(char) * n); // Initialize a new string

    int index = 0, count = 0;
    for (int i = 0; i < n; i++) {
        // If current character is a digit, add it to the count
        if (isdigit(str[i])) {
            count = count * 10 + (str[i] - '0');
        } else {
            // Add the current character to the decompressed string count number of times
            for (int j = 0; j < count; j++) {
                decompressed_str[index++] = str[i];
            }
            count = 0; // Reset the count
        }
    }

    return decompressed_str;
}

int main() {
    char original_str[] = "abbccccd";
    printf("Original string: %s\n", original_str);

    char *compressed_str = compress_string(original_str);
    printf("Compressed string: %s\n", compressed_str);

    char *decompressed_str = decompress_string(compressed_str);
    printf("Decompressed string: %s\n", decompressed_str);

    free(compressed_str);
    free(decompressed_str);
    return 0;
}
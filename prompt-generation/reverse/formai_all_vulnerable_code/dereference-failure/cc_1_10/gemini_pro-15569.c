//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the compressed data
typedef struct {
    char character;
    int count;
} CompressedData;

// Function to compress a string
char *compress(char *str) {
    int len = strlen(str);
    // Allocate memory for the compressed data
    CompressedData *data = malloc(sizeof(CompressedData) * len);
    // Initialize the compressed data
    int index = 0;
    data[0].character = str[0];
    data[0].count = 1;
    for (int i = 1; i < len; i++) {
        if (str[i] == data[index].character) {
            data[index].count++;
        } else {
            index++;
            data[index].character = str[i];
            data[index].count = 1;
        }
    }
    // Allocate memory for the compressed string
    int compressed_len = 0;
    for (int i = 0; i <= index; i++) {
        compressed_len += 1 + snprintf(NULL, 0, "%d", data[i].count);
    }
    char *compressed_str = malloc(compressed_len + 1);
    // Compress the string
    int pos = 0;
    for (int i = 0; i <= index; i++) {
        pos += snprintf(compressed_str + pos, compressed_len - pos, "%c%d", data[i].character, data[i].count);
    }
    // Free the memory allocated for the compressed data
    free(data);
    // Return the compressed string
    return compressed_str;
}

// Function to decompress a string
char *decompress(char *str) {
    int len = strlen(str);
    // Allocate memory for the decompressed data
    char *decompressed_str = malloc(len * 2 + 1);
    // Decompress the string
    int pos = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count = count * 10 + str[i] - '0';
        } else {
            for (int j = 0; j < count; j++) {
                decompressed_str[pos++] = str[i];
            }
            count = 0;
        }
    }
    // Add the null terminator
    decompressed_str[pos] = '\0';
    // Return the decompressed string
    return decompressed_str;
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string to compress: ");
    scanf("%s", str);
    // Compress the string
    char *compressed_str = compress(str);
    // Print the compressed string
    printf("Compressed string: %s\n", compressed_str);
    // Decompress the string
    char *decompressed_str = decompress(compressed_str);
    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_str);
    // Free the memory allocated for the compressed and decompressed strings
    free(compressed_str);
    free(decompressed_str);
    return 0;
}
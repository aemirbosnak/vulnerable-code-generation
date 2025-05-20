//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define BUFFER_SIZE 64

// Structure to store the compression data
typedef struct {
    char *buffer;
    int length;
} compression_data_t;

// Function to compress the data
compression_data_t *compress(const char *input) {
    compression_data_t *data = (compression_data_t *)malloc(sizeof(compression_data_t));
    int i, j, k;
    char *buffer = data->buffer;
    int length = 0;

    // Step 1: Convert the input string to uppercase
    for (i = 0; input[i] != '\0'; i++) {
        buffer[length++] = toupper(input[i]);
    }

    // Step 2: Remove consecutive duplicates
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (buffer[i] == buffer[j]) {
                // Remove the duplicate
                buffer[j] = '\0';
                length--;
                break;
            }
        }
    }

    // Step 3: Compress the remaining characters using a sliding window of size 3
    for (i = 0; i < length - 2; i++) {
        k = i + 2;
        while (k < length && buffer[i] == buffer[k]) {
            k++;
        }
        buffer[i] = buffer[k];
    }

    data->length = length;
    return data;
}

// Function to decompress the data
void decompress(compression_data_t *data) {
    char *buffer = data->buffer;
    int length = data->length;
    int i, j;

    // Step 1: Reverse the order of the characters in the compressed string
    for (i = 0; i < length / 2; i++) {
        j = length - i - 1;
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    // Step 2: Convert the reversed string to lowercase
    for (i = 0; i < length; i++) {
        buffer[i] = tolower(buffer[i]);
    }
}

int main() {
    char input[] = "The quick brown fox jumps over the lazy dog";
    compression_data_t *compressed = compress(input);
    printf("Compressed string: %s\n", compressed->buffer);
    decompress(compressed);
    printf("Original string: %s\n", input);
    free(compressed);
    return 0;
}
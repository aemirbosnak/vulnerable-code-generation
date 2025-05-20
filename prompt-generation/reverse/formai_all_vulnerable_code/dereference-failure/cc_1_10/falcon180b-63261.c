//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to compress the string using run-length encoding
char* compress(char* input) {
    int i = 0, j = 0, count = 1;
    char* output = (char*)malloc(MAX_LENGTH * sizeof(char));

    while (input[i]!= '\0') {
        if (input[i] == input[i+1]) {
            count++;
        } else {
            sprintf(&output[j], "%c%d", input[i], count);
            j += strlen(&output[j]);
            count = 1;
        }
        i++;
    }

    sprintf(&output[j], "%c%d", input[i-1], count);
    j += strlen(&output[j]);

    output[j] = '\0';

    return output;
}

// Function to decompress the compressed string
char* decompress(char* input) {
    int i = 0, j = 0, count = 0;
    char* output = (char*)malloc(MAX_LENGTH * sizeof(char));

    while (input[i]!= '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            count = input[i] - '0';
        } else {
            while (count-- > 0) {
                output[j++] = input[i];
            }
        }
        i++;
    }

    output[j] = '\0';

    return output;
}

int main() {
    char* input = "aaabbbbbcc";
    char* compressed = compress(input);
    char* decompressed = decompress(compressed);

    printf("Input string: %s\n", input);
    printf("Compressed string: %s\n", compressed);
    printf("Decompressed string: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}
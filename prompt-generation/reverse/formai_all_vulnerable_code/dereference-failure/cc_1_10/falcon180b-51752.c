//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

// Function to compress a string using run-length encoding
char* compress(char* input) {
    int i = 0;
    int j = 0;
    int count = 1;
    char* output = malloc(MAX_STRING_LENGTH);

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

// Function to decompress a string compressed using run-length encoding
char* decompress(char* input) {
    int i = 0;
    int j = 0;
    char* output = malloc(MAX_STRING_LENGTH);

    while (input[i]!= '\0') {
        if (input[i] >= 'a' && input[i] <= 'z') {
            sprintf(&output[j], "%c", input[i]);
            j++;
        } else {
            int count = input[i] - '0';
            i++;
            while (count > 0 && input[i] >= 'a' && input[i] <= 'z') {
                sprintf(&output[j], "%c", input[i]);
                j++;
                count--;
            }
            i++;
        }
    }

    output[j] = '\0';

    return output;
}

int main() {
    char* input = "aaabbbbbcc";
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);

    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}
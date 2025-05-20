//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using run-length encoding
char* compress(char* input) {
    int i, j, count = 1;
    char* output = (char*) malloc(strlen(input) + 1);
    strcpy(output, input);

    for (i = 0; i < strlen(output) - 1; i++) {
        if (output[i] == output[i+1]) {
            count++;
        } else {
            sprintf(&output[i], "%d%c", count, output[i]);
            count = 1;
        }
    }

    sprintf(&output[strlen(output) - 1], "%d%c", count, output[strlen(output) - 1]);

    return output;
}

// Function to decompress the compressed string back to its original form
char* decompress(char* input) {
    int i, j, count = 0;
    char* output = (char*) malloc(strlen(input) + 1);
    output[0] = '\0';

    for (i = 0; input[i]!= '\0'; i++) {
        if (isdigit(input[i])) {
            count = input[i] - '0';
        } else {
            strcat(output, &input[i]);
        }
    }

    for (i = 0; i < count; i++) {
        strcat(output, &output[i]);
    }

    return output;
}

int main() {
    char* input = "aaabbbbbcc";
    char* compressed = compress(input);
    char* decompressed = decompress(compressed);

    printf("Input: %s\n", input);
    printf("Compressed: %s\n", compressed);
    printf("Decompressed: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}
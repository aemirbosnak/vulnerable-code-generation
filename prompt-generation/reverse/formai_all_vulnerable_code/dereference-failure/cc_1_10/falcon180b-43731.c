//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000000

// function to compress the input string
char* compress(char* input) {
    int i, j;
    char* output = (char*) malloc(MAX_SIZE);
    output[0] = '\0';
    i = 0;
    while (input[i]!= '\0') {
        j = 0;
        while (i + j < strlen(input) && input[i] == input[i + j]) {
            j++;
        }
        if (j > 1) {
            sprintf(output + strlen(output), "%d%c", j, input[i]);
        } else {
            strcat(output, input[i]);
        }
        i += j;
    }
    return output;
}

// function to decompress the compressed string
char* decompress(char* input) {
    int i, j;
    char* output = (char*) malloc(MAX_SIZE);
    output[0] = '\0';
    i = 0;
    while (input[i]!= '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            j = input[i] - '0';
            strncat(output, input + i + 1, j);
            i += 1 + j;
        } else {
            strcat(output, input[i]);
            i++;
        }
    }
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
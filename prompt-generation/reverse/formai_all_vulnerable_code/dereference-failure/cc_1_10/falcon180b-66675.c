//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
char* compress(char* input) {
    int len = strlen(input);
    int j = 0;
    char* output = (char*)malloc(len*sizeof(char));

    for (int i = 0; i < len; i++) {
        if (i == 0 || input[i]!= input[i-1]) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    return output;
}

// Function to decompress the input string
char* decompress(char* input) {
    int len = strlen(input);
    int j = 0;
    char* output = (char*)malloc(len*sizeof(char));

    for (int i = 0; i < len; i++) {
        if (input[i]!= '\0') {
            while (input[i] == input[i+1]) {
                i++;
            }
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    return output;
}

int main() {
    char* input = "aaabbbbbcccc";
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);

    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}
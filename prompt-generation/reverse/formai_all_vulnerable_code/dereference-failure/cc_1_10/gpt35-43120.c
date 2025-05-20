//FormAI DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* compress(char* input) {
    char* output = (char*) malloc(sizeof(char) * MAX_SIZE);
    output[0] = input[0];
    int count = 1;
    for (int i = 1; i < strlen(input); i++) {
        if (input[i] == input[i-1]) {
            count++;
        } else {
            output[strlen(output)] = count + '0';
            count = 1;
            output[strlen(output)] = input[i];
        }
    }
    output[strlen(output)] = count + '0';
    output[strlen(output)] = '\0';
    return output;
}

char* decompress(char* input) {
    char* output = (char*) malloc(sizeof(char) * MAX_SIZE);
    int count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            count = count * 10 + (int)(input[i] - '0');
        } else {
            for (int j = 0; j < count; j++) {
                output[strlen(output)] = input[i];
            }
            count = 0;
        }
    }
    output[strlen(output)] = '\0';
    return output;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter text to compress: ");
    scanf("%[^\n]%*c", input);
    printf("Original input: %s\n", input);
    char* compressed = compress(input);
    printf("Compressed data: %s\n", compressed);
    char* decompressed = decompress(compressed);
    printf("Decompressed data: %s\n", decompressed);
    free(compressed);
    free(decompressed);
    return 0;
}
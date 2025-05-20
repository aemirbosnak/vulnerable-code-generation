//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function to compress the input string
char *compress(char *input) {
    int input_size = strlen(input);
    char *compressed = malloc(input_size + 1);

    int i, j, count;
    j = 0;
    for (i = 0; i < input_size; i++) {
        count = 1;
        while (i + 1 < input_size && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        compressed[j++] = input[i];
        if (count > 1) {
            compressed[j++] = (char) (count + '0');
        }
    }

    compressed[j] = '\0';

    return compressed;
}

// Function to decompress the input string
char *decompress(char *input) {
    int input_size = strlen(input);
    int decompressed_size = 0;

    for (int i = 0; i < input_size; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            int count = input[i] - '0';
            decompressed_size += count;
        } else {
            decompressed_size++;
        }
    }

    char *decompressed = malloc(decompressed_size + 1);

    int j = 0;
    for (int i = 0; i < input_size; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            int count = input[i] - '0';
            while (count--) {
                decompressed[j++] = input[i - 1];
            }
        } else {
            decompressed[j++] = input[i];
        }
    }

    decompressed[j] = '\0';

    return decompressed;
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter the input string: ");
    scanf("%s", input);

    char *compressed = compress(input);
    printf("Compressed string: %s\n", compressed);

    char *decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}
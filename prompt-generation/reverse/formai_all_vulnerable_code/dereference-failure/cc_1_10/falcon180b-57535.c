//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000000

typedef struct {
    char input[MAX_LENGTH];
    int input_length;
    char output[MAX_LENGTH];
    int output_length;
} Compression;

Compression* create_compression() {
    Compression* compression = (Compression*)malloc(sizeof(Compression));
    compression->input_length = 0;
    compression->output_length = 0;
    return compression;
}

void destroy_compression(Compression* compression) {
    free(compression);
}

void compress(Compression* compression) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < compression->input_length) {
        if (j == MAX_LENGTH) {
            printf("Error: Output buffer is full.\n");
            exit(1);
        }
        if (compression->input[i] == compression->output[j]) {
            j++;
        } else {
            compression->output[j] = compression->input[i];
            j++;
            i++;
        }
    }
    compression->output_length = j;
}

void decompress(Compression* compression) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (j < compression->output_length) {
        if (i == MAX_LENGTH) {
            printf("Error: Input buffer is full.\n");
            exit(1);
        }
        if (compression->output[j] == compression->input[i]) {
            i++;
        } else {
            compression->input[i] = compression->output[j];
            i++;
            j++;
        }
    }
    compression->input_length = i;
}

int main() {
    Compression* compression = create_compression();
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int input_length;
    int output_length;

    printf("Enter input string: ");
    fgets(input, MAX_LENGTH, stdin);
    input_length = strlen(input);

    printf("Input string: %s\n", input);
    printf("Input length: %d\n", input_length);

    compress(compression);

    printf("Compressed string: %s\n", compression->output);
    printf("Compressed length: %d\n", compression->output_length);

    decompress(compression);

    printf("Decompressed string: %s\n", compression->input);
    printf("Decompressed length: %d\n", compression->input_length);

    destroy_compression(compression);

    return 0;
}
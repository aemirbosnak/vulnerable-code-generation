//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 256

typedef struct {
    unsigned char *data;
    size_t size;
} CompressedBlock;

CompressedBlock compress(const char *input) {
    CompressedBlock output;
    output.data = (unsigned char *)malloc(MAX_BLOCK_SIZE);
    output.size = 0;

    unsigned char currentChar;
    int count;

    for (size_t i = 0; i < strlen(input);) {
        currentChar = input[i];
        count = 0;

        while (i < strlen(input) && input[i] == currentChar) {
            count++;
            i++;
        }

        if (count > 255) {
            count = 255; // Limit the count to 255
        }

        output.data[output.size++] = currentChar;
        output.data[output.size++] = (unsigned char)count;
    }

    return output;
}

void decompress(const CompressedBlock *input, char *output) {
    size_t index = 0;
    for (size_t i = 0; i < input->size;) {
        unsigned char currentChar = input->data[i++];
        unsigned char count = input->data[i++];

        for (int j = 0; j < count; j++) {
            output[index++] = currentChar;
        }
    }
    output[index] = '\0'; // Null-terminate the output string
}

void freeCompressedBlock(CompressedBlock *block) {
    free(block->data);
}

int main() {
    char str[MAX_BLOCK_SIZE];
    printf("Enter a string to compress: ");
    fgets(str, MAX_BLOCK_SIZE, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    CompressedBlock compressed = compress(str);
    printf("Compressed Data: ");
    for (size_t i = 0; i < compressed.size; i++) {
        printf("%02X ", compressed.data[i]);
    }
    printf("\n");

    char decompressed[MAX_BLOCK_SIZE];
    decompress(&compressed, decompressed);
    printf("Decompressed Data: %s\n", decompressed);

    freeCompressedBlock(&compressed);
    
    return 0;
}
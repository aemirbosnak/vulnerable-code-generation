//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char data;
    int count;
} CompressionUnit;

void compress(unsigned char* input, int size, unsigned char* output) {
    CompressionUnit* compUnits = malloc(size * sizeof(CompressionUnit));
    int index = 0;
    int current = input[0];
    compUnits[index].data = current;
    compUnits[index].count = 1;

    for (int i = 1; i < size; i++) {
        if (input[i] == current) {
            compUnits[index].count++;
        } else {
            output[index++] = (unsigned char)current;
            output[index++] = (unsigned char)(compUnits[index - 1].count >> 1) | (compUnits[index - 1].count & 0x80 ? 0x80 : 0);
            current = input[i];
            compUnits[index].data = current;
            compUnits[index].count = 1;
        }
    }

    output[index++] = (unsigned char)current;
    output[index++] = (unsigned char)(compUnits[index - 1].count >> 1) | (compUnits[index - 1].count & 0x80 ? 0x80 : 0);

    free(compUnits);
}

void decompress(unsigned char* input, int size, unsigned char* output) {
    for (int i = 0; i < size; i += 2) {
        int count = input[i] & 0x7F;
        if (input[i] & 0x80) count |= (input[i + 1] << 8);
        for (int j = 0; j < count; j++) output[i / 2 + j] = input[i / 2 + j + 1];
    }
}

int main() {
    unsigned char input[] = { 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00 };
    unsigned char output[sizeof(input)];

    compress(input, sizeof(input), output);

    printf("Compressed size: %d\n", (int)(sizeof(output) - sizeof(input)));

    unsigned char decompressed[sizeof(input)];
    decompress(output, sizeof(output), decompressed);

    for (int i = 0; i < sizeof(input); i++) {
        if (input[i] != decompressed[i]) {
            printf("Error: input and decompressed arrays differ at index %d\n", i);
            return 1;
        }
    }

    printf("Decompression successful!\n");

    return 0;
}
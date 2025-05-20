//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 8
#define WATERMARK_VALUE 0x7F

void watermark(unsigned char* data, int size) {
    unsigned char watermark[WATERMARK_SIZE] = {WATERMARK_VALUE};
    int i, j;

    for (i = 0; i < size; i += WATERMARK_SIZE) {
        for (j = 0; j < WATERMARK_SIZE; j++) {
            data[i + j] ^= watermark[j];
        }
    }
}

int main(int argc, char* argv[]) {
    FILE* input_file;
    FILE* output_file;
    unsigned char* data;
    int size;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size = ftell(input_file);
    rewind(input_file);

    data = malloc(size);
    fread(data, 1, size, input_file);
    fclose(input_file);

    watermark(data, size);

    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        free(data);
        return 1;
    }

    fwrite(data, 1, size, output_file);
    fclose(output_file);

    free(data);
    return 0;
}
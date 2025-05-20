//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

typedef struct {
    unsigned char data;
    unsigned char count;
} rle_t;

void compress(unsigned char *input, unsigned char *output, size_t size) {
    size_t index = 0;
    rle_t *rle_buffer = malloc(BUF_SIZE * sizeof(rle_t));

    for (size_t i = 0; i < size; i++) {
        if (index > 0 && rle_buffer[index - 1].data == input[i]) {
            rle_buffer[index - 1].count++;
        } else {
            if (index > 0) {
                fwrite(rle_buffer, sizeof(rle_t), index, output);
            }
            rle_buffer[index++] = (rle_t){input[i], 1};
        }
    }

    if (index > 0) {
        fwrite(rle_buffer, sizeof(rle_t), index, output);
    }

    free(rle_buffer);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    fseek(input, 0, SEEK_END);
    size_t size = ftell(input);
    rewind(input);

    compress((unsigned char *)input, (unsigned char *)output, size);

    fclose(input);
    fclose(output);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char data;
    int count;
} RLE_Compressed_Data;

void compress(FILE *input, FILE *output) {
    unsigned char buffer[BUFFER_SIZE];
    int read_bytes = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input);
    RLE_Compressed_Data compressed_data;

    while (read_bytes > 0) {
        while (read_bytes > 0 && buffer[read_bytes - 1] == buffer[read_bytes - 2]) {
            read_bytes--;
            compressed_data.count++;
        }

        if (compressed_data.count > 0) {
            fwrite(&compressed_data.count, sizeof(int), 1, output);
            fwrite(&compressed_data.data, sizeof(unsigned char), 1, output);
            compressed_data.count = 0;
        }

        if (read_bytes > 0) {
            compressed_data.data = buffer[--read_bytes];
        }
    }

    if (compressed_data.count > 0) {
        fwrite(&compressed_data.count, sizeof(int), 1, output);
        fwrite(&compressed_data.data, sizeof(unsigned char), 1, output);
    }
}

void decompress(FILE *input, FILE *output) {
    int count;
    unsigned char data;

    while (fread(&count, sizeof(int), 1, input) > 0 && fread(&data, sizeof(unsigned char), 1, input) > 0) {
        fwrite(&data, sizeof(unsigned char), count, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        return 1;
    }

    compress(input, output);
    fclose(input);
    fclose(output);

    return 0;
}
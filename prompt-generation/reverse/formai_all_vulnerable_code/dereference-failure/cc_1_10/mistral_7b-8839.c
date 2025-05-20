//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUF_SIZE 1024
#define CHUNK_SIZE 512

typedef struct {
    uint8_t data[CHUNK_SIZE];
    uint32_t crc;
} chunk_t;

void crc32_init(uint32_t* crc) {
    *crc = 0xFFFFFFFF;
}

void crc32_update(uint32_t* crc, const uint8_t* data, size_t size) {
    const uint8_t* src = data;
    size_t remain = size;

    while (remain) {
        uint32_t bit;

        if (remain & 1)
            *crc ^= (*src++) << 24;

        *crc = *crc >> 8;

        remain -= 1;

        bit = *src++;
        *crc ^= bit << 24;

        *crc = *crc >> 8;
        *crc ^= bit << 16;

        *crc = *crc >> 8;
        *crc ^= bit << 8;

        *crc = *crc >> 8;
        *crc ^= bit;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* in = fopen(argv[1], "rb");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    FILE* out = fopen(argv[2], "wb");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return 1;
    }

    chunk_t chunk;
    size_t read_size;

    crc32_init(chunk.crc);

    while ((read_size = fread(chunk.data, sizeof(uint8_t), CHUNK_SIZE, in)) > 0) {
        crc32_update(chunk.crc, chunk.data, read_size);

        fwrite(chunk.data, sizeof(uint8_t), read_size, out);
    }

    fclose(in);
    fclose(out);

    printf("Recovery completed. Output file: %s\n", argv[2]);

    return 0;
}
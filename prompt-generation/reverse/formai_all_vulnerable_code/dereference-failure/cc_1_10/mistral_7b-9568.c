//MISTRAL-7B DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 64
#define WATERMARK_SIZE 32
#define SEED 1337
#define DELTA 5

typedef struct Watermark {
    uint8_t data[WATERMARK_SIZE];
} Watermark;

void watermark_image(FILE *image_file, Watermark *watermark) {
    uint8_t buffer[BLOCK_SIZE];
    uint32_t position = 0;
    uint32_t bytes_read = fread(buffer, 1, BLOCK_SIZE, image_file);

    while (bytes_read > 0) {
        for (uint32_t i = 0; i < WATERMARK_SIZE; i++) {
            watermark->data[i] ^= buffer[position++];
        }

        bytes_read = fread(buffer, 1, BLOCK_SIZE, image_file);
    }

    fseek(image_file, -WATERMARK_SIZE, SEEK_CUR);
    fwrite(watermark->data, 1, WATERMARK_SIZE, image_file);
}

Watermark generate_watermark(const char *text) {
    Watermark watermark;

    for (uint32_t i = 0; i < WATERMARK_SIZE; i++) {
        watermark.data[i] = text[i % strlen(text)] ^ (uint8_t) (i / strlen(text)) * DELTA;
    }

    srand(SEED);
    for (uint32_t i = 0; i < WATERMARK_SIZE; i++) {
        watermark.data[i] ^= rand() % 256;
    }

    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input.bin output.bin 'watermark text'\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    char *text = argv[2];
    Watermark watermark = generate_watermark(text);

    fclose(input_file);

    FILE *output_file = fopen(argv[3], "wb");
    if (!output_file) {
        perror("Error creating output file");
        return 1;
    }

    watermark_image(input_file, &watermark);
    fclose(input_file);

    fwrite(argv[2], strlen(argv[2]), 1, output_file);
    fwrite(watermark.data, WATERMARK_SIZE, 1, output_file);

    fclose(output_file);

    printf("Watermark applied to '%s' and saved as '%s'\n", argv[2], argv[3]);

    return 0;
}
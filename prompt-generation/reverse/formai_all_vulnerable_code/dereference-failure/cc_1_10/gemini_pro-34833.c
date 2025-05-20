//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint8_t bm;
    uint32_t size;
    uint32_t reserved;
    uint32_t offset;
} bmp_header;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_resolution;
    int32_t y_resolution;
    uint32_t palette_colors;
    uint32_t important_colors;
} dib_header;
#pragma pack(pop)

void set_bit(uint8_t *byte, int bit, int value) {
    if (value)
        *byte |= (1 << bit);
    else
        *byte &= ~(1 << bit);
}

int get_bit(uint8_t byte, int bit) {
    return (byte >> bit) & 1;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <message>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        perror("fopen");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        perror("fopen");
        return 1;
    }

    bmp_header header;
    fread(&header, sizeof(header), 1, input);
    fwrite(&header, sizeof(header), 1, output);

    dib_header dib;
    fread(&dib, sizeof(dib), 1, input);
    fwrite(&dib, sizeof(dib), 1, output);

    int bit_count = dib.bit_count;
    int bytes_per_pixel = bit_count / 8;
    int image_size = dib.image_size;

    uint8_t *image_data = malloc(image_size);
    fread(image_data, image_size, 1, input);

    int message_length = strlen(argv[3]);
    int bits_used = 0;

    for (int i = 0; i < image_size && bits_used < message_length * 8; i++) {
        for (int j = 0; j < bytes_per_pixel && bits_used < message_length * 8; j++) {
            uint8_t byte = image_data[i * bytes_per_pixel + j];
            int bit = bits_used % 8;
            set_bit(&byte, bit, get_bit(argv[3][bits_used / 8], bit));
            image_data[i * bytes_per_pixel + j] = byte;
            bits_used++;
        }
    }

    fwrite(image_data, image_size, 1, output);

    free(image_data);
    fclose(input);
    fclose(output);

    return 0;
}
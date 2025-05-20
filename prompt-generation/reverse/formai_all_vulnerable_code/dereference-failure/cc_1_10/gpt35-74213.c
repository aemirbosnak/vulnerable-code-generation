//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTES_PER_PIXEL 3

typedef struct{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

Pixel* compress_image(uint8_t* pixels, int width, int height, int* compressed_size) {
    Pixel* compressed_pixels = malloc(sizeof(Pixel) * width * height);
    int count = 0;

    uint8_t current_byte = 0;
    int bits_remaining = 8;

    for (int i = 0; i < width * height; i++) {
        Pixel pixel = { pixels[i*BYTES_PER_PIXEL], pixels[i*BYTES_PER_PIXEL+1], pixels[i*BYTES_PER_PIXEL+2] };
        if (pixel.red < 128 && pixel.green < 128 && pixel.blue < 128) {
            current_byte <<= 1;
        } else {
            current_byte = (current_byte << 1) | 0x01;
        }
        bits_remaining--;

        if (bits_remaining == 0) {
            compressed_pixels[count++] = (Pixel) { current_byte, current_byte, current_byte };
            bits_remaining = 8;
            current_byte = 0;
        }
    }

    if (bits_remaining != 8) {
        current_byte <<= bits_remaining;
        compressed_pixels[count++] = (Pixel) { current_byte, current_byte, current_byte };
    }

    *compressed_size = count;
    return compressed_pixels;
}

int main() {
    FILE* file = fopen("input.bmp", "rb");
    if (!file) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Read BMP header
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, file);

    int image_width = *(int*)&header[18];
    int image_height = *(int*)&header[22];
    int image_size = *(int*)&header[34];

    uint8_t* image_data = malloc(sizeof(uint8_t) * image_size);
    fread(image_data, sizeof(uint8_t), image_size, file);
    fclose(file);

    int compressed_size;
    Pixel* compressed_image = compress_image(image_data, image_width, image_height, &compressed_size);

    FILE* output = fopen("output.bmp", "wb");
    fwrite(header, sizeof(uint8_t), 54, output);
    fwrite(compressed_image, sizeof(Pixel), compressed_size, output);
    fclose(output);

    free(image_data);
    free(compressed_image);

    printf("Image compression successful!\n");
    return 0;
}
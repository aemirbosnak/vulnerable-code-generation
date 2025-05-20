//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BITSPERBYTE 8

typedef struct {
    uint8_t red, green, blue, alpha;
} pixel;

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Could not open input file");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Could not open output file");
        return 1;
    }

    // Read the input image header
    uint32_t width, height;
    fread(&width, sizeof(uint32_t), 1, input_file);
    fread(&height, sizeof(uint32_t), 1, input_file);

    // Read the input image data
    pixel* pixels = malloc(width * height * sizeof(pixel));
    fread(pixels, sizeof(pixel), width * height, input_file);
    fclose(input_file);

    // Encode the message in the image data
    int message_length = strlen(argv[3]);
    for (int i = 0; i < message_length; i++) {
        char byte = argv[3][i];
        for (int j = 0; j < BITSPERBYTE; j++) {
            int bit = (byte >> j) & 1;
            pixels[i * BITSPERBYTE + j].red = (pixels[i * BITSPERBYTE + j].red & ~1) | bit;
        }
    }

    // Write the output image header
    fwrite(&width, sizeof(uint32_t), 1, output_file);
    fwrite(&height, sizeof(uint32_t), 1, output_file);

    // Write the output image data
    fwrite(pixels, sizeof(pixel), width * height, output_file);
    fclose(output_file);

    free(pixels);

    return 0;
}
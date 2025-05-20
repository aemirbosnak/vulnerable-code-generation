//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} pixel_t;

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("fopen");
        return 1;
    }
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        fclose(input);
        perror("fopen");
        return 1;
    }

    // Read the input image header
    uint32_t width, height;
    fread(&width, sizeof(width), 1, input);
    fread(&height, sizeof(height), 1, input);

    // Allocate memory for the input image data
    pixel_t *input_data = malloc(sizeof(pixel_t) * width * height);
    if (input_data == NULL) {
        fclose(input);
        fclose(output);
        perror("malloc");
        return 1;
    }

    // Read the input image data
    fread(input_data, sizeof(pixel_t), width * height, input);
    fclose(input);

    // Encode the message into the input image data
    size_t message_length = strlen(argv[3]);
    for (size_t i = 0; i < message_length; i++) {
        uint8_t byte = argv[3][i];
        for (int j = 0; j < 8; j++) {
            uint8_t bit = (byte >> j) & 1;
            input_data[i * 8 + j].blue &= ~1;
            input_data[i * 8 + j].blue |= bit;
        }
    }

    // Write the output image header
    fwrite(&width, sizeof(width), 1, output);
    fwrite(&height, sizeof(height), 1, output);

    // Write the output image data
    fwrite(input_data, sizeof(pixel_t), width * height, output);
    fclose(output);

    free(input_data);

    return 0;
}
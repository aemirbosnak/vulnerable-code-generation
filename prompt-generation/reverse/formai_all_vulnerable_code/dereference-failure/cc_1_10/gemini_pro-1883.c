//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s image.bmp message.txt output.bmp\n", argv[0]);
        return 1;
    }

    FILE *image = fopen(argv[1], "rb");
    if (!image) {
        printf("Could not open image file.\n");
        return 1;
    }

    FILE *message = fopen(argv[2], "rb");
    if (!message) {
        printf("Could not open message file.\n");
        return 1;
    }

    FILE *output = fopen(argv[3], "wb");
    if (!output) {
        printf("Could not open output file.\n");
        return 1;
    }

    // Read the header of the image file.
    unsigned char header[54];
    fread(header, sizeof(header), 1, image);

    // Get the width and height of the image.
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixels of the image.
    pixel *pixels = malloc(width * height * sizeof(pixel));
    fread(pixels, sizeof(pixel), width * height, image);

    // Encode the message in the pixels of the image.
    int message_size = strlen(argv[2]);
    for (int i = 0; i < message_size; i++) {
        unsigned char c = argv[2][i];
        for (int j = 0; j < 8; j++) {
            int bit = (c >> j) & 1;
            if (bit) {
                pixels[i * 8 + j].r |= 1;
            }
            else {
                pixels[i * 8 + j].r &= ~1;
            }
        }
    }

    // Write the header of the output image file.
    fwrite(header, sizeof(header), 1, output);

    // Write the pixels of the output image.
    fwrite(pixels, sizeof(pixel), width * height, output);

    // Close the files.
    fclose(image);
    fclose(message);
    fclose(output);

    return 0;
}
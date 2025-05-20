//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} pixel;

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        printf("Error opening input image: %s\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        printf("Error opening output image: %s\n", argv[2]);
        fclose(input);
        return 1;
    }

    // Read the input image header
    unsigned char header[54];
    fread(header, 1, 54, input);
    fwrite(header, 1, 54, output);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the image data
    pixel **pixels = malloc(sizeof(pixel *) * height);
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(sizeof(pixel) * width);
        fread(pixels[i], sizeof(pixel), width, input);
    }

    // Encode the message in the image data
    int message_length = strlen(argv[3]);
    int message_index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (message_index < message_length) {
                // Encode the next character of the message in the least significant bit of the blue channel
                pixels[i][j].b = (pixels[i][j].b & ~1) | (argv[3][message_index] & 1);
                message_index++;
            }
        }
    }

    // Write the modified image data to the output file
    for (int i = 0; i < height; i++) {
        fwrite(pixels[i], sizeof(pixel), width, output);
        free(pixels[i]);
    }
    free(pixels);

    fclose(input);
    fclose(output);

    printf("Message successfully encoded in image '%s'\n", argv[2]);
    return 0;
}
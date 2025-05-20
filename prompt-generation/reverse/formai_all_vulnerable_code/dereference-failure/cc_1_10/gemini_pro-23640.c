//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pixel {
    unsigned char r, g, b, a;
} pixel;

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [input image] [output image] [secret message]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input image
    FILE *inputImage = fopen(argv[1], "rb");
    if (inputImage == NULL) {
        printf("Could not open input image.\n");
        return EXIT_FAILURE;
    }

    // Open the output image
    FILE *outputImage = fopen(argv[2], "wb");
    if (outputImage == NULL) {
        printf("Could not open output image.\n");
        return EXIT_FAILURE;
    }

    // Read the input image
    int width, height;
    fread(&width, sizeof(int), 1, inputImage);
    fread(&height, sizeof(int), 1, inputImage);
    pixel *pixels = malloc(width * height * sizeof(pixel));
    fread(pixels, sizeof(pixel), width * height, inputImage);

    // Get the secret message
    char *message = argv[3];

    // Embed the secret message in the image
    int messageIndex = 0;
    int pixelIndex = 0;
    while (message[messageIndex] != '\0') {
        int byte = message[messageIndex];
        for (int i = 0; i < 8; i++) {
            pixels[pixelIndex].b = (pixels[pixelIndex].b & 0xFE) | ((byte >> i) & 1);
            pixelIndex++;
        }
        messageIndex++;
    }

    // Write the output image
    fwrite(&width, sizeof(int), 1, outputImage);
    fwrite(&height, sizeof(int), 1, outputImage);
    fwrite(pixels, sizeof(pixel), width * height, outputImage);

    // Free memory
    free(pixels);

    // Close the files
    fclose(inputImage);
    fclose(outputImage);

    return EXIT_SUCCESS;
}
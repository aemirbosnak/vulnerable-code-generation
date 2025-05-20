//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

int main() {
    // Open the image file
    FILE *image = fopen("image.bmp", "rb");
    if (!image) {
        fprintf(stderr, "Error opening image file\n");
        return 1;
    }

    // Read the image header
    unsigned char header[54];
    if (fread(header, 54, 1, image) != 1) {
        fprintf(stderr, "Error reading image header\n");
        return 1;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the image data
    Pixel *data = malloc(sizeof(Pixel) * width * height);
    if (!data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        return 1;
    }
    if (fread(data, sizeof(Pixel), width * height, image) != width * height) {
        fprintf(stderr, "Error reading image data\n");
        return 1;
    }

    // Close the image file
    fclose(image);

    // Hide the message in the image data
    char *message = "This is a secret message";
    int messageLength = strlen(message);
    for (int i = 0; i < messageLength; i++) {
        unsigned char c = message[i];

        // Embed the character in the least significant bits of the pixel data
        data[i].r &= 0xF8;
        data[i].r |= (c >> 5) & 0x07;
        data[i].g &= 0xFC;
        data[i].g |= (c >> 2) & 0x03;
        data[i].b &= 0xF8;
        data[i].b |= c & 0x07;
    }

    // Save the modified image data
    FILE *output = fopen("stego.bmp", "wb");
    if (!output) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }
    if (fwrite(header, 54, 1, output) != 1) {
        fprintf(stderr, "Error writing image header\n");
        return 1;
    }
    if (fwrite(data, sizeof(Pixel), width * height, output) != width * height) {
        fprintf(stderr, "Error writing image data\n");
        return 1;
    }

    // Close the output file
    fclose(output);

    // Free the memory allocated for the image data
    free(data);

    printf("Message hidden successfully!\n");

    return 0;
}
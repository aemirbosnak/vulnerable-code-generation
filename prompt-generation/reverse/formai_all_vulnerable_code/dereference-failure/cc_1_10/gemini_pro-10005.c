//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} RGBA;

int main() {
    // Declare an array to store the pixel data of the image
    RGBA pixels[512][512];

    // Open the image file
    FILE *fp = fopen("image.png", "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the header of the image file
    uint32_t header[13];
    fread(header, sizeof(uint32_t), 13, fp);

    // Check if the image file is a PNG file
    if (header[0] != 0x89504E47) {
        fprintf(stderr, "Error: Invalid PNG file\n");
        return EXIT_FAILURE;
    }

    // Read the pixel data of the image file
    fread(pixels, sizeof(RGBA), 512 * 512, fp);

    // Close the image file
    fclose(fp);

    // Read the text to embed in the image
    char *text = "Hello, world!";

    // Embed the text in the image
    int index = 0;
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            if (index < strlen(text)) {
                pixels[i][j].red = (pixels[i][j].red & 0xF0) | ((text[index] >> 4) & 0x0F);
                pixels[i][j].green = (pixels[i][j].green & 0xF0) | (text[index] & 0x0F);
                index++;
            }
        }
    }

    // Open the output image file
    fp = fopen("output.png", "wb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Write the header of the output image file
    fwrite(header, sizeof(uint32_t), 13, fp);

    // Write the pixel data of the output image file
    fwrite(pixels, sizeof(RGBA), 512 * 512, fp);

    // Close the output image file
    fclose(fp);

    // Print a success message
    printf("Text successfully embedded in image\n");

    return EXIT_SUCCESS;
}
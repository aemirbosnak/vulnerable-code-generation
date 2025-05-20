//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Open the image file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return EXIT_FAILURE;
    }

    // Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(header), 1, image_file);

    // Get the image dimensions
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Create an array to store the pixel data
    pixel *pixels = malloc(width * height * sizeof(pixel));
    if (pixels == NULL) {
        fprintf(stderr, "Error allocating memory for pixels\n");
        fclose(image_file);
        return EXIT_FAILURE;
    }

    // Read the pixel data
    fread(pixels, sizeof(pixel), width * height, image_file);
    fclose(image_file);

    // Open the text file
    FILE *text_file = fopen("text.txt", "rb");
    if (text_file == NULL) {
        fprintf(stderr, "Error opening text file\n");
        free(pixels);
        return EXIT_FAILURE;
    }

    // Get the text file size
    fseek(text_file, 0, SEEK_END);
    unsigned int text_size = ftell(text_file);
    fseek(text_file, 0, SEEK_SET);

    // Create an array to store the text data
    char *text = malloc(text_size + 1);
    if (text == NULL) {
        fprintf(stderr, "Error allocating memory for text\n");
        fclose(text_file);
        free(pixels);
        return EXIT_FAILURE;
    }

    // Read the text data
    fread(text, 1, text_size, text_file);
    fclose(text_file);
    text[text_size] = '\0';

    // Embed the text data in the image data
    unsigned int text_index = 0;
    for (unsigned int i = 0; i < width * height; i++) {
        // Get the pixel
        pixel *pixel = &pixels[i];

        // Embed the text character in the least significant bit of each color channel
        pixel->red &= 0xFE;
        pixel->red |= (text[text_index] >> 6) & 0x01;
        pixel->green &= 0xFE;
        pixel->green |= (text[text_index] >> 4) & 0x01;
        pixel->blue &= 0xFE;
        pixel->blue |= (text[text_index] >> 2) & 0x01;

        // Increment the text index
        text_index++;

        // If we have reached the end of the text, stop embedding
        if (text_index == text_size) {
            break;
        }
    }

    // Open the output image file
    FILE *output_image_file = fopen("output.bmp", "wb");
    if (output_image_file == NULL) {
        fprintf(stderr, "Error opening output image file\n");
        free(pixels);
        free(text);
        return EXIT_FAILURE;
    }

    // Write the BMP header
    fwrite(header, sizeof(header), 1, output_image_file);

    // Write the pixel data
    fwrite(pixels, sizeof(pixel), width * height, output_image_file);
    fclose(output_image_file);

    // Free the allocated memory
    free(pixels);
    free(text);

    return EXIT_SUCCESS;
}
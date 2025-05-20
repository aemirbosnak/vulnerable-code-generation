//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WATERMARK_SIZE 32

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    // Open the input image
    FILE* input_image = fopen(argv[1], "rb");
    if (input_image == NULL) {
        perror("Error opening input image");
        return 1;
    }

    // Determine the size of the input image
    fseek(input_image, 0, SEEK_END);
    int input_image_size = ftell(input_image);
    rewind(input_image);

    // Read the input image into a buffer
    unsigned char* input_image_buffer = (unsigned char*)malloc(input_image_size);
    fread(input_image_buffer, 1, input_image_size, input_image);
    fclose(input_image);

    // Extract the header information from the input image
    int width = *(int*)&input_image_buffer[0];
    int height = *(int*)&input_image_buffer[4];

    // Extract the pixel data from the input image
    pixel* pixels = (pixel*)&input_image_buffer[8];

    // Generate the watermark
    unsigned char watermark[WATERMARK_SIZE];
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = rand() % 256;
    }

    // Embed the watermark in the input image
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = (pixels[i].red & 0xF0) | (watermark[i % WATERMARK_SIZE] >> 4);
        pixels[i].green = (pixels[i].green & 0xF0) | (watermark[i % WATERMARK_SIZE] & 0x0F);
        pixels[i].blue = (pixels[i].blue & 0xF0) | ((watermark[(i + 1) % WATERMARK_SIZE] >> 4) & 0x0F);
    }

    // Create the output image
    FILE* output_image = fopen(argv[2], "wb");
    if (output_image == NULL) {
        perror("Error opening output image");
        return 1;
    }

    // Write the header information to the output image
    fwrite(&width, sizeof(int), 1, output_image);
    fwrite(&height, sizeof(int), 1, output_image);

    // Write the pixel data to the output image
    fwrite(pixels, sizeof(pixel), width * height, output_image);
    fclose(output_image);

    // Free the input image buffer
    free(input_image_buffer);

    return 0;
}
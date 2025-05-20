//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *image_in, *image_out;
    char buf[10000];
    unsigned char pixel_data[3];
    int width, height;

    // Open input and output images
    image_in = fopen(argv[1], "rb");
    if (image_in == NULL) {
        printf("Error opening input image\n");
        return 1;
    }
    image_out = fopen(argv[2], "wb");
    if (image_out == NULL) {
        printf("Error opening output image\n");
        fclose(image_in);
        return 1;
    }

    // Read image dimensions
    fread(&width, sizeof(int), 1, image_in);
    fread(&height, sizeof(int), 1, image_in);
    printf("Input image dimensions: %dx%d\n", width, height);

    // Read image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Read 3 bytes of pixel data
            fread(pixel_data, sizeof(pixel_data), 1, image_in);

            // Get RGB values
            int red = pixel_data[0];
            int green = pixel_data[1];
            int blue = pixel_data[2];

            // Modify RGB values
            if (red == 255) {
                red -= 1;
            } else {
                red += 1;
            }
            if (green == 255) {
                green -= 1;
            } else {
                green += 1;
            }
            if (blue == 255) {
                blue -= 1;
            } else {
                blue += 1;
            }

            // Write modified RGB values
            pixel_data[0] = red;
            pixel_data[1] = green;
            pixel_data[2] = blue;

            // Write pixel data to output image
            fwrite(pixel_data, sizeof(pixel_data), 1, image_out);
        }
    }

    // Close files
    fclose(image_in);
    fclose(image_out);

    return 0;
}
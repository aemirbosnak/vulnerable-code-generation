//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

int main(void) {
    char *input_file = "input_image.raw";
    char *output_file = "output_image.raw";
    int width = 640;
    int height = 480;
    unsigned char *image_data = malloc(width * height * sizeof(unsigned char));
    unsigned char *output_data = malloc(width * height * sizeof(unsigned char));
    FILE *f;

    /* Read image data from file */
    f = fopen(input_file, "rb");
    fread(image_data, sizeof(unsigned char), width * height, f);
    fclose(f);

    /* Flip image horizontally */
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            output_data[i * width + j] = image_data[i * width + (width - j - 1)];
        }
    }

    /* Adjust brightness and contrast of image */
    float brightness = -50.0;
    float contrast = 1.5;
    int pixel_value;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixel_value = output_data[i * width + j];
            pixel_value += brightness;
            pixel_value = (pixel_value - MAX_PIXEL_VALUE / 2) * contrast + MAX_PIXEL_VALUE / 2;
            if(pixel_value > MAX_PIXEL_VALUE) {
                pixel_value = MAX_PIXEL_VALUE;
            } else if(pixel_value < 0) {
                pixel_value = 0;
            }
            output_data[i * width + j] = (unsigned char)pixel_value;
        }
    }

    /* Write output image data to file */
    f = fopen(output_file, "wb");
    fwrite(output_data, sizeof(unsigned char), width * height, f);
    fclose(f);

    free(image_data);
    free(output_data);

    return 0;
}
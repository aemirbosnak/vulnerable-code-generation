//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

void flip(char *input, char *output, int width, int height) {
    FILE *input_file = fopen(input, "rb");
    FILE *output_file = fopen(output, "wb");

    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char) * width * height);

    fread(image, 1, width * height, input_file); //Reading from input file

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fwrite(&image[(i * width) + (width - 1 - j)], 1, sizeof(unsigned char), output_file); //Flipping the image
        }
    }

    fclose(input_file);
    fclose(output_file);
    free(image);
}

void adjust_brightness_contrast(char *input, char *output, int width, int height, int brightness, int contrast) {
    FILE *input_file = fopen(input, "rb");
    FILE *output_file = fopen(output, "wb");

    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char) * width * height);

    fread(image, 1, width * height, input_file); //Reading from input file

    float contrast_factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast)); //Formula for adjusting contrast
    float brightness_factor = (float)brightness / 255.0; //Formula for adjusting brightness

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int index = (i * width) + j;

            int adjusted_value = (int)(contrast_factor * (image[index] - 128) + 128 + (255.0 * brightness_factor));

            if(adjusted_value < 0) {
                adjusted_value = 0;
            } else if(adjusted_value > 255) {
                adjusted_value = 255;
            }

            fwrite(&adjusted_value, 1, sizeof(unsigned char), output_file); //Adjusting the brightness and contrast
        }
    }

    fclose(input_file);
    fclose(output_file);
    free(image);
}

int main() {
    flip("input_image.raw", "flipped_output_image.raw", 256, 256); //Flipping the image

    adjust_brightness_contrast("input_image.raw", "adjusted_brightness_contrast_output_image.raw", 256, 256, 50, 100); //Adjusting brightness and contrast

    return 0;
}
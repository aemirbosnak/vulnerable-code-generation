//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

#define BUFFER_SIZE 1024
#define MAX_PIXEL_VALUE 255

typedef struct Image {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Image;

int main(int argc, char *argv[]) {

    if(argc != 4) {
        printf("Usage: %s IN_FILENAME OUT_FILENAME FILTER\n", argv[0]);
        printf("Filters: invert, grayscale, sepia, blur\n");
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Failed to open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Failed to create file '%s'\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    Image *image = (Image *)malloc(sizeof(Image));
    if(image == NULL) {
        printf("Failed to allocate memory for image\n");
        exit(EXIT_FAILURE);
    }

    char *filter = argv[3];

    uint32_t width;
    uint32_t height;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    uint32_t x_resolution;
    uint32_t y_resolution;
    uint32_t num_colors;
    uint32_t important_colors;

    fread(&width, sizeof(width), 1, input_file);
    fread(&height, sizeof(height), 1, input_file);
    fread(&bits_per_pixel, sizeof(bits_per_pixel), 1, input_file);
    fseek(input_file, 2, SEEK_CUR);
    fread(&compression, sizeof(compression), 1, input_file);
    fread(&image_size, sizeof(image_size), 1, input_file);
    fread(&x_resolution, sizeof(x_resolution), 1, input_file);
    fread(&y_resolution, sizeof(y_resolution), 1, input_file);
    fread(&num_colors, sizeof(num_colors), 1, input_file);
    fread(&important_colors, sizeof(important_colors), 1, input_file);

    int padding = (4 - ((width * (bits_per_pixel / 8)) % 4)) % 4;

    fwrite(&width, sizeof(width), 1, output_file);
    fwrite(&height, sizeof(height), 1, output_file);
    fwrite(&bits_per_pixel, sizeof(bits_per_pixel), 1, output_file);
    fseek(output_file, 2, SEEK_CUR);
    fwrite(&compression, sizeof(compression), 1, output_file);
    fwrite(&image_size, sizeof(image_size), 1, output_file);
    fwrite(&x_resolution, sizeof(x_resolution), 1, output_file);
    fwrite(&y_resolution, sizeof(y_resolution), 1, output_file);
    fwrite(&num_colors, sizeof(num_colors), 1, output_file);
    fwrite(&important_colors, sizeof(important_colors), 1, output_file);

    if(strcmp(filter, "invert") == 0) {
        for(uint32_t i = 0; i < height; i++) {
            for(uint32_t j = 0; j < width; j++) {
                fread(image, sizeof(Image), 1, input_file);
                image->red = MAX_PIXEL_VALUE - image->red;
                image->green = MAX_PIXEL_VALUE - image->green;
                image->blue = MAX_PIXEL_VALUE - image->blue;
                fwrite(image, sizeof(Image), 1, output_file);
            }
            fseek(input_file, padding, SEEK_CUR);
            for(int k = 0; k < padding; k++) {
                fputc(0, output_file);
            }
        }
    } else if(strcmp(filter, "grayscale") == 0) {
        for(uint32_t i = 0; i < height; i++) {
            for(uint32_t j = 0; j < width; j++) {
                fread(image, sizeof(Image), 1, input_file);
                uint8_t gray_value = (uint8_t)(0.3 * image->red + 0.59 * image->green + 0.11 * image->blue);
                image->red = gray_value;
                image->green = gray_value;
                image->blue = gray_value;
                fwrite(image, sizeof(Image), 1, output_file);
            }
            fseek(input_file, padding, SEEK_CUR);
            for(int k = 0; k < padding; k++) {
                fputc(0, output_file);
            }
        }
    } else if(strcmp(filter, "sepia") == 0) {
        for(uint32_t i = 0; i < height; i++) {
            for(uint32_t j = 0; j < width; j++) {
                fread(image, sizeof(Image), 1, input_file);
                uint8_t old_red = image->red;
                uint8_t old_green = image->green;
                uint8_t old_blue = image->blue;
                image->red = (uint8_t)fmin(1.0 * (0.393 * old_red + 0.769 * old_green + 0.189 * old_blue), MAX_PIXEL_VALUE);
                image->green = (uint8_t)fmin(1.0 * (0.349 * old_red + 0.686 * old_green + 0.168 * old_blue), MAX_PIXEL_VALUE);
                image->blue = (uint8_t)fmin(1.0 * (0.272 * old_red + 0.534 * old_green + 0.131 * old_blue), MAX_PIXEL_VALUE);
                fwrite(image, sizeof(Image), 1, output_file);
            }
            fseek(input_file, padding, SEEK_CUR);
            for(int k = 0; k < padding; k++) {
                fputc(0, output_file);
            }
        }
    } else if(strcmp(filter, "blur") == 0) {
        for(uint32_t i = 0; i < height; i++) {
            for(uint32_t j = 0; j < width; j++) {
                uint32_t num_pixels = 0;
                uint32_t sum_red = 0;
                uint32_t sum_green = 0;
                uint32_t sum_blue = 0;
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        if(i + k < height && j + l < width) {
                            fseek(input_file, (i + k) * ((bits_per_pixel / 8) * width + padding) + (j + l) * sizeof(Image), SEEK_SET);
                            fread(image, sizeof(Image), 1, input_file);
                            num_pixels++;
                            sum_red += image->red;
                            sum_green += image->green;
                            sum_blue += image->blue;
                        }
                    }
                }
                image->red = (uint8_t)(sum_red / num_pixels);
                image->green = (uint8_t)(sum_green / num_pixels);
                image->blue = (uint8_t)(sum_blue / num_pixels);
                fseek(output_file, i * ((bits_per_pixel / 8) * width + padding) + j * sizeof(Image), SEEK_SET);
                fwrite(image, sizeof(Image), 1, output_file);
            }
        }
    } else {
        printf("Invalid filter\n");
        exit(EXIT_FAILURE);
    }

    fclose(input_file);
    fclose(output_file);
    free(image);

    return 0;
}
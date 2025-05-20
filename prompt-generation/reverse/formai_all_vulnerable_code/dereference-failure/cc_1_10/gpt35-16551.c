//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

void flip_image(pixel* image, int width, int height) {
    int row_size = width * sizeof(pixel);
    pixel* row_buffer = (pixel*)malloc(row_size);
    int i, j;
    for (i = 0; i < height / 2; i++) {
        int top_offset = i * width;
        int bottom_offset = (height - i - 1) * width;
        memcpy(row_buffer, &image[top_offset], row_size);
        memcpy(&image[top_offset], &image[bottom_offset], row_size);
        memcpy(&image[bottom_offset], row_buffer, row_size);
    }
    free(row_buffer);
}

void adjust_brightness(pixel* image, int width, int height, int brightness) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int offset = i * width + j;
            image[offset].red += brightness;
            image[offset].green += brightness;
            image[offset].blue += brightness;
        }
    }
}

void adjust_contrast(pixel* image, int width, int height, int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int offset = i * width + j;
            image[offset].red = 
                (unsigned char)(factor * (image[offset].red - 128) + 128);
            image[offset].green = 
                (unsigned char)(factor * (image[offset].green - 128) + 128);
            image[offset].blue = 
                (unsigned char)(factor * (image[offset].blue - 128) + 128);
        }
    }
}

void write_image_to_file(pixel* image, int width, int height, char* filename) {
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int offset = i * width + j;
            fwrite(&image[offset].red, 1, 1, fp);
            fwrite(&image[offset].green, 1, 1, fp);
            fwrite(&image[offset].blue, 1, 1, fp);
        }
    }
    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file> [output_file]\n", argv[0]);
        return 1;
    }
    char* input_filename = argv[1];
    char* output_filename = "out.ppm";
    if (argc > 2) {
        output_filename = argv[2];
    }
    FILE* fp = fopen(input_filename, "rb");
    char magic_number[3];
    fscanf(fp, "%s\n", magic_number);
    if (strcmp(magic_number, "P6") != 0) {
        printf("Error: input file is not in P6 format\n");
        return 1;
    }
    int width, height, maxval;
    fscanf(fp, "%d %d\n%d\n", &width, &height, &maxval);
    pixel* image = (pixel*)malloc(width * height * sizeof(pixel));
    fread(image, sizeof(pixel), width * height, fp);
    fclose(fp);
    flip_image(image, width, height);
    adjust_brightness(image, width, height, 50);
    adjust_contrast(image, width, height, 50);
    write_image_to_file(image, width, height, output_filename);
    free(image);
    printf("Image processing complete, output written to %s\n", output_filename);
    return 0;
}
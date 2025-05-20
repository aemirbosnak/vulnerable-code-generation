//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define PIXEL_SIZE 3

void flip_image(unsigned char* pixels, int width, int height) {
    unsigned char* temp_row = (unsigned char*) malloc(PIXEL_SIZE * width);
    int row_size = PIXEL_SIZE * width;
    for (int i = 0; i < height/2; i++) {
        int idx1 = i * row_size;
        int idx2 = (height - 1 - i) * row_size;
        memcpy(temp_row, pixels + idx1, row_size);
        memcpy(pixels + idx1, pixels + idx2, row_size);
        memcpy(pixels + idx2, temp_row, row_size);
    }
    free(temp_row);
}

void adjust_contrast(unsigned char* pixels, int n_pixels, float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for (int i = 0; i < n_pixels; i++) {
        int value = (int) ((((float) pixels[i]) - 128.0f) * factor + 128.0f);
        if (value < 0) value = 0;
        if (value > 255) value = 255;
        pixels[i] = value;
    }
}

void adjust_brightness(unsigned char* pixels, int n_pixels, int brightness) {
    for (int i = 0; i < n_pixels; i++) {
        int value = (int) pixels[i] + brightness;
        if (value < 0) value = 0;
        if (value > 255) value = 255;
        pixels[i] = value;
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s input_file output_file brightness\n", argv[0]);
        return 1;
    }
    int brightness = atoi(argv[3]);

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, input_file);
    int width = *(int*) (header + 18);
    int height = *(int*) (header + 22);
    int row_size = PIXEL_SIZE * width;
    int padding = (4 - (row_size % 4)) % 4;
    int n_pixels = row_size * height;

    unsigned char* pixels = (unsigned char*) malloc(n_pixels);
    fread(pixels, sizeof(unsigned char), n_pixels, input_file);
    fclose(input_file);

    flip_image(pixels, width, height);
    adjust_contrast(pixels, n_pixels, 50.0f);
    adjust_brightness(pixels, n_pixels, brightness);

    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, output_file);
    fwrite(pixels, sizeof(unsigned char), n_pixels, output_file);
    fclose(output_file);

    free(pixels);

    printf("Done!\n");

    return 0;
}
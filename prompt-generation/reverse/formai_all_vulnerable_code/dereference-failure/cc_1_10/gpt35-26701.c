//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


#define BMP_HEADER_SIZE 54
#define BYTES_PER_PIXEL 3

void flip_image(uint8_t *image_data, uint32_t width, uint32_t height){
    uint8_t temp[width * BYTES_PER_PIXEL];
    for (int i = 0; i < height/2; i++){
        uint8_t *top_pixel = image_data + i*width*BYTES_PER_PIXEL;
        uint8_t *bottom_pixel = image_data + (height-i-1)*width*BYTES_PER_PIXEL;
        memcpy(temp, top_pixel, width*BYTES_PER_PIXEL);
        memcpy(top_pixel, bottom_pixel, width*BYTES_PER_PIXEL);
        memcpy(bottom_pixel, temp, width*BYTES_PER_PIXEL);
    }
}

void adjust_brightness(uint8_t *image_data, uint32_t width, uint32_t height, uint8_t adjustment){
    uint32_t num_pixels = width * height;
    for (int i = 0; i < num_pixels; i++){
        uint8_t *pixel = image_data + i*BYTES_PER_PIXEL;
        pixel[0] = fmin(pixel[0] + adjustment, 255);
        pixel[1] = fmin(pixel[1] + adjustment, 255);
        pixel[2] = fmin(pixel[2] + adjustment, 255);
    }
}

void adjust_contrast(uint8_t *image_data, uint32_t width, uint32_t height, float adjustment){
    uint32_t num_pixels = width * height;
    float factor = (259 * (adjustment + 255)) / (255 * (259 - adjustment));
    for (int i = 0; i < num_pixels; i++){
        uint8_t *pixel = image_data + i*BYTES_PER_PIXEL;
        int r = pixel[0];
        int g = pixel[1];
        int b = pixel[2];

        r = fmin(fmax(round(factor * (r - 128) + 128), 0), 255);
        g = fmin(fmax(round(factor * (g - 128) + 128), 0), 255);
        b = fmin(fmax(round(factor * (b - 128) + 128), 0), 255);

        pixel[0] = r;
        pixel[1] = g;
        pixel[2] = b;
    }
}

int main(){
    FILE *input_file = fopen("input.bmp", "rb");   // read binary
    if (input_file == NULL){
        printf("Could not open input file\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END); // seek to end of file
    size_t input_size = ftell(input_file); // get current file pointer
    rewind(input_file); // seek back to beginning of file

    uint8_t *input_data = malloc(input_size);
    if (input_data == NULL){
        printf("Failed to allocate memory for input file\n");
        return 1;
    }

    if (fread(input_data, 1, input_size, input_file) != input_size){
        printf("Error reading input file\n");
        return 1;
    }

    fclose(input_file);

    uint32_t *width_ptr = (uint32_t*)(input_data + 18);
    uint32_t width = *width_ptr;
    uint32_t *height_ptr = (uint32_t*)(input_data + 22);
    uint32_t height = *height_ptr;

    flip_image(input_data + BMP_HEADER_SIZE, width, height);
    adjust_brightness(input_data + BMP_HEADER_SIZE, width, height, 50);
    adjust_contrast(input_data + BMP_HEADER_SIZE, width, height, 1.5);

    FILE *output_file = fopen("output.bmp", "wb");  // write binary
    if (output_file == NULL){
        printf("Could not open output file\n");
        return 1;
    }

    if (fwrite(input_data, 1, input_size, output_file) != input_size){
        printf("Error writing output file\n");
        return 1;
    }

    fclose(output_file);
    free(input_data);

    return 0;
}
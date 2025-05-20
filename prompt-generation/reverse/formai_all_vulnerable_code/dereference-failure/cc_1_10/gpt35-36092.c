//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// function to flip an image horizontally
void flip_image_horizontal(unsigned char *image_data, int image_width, int image_height, int bytes_per_pixel)
{
    unsigned char *row_buffer = (unsigned char*)malloc(image_width * bytes_per_pixel);
    int row_size = image_width * bytes_per_pixel;
    for (int y = 0; y < image_height / 2; ++y) {
        int top_offset = y * row_size;
        int bottom_offset = (image_height - y - 1) * row_size;
        memcpy(row_buffer, &image_data[top_offset], row_size);
        memcpy(&image_data[top_offset], &image_data[bottom_offset], row_size);
        memcpy(&image_data[bottom_offset], row_buffer, row_size);
    }
    free(row_buffer);
}

// function to adjust brightness/contrast of an image
void adjust_image_brightness_contrast(unsigned char *image_data, int image_size, int bytes_per_pixel, float brightness, float contrast)
{
    float pixel_value_factor = contrast / 255.0f;
    float pixel_value_bias = brightness / 255.0f;
    for (int i = 0; i < image_size; i += bytes_per_pixel) {
        for (int j = 0; j < bytes_per_pixel; ++j) {
            int pixel_value = (int)image_data[i + j];
            pixel_value = (int)(pixel_value * pixel_value_factor + 255.0f * pixel_value_bias);
            if (pixel_value < 0) pixel_value = 0;
            if (pixel_value > 255) pixel_value = 255;
            image_data[i + j] = (unsigned char)pixel_value;
        }
    }
}

int main()
{
    // load image data from file
    char *file_path = "image_data.bin";
    FILE *fp = fopen(file_path, "rb");
    if (!fp) {
        printf("Failed to open file %s\n", file_path);
        return -1;
    }
    int image_width = 320;
    int image_height = 240;
    int bytes_per_pixel = 3; // assuming 24-bit RGB image
    int image_size = image_width * image_height * bytes_per_pixel;
    unsigned char *image_data = (unsigned char*)malloc(image_size);
    fread(image_data, image_size, 1, fp);
    fclose(fp);

    // flip image horizontally
    flip_image_horizontal(image_data, image_width, image_height, bytes_per_pixel);

    // adjust image brightness/contrast
    float brightness = -50.0f;
    float contrast = 150.0f;
    adjust_image_brightness_contrast(image_data, image_size, bytes_per_pixel, brightness, contrast);

    // save the processed image data to file
    char *output_file_path = "processed_image_data.bin";
    FILE *output_fp = fopen(output_file_path, "wb");
    fwrite(image_data, image_size, 1, output_fp);
    fclose(output_fp);
    printf("Processed image saved to file %s\n", output_file_path);

    // free the memory
    free(image_data);

    return 0;
}
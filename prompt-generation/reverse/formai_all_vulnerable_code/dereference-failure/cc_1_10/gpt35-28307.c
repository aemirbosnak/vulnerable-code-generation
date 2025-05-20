//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip the image 
void flip_image(int height, int width, unsigned char *image){
    int stride = width * 3;
    unsigned char *temp = malloc(stride);
    for(int row = 0; row < height/2; row++){
        int swap_row = height - row - 1;
        unsigned char *row_start = image + row * stride;
        unsigned char *swap_row_start = image + swap_row * stride;
        memcpy(temp, row_start, stride);
        memcpy(row_start, swap_row_start, stride);
        memcpy(swap_row_start, temp, stride);
    }
    free(temp);
}

// Function to adjust brightness and contrast of the image
void adjust_brightness_contrast(int height, int width, unsigned char *image, float brightness, float contrast){
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int row = 0; row < height; row++){
        unsigned char *row_start = image + row * width * 3;
        for(int col = 0; col < width; col++){
            int blue = row_start[0];
            int green = row_start[1];
            int red = row_start[2];

            // Adjust brightness
            blue = (int) (blue * brightness);
            green = (int) (green * brightness);
            red = (int) (red * brightness);

            // Adjust contrast
            blue = (int) (factor * (blue - 128) + 128);
            green = (int) (factor * (green - 128) + 128);
            red = (int) (factor * (red - 128) + 128);

            // Clamp values between 0 and 255
            if(blue < 0) blue = 0;
            if(blue > 255) blue = 255;
            if(green < 0) green = 0;
            if(green > 255) green = 255;
            if(red < 0) red = 0;
            if(red > 255) red = 255;

            // Set new color values for pixel
            row_start[0] = blue;
            row_start[1] = green;
            row_start[2] = red;

            // Move to next pixel
            row_start += 3;
        }
    }
}

int main(){
    // Read image pixels from file
    FILE* file = fopen("example_image.bmp", "rb");
    if(file == NULL){
        printf("Error: Could not open image file");
        return 1;
    }

    // Read header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for image pixels
    int padding = (4 - (width * 3) % 4) % 4;
    int image_size = (width * 3 + padding) * height;
    unsigned char *image = malloc(image_size);

    // Read image pixels
    fread(image, sizeof(unsigned char), image_size, file);
    fclose(file);

    // Flip the image
    flip_image(height, width, image);

    // Adjust brightness and contrast
    adjust_brightness_contrast(height, width, image, 1.2, 80);

    // Save new image to file
    FILE* output_file = fopen("processed_image.bmp", "wb");
    if(output_file == NULL){
        printf("Error: Could not create output file");
        return 1;
    }
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(image, sizeof(unsigned char), image_size, output_file);
    fclose(output_file);

    // Free memory allocated for image
    free(image);

    return 0;
}
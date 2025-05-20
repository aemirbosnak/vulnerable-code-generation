//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//function to flip the image horizontally
void flip_horizontal(unsigned char* image_buffer, int width, int height, int bytes_per_pixel) {
    int i, j;
    unsigned char temp;
    for(i=0; i<height; i++) {
        for(j=0; j<width/2; j++) {
            temp = image_buffer[i*width*bytes_per_pixel + j*bytes_per_pixel];
            image_buffer[i*width*bytes_per_pixel + j*bytes_per_pixel] = image_buffer[i*width*bytes_per_pixel + (width-j-1)*bytes_per_pixel];
            image_buffer[i*width*bytes_per_pixel + (width-j-1)*bytes_per_pixel] = temp;
        }
    }
}

//function to change the brightness of the image
void change_brightness(unsigned char* image_buffer, int width, int height, int bytes_per_pixel, int brightness_level) {
    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width*bytes_per_pixel; j+=bytes_per_pixel) {
            int pixel_value = image_buffer[i*width*bytes_per_pixel + j];
            pixel_value += brightness_level;
            if(pixel_value < 0) {
                pixel_value = 0;
            }
            if(pixel_value > 255) {
                pixel_value = 255;
            }
            image_buffer[i*width*bytes_per_pixel + j] = (unsigned char) pixel_value;
        }
    }
}

//function to change the contrast of the image
void change_contrast(unsigned char* image_buffer, int width, int height, int bytes_per_pixel, float contrast_level) {
    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width*bytes_per_pixel; j+=bytes_per_pixel) {
            float pixel_value = (float) image_buffer[i*width*bytes_per_pixel + j];
            pixel_value = (pixel_value - 128) * contrast_level + 128;
            if(pixel_value < 0) {
                pixel_value = 0;
            }
            if(pixel_value > 255) {
                pixel_value = 255;
            }
            image_buffer[i*width*bytes_per_pixel + j] = (unsigned char) pixel_value;
        }
    }
}

int main() {
    char file_name[] = "example_image.raw";
    int width = 640;
    int height = 480;
    int bytes_per_pixel = 3;
    unsigned char* image_buffer = (unsigned char*) malloc(width*height*bytes_per_pixel*sizeof(unsigned char));
    FILE* file = fopen(file_name, "rb");
    fread(image_buffer, sizeof(unsigned char), width*height*bytes_per_pixel, file);
    fclose(file);

    //flip the image horizontally
    flip_horizontal(image_buffer, width, height, bytes_per_pixel);

    //change the brightness of the image
    int brightness_level = 50;
    change_brightness(image_buffer, width, height, bytes_per_pixel, brightness_level);

    //change the contrast of the image
    float contrast_level = 1.5;
    change_contrast(image_buffer, width, height, bytes_per_pixel, contrast_level);

    //save the modified image
    char output_file_name[] = "modified_image.raw";
    FILE* output_file = fopen(output_file_name, "wb");
    fwrite(image_buffer, sizeof(unsigned char), width*height*bytes_per_pixel, output_file);
    fclose(output_file);

    free(image_buffer);
    return 0;
}
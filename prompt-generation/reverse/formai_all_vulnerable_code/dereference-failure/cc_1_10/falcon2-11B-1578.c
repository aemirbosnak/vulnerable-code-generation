//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int channels;
    int data_size;
    int data_type;
    unsigned char* data;
} Image;

void flip_image(Image* image) {
    int width = image->width;
    int height = image->height;
    int channels = image->channels;
    int data_size = image->data_size;
    int data_type = image->data_type;
    unsigned char* data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char temp = data[x + (width * y) * data_size];
            data[x + (width * y) * data_size] = data[width - x - 1 + (width * y) * data_size];
            data[width - x - 1 + (width * y) * data_size] = temp;
        }
    }
}

void change_brightness_contrast(Image* image, float brightness, float contrast) {
    int width = image->width;
    int height = image->height;
    int channels = image->channels;
    int data_size = image->data_size;
    int data_type = image->data_type;
    unsigned char* data = image->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_value = data[x + (width * y) * data_size];
            int new_pixel_value = (int)(pixel_value * (1.0 + contrast));
            if (new_pixel_value > 255) {
                new_pixel_value = 255;
            }
            if (new_pixel_value < 0) {
                new_pixel_value = 0;
            }
            data[x + (width * y) * data_size] = (unsigned char)new_pixel_value;
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_value = data[x + (width * y) * data_size];
            int new_pixel_value = (int)(pixel_value * (1.0 + brightness));
            if (new_pixel_value > 255) {
                new_pixel_value = 255;
            }
            if (new_pixel_value < 0) {
                new_pixel_value = 0;
            }
            data[x + (width * y) * data_size] = (unsigned char)new_pixel_value;
        }
    }
}

int main() {
    Image image;
    image.width = 512;
    image.height = 512;
    image.channels = 3;
    image.data_size = image.width * image.height * image.channels;
    image.data_type = 1;
    image.data = (unsigned char*)malloc(image.data_size);

    // Load image data here

    // Flip the image
    flip_image(&image);

    // Change brightness and contrast
    float brightness = 1.2;
    float contrast = 0.8;
    change_brightness_contrast(&image, brightness, contrast);

    // Save the modified image here

    return 0;
}
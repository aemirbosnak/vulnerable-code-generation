//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define characters based on their brightness value
char ascii_chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

// function to convert an image to grayscale
void grayscale(unsigned char *image_data, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            float r = image_data[index];
            float g = image_data[index + 1];
            float b = image_data[index + 2];
            float gray = 0.299 * r + 0.587 * g + 0.114 * b;
            image_data[index] = gray;
            image_data[index + 1] = gray;
            image_data[index + 2] = gray;
        }
    }
}

// function to scale image down based on a given factor
void scale_down(unsigned char *image_data, int height, int width, int scale_factor) {
    int new_height = ceil(height / scale_factor);
    int new_width = ceil(width / scale_factor);
    unsigned char *new_image_data = malloc(sizeof(unsigned char) * new_height * new_width);
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            int index = (i * new_width + j);
            int sum = 0;
            for (int k = 0; k < scale_factor; k++) {
                for (int l = 0; l < scale_factor; l++) {
                    int x = i * scale_factor + k;
                    int y = j * scale_factor + l;
                    if (x < height && y < width) {
                        sum += image_data[(x * width + y)];
                    }
                }
            }
            new_image_data[index] = sum / pow(scale_factor, 2);
        }
    }
    free(image_data);
    image_data = NULL;
    image_data = new_image_data;
    height = new_height;
    width = new_width;
}

// function to convert a grayscale image to ASCII art
void ascii_art(unsigned char *image_data, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            int brightness = image_data[index] / 25;
            printf("%c", ascii_chars[brightness]);
        }
        printf("\n");
    }
}

int main() {
    // read image data from file
    FILE *file = fopen("romeo.jpg", "rb");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned char *image_data = malloc(sizeof(unsigned char) * file_size);
    fread(image_data, file_size, 1, file);
    fclose(file);

    // convert image to grayscale and scale it down
    grayscale(image_data, 720, 1280);
    scale_down(image_data, 720, 1280, 10);

    // convert image to ASCII art and print it
    ascii_art(image_data, 72, 128);
    free(image_data);
    image_data = NULL;
    return 0;
}
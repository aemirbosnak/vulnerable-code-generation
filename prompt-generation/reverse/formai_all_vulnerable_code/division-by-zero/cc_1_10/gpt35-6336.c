//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// enter the file path of the image you want to convert
char image_path[] = "example_image.jpg";

// set the dimensions of the ASCII art
int width = 100;
int height = 60;

// function to convert RGB values to grayscale
int rgb_to_gray(int r, int g, int b) {
    return 0.2989 * r + 0.5870 * g + 0.1140 * b;
}

int main() {
    // open the image file
    FILE *fp;
    fp = fopen(image_path, "rb");

    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // read the image file header
    char header[54];
    fread(header, sizeof(char), 54, fp);

    // get the dimensions of the image
    int image_width = *(int*)&header[18];
    int image_height = *(int*)&header[22];

    // calculate the size of the image data
    int image_size = image_width * image_height * 3;

    // read the image data
    unsigned char *image_data = (unsigned char*)malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, fp);

    // close the image file
    fclose(fp);

    // create a grayscale version of the image
    unsigned char *gray_data = (unsigned char*)malloc(image_width * image_height);
    int gray_index = 0;

    for (int i = 0; i < image_size; i += 3) {
        int r = image_data[i];
        int g = image_data[i+1];
        int b = image_data[i+2];

        int gray_value = rgb_to_gray(r, g, b);

        gray_data[gray_index] = gray_value;
        gray_index++;
    }

    // calculate the width and height of each ASCII character
    int char_width = image_width / width;
    int char_height = image_height / height;

    // create a matrix to hold the ASCII art
    char ascii_matrix[height][width+1];

    // fill the matrix with the ASCII characters
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int sum = 0;

            for (int i = 0; i < char_height; i++) {
                for (int j = 0; j < char_width; j++) {
                    int pixel_index = ((y*char_height+i)*image_width + (x*char_width+j));
                    sum += gray_data[pixel_index];
                }
            }

            int average = sum / (char_width * char_height);

            if (average >= 230) {
                ascii_matrix[y][x] = ' ';
            } else if (average >= 200) {
                ascii_matrix[y][x] = '.';
            } else if (average >= 180) {
                ascii_matrix[y][x] = ':';
            } else if (average >= 160) {
                ascii_matrix[y][x] = 'o';
            } else if (average >= 140) {
                ascii_matrix[y][x] = '&';
            } else if (average >= 120) {
                ascii_matrix[y][x] = '8';
            } else if (average >= 100) {
                ascii_matrix[y][x] = '#';
            } else {
                ascii_matrix[y][x] = '@';
            }
        }

        ascii_matrix[y][width] = '\0';
    }

    // print the ASCII art
    for (int y = 0; y < height; y++) {
        printf("%s\n", ascii_matrix[y]);
    }

    // free the memory
    free(image_data);
    free(gray_data);

    return 0;
}
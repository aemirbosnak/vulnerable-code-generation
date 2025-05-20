//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 128
#define HEIGHT 128
#define MAX_COLOR 255
#define MIN_COLOR 0

int main(int argc, char **argv) {
    char *input_file = argv[1];
    char *output_file = argv[2];

    // read image data from the input file
    FILE *fp = fopen(input_file, "rb");
    if (fp == NULL) {
        printf("Unable to open the input file.\n");
        exit(1);
    }

    unsigned char image[HEIGHT][WIDTH];
    fread(image, 1, WIDTH*HEIGHT, fp);
    fclose(fp);

    // flip the image horizontally
    for (int y=0; y<HEIGHT; ++y) {
        for (int x=0; x<WIDTH/2; ++x) {
            unsigned char temp = image[y][x];
            image[y][x] = image[y][WIDTH-x-1];
            image[y][WIDTH-x-1] = temp;
        }
    }

    // adjust the brightness and contrast of the image
    double brightness_factor = 1.5;
    double contrast_factor = 0.5;

    for (int y=0; y<HEIGHT; ++y) {
        for (int x=0; x<WIDTH; ++x) {
            double pixel = (double)image[y][x];
            pixel = (pixel - MIN_COLOR) * contrast_factor + MIN_COLOR + brightness_factor;
            if (pixel > MAX_COLOR) pixel = MAX_COLOR;
            if (pixel < MIN_COLOR) pixel = MIN_COLOR;
            image[y][x] = (unsigned char)pixel;
        }
    }

    // write the image data to the output file
    fp = fopen(output_file, "wb");
    if (fp == NULL) {
        printf("Unable to open the output file.\n");
        exit(1);
    }

    fwrite(image, 1, WIDTH*HEIGHT, fp);
    fclose(fp);

    return 0;
}
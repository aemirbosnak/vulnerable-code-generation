//FormAI DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct image {
    int width;
    int height;
    struct pixel* pixels;
};

void read_image(char* filename, struct image* img);
void write_image(char* filename, struct image* img);
void grayscale(struct image* img);
void invert_colors(struct image* img);
void swap_pixels(struct pixel* p1, struct pixel* p2);

int main(int argc, char** argv) {
    struct image img;
    read_image(argv[1], &img);
    // apply transformations to img as desired
    grayscale(&img);
    invert_colors(&img);
    write_image(argv[2], &img);
    free(img.pixels);
    return 0;
}

void read_image(char* filename, struct image* img) {
    // read image from file and store in img
}

void write_image(char* filename, struct image* img) {
    // write image to file with specified filename
}

void grayscale(struct image* img) {
    // apply grayscale transformation to img
}

void invert_colors(struct image* img) {
    // apply color inversion transformation to img
}

void swap_pixels(struct pixel* p1, struct pixel* p2) {
    // swap two pixels by swapping their RGB values
}
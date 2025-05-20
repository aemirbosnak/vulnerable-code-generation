//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BLOCK_SIZE 1024

void flip_image(unsigned char* img, int width, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            unsigned char tmp = img[width*i+j];
            img[width*i+j] = img[width*height-1-i*width+j];
            img[width*height-1-i*width+j] = tmp;
        }
    }
}

void change_brightness(unsigned char* img, int width, int height, float factor) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            img[width*i+j] *= factor;
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <image_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input = fopen(input_file, "rb");
    if(input == NULL) {
        printf("Failed to open input file %s.\n", input_file);
        return 1;
    }

    unsigned char *img = malloc(BLOCK_SIZE * BLOCK_SIZE);
    if(img == NULL) {
        printf("Failed to allocate memory for image.\n");
        return 1;
    }

    int width = 0;
    int height = 0;
    int size = fread(img, 1, BLOCK_SIZE * BLOCK_SIZE, input);
    if(size!= BLOCK_SIZE * BLOCK_SIZE) {
        printf("Failed to read image from file %s.\n", input_file);
        return 1;
    }

    width = BLOCK_SIZE;
    height = BLOCK_SIZE;

    fclose(input);
    input = fopen(input_file, "rb");
    if(input == NULL) {
        printf("Failed to open input file %s.\n", input_file);
        return 1;
    }

    size = fread(img, 1, BLOCK_SIZE * BLOCK_SIZE, input);
    if(size!= BLOCK_SIZE * BLOCK_SIZE) {
        printf("Failed to read image from file %s.\n", input_file);
        return 1;
    }

    width = BLOCK_SIZE * BLOCK_SIZE;
    height = BLOCK_SIZE * BLOCK_SIZE;

    fclose(input);

    flip_image(img, width, height);
    change_brightness(img, width, height, 1.5);

    FILE *output = fopen(output_file, "wb");
    if(output == NULL) {
        printf("Failed to open output file %s.\n", output_file);
        return 1;
    }

    size = fwrite(img, 1, BLOCK_SIZE * BLOCK_SIZE, output);
    if(size!= BLOCK_SIZE * BLOCK_SIZE) {
        printf("Failed to write image to file %s.\n", output_file);
        return 1;
    }

    fclose(output);

    free(img);

    return 0;
}
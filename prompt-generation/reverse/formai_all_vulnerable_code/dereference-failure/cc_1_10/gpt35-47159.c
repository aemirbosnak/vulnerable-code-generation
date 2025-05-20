//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to read the input image */
void readImage(char *filename, unsigned char *image, int width, int height) {
    FILE *fp;
    fp = fopen(filename, "rb");
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);
}

/* Function to write the output image */
void writeImage(char *filename, unsigned char *image, int width, int height) {
    FILE *fp;
    fp = fopen(filename, "wb");
    fwrite(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);
}

/* Function to flip the image */
void flipImage(unsigned char *image, int width, int height) {
    unsigned char temp;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width/2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

/* Function to change the brightness and contrast of the image */
void brightnessContrast(unsigned char *image, int width, int height, int brightness, int contrast) {
    int pixel;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixel = image[i * width + j];
            pixel = ((pixel * contrast) / 100) + brightness;
            if(pixel < 0) pixel = 0;
            if(pixel > 255) pixel = 255;
            image[i * width + j] = pixel;
        }
    }
}

int main() {
    char *filename = "input.pgm";
    char *outfilename1 = "output1.pgm";
    char *outfilename2 = "output2.pgm";
    int width = 256;
    int height = 256;
    unsigned char *image = (unsigned char*) malloc(width * height * sizeof(unsigned char));
    int brightness = 50;
    int contrast = 150;

    /* Read the input image */
    readImage(filename, image, width, height);

    /* Flip the image and write to output file */
    flipImage(image, width, height);
    writeImage(outfilename1, image, width, height);

    /* Change the brightness and contrast and write to output file */
    brightnessContrast(image, width, height, brightness, contrast);
    writeImage(outfilename2, image, width, height);

    free(image);

    return 0;
}
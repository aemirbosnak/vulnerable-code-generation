//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// flip image function
void flipImage(int *pixels, int width, int height) {
    int temp;
    for(int i=0;i<height;i++) {
        for(int j=0;j<width/2;j++) {
            temp = *(pixels + i*width + j);
            *(pixels + i*width + j) = *(pixels + i*width + width - j - 1);
            *(pixels + i*width + width - j - 1) = temp;
        }
    }
}

// change brightness function
void changeBrightness(int *pixels, int width, int height, int brightness) {
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            int value = *(pixels + i*width + j) + brightness;
            if(value > 255) {
                value = 255;
            }
            if(value < 0) {
                value = 0;
            }
            *(pixels + i*width + j) = value;
        }
    }
}

// change contrast function
void changeContrast(int *pixels, int width, int height, int contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            int value = (int)(factor * (*(pixels + i*width + j) - 128) + 128);
            if(value > 255) {
                value = 255;
            }
            if(value < 0) {
                value = 0;
            }
            *(pixels + i*width + j) = value;
        }
    }
}

int main() {
    // read image file
    FILE *inputFile = fopen("image.raw", "rb");
    if(!inputFile) {
        printf("Error opening file!");
        exit(1);
    }
    int width = 640;
    int height = 480;
    int *pixels = (int*)malloc(width*height*sizeof(int));
    fread(pixels, sizeof(int), width*height, inputFile);
    fclose(inputFile);

    // flip image
    flipImage(pixels, width, height);

    // change brightness
    int brightness = 50;
    changeBrightness(pixels, width, height, brightness);

    // change contrast
    int contrast = 50;
    changeContrast(pixels, width, height, contrast);

    // write image file
    FILE *outputFile = fopen("output.raw", "wb");
    if(!outputFile) {
        printf("Error creating file!");
        exit(1);
    }
    fwrite(pixels, sizeof(int), width*height, outputFile);
    fclose(outputFile);

    // free memory
    free(pixels);

    printf("Image processing complete! Thanks for using my program!");
    return 0;
}
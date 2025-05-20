//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000

void readFile(char* filename, unsigned char* image, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");

    // Determine the size of the file
    fseek(fp, 0L, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Read in the image data
    fread(image, sizeof(unsigned char), MAX_IMAGE_SIZE, fp);

    // Determine the width and height of the image
    *width = (int)image[18];
    *height = (int)image[22];

    fclose(fp);
}

void writeFile(char* filename, unsigned char* image, int size) {
    FILE* fp = fopen(filename, "wb");

    fwrite(image, sizeof(unsigned char), size, fp);

    fclose(fp);
}

void flipImage(unsigned char* image, int width, int height) {
    int rowLength = width * 3;
    unsigned char* tempRow = (unsigned char*)malloc(rowLength);
    for(int i = 0; i < height / 2; i++) {
        // Copy the top row to a temp array
        memcpy(tempRow, &image[i * rowLength], rowLength);
        // Copy the bottom row to the top row
        memcpy(&image[i * rowLength], &image[(height - i - 1) * rowLength], rowLength);
        // Copy the temp array (which contains the original top row) to the bottom row
        memcpy(&image[(height - i - 1) * rowLength], tempRow, rowLength);
    }
    free(tempRow);
}

void adjustBrightness(unsigned char* image, int size, int brightness) {
    for(int i = 0; i < size; i++) {
        int val = (int)image[i] + brightness;
        if(val > 255) {
            image[i] = 255;
        } else if(val < 0) {
            image[i] = 0;
        } else {
            image[i] = (unsigned char)val;
        }
    }
}

void adjustContrast(unsigned char* image, int size, int contrast) {
    double factor = (259.0 * (double)(contrast + 255.0)) / (255.0 * (259.0 - (double)contrast));

    for(int i = 0; i < size; i++) {
        int val = (int)(factor * ((double)image[i] - 128.0) + 128.0);
        if(val > 255) {
            image[i] = 255;
        } else if(val < 0) {
            image[i] = 0;
        } else {
            image[i] = (unsigned char)val;
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s [imagefile]\n", argv[0]);
        return 1;
    }

    // Allocate memory for the image data
    unsigned char* image = (unsigned char*)malloc(MAX_IMAGE_SIZE);

    // Read in the image file
    int width, height;
    readFile(argv[1], image, &width, &height);

    // Flip the image vertically
    flipImage(image, width, height);

    // Adjust brightness
    adjustBrightness(image, width * height * 3, 50);

    // Adjust contrast
    adjustContrast(image, width * height * 3, -50);

    // Write the modified image to a file
    writeFile("output.jpg", image, width * height * 3);

    printf("Done!\n");

    return 0;
}
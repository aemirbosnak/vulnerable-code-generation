//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Function to flip an image horizontally
void flip_horizontal(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    int i,j;
    unsigned char temp;
    for(i=0; i<height; i++) {
        for(j=0; j<width/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int value) {
    int i,j;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            if(image[i][j] + value > 255) {
                image[i][j] = 255;
            } else if(image[i][j] + value < 0) {
                image[i][j] = 0;
            } else {
                image[i][j] += value;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjust_contrast(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height, float value) {
    int i,j;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            float pixel = (float)image[i][j];
            pixel /= 255.0;
            pixel -= 0.5;
            pixel *= value;
            pixel += 0.5;
            pixel *= 255.0;
            if(pixel > 255.0) {
                pixel = 255.0;
            }
            if(pixel < 0.0) {
                pixel = 0.0;
            }
            image[i][j] = (unsigned char)pixel;
        }
    }
}

int main(int argc, char *argv[]) {
    char filename[100];
    int width, height;
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int i,j;

    if(argc != 4) {
        printf("Usage: ./image_processing [filename] [brightness value] [contrast value]\n");
        return 1;
    }

    strcpy(filename, argv[1]);
    int brightness = atoi(argv[2]);
    float contrast = atof(argv[3]);

    FILE *image_file = fopen(filename, "rb");
    if(!image_file) {
        printf("Error: Could not open image file '%s'.\n", filename);
        return 1;
    }

    // Read image file header
    char header[54];
    fread(header, sizeof(char), 54, image_file);
    if(header[0] != 'B' || header[1] != 'M') {
        printf("Error: Invalid image file format.\n");
        fclose(image_file);
        return 1;
    }
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    int padding = 0;
    if((width*3)%4 != 0) {
        padding = 4 - (width*3)%4;
    }

    // Read image data
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, image_file);
            image[height-1-i][j] = pixel[0];
        }
        fseek(image_file, padding, SEEK_CUR);
    }
    fclose(image_file);

    // Flip image horizontally
    flip_horizontal(image, width, height);

    // Adjust the brightness and contrast of the image
    adjust_brightness(image, width, height, brightness);
    adjust_contrast(image, width, height, contrast);

    // Save the modified image to a new file
    char new_filename[100];
    sprintf(new_filename, "modified_%s", filename);
    FILE *output_file = fopen(new_filename, "wb");
    fwrite(header, sizeof(char), 54, output_file);
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++){
            unsigned char pixel[3] = {image[height-i-1][j], image[height-i-1][j], image[height-i-1][j]};
            fwrite(pixel, sizeof(unsigned char), 3, output_file);
        }
        for(j=0; j<padding; j++) {
            fputc(0x00, output_file);
        }
    }
    fclose(output_file);

    printf("Image processing complete. Saved modified image to '%s'\n", new_filename);

    return 0;
}
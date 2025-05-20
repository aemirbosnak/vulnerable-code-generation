//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define the ASCII characters to be used in the conversion
char characters[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

//Get the average brightness of a portion of the image
int getBrightness(unsigned char *image_data, int x, int y, int width, int height, int sample_size) {
    int total_brightness = 0;
    int i, j;
    for (i = x; i < x + sample_size && i < width; i++) {
        for (j = y; j < y + sample_size && j < height; j++) {
            total_brightness += image_data[(j * width + i) * 3];
        }
    }
    return total_brightness / (sample_size * sample_size);
}

int main(int argc, char *argv[]) {
    //Load the image file
    FILE *fp;
    fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        printf("Failed to open file.\n");
        return 0;
    }

    //Get the width and height of the image
    unsigned char header[54];
    int width, height;
    fread(header, sizeof(unsigned char), 54, fp);
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    //Allocate memory for the image data
    unsigned char *image_data = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));
    if (image_data == NULL) {
        printf("Failed to allocate memory.\n");
        return 0;
    }

    //Read the image data into memory
    fread(image_data, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    //Set the size of the sampling box
    int sample_size = 10;

    //Get the number of characters that will be used for each row of the ASCII art
    int columns = floor((double)width / (double)sample_size);

    //Allocate memory for the ASCII art
    char **ascii_art = (char**)malloc(height * sizeof(char*));
    int i, j;
    for (i = 0; i < height; i++) {
        ascii_art[i] = (char*)malloc((columns + 1) * sizeof(char));
    }

    //Convert the image to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < columns; j++) {
            int brightness = getBrightness(image_data, j * sample_size, i * sample_size, width, height, sample_size);
            int character = floor(((double)brightness / 255.0) * 10.0);
            ascii_art[i][j] = characters[character];
        }
        ascii_art[i][columns] = '\0';
    }

    //Print the ASCII art to the console
    for (i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    //Free the memory allocated for the ASCII art and image data
    for (i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);
    free(image_data);

    return 0;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the ASCII characters used for the conversion
char ascii_chars[11] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int main() {

    // open the image file in binary mode
    FILE *fp = fopen("image.bin", "rb");
    
    // if file cannot be opened, display error message and exit program
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // get the size of the image
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // calculate the dimensions of the image
    int width = 0, height = 0;
    for (int i = 0; i < size; i += 3) {
        if (fgetc(fp) != '\n') {
            width++;
        } else {
            height++;
        }
    }
    height++;

    // allocate memory for the image data
    unsigned char *image_data = (unsigned char*) malloc(width * height * 3);

    // read the image data into memory
    fread(image_data, sizeof(unsigned char), width * height * 3, fp);

    // close the file
    fclose(fp);

    // create a string to store the ASCII art
    char ascii_art[height][width];
    memset(ascii_art, ' ', height * width);

    // convert the image data to ASCII art
    for (int i = 0, j = 0; i < size; i += 3) {
        int intensity = (image_data[i] + image_data[i + 1] + image_data[i + 2]) / 3;
        int ascii_index = intensity * 10 / 255;
        ascii_art[j / width][j % width] = ascii_chars[ascii_index];
        j++;
        if (image_data[i] == '\n') {
            j += (width - j % width);
        }
    }

    // print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // free the memory allocated to the image data
    free(image_data);

    return 0;
}
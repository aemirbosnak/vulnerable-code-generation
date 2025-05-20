//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert the image to grayscale
void grayscale(int **image, int height, int width) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int pixel = image[i][j];
            int gray_pixel = (pixel >> 16 & 0xFF) * 0.299 + (pixel >> 8 & 0xFF) * 0.587 + (pixel & 0xFF) * 0.114;
            image[i][j] = gray_pixel;
        }
    }
}

// Function to convert grayscale pixel value to ASCII char
char get_ascii_char(int gray_pixel) {
    char ascii_char;
    if(gray_pixel >= 230)
        ascii_char = ' ';
    else if(gray_pixel >= 200)
        ascii_char = '.';
    else if(gray_pixel >= 180)
        ascii_char = '-';
    else if(gray_pixel >= 160)
        ascii_char = '+';
    else if(gray_pixel >= 130)
        ascii_char = '*';
    else if(gray_pixel >= 100)
        ascii_char = '#';
    else if(gray_pixel >= 70)
        ascii_char = '&';
    else if(gray_pixel >= 50)
        ascii_char = '8';
    else
        ascii_char = '@';
    
    return ascii_char;
}

// Main function
int main() {
    FILE *fp;
    
    // Open file
    fp = fopen("input_image.png", "rb");
    if(!fp) {
        printf("Error: Unable to open file.");
        return -1;
    }

    int height, width, channels;
    unsigned char *image_data;
    char *ascii_image;
    
    // Read image header
    fseek(fp, 0x0A, SEEK_SET);
    fread(&height, 4, 1, fp);
    fseek(fp, 0x0E, SEEK_SET);
    fread(&width, 4, 1, fp);
    fseek(fp, 0x16, SEEK_SET);
    fread(&channels, 2, 1, fp);

    // Allocate memory for image data
    image_data = (unsigned char*) malloc(height * width * channels);
    if(!image_data) {
        printf("Error: Unable to allocate memory.");
        return -1;
    }
    
    // Read image data
    fseek(fp, 0x36, SEEK_SET);
    fread(image_data, sizeof(unsigned char), height * width * channels, fp);

    // Convert image data to 2D array
    int **image = (int**) malloc(height * sizeof(int*));
    if(!image) {
        printf("Error: Unable to allocate memory.");
        return -1;
    }

    for(int i=0; i<height; i++)
        image[i] = (int*) malloc(width * sizeof(int));

    int byte_count = 0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int pixel = 0;
            for(int k=0; k<channels; k++) {
                pixel += image_data[byte_count++] << (k * 8);
            }
            image[i][j] = pixel;
        }
    }

    fclose(fp);
    free(image_data);

    // Convert image to grayscale
    grayscale(image, height, width);

    // Allocate memory for output ascii image
    ascii_image = (char*) calloc(height * width, sizeof(char));
    if(!ascii_image) {
        printf("Error: Unable to allocate memory.");
        return -1;
    }

    int ascii_index = 0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int gray_pixel = image[i][j];
            char ascii_char = get_ascii_char(gray_pixel);
            ascii_image[ascii_index++] = ascii_char;
        }
        ascii_image[ascii_index++] = '\n';
    }

    // Save ascii image to file
    fp = fopen("output_ascii_image.txt", "w");
    if(!fp) {
        printf("Error: Unable to open file.");
        return -1;
    }
    fputs(ascii_image, fp);
    fclose(fp);
    free(ascii_image);

    // Free allocated memory
    for(int i=0; i<height; i++)
        free(image[i]);
    free(image);

    return 0;
}
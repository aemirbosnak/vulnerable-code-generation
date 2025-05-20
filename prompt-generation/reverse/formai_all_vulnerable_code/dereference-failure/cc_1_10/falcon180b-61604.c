//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print ASCII art
void print_ascii_art(char* image_data, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", image_data[i * width + j]);
        }
        printf("\n");
    }
}

// Function to read image data from file
void read_image_data(char* filename, char** image_data, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END); // Move to end of file
    int filesize = ftell(fp); // Get file size
    rewind(fp); // Move back to beginning of file

    *image_data = (char*) malloc(filesize); // Allocate memory for image data
    if (*image_data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    fread(*image_data, filesize, 1, fp); // Read image data from file
    fclose(fp);

    // Determine width and height of image
    char header[54];
    memcpy(header, *image_data, 54);
    if (memcmp(header, "BM", 2)!= 0) {
        printf("Error: Invalid image format\n");
        exit(1);
    }
    int offset = 10;
    *width = *(int*) (*image_data + offset);
    *height = *(int*) (*image_data + offset + 4);
}

int main() {
    char* image_data;
    int width, height;
    read_image_data("image.bmp", &image_data, &width, &height);
    print_ascii_art(image_data, width, height);
    free(image_data);
    return 0;
}
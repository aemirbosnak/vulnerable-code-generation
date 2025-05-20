//FormAI DATASET v1.0 Category: Image Editor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the RGB struct
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB;

//function declarations
void read_header(FILE *fp, int *width, int *height);
void read_image(FILE *fp, RGB **image, int width, int height);
void write_image(FILE *fp, RGB **image, int width, int height);
void grayscale(RGB **image, int width, int height);
void flip_horizontally(RGB **image, int width, int height);

int main() {
    //open the input file
    FILE *fp = fopen("input.ppm", "rb");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    //read the image header
    int width, height;
    read_header(fp, &width, &height);

    //allocate memory for the image and read it
    RGB **image = malloc(height * sizeof(RGB *));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(RGB));
    }
    read_image(fp, image, width, height);

    //close the input file
    fclose(fp);

    //perform some image processing
    grayscale(image, width, height);
    flip_horizontally(image, width, height);

    //open the output file
    fp = fopen("output.ppm", "wb");
    if (fp == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    //write the output file
    write_image(fp, image, width, height);

    //close the output file
    fclose(fp);

    //free the allocated memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}

//function to read the image header
void read_header(FILE *fp, int *width, int *height) {
    char magic_number[3];
    fscanf(fp, "%s\n", magic_number); //read the magic number
    fscanf(fp, "%d %d\n", width, height); //read the width and height
    int max_value;
    fscanf(fp, "%d\n", &max_value); //read the maximum pixel value
}

//function to read the image data
void read_image(FILE *fp, RGB **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%c%c%c", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
        }
    }
}

//function to write the image data
void write_image(FILE *fp, RGB **image, int width, int height) {
    fprintf(fp, "P6\n%d %d\n255\n", width, height); //write the header
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&image[i][j].red, 1, 1, fp);
            fwrite(&image[i][j].green, 1, 1, fp);
            fwrite(&image[i][j].blue, 1, 1, fp);
        }
    }
}

//function to convert the image to grayscale
void grayscale(RGB **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char gray = 0.3 * image[i][j].red + 0.59 * image[i][j].green + 0.11 * image[i][j].blue;
            image[i][j].red = gray;
            image[i][j].green = gray;
            image[i][j].blue = gray;
        }
    }
}

//function to flip the image horizontally
void flip_horizontally(RGB **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGB temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}
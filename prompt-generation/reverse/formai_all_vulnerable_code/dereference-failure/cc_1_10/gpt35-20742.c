//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COLOR 255

// Image struct representing a grayscale image
typedef struct {
    int width;
    int height;
    int **pixels;
} Image;

// Function to allocate memory for an Image struct
Image *create_image(int width, int height) {
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(int**) * height);
    for (int i = 0; i < height; i++) {
        img->pixels[i] = malloc(sizeof(int*) * width);
    }
    return img;
}

// Function to read a PGM image file and create an Image struct
Image *read_pgm(char *filename) {
    FILE *fp;
    int width, height, maxval;
    char buffer[80];
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }
    
    // Read header
    fgets(buffer, sizeof(buffer), fp);
    if (buffer[0] != 'P' || buffer[1] != '5') {
        printf("Invalid image format (must be P5)\n");
        return NULL;
    }
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "%d", &maxval);
    
    // Create Image struct
    Image *img = create_image(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img->pixels[i][j] = fgetc(fp);
        }
    }
    
    fclose(fp);
    return img;
}

// Function to write an Image struct to a PGM image file
void write_pgm(Image *img, char *filename) {
    FILE *fp;
    
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    
    // Write header
    fprintf(fp, "P5\n%d %d\n%d\n", img->width, img->height, MAX_COLOR);
    
    // Write pixel data
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fputc(img->pixels[i][j], fp);
        }
    }
    
    fclose(fp);
}

// Function to flip an image horizontally
void flip_image(Image *img) {
    int temp;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            temp = img->pixels[i][j];
            img->pixels[i][j] = img->pixels[i][img->width - j - 1];
            img->pixels[i][img->width - j - 1] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *img, int value) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] += value;
            if (img->pixels[i][j] < 0) img->pixels[i][j] = 0;
            if (img->pixels[i][j] > MAX_COLOR) img->pixels[i][j] = MAX_COLOR;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image *img, float value) {
    float factor = (259 * (value + 255)) / (255 * (259 - value));
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] = (int)(factor * (img->pixels[i][j] - 128) + 128);
            if (img->pixels[i][j] < 0) img->pixels[i][j] = 0;
            if (img->pixels[i][j] > MAX_COLOR) img->pixels[i][j] = MAX_COLOR;
        }
    }
}

int main() {
    Image *img = read_pgm("image.pgm"); // Read image from file
    
    flip_image(img); // Flip image horizontally
    change_brightness(img, 50); // Increase brightness by 50
    change_contrast(img, 1.2); // Increase contrast by 20%

    write_pgm(img, "output.pgm"); // Write image to file
    
    return 0;
}
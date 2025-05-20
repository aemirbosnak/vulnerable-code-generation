//FormAI DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VAL 255

typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel **pixels;
} Image;

//Function to allocate memory for a new image
Image *createImage(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (Pixel **)malloc(sizeof(Pixel *) * height);
    for(int i = 0; i < height; i++) {
        img->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * width);
    }
    return img;
}

//Function to read an image from a file
Image *readImage(char *filename) {
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        perror("Error opening file");
        return NULL;
    }
    char magic[3];
    int width, height, max_value;
    if(fgets(magic, sizeof(magic), fp) == NULL || strncmp(magic, "P6", 2) != 0) {
        fprintf(stderr, "Error reading file format\n");
        return NULL;
    }
    while(fgetc(fp) == '#') {
        while(fgetc(fp) != '\n');
    }
    fseek(fp, -1, SEEK_CUR);
    if(fscanf(fp, "%d %d", &width, &height) != 2 || fscanf(fp, "%d", &max_value) != 1) {
        fprintf(stderr, "Error reading image metadata\n");
        return NULL;
    }
    if(max_value > MAX_PIXEL_VAL) {
        fprintf(stderr, "Error: Max pixel value greater than 255\n");
        return NULL;
    }
    fgetc(fp);
    Image *img = createImage(width, height);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Pixel *curr_pixel = &img->pixels[i][j];
            curr_pixel->R = fgetc(fp);
            curr_pixel->G = fgetc(fp);
            curr_pixel->B = fgetc(fp);
        }
    }
    fclose(fp);
    return img;
}

//Function to write an image to a file
void writeImage(char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, MAX_PIXEL_VAL);
    for(int i = 0; i < img->height; i++) {
        for(int j = 0; j < img->width; j++) {
            Pixel *curr_pixel = &img->pixels[i][j];
            fwrite(&curr_pixel->R, 1, 1, fp);
            fwrite(&curr_pixel->G, 1, 1, fp);
            fwrite(&curr_pixel->B, 1, 1, fp);
        }
    }
    fclose(fp);
    return;
}

//Function to free memory allocated to an image
void freeImage(Image *img) {
    for(int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
    return;
}

//Function to convert an image to grayscale
void grayscale(Image *img) {
    for(int i = 0; i < img->height; i++) {
        for(int j = 0; j < img->width; j++) {
            Pixel *curr_pixel = &img->pixels[i][j];
            unsigned char gray_value = (0.3 * curr_pixel->R) + (0.59 * curr_pixel->G) + (0.11 * curr_pixel->B);
            curr_pixel->R = gray_value;
            curr_pixel->G = gray_value;
            curr_pixel->B = gray_value;
        }
    }
    return;
}

//Function to brighten an image
void brighten(Image *img, int value) {
    for(int i = 0; i < img->height; i++) {
        for(int j = 0; j < img->width; j++) {
            Pixel *curr_pixel = &img->pixels[i][j];
            if(curr_pixel->R + value > MAX_PIXEL_VAL) {
                curr_pixel->R = MAX_PIXEL_VAL;
            } else {
                curr_pixel->R += value;
            }
            if(curr_pixel->G + value > MAX_PIXEL_VAL) {
                curr_pixel->G = MAX_PIXEL_VAL;
            } else {
                curr_pixel->G += value;
            }
            if(curr_pixel->B + value > MAX_PIXEL_VAL) {
                curr_pixel->B = MAX_PIXEL_VAL;
            } else {
                curr_pixel->B += value;
            }
        }
    }
    return;
}

int main(int argc, char **argv) {
    Image *img = readImage("input.ppm");
    if(img == NULL) {
        fprintf(stderr, "Error reading image file\n");
        return -1;
    }
    printf("Image format: %d x %d\n", img->width, img->height);
    grayscale(img);
    writeImage("grayscale_output.ppm", img);
    brighten(img, 50);
    writeImage("brightness_output.ppm", img);
    freeImage(img);
    return 0;
}
//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the struct for the pixel
typedef struct {
    int R;
    int G;
    int B;
} Pixel;

// Define the struct for the image
typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function to create a new image
Image *createImage(int width, int height) {
    Image *img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (Pixel*) malloc(sizeof(Pixel) * width * height);

    // Set all pixels to black
    for (int i = 0; i < width * height; i++) {
        img->pixels[i].R = 0;
        img->pixels[i].G = 0;
        img->pixels[i].B = 0;
    }
    return img;
}

// Function to free memory for image
void freeImage(Image *img) {
    free(img->pixels);
    free(img);
}

// Function to get the pixel at (x,y) position
Pixel getPixel(Image *img, int x, int y) {
    return img->pixels[y * img->width + x];
}

// Function to set the pixel at (x,y) position
void setPixel(Image *img, int x, int y, Pixel p) {
    img->pixels[y * img->width + x] = p;
}

// Function to read image file and create an image
Image *readImage(char *filename) {
    char magicNum[3];
    int width, height, maxVal;
    FILE *fptr = fopen(filename, "rb");

    fscanf(fptr, "%2s\n", magicNum);
    fscanf(fptr, "%d %d\n", &width, &height);
    fscanf(fptr, "%d\n", &maxVal);

    Image *img = createImage(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel p;
            fread(&p.R, sizeof(unsigned char), 1, fptr);
            fread(&p.G, sizeof(unsigned char), 1, fptr);
            fread(&p.B, sizeof(unsigned char), 1, fptr);
            setPixel(img, x, y, p);
        }
    }
    fclose(fptr);
    return img;
}

// Function to write image to file
void writeImage(Image *img, char *filename) {
    FILE *fptr = fopen(filename, "wb");
    fprintf(fptr, "P6\n%d %d\n255\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel p = getPixel(img, x, y);
            fwrite(&p.R, sizeof(unsigned char), 1, fptr);
            fwrite(&p.G, sizeof(unsigned char), 1, fptr);
            fwrite(&p.B, sizeof(unsigned char), 1, fptr);
        }
    }
    fclose(fptr);
}

// Function to flip image horizontally
void flipHorizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = getPixel(img, x, y);
            setPixel(img, x, y, getPixel(img, img->width-x-1, y));
            setPixel(img, img->width-x-1, y, temp);
        }
    }
}

// Function to invert image colors
void invertColors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].R = 255 - img->pixels[i].R;
        img->pixels[i].G = 255 - img->pixels[i].G;
        img->pixels[i].B = 255 - img->pixels[i].B;
    }
}

// Function to grayscale image
void grayScale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        int gray = (img->pixels[i].R + img->pixels[i].G + img->pixels[i].B) / 3;
        img->pixels[i].R = gray;
        img->pixels[i].G = gray;
        img->pixels[i].B = gray;
    }
}

int main() {
    Image *img = readImage("input.ppm");
    flipHorizontal(img);
    writeImage(img, "output.ppm");
    freeImage(img);

    Image *img2 = readImage("input.ppm");
    invertColors(img2);
    writeImage(img2, "output2.ppm");
    freeImage(img2);

    Image *img3 = readImage("input.ppm");
    grayScale(img3);
    writeImage(img3, "output3.ppm");
    freeImage(img3);

    return 0;
}
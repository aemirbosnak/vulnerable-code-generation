//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} pixel;

void flip_image(pixel **image, int width, int height) {
    pixel temp;
    for(int i=0; i<height/2; i++) {
        for(int j=0; j<width; j++) {
            temp = image[i][j];
            image[i][j] = image[height-i-1][j];
            image[height-i-1][j] = temp;
        }
    }
}

void adjust_brightness(pixel **image, int width, int height, int brightness) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int r = image[i][j].red + brightness;
            int g = image[i][j].green + brightness;
            int b = image[i][j].blue + brightness;
            image[i][j].red = (r<0) ? 0 : (r>255) ? 255 : r;
            image[i][j].green = (g<0) ? 0 : (g>255) ? 255 : g;
            image[i][j].blue = (b<0) ? 0 : (b>255) ? 255 : b;
        }
    }
}

void adjust_contrast(pixel **image, int width, int height, int contrast) {
    double factor = (double)(259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int r = (int)(factor * (double)(image[i][j].red - 128) + 128);
            int g = (int)(factor * (double)(image[i][j].green - 128) + 128);
            int b = (int)(factor * (double)(image[i][j].blue - 128) + 128);
            image[i][j].red = (r<0) ? 0 : (r>255) ? 255 : r;
            image[i][j].green = (g<0) ? 0 : (g>255) ? 255 : g;
            image[i][j].blue = (b<0) ? 0 : (b>255) ? 255 : b;
        }
    }
}

int main() {
    FILE *f = fopen("image.dat", "rb");
    if(f == NULL) {
        printf("Error opening image file!\n");
        exit(1);
    }
    
    int width, height;
    fread(&width, sizeof(int), 1, f);
    fread(&height, sizeof(int), 1, f);
    
    pixel **image = (pixel **)malloc(sizeof(pixel *)*height);
    for(int i=0; i<height; i++) {
        image[i] = (pixel *)malloc(sizeof(pixel)*width);
    }
    
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            fread(&image[i][j].red, sizeof(unsigned char), 1, f);
            fread(&image[i][j].green, sizeof(unsigned char), 1, f);
            fread(&image[i][j].blue, sizeof(unsigned char), 1, f);
        }
    }
    
    fclose(f);
    
    // Flip the image
    flip_image(image, width, height);
    
    // Adjust brightness
    adjust_brightness(image, width, height, 50);
    
    // Adjust contrast
    adjust_contrast(image, width, height, 50);
    
    FILE *fout = fopen("modified_image.dat", "wb");
    if(fout == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }
    
    fwrite(&width, sizeof(int), 1, fout);
    fwrite(&height, sizeof(int), 1, fout);
    
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            fwrite(&image[i][j].red, sizeof(unsigned char), 1, fout);
            fwrite(&image[i][j].green, sizeof(unsigned char), 1, fout);
            fwrite(&image[i][j].blue, sizeof(unsigned char), 1, fout);
        }
    }
    
    fclose(fout);
    
    for(int i=0; i<height; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}
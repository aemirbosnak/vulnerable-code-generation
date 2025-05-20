//FormAI DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Pixel {
    unsigned char r; // Red
    unsigned char g; // Green
    unsigned char b; // Blue
} Pixel;

typedef struct Image {
    int width;
    int height;
    Pixel **pixels;
} Image;

void writeImage(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width; j++) {
            fwrite(&img->pixels[i][j].r, 1, 1, fp);
            fwrite(&img->pixels[i][j].g, 1, 1, fp);
            fwrite(&img->pixels[i][j].b, 1, 1, fp);
        }
    }
    fclose(fp);
}

Image *readImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("Couldn't open file %s\n", filename);
        return NULL;
    }
    char magic[3];
    int width, height, maxval;
    fscanf(fp, "%s\n%d %d\n%d\n", magic, &width, &height, &maxval);
    if(strcmp(magic, "P6") != 0 || maxval != 255) {
        printf("Invalid file format\n");
        return NULL;
    }
    Image *img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (Pixel**)malloc(sizeof(Pixel*) * height);
    for(int i=0; i<height; i++) {
        img->pixels[i] = (Pixel*)malloc(sizeof(Pixel) * width);
        for(int j=0; j<width; j++) {
            img->pixels[i][j].r = fgetc(fp);
            img->pixels[i][j].g = fgetc(fp);
            img->pixels[i][j].b = fgetc(fp);
        }
    }
    fclose(fp);
    return img;
}

void grayscale(Image *img) {
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width; j++) {
            Pixel p = img->pixels[i][j];
            unsigned char gray = (unsigned char)(0.2126 * p.r + 0.7152 * p.g + 0.0722 * p.b);
            img->pixels[i][j].r = gray;
            img->pixels[i][j].g = gray;
            img->pixels[i][j].b = gray;
        }
    }
}

void sepia(Image *img) {
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width; j++) {
            Pixel p = img->pixels[i][j];
            unsigned char r = (unsigned char)(0.393 * p.r + 0.769 * p.g + 0.189 * p.b);
            unsigned char g = (unsigned char)(0.349 * p.r + 0.686 * p.g + 0.168 * p.b);
            unsigned char b = (unsigned char)(0.272 * p.r + 0.534 * p.g + 0.131 * p.b);
            img->pixels[i][j].r = r;
            img->pixels[i][j].g = g;
            img->pixels[i][j].b = b;
        }
    }
}

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: %s inputfile outputfile\n", argv[0]);
        return 0;
    }
    Image *img = readImage(argv[1]);
    if(!img) {
        return 0;
    }
    grayscale(img);
    writeImage(img, "grayscale.ppm");
    sepia(img);
    writeImage(img, "sepia.ppm");
    printf("Output files written\n");
    return 0;
}
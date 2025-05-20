//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Image structure
typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_SIZE][MAX_SIZE][3];
} Image;

// Function to read an image from an ASCII PPM file
Image* readPPM(char* fileName) {
    Image* img = (Image*)malloc(sizeof(Image));
    char buffer[MAX_SIZE];
    int width, height, maxVal;
    unsigned char r, g, b;

    FILE* fp = fopen(fileName, "r");

    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", fileName);
        exit(1);
    }

    fgets(buffer, MAX_SIZE, fp);

    if (buffer[0] != 'P' || buffer[1] != '3') {
        fprintf(stderr, "Error: not a PPM file\n");
        exit(1);
    }

    fgets(buffer, MAX_SIZE, fp);

    while (buffer[0] == '#') {
        fgets(buffer, MAX_SIZE, fp);
    }

    sscanf(buffer, "%d %d", &width, &height);

    fgets(buffer, MAX_SIZE, fp);
    sscanf(buffer, "%d", &maxVal);

    if (maxVal > 255) {
        fprintf(stderr, "Error: cannot handle max value > 255\n");
        exit(1);
    }

    img->width = width;
    img->height = height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fgets(buffer, MAX_SIZE, fp);
            sscanf(buffer, "%hhu %hhu %hhu", &r, &g, &b);
            img->pixels[i][j][0] = r;
            img->pixels[i][j][1] = g;
            img->pixels[i][j][2] = b;
        }
    }

    fclose(fp);

    return img;
}

// Function to write an image to an ASCII PPM file
void writePPM(char* fileName, Image* img) {
    FILE* fp = fopen(fileName, "w");

    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", fileName);
        exit(1);
    }

    fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%hhu %hhu %hhu\n", img->pixels[i][j][0], img->pixels[i][j][1], img->pixels[i][j][2]);
        }
    }

    fclose(fp);
}

// Function to set a pixel to a color
void setPixel(Image* img, int x, int y, int r, int g, int b) {
    img->pixels[y][x][0] = r;
    img->pixels[y][x][1] = g;
    img->pixels[y][x][2] = b;
}

// Function to create a black image
Image* createBlackImage(int width, int height) {
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img->pixels[i][j][0] = 0;
            img->pixels[i][j][1] = 0;
            img->pixels[i][j][2] = 0;
        }
    }

    return img;
}

int main() {
    Image* img = createBlackImage(640, 480);
    setPixel(img, 100, 100, 255, 0, 0);
    setPixel(img, 200, 200, 0, 255, 0);
    setPixel(img, 300, 300, 0, 0, 255);
    writePPM("my_image.ppm", img);
    free(img);
    return 0;
}
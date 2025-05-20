//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IMAGES 100
#define IMAGE_WIDTH 10
#define IMAGE_HEIGHT 10

typedef struct {
    char filename[50];
    uint8_t pixels[IMAGE_HEIGHT][IMAGE_WIDTH];
} Image;

typedef struct {
    char className[20];
    uint8_t averagePixelValue;
} Classification;

void loadImage(const char* filename, Image* img) {
    strcpy(img->filename, filename);
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    
    fread(img->pixels, sizeof(uint8_t), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fclose(file);
}

uint8_t calculateAveragePixelValue(const Image* img) {
    uint32_t total = 0;
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            total += img->pixels[i][j];
        }
    }
    return total / (IMAGE_WIDTH * IMAGE_HEIGHT);
}

void classifyImage(const Image* img, Classification* classification) {
    classification->averagePixelValue = calculateAveragePixelValue(img);
    
    if (classification->averagePixelValue < 85) {
        strcpy(classification->className, "Dark Image");
    } else if (classification->averagePixelValue < 170) {
        strcpy(classification->className, "Gray Image");
    } else {
        strcpy(classification->className, "Bright Image");
    }
}

void displayClassifications(const Classification* classifications, int count) {
    printf("Image Classifications:\n");
    for (int i = 0; i < count; i++) {
        printf("Image: %s, Class: %s, Avg Pixel Value: %d\n", 
               classifications[i].className , classifications[i].className,
               classifications[i].averagePixelValue);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image1> <image2> ... <imageN>\n", argv[0]);
        return 1;
    }

    Image images[MAX_IMAGES];
    Classification classifications[MAX_IMAGES];
    int imageCount = 0;

    for (int i = 1; i < argc && imageCount < MAX_IMAGES; i++) {
        loadImage(argv[i], &images[imageCount]);
        classifyImage(&images[imageCount], &classifications[imageCount]);
        imageCount++;
    }

    displayClassifications(classifications, imageCount);

    return 0;
}
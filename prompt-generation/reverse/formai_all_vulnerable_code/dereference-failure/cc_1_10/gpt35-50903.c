//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawPixel(char pixel) {
    switch(pixel) {
        case '0':
            printf(" ");
            break;
        case '1':
            printf("*");
            break;
        case '2':
            printf("#");
            break;
        case '3':
            printf("@");
            break;
        default:
            printf(" ");
    }
}

char* generatePixels(int numPixels) {
    char* pixels;
    pixels = (char*) malloc(numPixels * sizeof(char));
    srand(time(NULL));
    for(int i=0; i<numPixels; i++) {
        pixels[i] = (rand() % (4-0)) + '0';
    }
    return pixels;
}

void drawArt(char* pixels, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            drawPixel(pixels[i*width+j]);
        }
        printf("\n");
    }
}

int main() {
    int width = 10;
    int height = 5;
    int numPixels = width * height;
    char* pixels = generatePixels(numPixels);
    drawArt(pixels, width, height);
    free(pixels);
    return 0;
}
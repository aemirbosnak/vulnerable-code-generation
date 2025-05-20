//FormAI DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

//Function to change image brightness
void brightness(int *img, int width, int height, int factor) {
    for(int i = 0; i < width*height; i++) {
        int r = (img[i] >> 16) & 255;
        int g = (img[i] >> 8) & 255;
        int b = img[i] & 255;
        r = r + factor;
        g = g + factor;
        b = b + factor;
        if(r < 0) r = 0;
        if(r > 255) r = 255;
        if(g < 0) g = 0;
        if(g > 255) g = 255;
        if(b < 0) b = 0;
        if(b > 255) b = 255;
        img[i] = (r << 16) | (g << 8) | b;
    }
}

//Function to flip image horizontally
void flip_horizontal(int *img, int width, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width/2; j++) {
            int t = img[i*width+j];
            img[i*width+j] = img[i*width+width-j-1];
            img[i*width+width-j-1] = t;
        }
    }
}

//Function to flip image vertically
void flip_vertical(int *img, int width, int height) {
    for(int i = 0; i < height/2; i++) {
        for(int j = 0; j < width; j++) {
            int t = img[i*width+j];
            img[i*width+j] = img[(height-i-1)*width+j];
            img[(height-i-1)*width+j] = t;
        }
    }
}

int main() {
    int width = 400;
    int height = 300;
    int *img = malloc(sizeof(int)*width*height);

    //Initialize image with random colors
    for(int i = 0; i < width*height; i++) {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        img[i] = (r << 16) | (g << 8) | b;
    }

    //Display original image
    printf("Original Image\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("(%d,%d,%d) ", (img[i*width+j]>>16)&255, (img[i*width+j]>>8)&255, img[i*width+j]&255);
        }
        printf("\n");
    }

    //Change image brightness
    brightness(img, width, height, 50);
    //Display brightness changed image
    printf("\nBrightness Changed Image\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("(%d,%d,%d) ", (img[i*width+j]>>16)&255, (img[i*width+j]>>8)&255, img[i*width+j]&255);
        }
        printf("\n");
    }

    //Flip image horizontally
    flip_horizontal(img, width, height);
    //Display horizontally flipped image
    printf("\nHorizontally Flipped Image\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("(%d,%d,%d) ", (img[i*width+j]>>16)&255, (img[i*width+j]>>8)&255, img[i*width+j]&255);
        }
        printf("\n");
    }

    //Flip image vertically
    flip_vertical(img, width, height);
    //Display vertically flipped image
    printf("\nVertically Flipped Image\n");
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("(%d,%d,%d) ", (img[i*width+j]>>16)&255, (img[i*width+j]>>8)&255, img[i*width+j]&255);
        }
        printf("\n");
    }

    free(img);
    return 0;
}
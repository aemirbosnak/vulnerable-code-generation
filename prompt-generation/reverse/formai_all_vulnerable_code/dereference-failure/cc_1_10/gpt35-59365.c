//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define pixel struct
typedef struct Pixel {
    int red;
    int green;
    int blue;
} Pixel;

// Define image struct
typedef struct Image {
    Pixel** pixels;
    int width;
    int height;
} Image;

// Function to create image with random pixel values
Image createImage(int width, int height) {
    Image img;
    img.width = width;
    img.height = height;
    
    // Allocate memory for pixel array
    img.pixels = (Pixel**)malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        img.pixels[i] = (Pixel*)malloc(width * sizeof(Pixel));
    }
    
    // Set random pixel values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img.pixels[i][j].red = rand() % 256;
            img.pixels[i][j].green = rand() % 256;
            img.pixels[i][j].blue = rand() % 256;
        }
    }
    
    return img;
}

// Function to print image to console
void printImage(Image img) {
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("(%d,%d,%d) ", img.pixels[i][j].red, img.pixels[i][j].green, img.pixels[i][j].blue);
        }
        printf("\n");
    }
}

// Function to flip image horizontally
Image flipHorizontal(Image img) {
    Image flippedImg;
    flippedImg.width = img.width;
    flippedImg.height = img.height;
    
    // Allocate memory for flipped pixel array
    flippedImg.pixels = (Pixel**)malloc(flippedImg.height * sizeof(Pixel*));
    for (int i = 0; i < flippedImg.height; i++) {
        flippedImg.pixels[i] = (Pixel*)malloc(flippedImg.width * sizeof(Pixel));
    }
    
    // Flip pixels horizontally
    for (int i = 0; i < flippedImg.height; i++) {
        for (int j = 0; j < flippedImg.width; j++) {
            int flippedJ = flippedImg.width - 1 - j;
            flippedImg.pixels[i][flippedJ].red = img.pixels[i][j].red;
            flippedImg.pixels[i][flippedJ].green = img.pixels[i][j].green;
            flippedImg.pixels[i][flippedJ].blue = img.pixels[i][j].blue;
        }
    }
    
    return flippedImg;
}

// Function to swap red and blue pixel values
Image swapColors(Image img) {
    Image swappedImg;
    swappedImg.width = img.width;
    swappedImg.height = img.height;
    
    // Allocate memory for swapped pixel array
    swappedImg.pixels = (Pixel**)malloc(swappedImg.height * sizeof(Pixel*));
    for (int i = 0; i < swappedImg.height; i++) {
        swappedImg.pixels[i] = (Pixel*)malloc(swappedImg.width * sizeof(Pixel));
    }
    
    // Swap red and blue pixel values
    for (int i = 0; i < swappedImg.height; i++) {
        for (int j = 0; j < swappedImg.width; j++) {
            swappedImg.pixels[i][j].red = img.pixels[i][j].blue;
            swappedImg.pixels[i][j].green = img.pixels[i][j].green;
            swappedImg.pixels[i][j].blue = img.pixels[i][j].red;
        }
    }
    
    return swappedImg;
}

int main() {
    // Create image
    Image img = createImage(10, 5);
    
    // Print original image
    printf("Original image:\n");
    printImage(img);
    printf("\n");
    
    // Flip image horizontally
    Image flippedImg = flipHorizontal(img);
    
    // Print flipped image
    printf("Flipped image:\n");
    printImage(flippedImg);
    printf("\n");
    
    // Swap red and blue pixels
    Image swappedImg = swapColors(img);
    
    // Print swapped image
    printf("Swapped image:\n");
    printImage(swappedImg);
    printf("\n");
    
    return 0;
}
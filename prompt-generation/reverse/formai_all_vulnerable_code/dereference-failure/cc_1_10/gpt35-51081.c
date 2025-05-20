//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
// C Image Editor Example Program
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>

// Define the image structure
typedef struct Image {
    int width;
    int height;
    int** data;
} Image;

// Function to allocate memory for the image
Image* createImage(int width, int height) {
    Image* img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (int**) malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        img->data[i] = (int*) malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            img->data[i][j] = 0;
        }
    }
    return img;
}

// Function to free memory of the image
void destroyImage(Image* img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

// Function to set the pixel value of the image
void setPixel(Image* img, int x, int y, int value) {
    img->data[y][x] = value;
}

// Function to get the pixel value of the image
int getPixel(Image* img, int x, int y) {
    return img->data[y][x];
}

// Function to draw a line on the image
void drawLine(Image* img, int x1, int y1, int x2, int y2, int value) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx, sy;
    if (x1 < x2) { sx = 1; } else { sx = -1; }
    if (y1 < y2) { sy = 1; } else { sy = -1; }
    int err = dx - dy;
    while (x1 != x2 || y1 != y2) {
        setPixel(img, x1, y1, value);
        int e2 = 2 * err;
        if (e2 > -dy && (x1 != x2)) {
            err = err - dy;
            x1 = x1 + sx;
        }
        if (e2 < dx && (y1 != y2)) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
    setPixel(img, x2, y2, value);
}

// Function to draw a rectangle on the image
void drawRectangle(Image* img, int x1, int y1, int x2, int y2, int value) {
    drawLine(img, x1, y1, x1, y2, value);
    drawLine(img, x1, y1, x2, y1, value);
    drawLine(img, x2, y1, x2, y2, value);
    drawLine(img, x1, y2, x2, y2, value);
}

// Function to print the image on the console
void printImage(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new image with size 10x10
    Image* img = createImage(10, 10);
    
    // Draw a rectangle on the image
    drawRectangle(img, 2, 2, 8, 8, 1);
    
    // Print the image on the console
    printImage(img);
    
    // Free the memory of the image
    destroyImage(img);
    
    return 0;
}
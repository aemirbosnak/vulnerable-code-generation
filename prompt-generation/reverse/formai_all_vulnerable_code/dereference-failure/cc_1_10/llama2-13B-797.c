//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: mathematical
// Mathematician's Image Editor

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    int rows;
    int cols;
    double *pixels;
} Image;

// Function to create a new image
Image* newImage(int rows, int cols) {
    Image* img = malloc(sizeof(Image));
    img->rows = rows;
    img->cols = cols;
    img->pixels = malloc(rows * cols * sizeof(double));
    return img;
}

// Function to draw a line on the image
void drawLine(Image* img, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    double slope = dy / dx;
    int x = x1;
    int y = y1;

    for (int i = 0; i < abs(dx); i++) {
        img->pixels[y * img->cols + x] = slope * i + y1;
        x += dx;
    }
}

// Function to draw a circle on the image
void drawCircle(Image* img, int x, int y, int radius) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    drawLine(img, x1, y1, x2, y2);
    drawLine(img, x1, y2, x2, y1);
}

// Function to draw a pixel on the image
void setPixel(Image* img, int x, int y, double value) {
    img->pixels[y * img->cols + x] = value;
}

// Function to display the image
void displayImage(Image* img) {
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            printf("%.2f ", img->pixels[i * img->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    Image* img = newImage(10, 10);

    // Draw a line
    drawLine(img, 1, 1, 9, 9);

    // Draw a circle
    drawCircle(img, 5, 5, 3);

    // Set some pixels
    setPixel(img, 2, 2, 1.5);
    setPixel(img, 3, 3, 2.5);
    setPixel(img, 6, 6, 3.5);

    // Display the image
    displayImage(img);

    return 0;
}
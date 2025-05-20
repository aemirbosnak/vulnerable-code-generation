//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to hold pixel data
typedef struct pixel {
    int red;
    int green;
    int blue;
} pixel;

// Define a structure to hold image data
typedef struct image {
    int width;
    int height;
    pixel* data;
} image;

// Function to initialize an image
void initImage(image* img) {
    // Set default values for width, height, and data
    img->width = 0;
    img->height = 0;
    img->data = NULL;
}

// Function to create an image of a given size
image* createImage(int width, int height) {
    // Allocate memory for the image data
    pixel* data = (pixel*)malloc(width * height * sizeof(pixel));
    if (data == NULL) {
        printf("Error: Could not allocate memory for image data\n");
        exit(1);
    }

    // Initialize the image structure
    image* img = (image*)malloc(sizeof(image));
    initImage(img);
    img->width = width;
    img->height = height;
    img->data = data;

    return img;
}

// Function to free an image
void freeImage(image* img) {
    if (img!= NULL) {
        free(img->data);
        free(img);
    }
}

// Function to draw a line on the image
void drawLine(image* img, int x1, int y1, int x2, int y2) {
    // Check if the line is outside the image bounds
    if (x1 < 0 || x1 >= img->width || y1 < 0 || y1 >= img->height || x2 < 0 || x2 >= img->width || y2 < 0 || y2 >= img->height) {
        printf("Error: Line is outside the image bounds\n");
        return;
    }

    // Calculate the slope and y-intercept of the line
    float m = (float)(y2 - y1) / (float)(x2 - x1);
    float b = y1 - m * x1;

    // Iterate over the pixels in the line
    int i = 0;
    for (int j = 0; j < img->height; j++) {
        int y = j + y1;
        if (y < 0 || y >= img->height) {
            continue;
        }
        int x = (int)(m * (float)(x1 - x2) + b);
        if (x < 0 || x >= img->width) {
            continue;
        }
        pixel* px = &img->data[i];
        px->red = 255;
        px->green = 0;
        px->blue = 0;
        i++;
    }
}

// Function to draw a rectangle on the image
void drawRectangle(image* img, int x1, int y1, int x2, int y2) {
    // Check if the rectangle is outside the image bounds
    if (x1 < 0 || x1 >= img->width || y1 < 0 || y1 >= img->height || x2 < 0 || x2 >= img->width || y2 < 0 || y2 >= img->height) {
        printf("Error: Rectangle is outside the image bounds\n");
        return;
    }

    // Iterate over the pixels in the rectangle
    int i = 0;
    for (int j = 0; j < img->height; j++) {
        int y = j + y1;
        if (y < 0 || y >= img->height) {
            continue;
        }
        int x = (int)(y - y1) * (float)(x2 - x1) / (float)(y2 - y1) + x1;
        if (x < 0 || x >= img->width) {
            continue;
        }
        pixel* px = &img->data[i];
        px->red = 255;
        px->green = 255;
        px->blue = 255;
        i++;
    }
}

// Main function
int main() {
    // Create an image of size 500x500
    image* img = createImage(500, 500);

    // Draw a line on the image
    drawLine(img, 100, 100, 200, 200);

    // Draw a rectangle on the image
    drawRectangle(img, 150, 150, 250, 250);

    // Display the image
    printf("Image:\n");
    for (int i = 0; i < img->width * img->height; i++) {
        printf("(%d, %d, %d)\n", img->data[i].red, img->data[i].green, img->data[i].blue);
    }

    // Free the image
    freeImage(img);

    return 0;
}
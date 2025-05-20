//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to hold image data
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to read an image from a file
Image read_image(const char *file_name) {
    Image image;
    int i, j;

    // Open the image file
    FILE *file = fopen(file_name, "rb");
    if (!file) {
        printf("Error: Could not open %s\n", file_name);
        return image;
    }

    // Read the image width and height
    fread(&image.width, sizeof(int), 1, file);
    fread(&image.height, sizeof(int), 1, file);

    // Allocate memory for the image data
    image.data = (unsigned char *)malloc(image.width * image.height * 3);
    if (!image.data) {
        printf("Error: Could not allocate memory for image data\n");
        fclose(file);
        return image;
    }

    // Read the image data
    for (i = 0; i < image.width; i++) {
        for (j = 0; j < image.height; j++) {
            fread(image.data + (i * image.height * 3) + (j * 3), sizeof(unsigned char), 1, file);
        }
    }

    // Close the image file
    fclose(file);

    return image;
}

// Function to write an image to a file
void write_image(const char *file_name, Image image) {
    int i, j;
    FILE *file = fopen(file_name, "wb");
    if (!file) {
        printf("Error: Could not open %s\n", file_name);
        return;
    }

    // Write the image width and height
    fwrite(&image.width, sizeof(int), 1, file);
    fwrite(&image.height, sizeof(int), 1, file);

    // Write the image data
    for (i = 0; i < image.width; i++) {
        for (j = 0; j < image.height; j++) {
            fwrite(image.data + (i * image.height * 3) + (j * 3), sizeof(unsigned char), 1, file);
        }
    }

    // Close the image file
    fclose(file);
}

// Function to draw a line on the image
void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int i, j;

    // Calculate the slope and y-intercept of the line
    int slope = (y2 - y1) / (x2 - x1);
    int y_intercept = y1 - (slope * x1);

    // Draw the line
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            image->data[((i - x1) * 3) + (j - y1) * image->width] = 255;
        }
    }
}

// Function to draw a rectangle on the image
void draw_rectangle(Image *image, int x, int y, int width, int height) {
    int i, j;

    // Draw the top and bottom lines of the rectangle
    draw_line(image, x, y, x + width, y);
    draw_line(image, x, y + height, x + width, y + height);

    // Draw the left and right lines of the rectangle
    draw_line(image, x, y, x, y + height);
    draw_line(image, x + width, y, x + width, y + height);
}

// Function to draw a circle on the image
void draw_circle(Image *image, int x, int y, int radius) {
    int i, j;
    int x_center = x - radius;
    int y_center = y - radius;
    int x_end = x + radius;
    int y_end = y + radius;

    // Draw the circle
    for (i = x_center; i <= x_end; i++) {
        for (j = y_center; j <= y_end; j++) {
            image->data[((i - x_center) * 3) + ((j - y_center) * image->width)] = 255;
        }
    }
}

int main() {
    // Load the image
    Image image = read_image("image.jpg");

    // Draw a line on the image
    draw_line(&image, 10, 10, 20, 30);

    // Draw a rectangle on the image
    draw_rectangle(&image, 50, 50, 100, 150);

    // Draw a circle on the image
    draw_circle(&image, 150, 150, 50);

    // Write the modified image to a new file
    write_image("modified_image.jpg", image);

    return 0;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000    // Maximum input image width
#define MAX_HEIGHT 1000   // Maximum input image height
#define MAX_SIZE 1000000  // Maximum input image size

// Function to convert pixel value to ASCII character
char pixel_to_ascii(int r, int g, int b) {
    // Grayscale conversion formula
    int gray = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
    // ASCII character mapping based on grayscale value
    if (gray >= 230) {
        return ' ';
    }
    else if (gray >= 200) {
        return '.';
    }
    else if (gray >= 180) {
        return '^';
    }
    else if (gray >= 160) {
        return '*';
    }
    else if (gray >= 130) {
        return 'o';
    }
    else if (gray >= 100) {
        return 'C';
    }
    else if (gray >= 70) {
        return '8';
    }
    else if (gray >= 50) {
        return '&';
    }
    else {
        return '#';
    }
}

// Function to read input image from file
void read_image(char* filename, int* width, int* height, int* pixels) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P3") != 0) {
        printf("Invalid file format\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d %d\n", width, height);
    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        printf("Input image exceeds maximum size\n");
        exit(EXIT_FAILURE);
    }
    int maxval;
    fscanf(file, "%d\n", &maxval);
    int red, green, blue;
    int index = 0;
    while (fscanf(file, "%d %d %d\n", &red, &green, &blue) == 3) {
        if (index >= MAX_SIZE) {
            printf("Input image exceeds maximum size\n");
            exit(EXIT_FAILURE);
        }
        pixels[index++] = red;
        pixels[index++] = green;
        pixels[index++] = blue;
    }
    fclose(file);
}

// Function to convert input image to ASCII art
void image_to_ascii(int* pixels, int width, int height) {
    printf("### IMAGE TO ASCII ART ###\n\n");
    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x++) {
            int pixel_top = (y * width + x) * 3;
            int pixel_bottom = ((y + 1) * width + x) * 3;
            int r_top = pixels[pixel_top];
            int g_top = pixels[pixel_top + 1];
            int b_top = pixels[pixel_top + 2];
            int r_bottom = pixels[pixel_bottom];
            int g_bottom = pixels[pixel_bottom + 1];
            int b_bottom = pixels[pixel_bottom + 2];
            char ascii_char = pixel_to_ascii(r_top, g_top, b_top);
            printf("%c", ascii_char);
            ascii_char = pixel_to_ascii(r_bottom, g_bottom, b_bottom);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int width, height;
    int pixels[MAX_SIZE];
    read_image("input.ppm", &width, &height, pixels);
    image_to_ascii(pixels, width, height);
    return 0;
}
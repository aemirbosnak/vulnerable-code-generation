//FormAI DATASET v1.0 Category: Image Editor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 400
#define HEIGHT 300

// Function to load an image file and store it in a 2D array
int** load_image(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Failed to open image file\n");
        exit(EXIT_FAILURE);
    }
    int** image = (int**) calloc(HEIGHT, sizeof(int*));
    for(int i = 0; i < HEIGHT; i++) {
        image[i] = (int*) calloc(WIDTH, sizeof(int));
        for(int j = 0; j < WIDTH; j++) {
            image[i][j] = fgetc(fp);
        }
    }
    fclose(fp);
    return image;
}

// Function to apply a grayscale filter to an image
void grayscale(int** image) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int r = image[i][j] >> 16 & 0xFF;
            int g = image[i][j] >> 8 & 0xFF;
            int b = image[i][j] & 0xFF;
            int gray = 0.3*r + 0.59*g + 0.11*b;
            image[i][j] = (gray << 16) + (gray << 8) + gray;
        }
    }
}

// Function to save an image file from a 2D array
void save_image(char* filename, int** image) {
    FILE* fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: Failed to save image file\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            fputc(image[i][j], fp);
        }
    }
    fclose(fp);
}

int main() {
    int** image = load_image("input.ppm");
    grayscale(image);
    save_image("output.ppm", image);
    printf("Image processing complete\n");
    return 0;
}
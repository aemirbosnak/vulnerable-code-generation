//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HEIGHT 1000
#define MAX_WIDTH 1000

// function to allocate memory for a 2D array
int** allocateMemory(int height, int width) {
    int** matrix = (int**) malloc(sizeof(int*) * height);
    for (int h = 0; h < height; h++) {
        matrix[h] = (int*) malloc(sizeof(int) * width);
    }
    return matrix;
}

// function to free allocated memory for a 2D array
void freeMemory(int** matrix, int height) {
    for (int h = 0; h < height; h++) {
        free(matrix[h]);
    }
    free(matrix);
}

// function to read an image from file
void readImage(char* filename, int** image, int* height, int* width) {
    FILE* fin = fopen(filename, "r");
    if (!fin) {
        printf("Could not read input file!\n");
        exit(1);
    }
    fscanf(fin, "%d %d", height, width);
    for (int h = 0; h < *height; h++) {
        for (int w = 0; w < *width; w++) {
            fscanf(fin, "%d", &image[h][w]);
        }
    }
    fclose(fin);
}

// function to write an image to file
void writeImage(char* filename, int** image, int height, int width) {
    FILE* fout = fopen(filename, "w");
    if (!fout) {
        printf("Could not write output file!\n");
        exit(1);
    }
    fprintf(fout, "%d %d\n", height, width);
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            fprintf(fout, "%d ", image[h][w]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}

// function to apply grayscale to an image
void grayscale(int** image, int height, int width) {
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            int pixel = image[h][w];
            int red = (pixel >> 16) & 0xff;
            int green = (pixel >> 8) & 0xff;
            int blue = pixel & 0xff;
            int gray = (red + green + blue) / 3;
            image[h][w] = (gray << 16) | (gray << 8) | gray;
        }
    }
}

// function to apply edge detection to an image
void edgeDetection(int** image, int height, int width) {
    int sobelX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int sobelY[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    // create temporary image to store convolution result
    int** tempImage = allocateMemory(height, width);

    // apply convolution using Sobel operator
    for (int h = 1; h < height - 1; h++) {
        for (int w = 1; w < width - 1; w++) {
            int sumX = 0, sumY = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    sumX += image[h + i][w + j] * sobelX[i + 1][j + 1];
                    sumY += image[h + i][w + j] * sobelY[i + 1][j + 1];
                }
            }
            int sum = abs(sumX) + abs(sumY);
            tempImage[h][w] = sum;
        }
    }

    // copy temporary image to original image
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            image[h][w] = tempImage[h][w];
        }
    }

    // free memory allocated for temporary image
    freeMemory(tempImage, height);
}

int main() {
    int height, width;
    int** image = allocateMemory(MAX_HEIGHT, MAX_WIDTH);
    readImage("input.txt", image, &height, &width);

    // apply grayscale and edge detection to image
    grayscale(image, height, width);
    edgeDetection(image, height, width);

    writeImage("output.txt", image, height, width);
    freeMemory(image, height);
    return 0;
}
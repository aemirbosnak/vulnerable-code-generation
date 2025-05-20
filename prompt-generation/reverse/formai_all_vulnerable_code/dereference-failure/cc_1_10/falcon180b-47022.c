//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip the image
void flip(int **image, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = *(image[i] + j);
            *(image[i] + j) = *(image[i] + cols - j - 1);
            *(image[i] + cols - j - 1) = temp;
        }
    }
}

// Function to change brightness and contrast
void change_brightness_contrast(int **image, int rows, int cols, int brightness, int contrast) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int gray = *(image[i] + j);
            int new_gray = (gray * contrast) + brightness;
            if (new_gray > 255) {
                new_gray = 255;
            } else if (new_gray < 0) {
                new_gray = 0;
            }
            *(image[i] + j) = new_gray;
        }
    }
}

int main() {
    int rows, cols, max_val;
    FILE *fp;
    int **image;

    fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&cols, sizeof(int), 1, fp);
    fread(&rows, sizeof(int), 1, fp);
    fread(&max_val, sizeof(int), 1, fp);

    image = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        image[i] = (int *)malloc(cols * sizeof(int));
    }

    fseek(fp, 54, SEEK_SET);
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = 0; j < cols; j++) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, fp);
            *(image[i] + j) = pixel;
        }
    }

    flip(image, rows, cols);
    change_brightness_contrast(image, rows, cols, 50, 1.5);

    fp = fopen("output.bmp", "wb");
    if (fp == NULL) {
        printf("Error creating file\n");
        exit(0);
    }

    fwrite("BM", sizeof(char), 2, fp);
    fwrite(&rows, sizeof(int), 1, fp);
    fwrite(&cols, sizeof(int), 1, fp);
    fwrite(&max_val, sizeof(int), 1, fp);

    fseek(fp, 54, SEEK_SET);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            unsigned char pixel = *(image[i] + j);
            fwrite(&pixel, sizeof(unsigned char), 1, fp);
        }
    }

    fclose(fp);

    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}
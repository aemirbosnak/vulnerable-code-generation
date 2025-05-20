//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flipImage(int** img, int width, int height) {
    int temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = img[i][j];
            img[i][j] = img[i][width - j - 1];
            img[i][width - j - 1] = temp;
        }
    }
}

void adjustBrightness(int** img, int width, int height, int level) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = img[i][j] + level;
            if (val < 0) {
                val = 0;
            }
            if (val > 255) {
                val = 255;
            }
            img[i][j] = val;
        }
    }
}

void adjustContrast(int** img, int width, int height, float level) {
    float factor = (259 * (level + 255)) / (255 * (259 - level));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = factor * (img[i][j] - 128) + 128;
            if (val < 0) {
                val = 0;
            }
            if (val > 255) {
                val = 255;
            }
            img[i][j] = val;
        }
    }
}

int main() {
    int width = 5;
    int height = 4;

    int** img = (int**)malloc(height * sizeof(int*));

    for (int i = 0; i < height; i++) {
        img[i] = (int*)malloc(width * sizeof(int));
    }

    int num = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = num % 256;
            num++;
        }
    }

    printf("Original Image:\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    flipImage(img, width, height);
    printf("\nFlipped Image:\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    adjustBrightness(img, width, height, 50);
    printf("\nBrighter Image:\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    adjustContrast(img, width, height, 50.0);
    printf("\nHigher Contrast Image:\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(img[i]);
    }
    free(img);

    return 0;
}
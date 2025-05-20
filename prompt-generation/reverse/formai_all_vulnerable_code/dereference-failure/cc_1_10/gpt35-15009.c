//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void flipImage(int *image, int rows, int cols);
void changeBrightness(int *image, int rows, int cols, int brightness);
void changeContrast(int *image, int rows, int cols, int contrast);

int main()
{
    int rows = 5;  // number of rows in image
    int cols = 5;  // number of columns in image

    // initialize image array
    int *image = (int*)malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows * cols; i++) {
        image[i] = i + 1;
    }

    // print original image
    printf("Original Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(image + i * cols + j));
        }
        printf("\n");
    }

    // flip image
    flipImage(image, rows, cols);

    // print flipped image
    printf("\nFlipped Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(image + i * cols + j));
        }
        printf("\n");
    }

    // change brightness of image
    int brightness = 10;
    changeBrightness(image, rows, cols, brightness);

    // print image with changed brightness
    printf("\nImage with changed Brightness:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(image + i * cols + j));
        }
        printf("\n");
    }

    // change contrast of image
    int contrast = 20;
    changeContrast(image, rows, cols, contrast);

    // print image with changed contrast
    printf("\nImage with changed Contrast:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(image + i * cols + j));
        }
        printf("\n");
    }

    // free memory
    free(image);

    return 0;
}

/* Function to flip the image */
void flipImage(int *image, int rows, int cols)
{
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols/2; j++) {
            temp = *(image + i * cols + j);
            *(image + i * cols + j) = *(image + i * cols + cols - j - 1);
            *(image + i * cols + cols - j - 1) = temp;
        }
    }
}

/* Function to change the brightness of the image */
void changeBrightness(int *image, int rows, int cols, int brightness)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(image + i * cols + j) += brightness;
            if (*(image + i * cols + j) < 0) {
                *(image + i * cols + j) = 0;
            }
            if (*(image + i * cols + j) > 255) {
                *(image + i * cols + j) = 255;
            }
        }
    }
}

/* Function to change the contrast of the image */
void changeContrast(int *image, int rows, int cols, int contrast)
{
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(image + i * cols + j) = (int)(factor * (*(image + i * cols + j) - 128) + 128);
            if (*(image + i * cols + j) < 0) {
                *(image + i * cols + j) = 0;
            }
            if (*(image + i * cols + j) > 255) {
                *(image + i * cols + j) = 255;
            }
        }
    }
}
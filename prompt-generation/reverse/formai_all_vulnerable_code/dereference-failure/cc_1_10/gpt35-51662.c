//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} image;

// Function to allocate memory for the image data
void allocateImageData(image *img) {
    img->data = (unsigned char *)malloc(img->width * img->height * sizeof(unsigned char));
}

// Function to free memory used by the image data
void freeImageData(image *img) {
    free(img->data);
}

// Function to flip an image horizontally using recursion
void flipHorizontalRecursive(image *img, int row, int col1, int col2) {
    if (col1 >= col2) {
        return;
    }
    unsigned char temp = img->data[row * img->width + col1];
    img->data[row * img->width + col1] = img->data[row * img->width + col2];
    img->data[row * img->width + col2] = temp;
    flipHorizontalRecursive(img, row, col1 + 1, col2 - 1);
}

// Function to flip an image vertically using recursion
void flipVerticalRecursive(image *img, int col, int row1, int row2) {
    if (row1 >= row2) {
        return;
    }
    unsigned char temp = img->data[row1 * img->width + col];
    img->data[row1 * img->width + col] = img->data[row2 * img->width + col];
    img->data[row2 * img->width + col] = temp;
    flipVerticalRecursive(img, col, row1 + 1, row2 - 1);
}

// Function to change the brightness of an image using recursion
void changeBrightnessRecursive(image *img, int row, int col, unsigned char adjustment) {
    if (row >= img->height) {
        return;
    }
    unsigned char pixel = img->data[row * img->width + col];
    if ((int)pixel + (int)adjustment > 255) {
        pixel = 255;
    } else if ((int)pixel + (int)adjustment < 0) {
        pixel = 0;
    } else {
        pixel += adjustment;
    }
    img->data[row * img->width + col] = pixel;
    if (col < img->width - 1) {
        changeBrightnessRecursive(img, row, col + 1, adjustment);
    } else {
        changeBrightnessRecursive(img, row + 1, 0, adjustment);
    }
}

// Function to change the contrast of an image using recursion
void changeContrastRecursive(image *img, int row, int col, float adjustment) {
    if (row >= img->height) {
        return;
    }
    unsigned char pixel = img->data[row * img->width + col];
    float value = (float)(pixel - 127) * adjustment + 127.0;
    if (value > 255.0) {
        pixel = 255;
    } else if (value < 0) {
        pixel = 0;
    } else {
        pixel = (unsigned char)value;
    }
    img->data[row * img->width + col] = pixel;
    if (col < img->width - 1) {
        changeContrastRecursive(img, row, col + 1, adjustment);
    } else {
        changeContrastRecursive(img, row + 1, 0, adjustment);
    }
}

int main() {
    // Create a sample image
    image img;
    img.width = 5;
    img.height = 5;
    allocateImageData(&img);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            img.data[i * img.width + j] = (unsigned char)(i * img.width + j);
        }
    }

    // Flip the image horizontally
    flipHorizontalRecursive(&img, 2, 0, img.width - 1);
    printf("Horizontally Flipped Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%d ", img.data[i * img.width + j]);
        }
        printf("\n");
    }

    // Flip the image vertically
    flipVerticalRecursive(&img, 2, 0, img.height - 1);
    printf("Vertically Flipped Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%d ", img.data[i * img.width + j]);
        }
        printf("\n");
    }

    // Increase brightness of the image
    changeBrightnessRecursive(&img, 0, 0, 50);
    printf("Brightened Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%d ", img.data[i * img.width + j]);
        }
        printf("\n");
    }

    // Increase contrast of the image
    changeContrastRecursive(&img, 0, 0, 2.0);
    printf("Contrasted Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%d ", img.data[i * img.width + j]);
        }
        printf("\n");
    }

    // Free memory used by the image data
    freeImageData(&img);

    return 0;
}
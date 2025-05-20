//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024

void flip_image(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i*width+j];
            image[i*width+j] = image[width-i-1*width+j];
            image[width-i-1*width+j] = temp;
        }
    }
}

void change_brightness(unsigned char *image, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i*width+j];
            temp = (int)((temp * factor + 0.5) * 255);
            image[i*width+j] = temp;
        }
    }
}

void change_contrast(unsigned char *image, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i*width+j];
            if (temp > 128) {
                temp = (int)((temp * factor + 0.5) * 255);
            } else {
                temp = (int)((temp * factor + 128) * 255);
            }
            image[i*width+j] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    int width = 1000;
    int height = 800;
    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char) * width * height);

    for (int i = 0; i < width * height; i++) {
        image[i] = rand() % 255;
    }

    printf("Original Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i*width+j]);
        }
        printf("\n");
    }
    printf("\n");

    flip_image(image, width, height);
    printf("Flipped Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i*width+j]);
        }
        printf("\n");
    }
    printf("\n");

    change_brightness(image, width, height, 1.5);
    printf("Brightened Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i*width+j]);
        }
        printf("\n");
    }
    printf("\n");

    change_contrast(image, width, height, 1.5);
    printf("Contrasted Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i*width+j]);
        }
        printf("\n");
    }
    printf("\n");

    free(image);
    return 0;
}
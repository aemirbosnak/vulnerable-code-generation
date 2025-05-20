//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
/* A Simple Program to Flip an Image and Change its Brightness/Contrast */
#include <stdio.h>
#include <stdlib.h>

/* Define Image properties */
#define IMG_WIDTH 128
#define IMG_HEIGHT 128
#define IMG_DEPTH 8

/* Define Image type */
typedef struct {
    int width;
    int height;
    int depth;
    unsigned char *data;
} Image;

/* Function to Flip Image */
void Flip(Image *img) {
    int x, y;
    unsigned char temp;

    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width/2; x++) {
            temp = img->data[y*img->width + x];
            img->data[y*img->width + x] = img->data[y*img->width + (img->width - x - 1)];
            img->data[y*img->width + (img->width - x - 1)] = temp;
        }
    }
}

/* Function to Change Brightness/Contrast */
void BrightnessContrast(Image *img, int brightness, float contrast) {
    int x, y;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int value = img->data[y*img->width + x];
            value = (int)(factor * (value - 128) + 128 + brightness);
            if (value < 0) value = 0;
            if (value > 255) value = 255;
            img->data[y*img->width + x] = (unsigned char)value;
        }
    }
}

/* Main Function */
int main() {
    /* Allocate Memory to Store Image Data */
    unsigned char *img_data = (unsigned char*)malloc(IMG_WIDTH * IMG_HEIGHT * sizeof(unsigned char));

    /* Populate Random Image Data */
    int i;
    for (i = 0; i < IMG_WIDTH * IMG_HEIGHT; i++) {
        img_data[i] = rand() % 256;
    }

    /* Create Image Structure */
    Image img;
    img.width = IMG_WIDTH;
    img.height = IMG_HEIGHT;
    img.depth = IMG_DEPTH;
    img.data = img_data;

    /* Print Image Before Processing */
    printf("Before Processing:\n");

    int x, y;
    for (y = 0; y < img.height; y++) {
        for (x = 0; x < img.width; x++) {
            printf("%d ", img.data[y*img.width + x]);
        }
        printf("\n");
    }

    /* Flip Image */
    Flip(&img);

    /* Print Image After Flipping */
    printf("\nAfter Flipping:\n");

    for (y = 0; y < img.height; y++) {
        for (x = 0; x < img.width; x++) {
            printf("%d ", img.data[y*img.width + x]);
        }
        printf("\n");
    }

    /* Change Brightness and Contrast */
    BrightnessContrast(&img, 50, 50.0);

    /* Print Image After Brightness/Contrast Adjustment */
    printf("\nAfter Brightness/Contrast Adjustment:\n");

    for (y = 0; y < img.height; y++) {
        for (x = 0; x < img.width; x++) {
            printf("%d ", img.data[y*img.width + x]);
        }
        printf("\n");
    }

    /* Free Allocated Memory */
    free(img_data);

    return 0;
}
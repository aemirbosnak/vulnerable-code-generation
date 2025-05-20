//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

/* function to flip the image horizontally */
void flip_horizontal(int *img, int width, int height) {
    int i, j;
    int temp;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width/2; j++) {
            temp = *(img + i*width + j);
            *(img + i*width + j) = *(img + i*width + (width-j-1));
            *(img + i*width + (width-j-1)) = temp;
        }
    }
}

/* function to adjust the brightness of an image */
void brightness_adjustment(int *img, int width, int height, int bs) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            *(img + i*width + j) += bs;
            if(*(img + i*width + j) > 255) {
                *(img + i*width + j) = 255;
            }
            else if(*(img + i*width + j) < 0) {
                *(img + i*width + j) = 0;
            }
        }
    }
}

/* function to adjust the contrast of an image */
void contrast_adjustment(int *img, int width, int height, int cs) {
    int i, j;
    float factor = (259.0 * (float)(cs + 255)) / (255.0 * (float)(259 - cs));
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            *(img + i*width + j) = (int)(factor * ((float)*(img + i*width + j) - 128) + 128);
            if(*(img + i*width + j) > 255) {
                *(img + i*width + j) = 255;
            }
            else if(*(img + i*width + j) < 0) {
                *(img + i*width + j) = 0;
            }
        }
    }
}

int main() {
    int width = 4;
    int height = 3;
    int *img = malloc(width * height * sizeof(int));
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            *(img + i*width + j) = (i+1)*(j+1)*10;
        }
    }
    printf("Original Image:\n");
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%d ", *(img + i*width + j));
        }
        printf("\n");
    }
    printf("\n");
    /* flip the image horizontally */
    flip_horizontal(img, width, height);
    printf("Horizontally Flipped Image:\n");
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%d ", *(img + i*width + j));
        }
        printf("\n");
    }
    printf("\n");
    /* adjust the brightness of the image */
    brightness_adjustment(img, width, height, -20);
    printf("Image after Brightness Adjustment:\n");
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%d ", *(img + i*width + j));
        }
        printf("\n");
    }
    printf("\n");
    /* adjust the contrast of the image */
    contrast_adjustment(img, width, height, 40);
    printf("Image after Contrast Adjustment:\n");
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%d ", *(img + i*width + j));
        }
        printf("\n");
    }
    free(img);
    return 0;
}
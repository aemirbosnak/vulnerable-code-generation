//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int height;
    int width;
    int channels;
    int *data;
} image_t;

void flip_image(image_t *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[j * img->channels + 2] = img->data[img->width - 1 - j * img->channels + 2];
            img->data[j * img->channels + 1] = img->data[img->width - 1 - j * img->channels + 1];
            img->data[j * img->channels] = img->data[img->width - 1 - j * img->channels];
        }
    }
}

void change_brightness(image_t *img, float factor) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[j * img->channels + 0] = (img->data[j * img->channels + 0] * factor) / 255.0;
            img->data[j * img->channels + 1] = (img->data[j * img->channels + 1] * factor) / 255.0;
            img->data[j * img->channels + 2] = (img->data[j * img->channels + 2] * factor) / 255.0;
        }
    }
}

void change_contrast(image_t *img, float factor) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[j * img->channels + 0] = (img->data[j * img->channels + 0] * factor) / 255.0;
            img->data[j * img->channels + 1] = (img->data[j * img->channels + 1] * factor) / 255.0;
            img->data[j * img->channels + 2] = (img->data[j * img->channels + 2] * factor) / 255.0;
        }
    }
}

int main() {
    srand(time(NULL));

    image_t img = { 500, 500, 3, (int*)malloc(500 * 500 * 3 * sizeof(int)) };

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            img.data[j * img.channels + 0] = rand() % 256;
            img.data[j * img.channels + 1] = rand() % 256;
            img.data[j * img.channels + 2] = rand() % 256;
        }
    }

    flip_image(&img);
    change_brightness(&img, 2.0);
    change_contrast(&img, 1.5);

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%d ", img.data[j * img.channels + 0]);
        }
        printf("\n");
    }

    free(img.data);
    return 0;
}
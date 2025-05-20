//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_CHANNELS 4

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image *create_image(int width, int height, int channels) {
    Image *img = malloc(sizeof(Image));

    if (img == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = malloc(width * height * channels * sizeof(unsigned char));

    if (img->data == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    memset(img->data, 0, width * height * channels * sizeof(unsigned char));

    return img;
}

void destroy_image(Image *img) {
    free(img->data);
    free(img);
}

void print_image(Image *img) {
    int i, j, k;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < img->channels; k++) {
                printf("%d ", img->data[i * img->width * img->channels + j * img->channels + k]);
            }
        }
        printf("\n");
    }
}

int main() {
    Image *img = create_image(MAX_WIDTH, MAX_HEIGHT, MAX_CHANNELS);

    if (img == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    print_image(img);

    destroy_image(img);

    return 0;
}
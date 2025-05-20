//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width, height;
    char *data;
} image_t;

image_t *create_image(int width, int height) {
    image_t *img = malloc(sizeof(image_t));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(char) * width * height);
    return img;
}

void destroy_image(image_t *img) {
    free(img->data);
    free(img);
}

void fill_image(image_t *img, char color) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[i * img->width + j] = color;
        }
    }
}

void print_image(image_t *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            printf("%c", img->data[i * img->width + j]);
        }
        printf("\n");
    }
}

int main() {
    image_t *img1 = create_image(10, 10);
    image_t *img2 = create_image(10, 10);

    fill_image(img1, 'X');
    fill_image(img2, 'O');

    print_image(img1);
    printf("\n");
    print_image(img2);

    destroy_image(img1);
    destroy_image(img2);

    return 0;
}
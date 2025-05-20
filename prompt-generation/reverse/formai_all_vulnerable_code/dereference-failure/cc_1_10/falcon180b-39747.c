//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    int size;
    int *data;
} Image;

void init_image(Image *img, int size) {
    img->size = size;
    img->data = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        img->data[i] = rand() % 256;
    }
}

void free_image(Image *img) {
    free(img->data);
}

void print_image(Image *img) {
    for (int i = 0; i < img->size; i++) {
        printf("%d ", img->data[i]);
    }
    printf("\n");
}

int main() {
    Image img1, img2;
    init_image(&img1, MAX_SIZE);
    init_image(&img2, MAX_SIZE);

    int *watermark = malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++) {
        watermark[i] = rand() % 256;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        img1.data[i] = (img1.data[i] + watermark[i]) % 256;
    }

    printf("Watermarked image:\n");
    print_image(&img1);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (img1.data[i]!= watermark[i]) {
            printf("Watermark not found!\n");
            return 1;
        }
    }

    printf("Watermark found!\n");
    return 0;
}
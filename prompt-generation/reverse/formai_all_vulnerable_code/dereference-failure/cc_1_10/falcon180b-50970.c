//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_PIXEL_VALUE 255
#define BITS_PER_PIXEL 8
#define BYTES_PER_PIXEL 1

typedef struct {
    int width;
    int height;
    unsigned char* data;
} image_t;

void create_image(image_t* img) {
    img->width = WIDTH;
    img->height = HEIGHT;
    img->data = (unsigned char*) malloc(WIDTH * HEIGHT * BYTES_PER_PIXEL);

    srand(time(NULL));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        img->data[i] = rand() % MAX_PIXEL_VALUE;
    }
}

void print_image(image_t* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("%d ", img->data[y * img->width + x]);
        }
        printf("\n");
    }
}

void destroy_image(image_t* img) {
    free(img->data);
}

void hide_data(image_t* img, unsigned char* data, int data_size) {
    int index = 0;
    for (int i = 0; i < img->width * img->height; i++) {
        if (img->data[i] == 0) {
            img->data[i] = data[index++];
        }
    }
}

void extract_data(image_t* img, unsigned char* data, int data_size) {
    int index = 0;
    for (int i = 0; i < img->width * img->height; i++) {
        if (img->data[i] == 0) {
            data[index++] = img->data[i];
        }
    }
}

int main() {
    image_t image;
    create_image(&image);

    unsigned char* data = "Hello, world!";
    int data_size = strlen((char*) data);

    hide_data(&image, data, data_size);

    print_image(&image);

    unsigned char extracted_data[data_size];
    extract_data(&image, extracted_data, data_size);

    printf("Extracted data: %s\n", extracted_data);

    destroy_image(&image);

    return 0;
}
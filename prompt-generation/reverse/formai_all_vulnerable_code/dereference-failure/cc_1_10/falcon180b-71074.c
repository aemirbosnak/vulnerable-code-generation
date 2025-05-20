//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define IMAGE_SIZE WIDTH * HEIGHT

#define RED 0
#define GREEN 1
#define BLUE 2

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} image;

void init_image(image *img) {
    img->width = WIDTH;
    img->height = HEIGHT;
    img->channels = 3;
    img->data = (unsigned char*) malloc(IMAGE_SIZE * sizeof(unsigned char));
    memset(img->data, 0, IMAGE_SIZE * sizeof(unsigned char));
}

void set_pixel(image *img, int x, int y, int channel, int value) {
    int index = (y * img->width + x) * img->channels + channel;
    img->data[index] = value;
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not save image.\n");
        exit(1);
    }
    fwrite(img->data, IMAGE_SIZE, 1, fp);
    fclose(fp);
}

int main() {
    srand(time(NULL));

    image cover, stego;
    init_image(&cover);
    init_image(&stego);

    int message_size = 10000;
    unsigned char *message = (unsigned char*) malloc(message_size * sizeof(unsigned char));
    for (int i = 0; i < message_size; i++) {
        message[i] = rand() % 256;
    }

    int capacity = (int) ((double) message_size / (double) (WIDTH * HEIGHT * 3) * 4);
    printf("Capacity: %d bytes\n", capacity);

    int index = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = message[index++];
            set_pixel(&stego, x, y, RED, value);
            set_pixel(&stego, x, y, GREEN, value);
            set_pixel(&stego, x, y, BLUE, value);
        }
    }

    save_image(&cover, "cover.bmp");
    save_image(&stego, "stego.bmp");

    printf("Done.\n");
    return 0;
}
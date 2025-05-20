//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 768
#define MAX_IMAGE_SIZE (WIDTH * HEIGHT * 3)

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

typedef struct {
    int x, y;
    int value;
} pixel_t;

void init_image(image_t *image) {
    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = (char *)malloc(MAX_IMAGE_SIZE);
    memset(image->data, 0, MAX_IMAGE_SIZE);
}

void set_pixel(image_t *image, int x, int y, int value) {
    int index = (y * image->width + x) * 3;
    image->data[index] = value & 0xff;
    image->data[index + 1] = (value >> 8) & 0xff;
    image->data[index + 2] = (value >> 16) & 0xff;
}

void save_image(image_t *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: cannot save image to file %s\n", filename);
        exit(1);
    }
    fwrite(image->data, 1, MAX_IMAGE_SIZE, fp);
    fclose(fp);
}

int main() {
    srand(time(NULL));
    image_t image;
    init_image(&image);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int value = rand() % 256;
            set_pixel(&image, i, j, value);
        }
    }
    char *message = "Hello, world!";
    int message_size = strlen(message);
    int pixel_count = 0;
    for (int i = 0; i < message_size; i++) {
        pixel_t pixel;
        pixel.x = rand() % WIDTH;
        pixel.y = rand() % HEIGHT;
        pixel.value = rand() % 256;
        set_pixel(&image, pixel.x, pixel.y, pixel.value);
        pixel_count++;
        if (pixel_count >= (WIDTH * HEIGHT / message_size)) {
            pixel_count = 0;
        }
    }
    save_image(&image, "image.bmp");
    printf("Steganographic image saved as image.bmp\n");
    return 0;
}
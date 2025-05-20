//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_CHANNELS 4
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT * MAX_CHANNELS)

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image *create_image(int width, int height, int channels) {
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = calloc(width * height * channels, sizeof(unsigned char));
    return img;
}

void destroy_image(Image *img) {
    free(img->data);
    free(img);
}

void set_pixel(Image *img, int x, int y, int channel, int value) {
    int offset = (y * img->width + x) * img->channels + channel;
    img->data[offset] = value;
}

int get_pixel(Image *img, int x, int y, int channel) {
    int offset = (y * img->width + x) * img->channels + channel;
    return img->data[offset];
}

void print_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = 0; c < img->channels; c++) {
                int value = get_pixel(img, x, y, c);
                printf("%d ", value);
            }
        }
        printf("\n");
    }
}

int main() {
    Image *img = create_image(100, 100, 3);
    set_pixel(img, 0, 0, 0, 255);
    set_pixel(img, 0, 0, 1, 0);
    set_pixel(img, 0, 0, 2, 0);
    set_pixel(img, 50, 50, 0, 0);
    set_pixel(img, 50, 50, 1, 255);
    set_pixel(img, 50, 50, 2, 0);
    print_image(img);
    destroy_image(img);
    return 0;
}
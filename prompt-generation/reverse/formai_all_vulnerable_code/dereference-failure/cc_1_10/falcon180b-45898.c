//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLOR_COMPONENTS 4

typedef struct {
    int width;
    int height;
    int num_components;
    unsigned char* data;
} Image;

void create_image(Image* img, int width, int height, int num_components) {
    img->width = width;
    img->height = height;
    img->num_components = num_components;
    img->data = (unsigned char*)malloc(width * height * num_components);
}

void destroy_image(Image* img) {
    free(img->data);
}

void set_pixel(Image* img, int x, int y, unsigned char* color) {
    int offset = (y * img->width + x) * img->num_components;
    memcpy(img->data + offset, color, img->num_components);
}

unsigned char* get_pixel(Image* img, int x, int y) {
    int offset = (y * img->width + x) * img->num_components;
    return img->data + offset;
}

void print_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            unsigned char* pixel = get_pixel(img, x, y);
            printf("%02X%02X%02X%02X ", pixel[0], pixel[1], pixel[2], pixel[3]);
        }
        printf("\n");
    }
}

int main() {
    Image img;
    create_image(&img, 100, 100, 4);

    set_pixel(&img, 0, 0, (unsigned char[]) { 0, 0, 0, 255 });
    set_pixel(&img, 50, 50, (unsigned char[]) { 255, 0, 0, 255 });
    set_pixel(&img, 100, 0, (unsigned char[]) { 0, 255, 0, 255 });

    print_image(&img);

    destroy_image(&img);

    return 0;
}
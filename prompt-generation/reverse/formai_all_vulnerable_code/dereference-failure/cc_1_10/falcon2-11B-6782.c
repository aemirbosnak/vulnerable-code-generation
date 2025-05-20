//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024 * 1024

typedef struct {
    int width;
    int height;
    int channels;
    char* data;
} Image;

Image* create_image(int width, int height, int channels) {
    Image* img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = (char*) malloc(width * height * channels);
    return img;
}

void destroy_image(Image* img) {
    free(img->data);
    free(img);
}

int get_pixel(Image* img, int x, int y, int channel) {
    if (x < 0 || y < 0 || x >= img->width || y >= img->height) {
        return -1;
    }
    return img->data[y * img->width * img->channels + x * img->channels + channel];
}

void set_pixel(Image* img, int x, int y, int channel, int value) {
    if (x < 0 || y < 0 || x >= img->width || y >= img->height) {
        return;
    }
    img->data[y * img->width * img->channels + x * img->channels + channel] = value;
}

void draw_line(Image* img, int x0, int y0, int x1, int y1, int color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int err = dx - dy;

    if (abs(err) > 0) {
        int sgn = (err < 0)? 1 : -1;
        int x = x0;
        int y = y0;

        while (x!= x1 || y!= y1) {
            int alpha = 255 * (1 - (sgn * err * 0.5));
            set_pixel(img, x, y, 0, color);
            set_pixel(img, x, y, 1, color);
            set_pixel(img, x, y, 2, color);
            if (abs(err) < 1) {
                err = err > 0? err - 1 : err + 1;
            } else {
                err = err - abs(err) * 0.5;
                if (err < 0) {
                    err = 0;
                    sgn = -sgn;
                }
            }
            x += sgn;
            y += sgn;
        }
    }
}

int main() {
    srand(time(NULL));

    Image* img = create_image(MAX_IMAGE_SIZE, MAX_IMAGE_SIZE, 3);

    for (int x = 0; x < img->width; x++) {
        for (int y = 0; y < img->height; y++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            set_pixel(img, x, y, 0, r);
            set_pixel(img, x, y, 1, g);
            set_pixel(img, x, y, 2, b);
        }
    }

    draw_line(img, 0, 0, 100, 100, 255);
    draw_line(img, 0, 100, 100, 200, 255);
    draw_line(img, 100, 0, 200, 100, 255);
    draw_line(img, 200, 0, 100, 200, 255);
    draw_line(img, 200, 100, 200, 200, 255);
    draw_line(img, 100, 200, 200, 100, 255);
    draw_line(img, 0, 200, 100, 100, 255);
    draw_line(img, 0, 100, 0, 100, 255);
    draw_line(img, 200, 100, 200, 200, 255);
    draw_line(img, 200, 200, 100, 200, 255);
    draw_line(img, 200, 100, 100, 200, 255);

    printf("Created image with size %dx%d\n", img->width, img->height);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("%d ", get_pixel(img, x, y, 0));
            printf("%d ", get_pixel(img, x, y, 1));
            printf("%d ", get_pixel(img, x, y, 2));
            printf("\n");
        }
    }

    destroy_image(img);

    return 0;
}
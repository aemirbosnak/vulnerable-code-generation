//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_COLOR 255

typedef struct {
    int x, y;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

void init_image(Image *img) {
    img->width = WIDTH;
    img->height = HEIGHT;
    img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].x = rand() % WIDTH;
        img->pixels[i].y = rand() % HEIGHT;
    }
}

void print_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        printf("%c", (img->pixels[i].x + img->pixels[i].y) % MAX_COLOR + 33);
    }
}

void steganography(Image *img, char *msg) {
    int len = strlen(msg);
    int count = 0;
    for (int i = 0; i < img->width * img->height; i++) {
        if (count < len) {
            if ((img->pixels[i].x + img->pixels[i].y) % 2 == 0) {
                img->pixels[i].x++;
            } else {
                img->pixels[i].y++;
            }
            count++;
        } else {
            count = 0;
        }
    }
}

void main() {
    srand(time(NULL));
    Image img;
    init_image(&img);
    steganography(&img, "Secret message!");
    print_image(&img);
}
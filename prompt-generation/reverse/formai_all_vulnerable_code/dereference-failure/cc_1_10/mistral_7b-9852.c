//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 8
#define HEIGHT 8
#define COLORS 2

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

typedef struct {
    Color* pixels;
    int width;
    int height;
} Image;

void init_image(Image* img) {
    img->width = WIDTH;
    img->height = HEIGHT;
    img->pixels = (Color*) malloc(img->width * img->height * sizeof(Color));
    memset(img->pixels, 0, img->width * img->height * sizeof(Color));
}

void random_pixel(Image* img, int x, int y, Color color) {
    img->pixels[y * img->width + x] = color;
}

Color get_random_color() {
    static Color colors[COLORS] = { { 150, 255, 150 }, { 255, 0, 0 } };
    return colors[rand() % COLORS];
}

void fill_randomly(Image* img) {
    srand(time(NULL));
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            random_pixel(img, x, y, get_random_color());
        }
    }
}

void save_ppm(const char* filename, const Image* img) {
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P3\n%d %d\n255\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Color pixel = img->pixels[y * img->width + x];
            fprintf(file, "%d %d %d\n", pixel.r, pixel.g, pixel.b);
        }
    }
    fclose(file);
}

int main() {
    Image img;
    init_image(&img);
    fill_randomly(&img);
    save_ppm("output.ppm", &img);
    free(img.pixels);
    return 0;
}
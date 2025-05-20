//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define MAX_COLORS 256

typedef struct {
    unsigned char r, g, b;
} color_t;

typedef struct {
    color_t pixel[WIDTH * HEIGHT];
} image_t;

image_t* load_image(const char* file_name) {
    image_t* image = malloc(sizeof(image_t));
    FILE* file = fopen(file_name, "rb");
    if (!file) {
        printf("Error: Could not open %s\n", file_name);
        return NULL;
    }
    fread(image->pixel, sizeof(color_t), WIDTH * HEIGHT, file);
    fclose(file);
    return image;
}

void draw_rectangle(image_t* image, int x, int y, int width, int height, color_t color) {
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            image->pixel[i * WIDTH + j].r = color.r;
            image->pixel[i * WIDTH + j].g = color.g;
            image->pixel[i * WIDTH + j].b = color.b;
        }
    }
}

void draw_line(image_t* image, int x1, int y1, int x2, int y2, color_t color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int stepx = 1;
    int stepy = 1;
    int x = x1;
    int y = y1;
    color_t curr_color = color;
    while (x != x2 || y != y2) {
        if (dx == 0) {
            if (dy < 0) {
                y++;
                stepy = -1;
            } else if (dy > 0) {
                y--;
                stepy = 1;
            } else {
                x++;
                stepx = 1;
            }
            dx = 0;
        } else if (dy == 0) {
            if (dx < 0) {
                x--;
                stepx = -1;
            } else if (dx > 0) {
                x++;
                stepx = 1;
            } else {
                y++;
                stepy = 1;
            }
            dx = 0;
        } else {
            dx += stepx;
            dy += stepy;
        }
        image->pixel[x * WIDTH + y].r = curr_color.r;
        image->pixel[x * WIDTH + y].g = curr_color.g;
        image->pixel[x * WIDTH + y].b = curr_color.b;
    }
}

void save_image(image_t* image, const char* file_name) {
    FILE* file = fopen(file_name, "wb");
    if (!file) {
        printf("Error: Could not open %s\n", file_name);
        return;
    }
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fwrite(image->pixel[i].r, sizeof(char), 3, file);
        fwrite(image->pixel[i].g, sizeof(char), 3, file);
        fwrite(image->pixel[i].b, sizeof(char), 3, file);
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    image_t* image = load_image("example.bmp");
    if (!image) {
        printf("Error: Could not load example.bmp\n");
        return 1;
    }
    color_t color = (color_t) {
        .r = rand() % 256,
        .g = rand() % 256,
        .b = rand() % 256,
    };
    draw_rectangle(image, 100, 100, 200, 100, color);
    draw_line(image, 100, 100, 300, 200, color);
    save_image(image, "output.bmp");
    return 0;
}
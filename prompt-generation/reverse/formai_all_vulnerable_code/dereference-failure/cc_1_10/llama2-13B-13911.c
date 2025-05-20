//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x;
    int y;
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    image->x = 0;
    image->y = 0;
    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = malloc(WIDTH * HEIGHT * 3);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Unable to open %s\n", filename);
        return NULL;
    }

    fread(image->data, 1, WIDTH * HEIGHT * 3, file);
    fclose(file);

    return image;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steep = (dy > dx);

    if (steep) {
        int temp = x1;
        x1 = y1;
        y1 = temp;
    }

    for (int i = 0; i < dx; i++) {
        image->data[(y1 * WIDTH + x1) * 3] = 255;
        image->data[(y1 * WIDTH + x1) * 3 + 1] = 255;
        image->data[(y1 * WIDTH + x1) * 3 + 2] = 0;
        x1++;
    }

    for (int i = 0; i < dy; i++) {
        image->data[(y2 * WIDTH + x2) * 3] = 255;
        image->data[(y2 * WIDTH + x2) * 3 + 1] = 255;
        image->data[(y2 * WIDTH + x2) * 3 + 2] = 0;
        y2++;
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image->data[(y * WIDTH + x) * 3] = 255;
            image->data[(y * WIDTH + x) * 3 + 1] = 255;
            image->data[(y * WIDTH + x) * 3 + 2] = 0;
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius) {
    int f = 1 - (radius / 10);
    int d = 2 * f;

    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d; j++) {
            int x1 = x + (i * cos(M_PI / 180 * (f - 0.1))) + (j * sin(M_PI / 180 * (f - 0.1)));
            int y1 = y + (i * sin(M_PI / 180 * (f - 0.1))) + (j * cos(M_PI / 180 * (f - 0.1)));

            if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT) {
                image->data[(y1 * WIDTH + x1) * 3] = 255;
                image->data[(y1 * WIDTH + x1) * 3 + 1] = 255;
                image->data[(y1 * WIDTH + x1) * 3 + 2] = 0;
            }
        }
    }
}

void display_image(Image *image) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%02x", image->data[i]);
    }
    printf("\n");
}

int main() {
    Image *image = load_image("example.bmp");
    if (!image) {
        printf("Error: Unable to load image\n");
        return 1;
    }

    draw_line(image, 100, 100, 200, 200);
    draw_rectangle(image, 50, 50, 150, 100);
    draw_circle(image, 150, 150, 50);

    display_image(image);

    free(image->data);
    free(image);

    return 0;
}
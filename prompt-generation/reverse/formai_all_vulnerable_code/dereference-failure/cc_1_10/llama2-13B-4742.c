//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
    int width, height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    image->x = 0;
    image->y = 0;
    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = malloc(WIDTH * HEIGHT * 3);
    return image;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = dy > dx;
    if (steep) {
        int temp = dx;
        dx = dy;
        dy = temp;
    }
    for (int x = x1; x <= x2; x++) {
        int y = y1 + (dx * (x - x1));
        image->data[(y * WIDTH + x) * 3] = 255;
        image->data[(y * WIDTH + x) * 3 + 1] = 255;
        image->data[(y * WIDTH + x) * 3 + 2] = 0;
    }
}

void draw_circle(Image *image, int x, int y, int radius) {
    int factor = 1 - radius;
    for (int x = 0; x <= WIDTH; x++) {
        for (int y = 0; y <= HEIGHT; y++) {
            int distance = sqrt(pow(x - x, 2) + pow(y - y, 2));
            if (distance <= radius) {
                image->data[(y * WIDTH + x) * 3] = 255;
                image->data[(y * WIDTH + x) * 3 + 1] = 255;
                image->data[(y * WIDTH + x) * 3 + 2] = 0;
            } else {
                image->data[(y * WIDTH + x) * 3] = factor * (distance - radius) / (1 - radius);
                image->data[(y * WIDTH + x) * 3 + 1] = factor * (distance - radius) / (1 - radius);
                image->data[(y * WIDTH + x) * 3 + 2] = 0;
            }
        }
    }
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(image->data, 3, WIDTH * HEIGHT, file);
    fclose(file);
}

int main() {
    srand(time(NULL));
    Image *image = load_image("image.png");
    draw_line(image, 100, 100, 300, 300);
    draw_circle(image, 200, 200, 150);
    save_image(image, "output.png");
    return 0;
}
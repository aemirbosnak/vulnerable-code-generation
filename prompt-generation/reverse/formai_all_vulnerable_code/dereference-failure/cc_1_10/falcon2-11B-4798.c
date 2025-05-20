//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char* buffer;
} Image;

void init_image(Image* image, int width, int height) {
    image->width = width;
    image->height = height;
    image->buffer = (char*)malloc(width * height * sizeof(char));
    memset(image->buffer, 0, width * height * sizeof(char));
}

void draw_line(Image* image, int x1, int y1, int x2, int y2, char color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;

    if (x2 < x1) {
        dx = -dx;
    }
    if (y2 < y1) {
        dy = -dy;
    }

    for (; x!= x2 && y!= y2; x++, y++) {
        image->buffer[y * image->width + x] = color;
    }
}

void draw_circle(Image* image, int x, int y, int radius, char color) {
    int dx = 0;
    int dy = 0;
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    if (x1 >= 0) {
        dx = 1;
    }
    if (y1 >= 0) {
        dy = 1;
    }

    if (x2 < image->width) {
        dx = -1;
    }
    if (y2 < image->height) {
        dy = -1;
    }

    for (; dx!= 0 || dy!= 0; dx = -dx, dy = -dy) {
        int x = x1 + dx;
        int y = y1 + dy;

        image->buffer[y * image->width + x] = color;

        if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
            draw_circle(image, x, y, radius, color);
        }
    }
}

void draw_text(Image* image, int x, int y, char* text, char color) {
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        image->buffer[y * image->width + x + i] = color;
    }
}

void save_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "wb");
    fwrite(image->buffer, sizeof(char), image->width * image->height, file);
    fclose(file);
}

int main() {
    int width = 800;
    int height = 600;

    Image image;
    init_image(&image, width, height);

    draw_line(&image, 100, 100, 300, 300, 'r');
    draw_line(&image, 200, 200, 300, 300, 'g');
    draw_line(&image, 100, 100, 100, 400, 'b');

    draw_circle(&image, 400, 300, 100, 'r');
    draw_circle(&image, 400, 300, 200, 'g');
    draw_circle(&image, 400, 300, 100, 'b');

    draw_text(&image, 500, 500, "Hello, World!", 'w');

    save_image(&image, "output.png");

    return 0;
}
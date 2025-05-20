//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char **data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(sizeof(char) * width);
        memset(image->data[i], ' ', width);
    }
    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        printf("%s\n", image->data[i]);
    }
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        if (x1 > x2) {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }

        int error = -dx;
        int y = y1;

        for (int x = x1; x <= x2; x++) {
            image->data[y][x] = '*';
            error += 2 * dy;
            if (error > 0) {
                y += 1;
                error -= 2 * dx;
            }
        }
    } else {
        if (y1 > y2) {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }

        int error = -dy;
        int x = x1;

        for (int y = y1; y <= y2; y++) {
            image->data[y][x] = '*';
            error += 2 * dx;
            if (error > 0) {
                x += 1;
                error -= 2 * dy;
            }
        }
    }
}

int main() {
    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);

    draw_line(image, 0, 0, MAX_WIDTH - 1, MAX_HEIGHT - 1);
    draw_line(image, MAX_WIDTH - 1, 0, 0, MAX_HEIGHT - 1);
    draw_line(image, 0, MAX_HEIGHT / 2, MAX_WIDTH - 1, MAX_HEIGHT / 2);
    draw_line(image, MAX_WIDTH / 2, 0, MAX_WIDTH / 2, MAX_HEIGHT - 1);

    print_image(image);

    free_image(image);

    return 0;
}
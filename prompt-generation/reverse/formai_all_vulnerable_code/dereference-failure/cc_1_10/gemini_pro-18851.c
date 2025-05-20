//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    if (image->data == NULL) {
        free(image);
        return NULL;
    }

    memset(image->data, ' ', width * height);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void print_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

void draw_line(Image *image, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = (x1 >= x0) ? 1 : -1;
    int sy = (y1 >= y0) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        image->data[y0 * image->width + x0] = '*';

        if (x0 == x1 && y0 == y1) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_circle(Image *image, int x0, int y0, int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        image->data[(y0 + y) * image->width + (x0 + x)] = '*';
        image->data[(y0 + y) * image->width + (x0 - x)] = '*';
        image->data[(y0 - y) * image->width + (x0 + x)] = '*';
        image->data[(y0 - y) * image->width + (x0 - x)] = '*';
        image->data[(y0 + x) * image->width + (x0 + y)] = '*';
        image->data[(y0 + x) * image->width + (x0 - y)] = '*';
        image->data[(y0 - x) * image->width + (x0 + y)] = '*';
        image->data[(y0 - x) * image->width + (x0 - y)] = '*';

        x++;

        if (d > 0) {
            y--;
            d += 4 * (x - y) + 6;
        } else {
            d += 4 * x + 6;
        }
    }
}

void draw_text(Image *image, int x, int y, const char *text) {
    int i = 0;
    while (text[i] != '\0') {
        int c = text[i];
        int offset = c - ' ';
        int width = 5;
        int height = 7;
        const char *font[] = {
            " *   * ",
            "* *  * *",
            "*   *   ",
            "*****  ",
            "    *   ",
            "*   *   ",
            "*  **   ",
            "* * *  ",
            "******* ",
            "* * * * ",
            "    *   ",
            " ****   ",
            "*   * * ",
            "***  ** ",
            "*   * * ",
            "*   * * ",
            " *****  ",
            "*     * ",
            "*    *  ",
            "* *  * *",
            "**  **  ",
            "*****   ",
            "* ** *  ",
            " * ***  ",
            " *****  ",
            "*   *   ",
            "   *    ",
            "  * *   ",
            "  **    ",
            "   ***  ",
            "  ***   ",
            " ****** ",
        };

        for (int y2 = 0; y2 < height; y2++) {
            for (int x2 = 0; x2 < width; x2++) {
                image->data[(y + y2) * image->width + (x + x2 + offset * width)] = font[y2][x2];
            }
        }

        x += width + 1;
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s text\n", argv[0]);
        return 1;
    }

    const char *text = argv[1];

    int width = strlen(text) * 6 + 2;
    int height = 10;

    Image *image = new_image(width, height);
    if (image == NULL) {
        printf("Failed to allocate memory for image\n");
        return 1;
    }

    draw_text(image, 1, 1, text);

    print_image(image);

    free_image(image);

    return 0;
}
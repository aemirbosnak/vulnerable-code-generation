//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int w, h;
    char **data;
} Image;

Image *new_image(int w, int h) {
    Image *img = malloc(sizeof(Image));
    img->w = w;
    img->h = h;
    img->data = malloc(sizeof(char *) * h);
    for (int i = 0; i < h; i++) {
        img->data[i] = malloc(sizeof(char) * w);
        for (int j = 0; j < w; j++) {
            img->data[i][j] = ' ';
        }
    }
    return img;
}

void free_image(Image *img) {
    for (int i = 0; i < img->h; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

void draw_line(Image *img, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 - x1) / dx;
    int sy = (y2 - y1) / dy;
    int err = dx - dy;

    while (1) {
        img->data[y1][x1] = '*';
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

void draw_circle(Image *img, int x, int y, int r) {
    int x0 = 0;
    int y0 = r;
    int d = 3 - 2 * r;

    while (y0 >= x0) {
        img->data[y + y0][x + x0] = '*';
        img->data[y + y0][x - x0] = '*';
        img->data[y - y0][x + x0] = '*';
        img->data[y - y0][x - x0] = '*';
        img->data[y + x0][x + y0] = '*';
        img->data[y + x0][x - y0] = '*';
        img->data[y - x0][x + y0] = '*';
        img->data[y - x0][x - y0] = '*';

        x0++;

        if (d <= 0) {
            d += 4 * x0 + 6;
        } else {
            d += 4 * (x0 - y0) + 10;
            y0--;
        }
    }
}

void draw_text(Image *img, int x, int y, char *text) {
    int i = 0;
    while (text[i] != '\0') {
        int w = 5;
        int h = 7;
        char **chars = malloc(sizeof(char *) * h);
        for (int j = 0; j < h; j++) {
            chars[j] = malloc(sizeof(char) * w);
        }

        switch (text[i]) {
            case 'A':
                chars[0] = "  *  ";
                chars[1] = " * * ";
                chars[2] = "*   *";
                chars[3] = "*****";
                chars[4] = "*   *";
                chars[5] = "*   *";
                chars[6] = "  *  ";
                break;
            case 'B':
                chars[0] = "**** ";
                chars[1] = "*    ";
                chars[2] = "**** ";
                chars[3] = "*    ";
                chars[4] = "**** ";
                chars[5] = "*    ";
                chars[6] = "**** ";
                break;
            case 'C':
                chars[0] = " **** ";
                chars[1] = "*     ";
                chars[2] = "*     ";
                chars[3] = "*     ";
                chars[4] = "*     ";
                chars[5] = "*     ";
                chars[6] = " **** ";
                break;
            case 'D':
                chars[0] = "*    *";
                chars[1] = "*    *";
                chars[2] = "*    *";
                chars[3] = "*    *";
                chars[4] = "*    *";
                chars[5] = "*    *";
                chars[6] = "*    *";
                break;
            case 'E':
                chars[0] = "*****";
                chars[1] = "*     ";
                chars[2] = "*****";
                chars[3] = "*     ";
                chars[4] = "*****";
                chars[5] = "*     ";
                chars[6] = "*****";
                break;
        }

        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                img->data[y + j][x + k + i * w] = chars[j][k];
            }
        }

        for (int j = 0; j < h; j++) {
            free(chars[j]);
        }
        free(chars);

        i++;
    }
}

void print_image(Image *img) {
    for (int i = 0; i < img->h; i++) {
        for (int j = 0; j < img->w; j++) {
            printf("%c", img->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image *img = new_image(200, 100);

    draw_line(img, 0, 0, 200, 100);
    draw_circle(img, 100, 50, 20);
    draw_text(img, 10, 10, "Hello, world!");

    print_image(img);

    free_image(img);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 60

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x, y, w, h;
} Rect;

void draw_rect(Rect r, char c) {
    for (int i = r.x; i < r.x + r.w; i++) {
        for (int j = r.y; j < r.y + r.h; j++) {
            printf("%c", c);
        }
        printf("\n");
    }
}

void draw_image(char *filename, int scale) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    fread(data, filesize, 1, fp);
    fclose(fp);

    int width = scale * WIDTH;
    int height = scale * HEIGHT;
    int pixels = width * height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) / scale;
            int x = j * scale;
            int y = i * scale;

            if (index >= 0 && index < pixels) {
                int r = data[3 * index] / 8;
                int g = data[3 * index + 1] / 8;
                int b = data[3 * index + 2] / 8;

                int c = (r * 36 + g * 6 + b) % 6 + 32;
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <scale>\n", argv[0]);
        return 1;
    }

    int scale = atoi(argv[2]);
    draw_image(argv[1], scale);

    return 0;
}
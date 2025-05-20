//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

typedef struct {
    int x;
    int y;
    int w;
    int h;
} rect_t;

void draw_rect(rect_t rect, char c) {
    for (int y = rect.y; y < rect.y + rect.h; y++) {
        for (int x = rect.x; x < rect.x + rect.w; x++) {
            printf("%c", c);
        }
        printf("\n");
    }
}

void draw_image(image_t *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            if (img->data[y * img->width + x] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

image_t load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    fread(data, filesize, 1, fp);
    fclose(fp);

    image_t img;
    img.data = data;
    img.width = WIDTH;
    img.height = HEIGHT;

    return img;
}

int main() {
    image_t img = load_image("example.bmp");
    draw_image(&img);

    return 0;
}
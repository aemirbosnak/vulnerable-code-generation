//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define MIN_VALUE 0

typedef struct {
    int x, y;
} Point;

typedef struct {
    float r, g, b;
} Color;

void create_image(Color *image, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image[j * width + i].r = rand() % MAX_VALUE;
            image[j * width + i].g = rand() % MAX_VALUE;
            image[j * width + i].b = rand() % MAX_VALUE;
        }
    }
}

void add_watermark(Color *image, char *watermark, int width, int height) {
    int watermark_width, watermark_height;
    Color *watermark_image = (Color *)malloc(sizeof(Color) * width * height);
    create_image(watermark_image, width, height);

    for (int i = 0; i < strlen(watermark); i++) {
        if (watermark[i] == '1') {
            watermark_image[i * height * width + i * width + i].r = MIN_VALUE;
        }
    }

    int offset_x = (WIDTH - watermark_width) / 2;
    int offset_y = (HEIGHT - watermark_height) / 2;

    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            int x = i + offset_x;
            int y = j + offset_y;

            if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
                continue;
            }

            if (watermark_image[j * watermark_width + i].r == MIN_VALUE) {
                image[y * WIDTH + x].r = MIN_VALUE;
            }
        }
    }

    free(watermark_image);
}

void save_image(Color *image, char *filename, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(image, sizeof(Color), width * height, fp);
    fclose(fp);
}

int main() {
    Color *image = (Color *)malloc(sizeof(Color) * WIDTH * HEIGHT);
    create_image(image, WIDTH, HEIGHT);

    char *watermark = "Digital Watermarking Example";
    add_watermark(image, watermark, WIDTH, HEIGHT);

    save_image(image, "watermarked.bmp", WIDTH, HEIGHT);

    return 0;
}
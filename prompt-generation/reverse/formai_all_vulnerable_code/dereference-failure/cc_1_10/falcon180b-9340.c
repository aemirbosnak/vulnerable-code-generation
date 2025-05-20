//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define WIDTH 1024
#define HEIGHT 1024
#define MAX_CHAR 256
#define MAX_WATERMARK 256
#define MAX_WATERMARK_SIZE 1024
#define MAX_WATERMARK_SIZE_SQ 1048576

struct Pixel {
    int x, y;
    int r, g, b;
};

struct Watermark {
    char text[MAX_WATERMARK];
    int size;
    int x, y;
    int dx, dy;
};

int* createImage(int width, int height) {
    int* image = (int*)malloc(width * height * sizeof(int));
    for (int i = 0; i < width * height; i++) {
        image[i] = rand() % 256;
    }
    return image;
}

void applyWatermark(int* image, struct Watermark watermark) {
    for (int i = 0; i < watermark.size; i++) {
        for (int j = 0; j < watermark.size; j++) {
            int x = watermark.x + i - watermark.size / 2;
            int y = watermark.y + j - watermark.size / 2;
            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                int r = image[y * WIDTH + x] & 0xff0000;
                int g = image[y * WIDTH + x] & 0xff00;
                int b = image[y * WIDTH + x] & 0xff;
                int w = watermark.text[i * watermark.size + j] & 0xff;
                if (isalpha(w)) {
                    if (isupper(w)) {
                        r += (w - 'A') * 8;
                    } else {
                        r -= (w - 'a') * 8;
                    }
                } else {
                    r -= 8;
                }
                image[y * WIDTH + x] = (r << 16) | (g << 8) | b;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int* image = createImage(WIDTH, HEIGHT);
    struct Watermark watermark;
    strcpy(watermark.text, "Brave C Digital Watermarking");
    watermark.size = strlen(watermark.text);
    watermark.size = watermark.size > MAX_WATERMARK_SIZE? MAX_WATERMARK_SIZE : watermark.size;
    watermark.x = rand() % (WIDTH - watermark.size);
    watermark.y = rand() % (HEIGHT - watermark.size);
    applyWatermark(image, watermark);
    printf("PLAINFORMAT\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i * WIDTH + j]);
        }
        printf("\n");
    }
    free(image);
    return 0;
}
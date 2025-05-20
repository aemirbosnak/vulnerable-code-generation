//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define WATERMARK_TEXT "Medieval Digital Watermarking"

typedef unsigned char byte;

void putpixel(byte* image, int x, int y, byte color) {
    int offset = y * WIDTH + x;
    image[offset] = color;
}

byte getpixel(byte* image, int x, int y) {
    int offset = y * WIDTH + x;
    return image[offset];
}

void draw_watermark(byte* image) {
    int x = (WIDTH / 2) - (WATERMARK_WIDTH / 2);
    int y = (HEIGHT / 2) - (WATERMARK_HEIGHT / 2);

    for (int i = 0; i < WATERMARK_WIDTH; i++) {
        for (int j = 0; j < WATERMARK_HEIGHT; j++) {
            int index = j * WATERMARK_WIDTH + i;
            byte color = getpixel(image, x + i, y + j);
            putpixel(image, x + i, y + j, color);
            putpixel(image, x + i + WATERMARK_WIDTH, y + j, color);
            putpixel(image, x + i, y + j + WATERMARK_HEIGHT, color);
            putpixel(image, x + i + WATERMARK_WIDTH, y + j + WATERMARK_HEIGHT, color);
        }
    }
}

void save_image(byte* image, char* filename) {
    FILE* file = fopen(filename, "wb");
    fwrite(image, 1, WIDTH * HEIGHT, file);
    fclose(file);
}

int main() {
    byte* image = malloc(WIDTH * HEIGHT);
    memset(image, 0, WIDTH * HEIGHT);

    draw_watermark(image);

    save_image(image, "watermarked_image.bmp");

    free(image);

    return 0;
}
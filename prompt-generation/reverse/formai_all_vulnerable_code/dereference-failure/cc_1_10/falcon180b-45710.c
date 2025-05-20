//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define WATERMARK_WIDTH 32
#define WATERMARK_HEIGHT 32

#define MAX_VALUE 255

int main(int argc, char *argv[]) {
    srand(time(NULL));

    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
    unsigned char *watermark = (unsigned char *)malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT * 3);
    unsigned char *watermarked_image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);

    // Initialize image
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        image[i] = rand() % MAX_VALUE;
    }

    // Initialize watermark
    for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT * 3; i++) {
        watermark[i] = rand() % MAX_VALUE;
    }

    // Embed watermark
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int watermark_x = rand() % WATERMARK_WIDTH;
            int watermark_y = rand() % WATERMARK_HEIGHT;

            for (int k = 0; k < 3; k++) {
                watermarked_image[(y * WIDTH + x) * 3 + k] = image[(y * WIDTH + x) * 3 + k] ^ watermark[(watermark_x * WATERMARK_HEIGHT + watermark_y) * 3 + k];
            }
        }
    }

    // Save watermarked image
    FILE *fp = fopen("watermarked_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fwrite(watermarked_image, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    free(image);
    free(watermark);
    free(watermarked_image);

    return 0;
}
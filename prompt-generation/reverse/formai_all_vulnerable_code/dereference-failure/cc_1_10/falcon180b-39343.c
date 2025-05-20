//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)
#define WATERMARK_SIZE 16
#define WATERMARK_ALPHA 0.5
#define WATERMARK_COLOR 0xffff00

void init_image(unsigned char *image) {
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image[i] = rand() % 256;
    }
}

void add_watermark(unsigned char *image, unsigned char *watermark) {
    int watermark_x = rand() % IMAGE_WIDTH;
    int watermark_y = rand() % IMAGE_HEIGHT;

    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            int x = watermark_x + i;
            int y = watermark_y + j;

            if (x >= 0 && x < IMAGE_WIDTH && y >= 0 && y < IMAGE_HEIGHT) {
                int index = y * IMAGE_WIDTH + x;

                if (image[index] < 128) {
                    image[index] = (image[index] + (WATERMARK_COLOR - 128) * WATERMARK_ALPHA);
                }
            }
        }
    }
}

void save_image(const char *filename, unsigned char *image) {
    FILE *fp = fopen(filename, "wb");

    if (fp!= NULL) {
        fwrite(image, 1, IMAGE_SIZE, fp);
        fclose(fp);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        return 1;
    }

    unsigned char *image = (unsigned char *)malloc(IMAGE_SIZE);
    unsigned char *watermark = (unsigned char *)malloc(WATERMARK_SIZE);

    init_image(image);
    add_watermark(image, watermark);

    save_image(argv[2], image);

    free(image);
    free(watermark);

    return 0;
}
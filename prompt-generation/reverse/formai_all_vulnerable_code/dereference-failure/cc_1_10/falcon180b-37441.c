//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define ALPHA 0.5

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void read_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = (unsigned char *)malloc(filesize);
    fread(image->data, filesize, 1, fp);
    fclose(fp);

    image->width = WIDTH;
    image->height = HEIGHT;
}

void write_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);
}

void apply_watermark(Image *image) {
    int watermark_size = WATERMARK_WIDTH * WATERMARK_HEIGHT;
    unsigned char *watermark_data = (unsigned char *)malloc(watermark_size);
    memset(watermark_data, 255, watermark_size);

    int x = rand() % (image->width - WATERMARK_WIDTH);
    int y = rand() % (image->height - WATERMARK_HEIGHT);

    for (int i = 0; i < WATERMARK_WIDTH; i++) {
        for (int j = 0; j < WATERMARK_HEIGHT; j++) {
            int idx = (i + x) * image->width + (j + y);
            int alpha = ALPHA * watermark_data[i * WATERMARK_HEIGHT + j];
            image->data[idx] = (image->data[idx] * (1 - alpha)) >> 8;
        }
    }

    free(watermark_data);
}

void main() {
    srand(time(NULL));

    Image input_image;
    read_image(&input_image, "input.bmp");

    apply_watermark(&input_image);

    write_image(&input_image, "output.bmp");
}
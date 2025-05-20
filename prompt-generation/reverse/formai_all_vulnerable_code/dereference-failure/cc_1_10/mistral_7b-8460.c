//MISTRAL-7B DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define BPP 3
#define WATERMARK "SECRET"
#define WATERMARK_LEN 6
#define THRESHOLD 128

typedef struct {
    unsigned char r, g, b;
} pixel;

void read_image(const char *filename, pixel **image, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 2, SEEK_SET);
    int size = ftell(fp);
    fseek(fp, 18, SEEK_SET);
    *width = *(int *) &(((char *) 0)[0]);
    *height = *(int *) &(((char *) 0)[4]);
    *image = malloc(sizeof(pixel) * (*width) * (*height));
    fread(*image, sizeof(pixel), (*width) * (*height), fp);
    fclose(fp);
}

void write_image(const char *filename, pixel *image, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    fwrite(&(width), sizeof(int), 1, fp);
    fwrite(&(height), sizeof(int), 1, fp);
    fwrite(image, sizeof(pixel), width * height, fp);
    fclose(fp);
}

void watermark_image(pixel *image, int width, int height) {
    int x, y;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            if (image[y * width + x].r > THRESHOLD &&
                image[y * width + x].g > THRESHOLD &&
                image[y * width + x].b > THRESHOLD) {
                int dx, dy;
                dx = (x % (WIDTH / WATERMARK_LEN)) * WATERMARK_LEN;
                dy = (y % (HEIGHT / WATERMARK_LEN)) * WATERMARK_LEN;
                for (int i = 0; i < WATERMARK_LEN; i++) {
                    image[dy * WIDTH + dx + i].r += WATERMARK[i] * 30;
                    image[dy * WIDTH + dx + i].g += WATERMARK[i] * 15;
                    image[dy * WIDTH + dx + i].b += WATERMARK[i] * 10;
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_image>\n", argv[0]);
        return 1;
    }

    pixel *image;
    int width, height;
    read_image(argv[1], &image, &width, &height);

    watermark_image(image, width, height);
    write_image("output.bmp", image, width, height);

    free(image);
    return 0;
}
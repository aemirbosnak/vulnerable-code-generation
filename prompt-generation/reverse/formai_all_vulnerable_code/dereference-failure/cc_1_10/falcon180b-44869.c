//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VAL 255
#define THRESHOLD 10

typedef struct {
    int x, y;
    int val;
} Point;

void read_image(char *filename, int **img) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    *img = malloc(filesize);
    fread(*img, filesize, 1, fp);

    fclose(fp);
}

void write_image(char *filename, int **img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error writing file %s\n", filename);
        exit(1);
    }

    fwrite(*img, sizeof(int), WIDTH * HEIGHT, fp);

    fclose(fp);
}

void apply_watermark(int **img, int **watermark) {
    int i, j, k;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (img[i][j] > THRESHOLD) {
                for (k = 0; k < WIDTH; k++) {
                    img[i][j] -= watermark[k][j] * (img[i][j] / MAX_VAL);
                }
            }
        }
    }
}

void generate_watermark(int **watermark) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            watermark[i][j] = rand() % MAX_VAL;
        }
    }
}

int main() {
    int **img, **watermark;
    read_image("image.bmp", &img);

    generate_watermark(watermark);

    apply_watermark(img, watermark);

    write_image("watermarked_image.bmp", img);

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        free(img[i]);
        free(watermark[i]);
    }
    free(img);
    free(watermark);

    return 0;
}
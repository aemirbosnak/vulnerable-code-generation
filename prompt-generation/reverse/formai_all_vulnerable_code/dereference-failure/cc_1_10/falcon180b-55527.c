//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

#define W 3
#define H 3
#define N (WIDTH-W)/W
#define M (HEIGHT-H)/H

typedef struct {
    int x, y;
} point;

typedef struct {
    int value;
    point location;
} watermark;

void readImage(char *filename, int **image) {
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *image = (int *) malloc(filesize);
    fread(*image, sizeof(int), WIDTH*HEIGHT, fp);
    fclose(fp);
}

void writeImage(char *filename, int *image) {
    FILE *fp = fopen(filename, "wb");
    fwrite(image, sizeof(int), WIDTH*HEIGHT, fp);
    fclose(fp);
}

void addWatermark(int *image, watermark *wm) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int x = i*W+wm->location.x;
            int y = j*H+wm->location.y;
            int value = (image[y*WIDTH+x] + wm->value) % 256;
            image[y*WIDTH+x] = value;
        }
    }
}

void detectWatermark(int *image, watermark *wm) {
    int sum = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int x = i*W+wm->location.x;
            int y = j*H+wm->location.y;
            int value = (image[y*WIDTH+x] - wm->value + 256) % 256;
            sum += value*value;
        }
    }
    wm->value = sum % 256;
}

int main() {
    int *image = NULL;
    watermark wm;

    readImage("input.bmp", &image);

    wm.value = rand() % 256;
    wm.location.x = rand() % (WIDTH-W);
    wm.location.y = rand() % (HEIGHT-H);

    addWatermark(image, &wm);

    writeImage("output.bmp", image);

    return 0;
}
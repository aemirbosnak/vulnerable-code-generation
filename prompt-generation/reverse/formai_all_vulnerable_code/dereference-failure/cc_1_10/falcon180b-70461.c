//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define NUM_WATERMARKS 10
#define WATERMARK_VALUE 0.5

typedef struct {
    int x, y;
    int value;
} Watermark;

void initWatermarks(Watermark *watermarks) {
    int i;
    for (i = 0; i < NUM_WATERMARKS; i++) {
        watermarks[i].x = rand() % IMAGE_WIDTH;
        watermarks[i].y = rand() % IMAGE_HEIGHT;
        watermarks[i].value = WATERMARK_VALUE;
    }
}

void embedWatermarks(unsigned char *image, Watermark *watermarks) {
    int i;
    for (i = 0; i < NUM_WATERMARKS; i++) {
        int x = watermarks[i].x;
        int y = watermarks[i].y;
        int value = watermarks[i].value;
        int offset = (y * IMAGE_WIDTH + x) * 3;
        image[offset] += value;
        image[offset + 1] += value;
        image[offset + 2] += value;
    }
}

void detectWatermarks(unsigned char *image, Watermark *watermarks) {
    int i;
    for (i = 0; i < NUM_WATERMARKS; i++) {
        int x = watermarks[i].x;
        int y = watermarks[i].y;
        int value = watermarks[i].value;
        int offset = (y * IMAGE_WIDTH + x) * 3;
        int sum = 0;
        sum += abs(image[offset] - value);
        sum += abs(image[offset + 1] - value);
        sum += abs(image[offset + 2] - value);
        if (sum < 20) {
            printf("Watermark found at (%d, %d)\n", x, y);
        }
    }
}

int main() {
    unsigned char *image = malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 3);
    Watermark *watermarks = malloc(NUM_WATERMARKS * sizeof(Watermark));
    initWatermarks(watermarks);
    embedWatermarks(image, watermarks);
    printf("Embedded %d watermarks\n", NUM_WATERMARKS);
    detectWatermarks(image, watermarks);
    free(image);
    free(watermarks);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define MIN_VALUE 0

typedef struct {
    int x, y;
    int value;
} Pixel;

Pixel* image;

void init_image() {
    image = (Pixel*)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].x = i % WIDTH;
        image[i].y = i / WIDTH;
        image[i].value = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
    }
}

void display_image() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%02X ", image[i].value);
    }
    printf("\n");
}

void encode_watermark(char* watermark, int scale) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = image[i].x / scale;
        int y = image[i].y / scale;
        if (watermark[(y * (strlen(watermark) / WIDTH)) + x] == '1') {
            image[i].value += 10;
        }
    }
}

void decode_watermark() {
    int count = 0;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (image[i].value > MAX_VALUE - 10) {
            count++;
        }
    }
    if (count > 0) {
        printf("Watermark present\n");
    } else {
        printf("Watermark not present\n");
    }
}

int main() {
    init_image();
    encode_watermark("watermark", 2);
    display_image();
    decode_watermark();
    return 0;
}
//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 1024

typedef struct watermark_t {
    char *data;
    int length;
    int strength;
} watermark_t;

void watermark_create(watermark_t *wm, char *data, int length, int strength) {
    wm->data = malloc(length + 1);
    wm->length = length;
    wm->strength = strength;
    memcpy(wm->data, data, length);
}

void watermark_embed( watermark_t *wm, unsigned char *image, int image_size ) {
    for (int i = 0; i < wm->length; i++) {
        int index = rand() % image_size;
        image[index] ^= wm->data[i] & 0xFF;
    }
}

void watermark_extract( watermark_t *wm, unsigned char *image, int image_size ) {
    for (int i = 0; i < wm->length; i++) {
        int index = rand() % image_size;
        int watermark_bit = image[index] & 0xFF;
        if (watermark_bit != wm->data[i]) {
            printf("Watermark not found!\n");
            exit(1);
        }
    }
    printf("Watermark extracted successfully!\n");
}

int main() {
    char data[] = "This is a secret message";
    int length = strlen(data) + 1;
    int strength = 50;

    watermark_t wm;
    watermark_create(&wm, data, length, strength);

    unsigned char image[1024];
     watermark_embed(&wm, image, 1024);

     watermark_extract(&wm, image, 1024);

    return 0;
}
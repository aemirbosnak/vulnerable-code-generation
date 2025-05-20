//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LEN 256

typedef struct Watermark {
    char data[MAX_WATERMARK_LEN];
    int len;
} Watermark;

Watermark watermark_create(char *watermark_data, int watermark_len) {
    Watermark watermark;

    watermark.len = watermark_len;
    memcpy(watermark.data, watermark_data, watermark_len);

    return watermark;
}

void watermark_embed(Watermark watermark, unsigned char *image_data, int image_size) {
    for (int i = 0; i < image_size; i++) {
        for (int j = 0; j < watermark.len; j++) {
            image_data[i] ^= watermark.data[j] & 0x0F;
        }
    }
}

void watermark_extract(Watermark watermark, unsigned char *image_data, int image_size) {
    for (int i = 0; i < image_size; i++) {
        for (int j = 0; j < watermark.len; j++) {
            if (image_data[i] & watermark.data[j] & 0x0F) {
                printf("Watermark detected!\n");
            }
        }
    }
}

int main() {
    char watermark_data[] = "Secret message";
    int watermark_len = strlen(watermark_data) + 1;

    Watermark watermark = watermark_create(watermark_data, watermark_len);

    unsigned char image_data[] = "image.jpg";
    int image_size = 1024;

    watermark_embed(watermark, image_data, image_size);

    watermark_extract(watermark, image_data, image_size);

    return 0;
}
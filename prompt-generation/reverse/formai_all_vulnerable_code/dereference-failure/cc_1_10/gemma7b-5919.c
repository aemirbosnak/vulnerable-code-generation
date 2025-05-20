//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 1024

typedef struct watermark_data {
    char *data;
    int size;
    int strength;
} watermark_data;

void watermark_encode(watermark_data *data, char *image_data, int image_size) {
    int i, j, k, l;
    int watermarked_size = image_size * 2;
    data->data = malloc(watermarked_size);
    data->size = watermarked_size;
    data->strength = rand() % 100 + 1;

    for (i = 0; i < image_size; i++) {
        for (j = 0; j < 3; j++) {
            k = (i * 3) + j;
            l = rand() % data->strength;
            data->data[k] = image_data[i] ^ l;
        }
    }
}

int watermark_decode( watermark_data *data, char *image_data ) {
    int i, j, k, l;
    int watermarked_size = data->size;

    for (i = 0; i < watermarked_size; i++) {
        for (j = 0; j < 3; j++) {
            k = (i * 3) + j;
            l = data->data[k] ^ data->strength;
            image_data[i] = image_data[i] ^ l;
        }
    }

    return 0;
}

int main() {
    char image_data[] = "This is an image";
    int image_size = strlen(image_data);

    watermark_data data;
    watermark_encode(&data, image_data, image_size);

    watermark_decode(&data, image_data);

    printf("%s", image_data);

    return 0;
}
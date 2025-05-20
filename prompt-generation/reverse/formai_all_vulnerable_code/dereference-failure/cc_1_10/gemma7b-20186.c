//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 1024

typedef struct watermark_t {
    int size;
    char **data;
} watermark_t;

 watermark_t* watermark_create(int size) {
     watermark_t* watermark = malloc(sizeof(watermark_t));
    watermark->size = size;
    watermark->data = malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        watermark->data[i] = malloc(MAX_WATERMARK_SIZE * sizeof(char));
    }
    return watermark;
}

void watermark_destroy(watermark_t* watermark) {
    for (int i = 0; i < watermark->size; i++) {
        free(watermark->data[i]);
    }
    free(watermark->data);
    free(watermark);
}

void watermark_embed( watermark_t* watermark, char* image, int image_size) {
    for (int i = 0; i < watermark->size; i++) {
        for (int j = 0; j < MAX_WATERMARK_SIZE; j++) {
            int index = (i * MAX_WATERMARK_SIZE) + j;
            if (index < image_size) {
                watermark->data[i][j] = image[index];
            } else {
                watermark->data[i][j] = 0;
            }
        }
    }
}

int watermark_extract( watermark_t* watermark, char* image, int image_size) {
    int similarity = 0;
    for (int i = 0; i < watermark->size; i++) {
        for (int j = 0; j < MAX_WATERMARK_SIZE; j++) {
            int index = (i * MAX_WATERMARK_SIZE) + j;
            if (index < image_size) {
                similarity += abs(image[index] - watermark->data[i][j]);
            } else {
                similarity += MAX_WATERMARK_SIZE;
            }
        }
    }
    return similarity;
}

int main() {
    char* image = "image.jpg";
    int image_size = 1000000;

     watermark_t* watermark = watermark_create(128);
    watermark_embed(watermark, image, image_size);

    int similarity = watermark_extract(watermark, image, image_size);
    printf("Similarity: %d", similarity);

    watermark_destroy(watermark);

    return 0;
}
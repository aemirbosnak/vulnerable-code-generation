//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_CHAR 256

typedef struct {
    int x, y;
} Point;

void init_image(unsigned char* image) {
    int i, j;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            image[i * WIDTH + j] = rand() % MAX_CHAR;
        }
    }
}

unsigned char* add_watermark(unsigned char* image, const char* watermark) {
    int watermark_size = strlen(watermark);
    int image_size = WIDTH * HEIGHT;
    unsigned char* result = malloc(image_size * sizeof(unsigned char));

    int i, j, k;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            result[i * WIDTH + j] = image[i * WIDTH + j];
        }
    }

    int watermark_index = 0;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            if (result[i * WIDTH + j] == 0) {
                result[i * WIDTH + j] = watermark[watermark_index];
                ++watermark_index;
            }
        }
    }

    return result;
}

void save_image(const char* filename, unsigned char* image, int size) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: failed to open file %s\n", filename);
        exit(1);
    }

    fwrite(image, sizeof(unsigned char), size, fp);
    fclose(fp);
}

int main() {
    unsigned char* image = malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    init_image(image);

    const char* watermark = "Dennis Ritchie";
    unsigned char* watermarked_image = add_watermark(image, watermark);

    save_image("watermarked.bmp", watermarked_image, WIDTH * HEIGHT);

    free(image);
    free(watermarked_image);

    return 0;
}
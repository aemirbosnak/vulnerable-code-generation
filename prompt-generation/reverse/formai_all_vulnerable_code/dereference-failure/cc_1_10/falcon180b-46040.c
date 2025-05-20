//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_CHANNELS 4
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT * MAX_CHANNELS)

typedef struct {
    int width;
    int height;
    int channels;
    uint8_t *data;
} Image;

Image *createImage(int width, int height, int channels) {
    Image *image = (Image *) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = (uint8_t *) malloc(MAX_PIXELS * sizeof(uint8_t));
    return image;
}

void destroyImage(Image *image) {
    free(image->data);
    free(image);
}

void setPixel(Image *image, int x, int y, uint8_t value) {
    int index = (y * image->width + x) * image->channels;
    for (int i = 0; i < image->channels; i++) {
        image->data[index + i] = value;
    }
}

void saveImage(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not save image to file.\n");
        return;
    }
    fprintf(file, "P6\n%d %d\n%d\n", image->width, image->height, MAX_CHANNELS);
    fwrite(image->data, 1, MAX_PIXELS, file);
    fclose(file);
}

int main() {
    srand(time(NULL));
    Image *image = createImage(MAX_WIDTH, MAX_HEIGHT, MAX_CHANNELS);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            setPixel(image, x, y, rand() % 256);
        }
    }
    saveImage(image, "random.png");
    destroyImage(image);
    return 0;
}
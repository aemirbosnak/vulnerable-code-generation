//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define WIDTH 512
#define HEIGHT 512
#define BLOCK_SIZE 8
#define NUM_BLOCKS (WIDTH / BLOCK_SIZE) * (HEIGHT / BLOCK_SIZE)
#define NUM_PIXELS (WIDTH * HEIGHT)
#define MAX_VALUE 255
#define THRESHOLD 64

typedef struct {
    int x, y;
} Point;

typedef struct {
    char *filename;
    unsigned char *data;
    int size;
} Image;

Image load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error loading image %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    unsigned char *data = malloc(size);
    assert(data);

    fread(data, size, 1, file);
    fclose(file);

    Image image = {.filename = strdup(filename),.data = data,.size = size};
    return image;
}

void save_image(const char *filename, unsigned char *data, int size) {
    FILE *file = fopen(filename, "wb");
    assert(file);

    fwrite(data, size, 1, file);
    fclose(file);
}

void apply_watermark(unsigned char *data, int size, int strength) {
    for (int i = 0; i < size; i++) {
        data[i] += strength;
    }
}

int main() {
    srand(time(NULL));

    Image image = load_image("input.bmp");
    unsigned char *data = image.data;
    int size = image.size;

    int watermark_strength = rand() % 128 + 1;
    printf("Watermark strength: %d\n", watermark_strength);

    apply_watermark(data, size, watermark_strength);

    save_image("output.bmp", data, size);

    free(image.filename);
    free(image.data);

    return 0;
}
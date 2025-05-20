//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} color_t;

typedef struct {
    int x;
    int y;
    color_t color;
} pixel_t;

pixel_t* create_image(int width, int height) {
    pixel_t* image = (pixel_t*)malloc(sizeof(pixel_t) * width * height);
    for (int i = 0; i < width * height; i++) {
        image[i].x = i % width;
        image[i].y = i / width;
        image[i].color.r = rand() % 256;
        image[i].color.g = rand() % 256;
        image[i].color.b = rand() % 256;
    }
    return image;
}

void save_image(pixel_t* image, int width, int height, char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    for (int i = 0; i < width * height; i++) {
        fprintf(file, "%d %d %d ", image[i].color.r, image[i].color.g, image[i].color.b);
    }
    fclose(file);
}

int main() {
    srand(time(NULL));

    pixel_t* image = create_image(WIDTH, HEIGHT);
    save_image(image, WIDTH, HEIGHT, "image.png");

    free(image);
    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#define WIDTH 80
#define HEIGHT 25
#define BMP_SIZE (WIDTH * HEIGHT * 3)

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel;

pixel *image;

void init() {
    image = (pixel *) calloc(BMP_SIZE, sizeof(pixel));
}

void generate_post_apocalyptic_scene() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i < HEIGHT / 2 && j < WIDTH / 2) { // Ruins
                image[i * WIDTH + j].blue = 0;
                image[i * WIDTH + j].green = 128;
                image[i * WIDTH + j].red = 128;
            } else if (i > HEIGHT / 2 && j < WIDTH / 2) { // Radiation
                image[i * WIDTH + j].blue = 255;
                image[i * WIDTH + j].green = 0;
                image[i * WIDTH + j].red = 0;
            } else if (i < HEIGHT / 2 && j > WIDTH / 2) { // Forest
                image[i * WIDTH + j].blue = 0;
                image[i * WIDTH + j].green = 128;
                image[i * WIDTH + j].red = 0;
            } else { // Desert
                image[i * WIDTH + j].blue = 255;
                image[i * WIDTH + j].green = 255;
                image[i * WIDTH + j].red = 255;
            }
        }
    }
}

void save_image(const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite("BM", 2, 1, file);
    fwrite("P6\n", 3, 1, file);
    fprintf(file, "%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < BMP_SIZE; i++)
        fprintf(file, "%d %d %d ", image[i].blue, image[i].green, image[i].red);
    fclose(file);
}

int main() {
    init();
    generate_post_apocalyptic_scene();
    save_image("output.pgm");
    free(image);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 64
#define HEIGHT 64

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * 3);
    image->width = width;
    image->height = height;
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, int r, int g, int b) {
    int index = (y * image->width + x) * 3;
    image->data[index + 0] = r;
    image->data[index + 1] = g;
    image->data[index + 2] = b;
}

void write_ppm(Image *image, FILE *file) {
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = (y * image->width + x) * 3;
            fprintf(file, "%d %d %d ", image->data[index + 0], image->data[index + 1], image->data[index + 2]);
        }
        fprintf(file, "\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Image *image = new_image(WIDTH, HEIGHT);

    // Draw a red circle
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int dx = x - WIDTH / 2;
            int dy = y - HEIGHT / 2;
            if (dx * dx + dy * dy <= WIDTH * WIDTH / 4) {
                set_pixel(image, x, y, 255, 0, 0);
            }
        }
    }

    // Draw a green square
    for (int y = 0; y < HEIGHT / 2; y++) {
        for (int x = 0; x < WIDTH / 2; x++) {
            set_pixel(image, x, y, 0, 255, 0);
        }
    }

    // Draw a blue triangle
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y > x) {
                set_pixel(image, x, y, 0, 0, 255);
            }
        }
    }

    write_ppm(image, file);

    free_image(image);
    fclose(file);

    return 0;
}
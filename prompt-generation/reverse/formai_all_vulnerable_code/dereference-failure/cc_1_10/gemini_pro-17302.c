//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512

struct Image {
    unsigned char *data;
    int width;
    int height;
};

void read_image(struct Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fread(image->data, 1, image->width * image->height, file);
    fclose(file);
}

void flip_vertically(struct Image *image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->height - j - 1];
            image->data[i * image->width + image->height - j - 1] = temp;
        }
    }
}

void write_image(struct Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);
}

int main() {
    struct Image image;
    image.data = malloc(WIDTH * HEIGHT);
    image.width = WIDTH;
    image.height = HEIGHT;

    read_image(&image, "input.bmp");
    flip_vertically(&image);
    write_image(&image, "output.bmp");

    free(image.data);
    return 0;
}
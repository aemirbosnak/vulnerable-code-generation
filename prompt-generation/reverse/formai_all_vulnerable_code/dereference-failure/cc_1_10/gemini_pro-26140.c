//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, sizeof(unsigned char), fp);
    fclose(fp);
}

void generate_art(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int offset = y * image->width + x;
            image->data[offset] = rand() % 256;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <width> <height> <filename>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    const char *filename = argv[3];

    Image *image = new_image(width, height);
    generate_art(image);
    save_image(image, filename);
    free_image(image);

    return 0;
}
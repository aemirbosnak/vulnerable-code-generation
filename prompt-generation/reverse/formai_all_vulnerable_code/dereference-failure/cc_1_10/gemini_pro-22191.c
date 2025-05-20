//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct pixel {
    unsigned char r, g, b;
};

struct image {
    int width, height;
    struct pixel *data;
};

struct image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    struct image *image = malloc(sizeof(struct image));

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->data = malloc(image->width * image->height * sizeof(struct pixel));
    fread(image->data, sizeof(struct pixel), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void save_image(const char *filename, struct image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, sizeof(struct pixel), image->width * image->height, fp);

    fclose(fp);
}

void invert_image(struct image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

int main() {
    struct image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    invert_image(image);

    save_image("inverted.bmp", image);

    free(image->data);
    free(image);

    return 0;
}
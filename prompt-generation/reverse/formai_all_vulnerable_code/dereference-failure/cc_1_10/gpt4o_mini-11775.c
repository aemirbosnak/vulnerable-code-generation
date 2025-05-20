//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Reading the header
    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported image format\n");
        fclose(file);
        return NULL;
    }

    int width, height, max_color;
    fscanf(file, "%d %d %d", &width, &height, &max_color);
    fgetc(file);  // Consume the newline character after max_color

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    invert_colors(img);
    save_image(argv[2], img);
    free_image(img);

    printf("Image processing complete. Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}
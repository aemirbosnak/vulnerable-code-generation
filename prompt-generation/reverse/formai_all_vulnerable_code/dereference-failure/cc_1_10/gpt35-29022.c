//FormAI DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pixel {
    int r, g, b;
};

struct Image {
    int width, height;
    struct Pixel *data;
};

void load_image(struct Image *img, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int width, height;
    fscanf(fp, "%d %d", &width, &height);
    img->width = width;
    img->height = height;

    img->data = malloc(sizeof(struct Pixel) * width * height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r, g, b;
            fscanf(fp, "%d %d %d", &r, &g, &b);
            struct Pixel px = {r, g, b};
            img->data[y * width + x] = px;
        }
    }

    fclose(fp);
}

void save_image(struct Image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%d %d\n", img->width, img->height);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            struct Pixel px = img->data[y * img->width + x];
            fprintf(fp, "%d %d %d ", px.r, px.g, px.b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void invert_colors(struct Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            struct Pixel *px = &img->data[y * img->width + x];
            px->r = 255 - px->r;
            px->g = 255 - px->g;
            px->b = 255 - px->b;
        }
    }
}

int main(int argc, char **argv) {
    printf("Starting C Image Editor...\n");

    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <operation>\n", argv[0]);
        exit(1);
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char *operation = argv[3];

    printf("Loading image %s...\n", input_filename);
    struct Image img;
    load_image(&img, input_filename);

    if (strcmp(operation, "invert") == 0) {
        printf("Inverting colors...\n");
        invert_colors(&img);
    } else {
        printf("Unknown operation: %s\n", operation);
        exit(1);
    }

    printf("Saving image to %s...\n", output_filename);
    save_image(&img, output_filename);

    printf("Done!\n");
    return 0;
}
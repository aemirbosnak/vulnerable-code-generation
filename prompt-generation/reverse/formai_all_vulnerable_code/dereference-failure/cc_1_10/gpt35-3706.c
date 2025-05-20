//FormAI DATASET v1.0 Category: Image Editor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct color {
    unsigned char r, g, b;
};

struct image {
    int width, height;
    struct color **pixels;
};

// Function to allocate memory for an image
struct image *create_image(int width, int height) {
    struct image *img = malloc(sizeof(struct image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(height * sizeof(struct color *));
    for (int i = 0; i < height; i++) {
        img->pixels[i] = calloc(width, sizeof(struct color));
    }
    return img;
}

// Function to destroy an image and free its memory
void destroy_image(struct image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

// Function to read an image from a file
struct image *read_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    struct image *img = create_image(width, height);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            unsigned char r, g, b;
            fscanf(file, "%hhu %hhu %hhu", &r, &g, &b);
            img->pixels[row][col].r = r;
            img->pixels[row][col].g = g;
            img->pixels[row][col].b = b;
        }
    }
    fclose(file);
    return img;
}

// Function to write an image to a file
void write_image(char *filename, struct image *img) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", filename);
        return;
    }
    fprintf(file, "%d %d\n", img->width, img->height);
    for (int row = 0; row < img->height; row++) {
        for (int col = 0; col < img->width; col++) {
            fprintf(file, "%hhu %hhu %hhu ", img->pixels[row][col].r,
                    img->pixels[row][col].g, img->pixels[row][col].b);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Function to get the color of a pixel in an image
struct color get_pixel_color(struct image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        fprintf(stderr, "Error: pixel (%d,%d) is out of range\n", x, y);
        exit(1);
    }
    return img->pixels[y][x];
}

// Function to set the color of a pixel in an image
void set_pixel_color(struct image *img, int x, int y, struct color color) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        fprintf(stderr, "Error: pixel (%d,%d) is out of range\n", x, y);
        exit(1);
    }
    img->pixels[y][x] = color;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s infile outfile\n", argv[0]);
        return 1;
    }
    struct image *img = read_image(argv[1]);
    // Do some image processing here...
    set_pixel_color(img, 0, 0, (struct color){0, 0, 0});  // Set pixel (0,0) to black
    write_image(argv[2], img);
    destroy_image(img);
    return 0;
}
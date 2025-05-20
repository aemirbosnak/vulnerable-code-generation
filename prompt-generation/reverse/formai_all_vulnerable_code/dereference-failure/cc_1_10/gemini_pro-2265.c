//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel {
    unsigned char r, g, b;
} pixel;

typedef struct image {
    int width, height;
    pixel *data;
} image;

image *create_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void set_pixel(image *img, int x, int y, pixel color) {
    img->data[y * img->width + x] = color;
}

pixel get_pixel(image *img, int x, int y) {
    return img->data[y * img->width + x];
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

int main() {
    image *img = create_image(512, 512);

    // Draw a circle
    for (int x = 0; x < img->width; x++) {
        for (int y = 0; y < img->height; y++) {
            int dx = x - img->width / 2;
            int dy = y - img->height / 2;
            if (dx * dx + dy * dy < img->width * img->height / 4) {
                set_pixel(img, x, y, (pixel){255, 255, 255});
            }
        }
    }

    // Draw a line
    for (int x = 0; x < img->width; x++) {
        set_pixel(img, x, img->height / 2, (pixel){0, 0, 0});
    }

    // Draw a rectangle
    for (int x = 0; x < img->width / 2; x++) {
        for (int y = 0; y < img->height / 2; y++) {
            set_pixel(img, x, y, (pixel){0, 255, 0});
        }
    }

    // Save the image
    save_image(img, "pixel_art.ppm");

    free_image(img);

    return 0;
}
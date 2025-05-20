//FormAI DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel {
    int red;
    int green;
    int blue;
} pixel;

typedef struct image {
    pixel *pixels;
    int width;
    int height;
} image;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void grayscale(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        int gray = (img->pixels[i].red + img->pixels[i].green + img->pixels[i].blue) / 3;
        img->pixels[i].red = gray;
        img->pixels[i].green = gray;
        img->pixels[i].blue = gray;
    }
}

void invert(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].red = 255 - img->pixels[i].red;
        img->pixels[i].green = 255 - img->pixels[i].green;
        img->pixels[i].blue = 255 - img->pixels[i].blue;
    }
}

void blur(image *img) {
    pixel *new_pixels = calloc(img->width * img->height, sizeof(pixel));
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int total_red = 0, total_green = 0, total_blue = 0, count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int new_i = i + k, new_j = j + l;
                    if (new_i >= 0 && new_i < img->height && new_j >= 0 && new_j < img->width) {
                        total_red += img->pixels[new_i * img->width + new_j].red;
                        total_green += img->pixels[new_i * img->width + new_j].green;
                        total_blue += img->pixels[new_i * img->width + new_j].blue;
                        count++;
                    }
                }
            }
            new_pixels[i * img->width + j].red = total_red / count;
            new_pixels[i * img->width + j].green = total_green / count;
            new_pixels[i * img->width + j].blue = total_blue / count;
        }
    }
    free(img->pixels);
    img->pixels = new_pixels;
}

void save_image(image *img, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    fwrite(img->pixels, sizeof(pixel), img->width * img->height, file);
    fclose(file);
}

int main() {
    image img;
    img.width = 512;
    img.height = 512;
    img.pixels = calloc(img.width * img.height, sizeof(pixel));

    // Draw a square in the middle of the image
    for (int i = 128; i < 384; i++) {
        for (int j = 128; j < 384; j++) {
            img.pixels[i * img.width + j].red = 255;
            img.pixels[i * img.width + j].green = 0;
            img.pixels[i * img.width + j].blue = 0;
        }
    }

    // Convert to grayscale
    grayscale(&img);

    // Invert colors
    invert(&img);

    // Apply blur
    blur(&img);

    // Save the image
    save_image(&img, "example.ppm");

    free(img.pixels);
    return 0;
}
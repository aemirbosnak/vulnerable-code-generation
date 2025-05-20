//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P6\n%d %d\n255\n", &img->width, &img->height);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->data, img->width * img->height * sizeof(pixel), 1, fp);
    fclose(fp);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

char *ascii_art(image *img) {
    int width = img->width;
    int height = img->height;

    // Create a 2D array of characters to store the ASCII art.
    char **art = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        art[i] = malloc(width * sizeof(char));
    }

    // Convert each pixel to an ASCII character.
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel p = img->data[y * width + x];
            float gray = (p.r + p.g + p.b) / 3.0 / 255.0;
            art[y][x] = " .,-~;+=*#%@"; // Replace with your own character set
        }
    }

    // Convert the 2D array of characters to a single string.
    char *str = malloc((width + 1) * height * sizeof(char));
    int k = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            str[k++] = art[y][x];
        }
        str[k++] = '\n';
    }

    // Free the memory allocated for the 2D array of characters.
    for (int i = 0; i < height; i++) {
        free(art[i]);
    }
    free(art);

    return str;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    char *art = ascii_art(img);
    printf("%s", art);

    free_image(img);
    free(art);

    return 0;
}
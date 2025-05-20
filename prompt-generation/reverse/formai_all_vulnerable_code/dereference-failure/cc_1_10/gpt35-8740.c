//FormAI DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255

typedef struct {
    int r;
    int g;
    int b;
} pixel;

typedef struct {
    int width;
    int height;
    pixel** pixels;
} image;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

image* init_image(int w, int h) {
    image* img = malloc(sizeof(image));
    img->width = w;
    img->height = h;
    img->pixels = malloc(sizeof(pixel*) * h);
    for (int i = 0; i < h; i++) {
        img->pixels[i] = malloc(sizeof(pixel) * w);
        memset(img->pixels[i], 0, sizeof(pixel) * w);
    }
    return img;
}

image* load_image(char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        error("Could not open file");
    }
    char format[3];
    int width, height, maxval;
    if (fscanf(f, "%2s\n%d %d\n%d\n", format, &width, &height, &maxval) != 4) {
        error("Invalid image format");
    }
    if (strcmp(format, "P3") != 0) {
        error("Unsupported format");
    }
    if (maxval != MAX_COLOR_VALUE) {
        error("Unsupported color depth");
    }
    image* img = init_image(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r, g, b;
            if (fscanf(f, "%d %d %d", &r, &g, &b) != 3) {
                error("Invalid color value");
            }
            img->pixels[i][j].r = r;
            img->pixels[i][j].g = g;
            img->pixels[i][j].b = b;
        }
    }
    fclose(f);
    return img;
}

void save_image(char* filename, image* img) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        error("Could not open file");
    }
    fprintf(f, "P3\n%d %d\n%d\n", img->width, img->height, MAX_COLOR_VALUE);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel p = img->pixels[i][j];
            fprintf(f, "%d %d %d ", p.r, p.g, p.b);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void apply_filter(image* img, int** filter, int filter_size) {
    int padding = filter_size / 2;
    image* temp = init_image(img->width + padding * 2, img->height + padding * 2);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            temp->pixels[i + padding][j + padding] = img->pixels[i][j];
        }
    }
    for (int i = padding; i < temp->height - padding; i++) {
        for (int j = padding; j < temp->width - padding; j++) {
            int r = 0, g = 0, b = 0;
            for (int k = 0; k < filter_size; k++) {
                for (int l = 0; l < filter_size; l++) {
                    r += temp->pixels[i + k - padding][j + l - padding].r * filter[k][l];
                    g += temp->pixels[i + k - padding][j + l - padding].g * filter[k][l];
                    b += temp->pixels[i + k - padding][j + l - padding].b * filter[k][l];
                }
            }
            if (r < 0) {
                r = 0;
            }
            if (g < 0) {
                g = 0;
            }
            if (b < 0) {
                b = 0;
            }
            if (r > MAX_COLOR_VALUE) {
                r = MAX_COLOR_VALUE;
            }
            if (g > MAX_COLOR_VALUE) {
                g = MAX_COLOR_VALUE;
            }
            if (b > MAX_COLOR_VALUE) {
                b = MAX_COLOR_VALUE;
            }
            img->pixels[i - padding][j - padding].r = r;
            img->pixels[i - padding][j - padding].g = g;
            img->pixels[i - padding][j - padding].b = b;
        }
    }
    for (int i = 0; i < temp->height; i++) {
        free(temp->pixels[i]);
    }
    free(temp->pixels);
    free(temp);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        error("Usage: image_editor filter_size input_file output_file");
    }
    int filter_size = atoi(argv[1]);
    if (filter_size % 2 != 1 || filter_size < 3 || filter_size > 15) {
        error("Invalid filter size");
    }
    image* img = load_image(argv[2]);
    int** filter = malloc(sizeof(int*) * filter_size);
    for (int i = 0; i < filter_size; i++) {
        filter[i] = malloc(sizeof(int) * filter_size);
    }
    for (int i = 0; i < filter_size; i++) {
        for (int j = 0; j < filter_size; j++) {
            if (scanf("%d", &filter[i][j]) != 1) {
                error("Invalid filter");
            }
        }
    }
    apply_filter(img, filter, filter_size);
    save_image(argv[3], img);
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
    for (int i = 0; i < filter_size; i++) {
        free(filter[i]);
    }
    free(filter);
    return 0;
}
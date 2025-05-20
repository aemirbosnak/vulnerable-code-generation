//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel image[WIDTH][HEIGHT];

void load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fread(image, sizeof(pixel), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void save_image(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(image, sizeof(pixel), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void invert_colors() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j].r = 255 - image[i][j].r;
            image[i][j].g = 255 - image[i][j].g;
            image[i][j].b = 255 - image[i][j].b;
        }
    }
}

void grayscale() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            unsigned char gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = gray;
            image[i][j].g = gray;
            image[i][j].b = gray;
        }
    }
}

void blur() {
    pixel blurred[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            blurred[i][j].r = 0;
            blurred[i][j].g = 0;
            blurred[i][j].b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < WIDTH && j + l >= 0 && j + l < HEIGHT) {
                        blurred[i][j].r += image[i + k][j + l].r;
                        blurred[i][j].g += image[i + k][j + l].g;
                        blurred[i][j].b += image[i + k][j + l].b;
                    }
                }
            }
            blurred[i][j].r /= 9;
            blurred[i][j].g /= 9;
            blurred[i][j].b /= 9;
        }
    }
    memcpy(image, blurred, sizeof(pixel) * WIDTH * HEIGHT);
}

void sharpen() {
    pixel sharpened[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            sharpened[i][j].r = 0;
            sharpened[i][j].g = 0;
            sharpened[i][j].b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < WIDTH && j + l >= 0 && j + l < HEIGHT) {
                        sharpened[i][j].r += image[i + k][j + l].r * (1 - (k == 0 && l == 0));
                        sharpened[i][j].g += image[i + k][j + l].g * (1 - (k == 0 && l == 0));
                        sharpened[i][j].b += image[i + k][j + l].b * (1 - (k == 0 && l == 0));
                    }
                }
            }
            sharpened[i][j].r += image[i][j].r * 9;
            sharpened[i][j].g += image[i][j].g * 9;
            sharpened[i][j].b += image[i][j].b * 9;
            sharpened[i][j].r /= 10;
            sharpened[i][j].g /= 10;
            sharpened[i][j].b /= 10;
        }
    }
    memcpy(image, sharpened, sizeof(pixel) * WIDTH * HEIGHT);
}

void edge_detection() {
    pixel edges[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            edges[i][j].r = 0;
            edges[i][j].g = 0;
            edges[i][j].b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < WIDTH && j + l >= 0 && j + l < HEIGHT) {
                        edges[i][j].r += image[i + k][j + l].r * (k == 0 ? 0 : 1);
                        edges[i][j].g += image[i + k][j + l].g * (k == 0 ? 0 : 1);
                        edges[i][j].b += image[i + k][j + l].b * (k == 0 ? 0 : 1);
                    }
                }
            }
            edges[i][j].r += image[i][j].r * (-4);
            edges[i][j].g += image[i][j].g * (-4);
            edges[i][j].b += image[i][j].b * (-4);
            edges[i][j].r /= 6;
            edges[i][j].g /= 6;
            edges[i][j].b /= 6;
        }
    }
    memcpy(image, edges, sizeof(pixel) * WIDTH * HEIGHT);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> <output image> [operation]\n", argv[0]);
        exit(1);
    }

    load_image(argv[1]);

    if (argc >= 4) {
        if (strcmp(argv[3], "invert") == 0) {
            invert_colors();
        } else if (strcmp(argv[3], "grayscale") == 0) {
            grayscale();
        } else if (strcmp(argv[3], "blur") == 0) {
            blur();
        } else if (strcmp(argv[3], "sharpen") == 0) {
            sharpen();
        } else if (strcmp(argv[3], "edge_detection") == 0) {
            edge_detection();
        }
    }

    save_image(argv[2]);

    return 0;
}
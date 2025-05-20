//FormAI DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

struct Image {
    int width;
    int height;
    int* pixels;
};

void createImage(struct Image* image, int width, int height) {
    image->width = width;
    image->height = height;
    image->pixels = (int*)malloc(sizeof(int) * width * height);
}

void destroyImage(struct Image* image) {
    free(image->pixels);
}

void setPixel(struct Image* image, int x, int y, int color) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->pixels[y * image->width + x] = color;
    }
}

int getPixel(struct Image* image, int x, int y) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        return image->pixels[y * image->width + x];
    }
    return -1;
}

void saveImage(struct Image* image, char* filename) {
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int pixel = getPixel(image, x, y);
            int r = (pixel >> 16) & 255;
            int g = (pixel >> 8) & 255;
            int b = pixel & 255;
            fprintf(fp, "%d %d %d ", r, g, b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

struct Image* loadImage(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }
    char format[3];
    int width, height;
    fscanf(fp, "%s\n%d %d\n", format, &width, &height);
    if (strcmp(format, "P3") != 0) {
        return NULL;
    }
    struct Image* image = malloc(sizeof(struct Image));
    createImage(image, width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r, g, b;
            fscanf(fp, "%d %d %d ", &r, &g, &b);
            setPixel(image, x, y, (r << 16) | (g << 8) | b);
        }
    }
    fclose(fp);
    return image;
}

void drawLine(struct Image* image, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = -abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;
    while (1) {
        setPixel(image, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void applyFilter(struct Image* image, float filter[3][3]) {
    struct Image copy;
    createImage(&copy, image->width, image->height);
    memcpy(copy.pixels, image->pixels, sizeof(int) * image->width * image->height);

    for (int y = 1; y < image->height - 1; y++) {
        for (int x = 1; x < image->width - 1; x++) {
            float sum_red = 0;
            float sum_green = 0;
            float sum_blue = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixel = getPixel(&copy, x + kx, y + ky);
                    float weight = filter[ky + 1][kx + 1];
                    sum_red += weight * ((pixel >> 16) & 255);
                    sum_green += weight * ((pixel >> 8) & 255);
                    sum_blue += weight * (pixel & 255);
                }
            }
            int new_red = (int)sum_red;
            int new_green = (int)sum_green;
            int new_blue = (int)sum_blue;
            setPixel(image, x, y, (new_red << 16) | (new_green << 8) | new_blue);
        }
    }

    destroyImage(&copy);
}

int main() {
    int width = 500;
    int height = 500;
    struct Image image;
    createImage(&image, width, height);
    for (int i = 0; i < height; i++) {
        drawLine(&image, 0, i, width - 1, i, (i % 2 == 0) ? 0xffffff : 0x444444);
    }
    applyFilter(&image, (float[][3]){{0.1, 0.1, 0.1}, {0.1, 0.2, 0.1}, {0.1, 0.1, 0.1}});
    saveImage(&image, "output.ppm");
    destroyImage(&image);
    return 0;
}
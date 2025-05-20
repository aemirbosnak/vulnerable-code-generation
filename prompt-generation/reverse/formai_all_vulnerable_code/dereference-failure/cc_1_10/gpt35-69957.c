//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

RGB** readPPM(const char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: failed to open file\n");
        return NULL;
    }

    char magic[3];
    fscanf(fp, "%s\n", magic);
    if (magic[0] != 'P' || magic[1] != '6') {
        printf("Error: invalid PPM file format\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%d %d\n", width, height);
    int max_value;
    fscanf(fp, "%d\n", &max_value);
    if (max_value != 255) {
        printf("Error: unsupported PPM file format\n");
        fclose(fp);
        return NULL;
    }

    RGB** image = (RGB**)malloc(*height * sizeof(RGB*));
    for (int y = 0; y < *height; y++) {
        image[y] = (RGB*)malloc(*width * sizeof(RGB));
        fread(image[y], sizeof(RGB), *width, fp);
    }

    fclose(fp);
    return image;
}

void writePPM(const char* filename, RGB** image, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: failed to create file\n");
        return;
    }

    fprintf(fp, "P6\n%d %d\n%d\n", width, height, 255);
    for (int y = 0; y < height; y++) {
        fwrite(image[y], sizeof(RGB), width, fp);
    }

    fclose(fp);
}

void flipImage(RGB** image, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            RGB temp = image[y][x];
            image[y][x] = image[height - y - 1][x];
            image[height - y - 1][x] = temp;
        }
    }
}

void changeBrightness(RGB** image, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = (int)image[y][x].r + brightness;
            int g = (int)image[y][x].g + brightness;
            int b = (int)image[y][x].b + brightness;

            if (r < 0) r = 0;
            if (r > 255) r = 255;
            if (g < 0) g = 0;
            if (g > 255) g = 255;
            if (b < 0) b = 0;
            if (b > 255) b = 255;

            image[y][x].r = (unsigned char)r;
            image[y][x].g = (unsigned char)g;
            image[y][x].b = (unsigned char)b;
        }
    }
}

void changeContrast(RGB** image, int width, int height, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = (int)image[y][x].r;
            int g = (int)image[y][x].g;
            int b = (int)image[y][x].b;

            r = (int)(factor * (r - 128) + 128);
            g = (int)(factor * (g - 128) + 128);
            b = (int)(factor * (b - 128) + 128);

            if (r < 0) r = 0;
            if (r > 255) r = 255;
            if (g < 0) g = 0;
            if (g > 255) g = 255;
            if (b < 0) b = 0;
            if (b > 255) b = 255;

            image[y][x].r = (unsigned char)r;
            image[y][x].g = (unsigned char)g;
            image[y][x].b = (unsigned char)b;
        }
    }
}

int main() {
    int width, height;
    RGB** image = readPPM("input.ppm", &width, &height);
    if (!image) {
        return 1;
    }

    flipImage(image, width, height);
    changeBrightness(image, width, height, 50);
    changeContrast(image, width, height, 100.0);

    writePPM("output.ppm", image, width, height);

    for (int y = 0; y < height; y++) {
        free(image[y]);
    }
    free(image);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define CHANNELS 3

unsigned char *pixels;
int width, height;

void read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("failed to open image file");
        exit(1);
    }
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    pixels = malloc(width * height * CHANNELS);
    fread(pixels, sizeof(unsigned char), width * height * CHANNELS, fp);
    fclose(fp);
}

void write_image(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("failed to open image file");
        exit(1);
    }
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(pixels, sizeof(unsigned char), width * height * CHANNELS, fp);
    fclose(fp);
}

void invert_colors() {
    for (int i = 0; i < width * height * CHANNELS; i++) {
        pixels[i] = 255 - pixels[i];
    }
}

void sepia() {
    for (int i = 0; i < width * height * CHANNELS; i += CHANNELS) {
        unsigned char r = pixels[i];
        unsigned char g = pixels[i + 1];
        unsigned char b = pixels[i + 2];
        pixels[i] = (r * 0.393 + g * 0.769 + b * 0.189);
        pixels[i + 1] = (r * 0.349 + g * 0.686 + b * 0.168);
        pixels[i + 2] = (r * 0.272 + g * 0.534 + b * 0.131);
    }
}

void blur() {
    unsigned char *new_pixels = malloc(width * height * CHANNELS);
    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            for (int c = 0; c < CHANNELS; c++) {
                int sum = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        sum += pixels[(i + k) * width + (j + l) * CHANNELS + c];
                    }
                }
                new_pixels[i * width + j * CHANNELS + c] = sum / 9;
            }
        }
    }
    memcpy(pixels, new_pixels, width * height * CHANNELS);
    free(new_pixels);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }
    read_image(argv[1]);
    invert_colors();
    sepia();
    blur();
    write_image(argv[2]);
    free(pixels);
    return 0;
}
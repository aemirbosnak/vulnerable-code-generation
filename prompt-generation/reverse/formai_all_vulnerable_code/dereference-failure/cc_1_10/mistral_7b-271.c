//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 64
#define HEIGHT 16

typedef struct {
    unsigned char r, g, b;
} Pixel;

void write_file(const char* filename, const Pixel* img, int width, int height) {
    FILE* fp = fopen(filename, "w");

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel pixel = img[y * width + x];
            fprintf(fp, "\033[%d;%dH%c", y + 1, x + 1,
                    (pixel.r > 128 ? ':' : ' ')|(pixel.g > 128 ? ':' : ' ')|(pixel.b > 128 ? ':' : ' '));
        }
        fprintf(fp, "\033[2K\n");
    }

    fclose(fp);
}

void read_image(const char* filename, Pixel* img, int width, int height) {
    FILE* fp = fopen(filename, "r");

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int c = getc(fp);
            img[y * width + x].r = c > ' ' && c < ':' ? c - ' ' : 255;
            c = getc(fp);
            img[y * width + x].g = c > ' ' && c < ':' ? c - ' ' : 255;
            c = getc(fp);
            img[y * width + x].b = c > ' ' && c < ':' ? c - ' ' : 255;
        }
        getc(fp); // consume newline
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image.pgm> <output_ascii_art.txt>\n", argv[0]);
        return 1;
    }

    Pixel* img = malloc(WIDTH * HEIGHT * sizeof(Pixel));
    read_image(argv[1], img, WIDTH, HEIGHT);

    write_file(argv[2], img, WIDTH, HEIGHT);

    free(img);
    return 0;
}
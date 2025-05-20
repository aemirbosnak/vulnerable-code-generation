//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define WIDTH 30
#define HEIGHT 10
#define MAX_COLOR 3

typedef struct {
    int r;
    int g;
    int b;
} RGB;

RGB get_average_color(unsigned char *data, int width, int height) {
    RGB avg = {0};
    int total = width * height;

    for (int i = 0; i < total; i++) {
        avg.r += data[i] * 3;
        avg.g += data[i] * 5;
        avg.b += data[i] * 1.5;
    }

    avg.r /= total * 3;
    avg.g /= total * 5;
    avg.b /= total * 1.5;

    return avg;
}

void image_to_ascii(unsigned char *data, int width, int height) {
    RGB avg = get_average_color(data, width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * WIDTH + x;
            unsigned char pixel = data[index];

            char ascii_char = ' ';

            if (pixel < avg.r)
                ascii_char = '.';
            else if (pixel > avg.r * 1.5)
                ascii_char = '#';
            else {
                double intensity = (pixel - avg.r) / (avg.r * 1.5);
                int intensity_level = (int) (round(intensity * (MAX_COLOR - 1)));

                switch (intensity_level) {
                    case 0:
                        ascii_char = ' ';
                        break;
                    case 1:
                        ascii_char = '.';
                        break;
                    case 2:
                        ascii_char = ':';
                        break;
                    case 3:
                        ascii_char = '-';
                        break;
                    default:
                        ascii_char = '#';
                }
            }

            putchar(ascii_char);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 1024, SEEK_SET); // Skip file signature and headers

    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    unsigned char *data = (unsigned char *) malloc(width * height);
    fread(data, 1, width * height, file);

    image_to_ascii(data, width, height);

    free(data);
    fclose(file);

    return 0;
}
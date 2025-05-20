//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_IMAGE_SIZE 1024 * 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image;

image read_pgm(const char *filename);
void write_ascii(const image img, const char *output);
void convert_pixel_to_ascii(unsigned char pixel);

image read_pgm(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    char magic_number[3];
    int width, height, max_pixel;

    fgets(magic_number, sizeof(magic_number), fp);
    sscanf(magic_number, "P5%d %d%n", &width, &height, NULL);

    image img;
    img.width = width;
    img.height = height;

    img.data = malloc(width * height);

    fread(img.data, 1, width * height, fp);
    fclose(fp);

    for (int i = 0; i < 255; i++) {
        if (i == img.data[0]) {
            max_pixel = i;
            break;
        }
    }

    return img;
}

void write_ascii(const image img, const char *output) {
    FILE *fp = fopen(output, "w");

    fprintf(fp, "P5\n%d %d\n255\n", img.width, img.height);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            unsigned char pixel = img.data[y * img.width + x];
            convert_pixel_to_ascii(pixel);
            fputc('\n', fp);

            for (int i = 0; i < 5; i++)
                putchar(i < 3 ? (pixel > i ? '#' : ' ') : (pixel > (255 - i) ? '#' : ' '));
        }
    }

    fclose(fp);
}

void convert_pixel_to_ascii(unsigned char pixel) {
    const char *ascii_chars = "  .:!*oe%$#@";

    for (int i = 0; i < 16; i++) {
        if (pixel < (i + 1) * 16) {
            putchar(ascii_chars[i]);
            return;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_pgm> <output_ascii>\n", argv[0]);
        return 1;
    }

    image img = read_pgm(argv[1]);
    write_ascii(img, argv[2]);

    free(img.data);
    return 0;
}
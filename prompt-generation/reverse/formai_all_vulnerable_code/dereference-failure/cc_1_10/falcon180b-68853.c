//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 60

typedef struct {
    char *data;
    int width;
    int height;
} Image;

typedef struct {
    char *data;
    int width;
    int height;
} ASCIIArt;

void print_ascii_art(const ASCIIArt *art) {
    int x, y;
    for (y = 0; y < art->height; ++y) {
        for (x = 0; x < art->width; ++x) {
            printf("%c", art->data[y * art->width + x]);
        }
        printf("\n");
    }
}

int get_pixel_value(const Image *image, int x, int y) {
    int index = y * image->width + x;
    return image->data[index];
}

void convert_image_to_ascii_art(const Image *image, ASCIIArt *art) {
    int x, y;
    for (y = 0; y < image->height; ++y) {
        for (x = 0; x < image->width; ++x) {
            int pixel_value = get_pixel_value(image, x, y);
            char ascii_char = (pixel_value / 16) + '0';
            art->data[y * art->width + x] = ascii_char;
        }
    }
}

int main() {
    Image image = {
       .data = "P6\n"
                "WIDTH HEIGHT\n"
                "255\n"
                "0123456789ABCDEF\n",
       .width = WIDTH,
       .height = HEIGHT
    };

    ASCIIArt ascii_art = {0};
    convert_image_to_ascii_art(&image, &ascii_art);

    print_ascii_art(&ascii_art);

    return 0;
}
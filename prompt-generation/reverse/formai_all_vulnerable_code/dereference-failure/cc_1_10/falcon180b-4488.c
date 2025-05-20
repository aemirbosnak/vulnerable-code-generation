//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

struct pixel {
    char character;
    int red;
    int green;
    int blue;
};

struct image {
    struct pixel *data;
    int width;
    int height;
};

void create_image(struct image *image, int width, int height) {
    image->data = malloc(sizeof(struct pixel) * width * height);
    image->width = width;
    image->height = height;
}

void destroy_image(struct image *image) {
    free(image->data);
}

void set_pixel(struct image *image, int x, int y, char character, int red, int green, int blue) {
    int index = y * image->width + x;
    struct pixel *pixel = &image->data[index];
    pixel->character = character;
    pixel->red = red;
    pixel->green = green;
    pixel->blue = blue;
}

void print_image(const struct image *image) {
    for (int y = 0; y < image->height; ++y) {
        for (int x = 0; x < image->width; ++x) {
            struct pixel pixel = image->data[y * image->width + x];
            printf("%c", pixel.character);
        }
        printf("\n");
    }
}

int main() {
    struct image image;
    create_image(&image, MAX_WIDTH, MAX_HEIGHT);

    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    char line[MAX_WIDTH];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < strlen(line); ++i) {
            char character = toupper(line[i]);
            int red = (character & 0x07) * 85;
            int green = (character & 0x38) >> 3;
            int blue = (character & 0xC0) >> 6;
            set_pixel(&image, x, y, character, red, green, blue);
            if (++x >= image.width) {
                x = 0;
                ++y;
            }
        }
    }

    fclose(file);

    print_image(&image);

    destroy_image(&image);

    return 0;
}
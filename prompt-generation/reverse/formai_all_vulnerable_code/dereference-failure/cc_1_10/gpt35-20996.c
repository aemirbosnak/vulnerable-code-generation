//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

typedef struct {
    int width;
    int height;
    char **data;
} Image;

Image *create_image(int width, int height) {
    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (char**) malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        image->data[i] = (char*) malloc(sizeof(char) * (width + 1));
        for (int j = 0; j < width; j++) {
            image->data[i][j] = ' ';
        }
        image->data[i][width] = '\0';
    }
    return image;
}

void destroy_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void draw_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        printf("%s\n", image->data[i]);
    }
}

void convert_to_ascii(Image *image) {
    char ascii_chars[] = " .,:;ox%#@";
    int num_chars = sizeof(ascii_chars) - 1;
    int brightness[num_chars];
    for (int i = 0; i < num_chars; i++) {
        brightness[i] = (255 * i) / (num_chars - 1);
    }
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int brightness_index = (int) ((image->data[i][j] & 0xFF) * num_chars / 256);
            brightness_index = brightness_index >= num_chars ? num_chars - 1 : brightness_index;
            image->data[i][j] = ascii_chars[brightness_index];
        }
    }
}

int main() {
    Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->data[i][j] = ((i * image->width) + j) % 256;
        }
    }
    convert_to_ascii(image);
    draw_image(image);
    destroy_image(image);
    return 0;
}
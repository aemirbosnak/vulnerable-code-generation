//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *image_new(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    memset(image->data, ' ', width * height);
    return image;
}

void image_free(Image *image) {
    free(image->data);
    free(image);
}

void image_set_pixel(Image *image, int x, int y, char c) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = c;
}

void image_draw_text(Image *image, int x, int y, const char *text) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        image_set_pixel(image, x + i, y, text[i]);
    }
}

void image_print(Image *image) {
    int i;
    for (i = 0; i < image->height; i++) {
        printf("%s\n", image->data + i * image->width);
    }
}

int main() {
    Image *image = image_new(MAX_WIDTH, MAX_HEIGHT);
    image_draw_text(image, 10, 10, "Brave New World");
    image_print(image);
    image_free(image);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(char) * width);
        memset(image->pixels[i], ' ', width);
    }
    return image;
}

void destroy_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void draw_text(Image *image, int x, int y, const char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        image->pixels[y][x + i] = text[i];
    }
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        printf("%s\n", image->pixels[i]);
    }
}

int main() {
    Image *image = create_image(MAX_WIDTH, 20);

    draw_text(image, 10, 10, "ASCII Art Generator");
    draw_text(image, 10, 12, "Enter your text:");

    char text[MAX_WIDTH];
    scanf("%s", text);

    draw_text(image, 10, 14, text);

    print_image(image);

    destroy_image(image);

    return 0;
}
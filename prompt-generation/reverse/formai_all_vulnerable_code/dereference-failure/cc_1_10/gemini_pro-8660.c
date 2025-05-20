//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

typedef struct {
    int width;
    int height;
    char **data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(width + 1);
        memset(image->data[i], ' ', width);
        image->data[i][width] = '\0';
    }
    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        printf("%s\n", image->data[i]);
    }
}

int main() {
    char *text = "Hello, world!";
    int width = strlen(text);
    int height = 1;

    Image *image = new_image(width, height);

    for (int i = 0; i < width; i++) {
        image->data[0][i] = text[i];
    }

    print_image(image);

    free_image(image);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void read_image(Image *image, FILE *file) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fscanf(file, "%c", &image->data[i * image->width + j]);
        }
    }
}

void write_image(Image *image, FILE *file) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fprintf(file, "%c", image->data[i * image->width + j]);
        }
    }
}

Image *text_to_ascii_art(char *text, int width, int height) {
    Image *image = new_image(width, height);

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i < strlen(text)) {
                image->data[i * image->width + j] = text[i];
            } else {
                image->data[i * image->width + j] = ' ';
            }
        }
    }

    return image;
}

int main() {
    char *text = "Hello, world!";
    int width = 10;
    int height = 5;

    Image *image = text_to_ascii_art(text, width, height);

    FILE *file = fopen("output.txt", "w");
    write_image(image, file);
    fclose(file);

    free_image(image);

    return 0;
}
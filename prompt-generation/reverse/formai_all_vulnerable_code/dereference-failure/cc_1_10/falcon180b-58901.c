//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_CHARS 1000

typedef struct {
    char *filename;
    char *data;
    int width;
    int height;
    int chars;
} Image;

char *load_image_data(Image *image) {
    FILE *fp = fopen(image->filename, "rb");
    if (fp == NULL) {
        printf("Error loading image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *data = malloc(size + 1);
    fread(data, size, 1, fp);
    fclose(fp);

    data[size] = '\0';
    image->data = data;
    return data;
}

void count_chars(Image *image) {
    int count = 0;
    char *data = image->data;
    while (*data) {
        if (isprint(*data)) {
            count++;
        }
        data++;
    }
    image->chars = count;
}

void print_ascii_art(Image *image) {
    int x, y;
    char *data = image->data;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            char c = *data++;
            if (c == '\n') {
                printf("\n");
            } else if (isprint(c)) {
                int color = c % 32;
                printf("\x1b[38;5;%dm%c", color, c);
            }
        }
        printf("\n");
    }
}

int main() {
    Image image;
    image.filename = "example.jpg";
    image.data = NULL;
    image.width = 0;
    image.height = 0;
    image.chars = 0;

    load_image_data(&image);
    count_chars(&image);

    printf("Image name: %s\n", image.filename);
    printf("Width: %d\n", image.width);
    printf("Height: %d\n", image.height);
    printf("Chars: %d\n", image.chars);

    print_ascii_art(&image);

    free(image.data);
    return 0;
}
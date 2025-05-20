//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int max_color;
    char* image;
} Image;

Image* create_image(int width, int height, int max_color) {
    Image* image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->max_color = max_color;
    image->image = (char*)malloc(width * height * max_color * sizeof(char));
    return image;
}

void display_image(Image* image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%c", image->image[i * image->width + j]);
        }
        printf("\n");
    }
}

void set_pixel(Image* image, int x, int y, int color) {
    if (x < 0 || y < 0 || x >= image->width || y >= image->height) {
        printf("Invalid coordinates!\n");
        return;
    }
    if (color < 0 || color >= image->max_color) {
        printf("Invalid color value!\n");
        return;
    }
    image->image[y * image->width + x] = (char)color;
}

int main() {
    Image* image = create_image(100, 100, 256);

    set_pixel(image, 50, 50, 255);
    set_pixel(image, 75, 75, 128);
    set_pixel(image, 25, 25, 0);

    display_image(image);

    free(image->image);
    free(image);

    return 0;
}
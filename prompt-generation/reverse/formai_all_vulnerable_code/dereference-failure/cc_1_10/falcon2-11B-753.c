//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int height;
    int width;
    char* pixels;
} Image;

void create_image(Image* image, int height, int width) {
    image->height = height;
    image->width = width;
    image->pixels = malloc(height * width * sizeof(char));
}

void free_image(Image* image) {
    free(image->pixels);
}

void print_image(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image->pixels[y * image->width + x]);
        }
        printf("\n");
    }
}

int main() {
    Image* image = malloc(sizeof(Image));
    create_image(image, 10, 10);

    image->pixels[0] = 'A';
    image->pixels[1] = 'B';
    image->pixels[2] = 'C';
    image->pixels[3] = 'D';
    image->pixels[4] = 'E';
    image->pixels[5] = 'F';
    image->pixels[6] = 'G';
    image->pixels[7] = 'H';
    image->pixels[8] = 'I';
    image->pixels[9] = 'J';

    printf("Original Image: \n");
    print_image(image);

    free_image(image);

    return 0;
}
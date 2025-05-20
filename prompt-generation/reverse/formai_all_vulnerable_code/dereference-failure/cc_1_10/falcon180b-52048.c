//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

void print_ascii_art(const image_t *image) {
    int x, y;
    for (y = 0; y < image->height; ++y) {
        for (x = 0; x < image->width; ++x) {
            int intensity = (int) (image->data[y * image->width + x] * 255);
            if (intensity < 128) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    image_t image;
    FILE *fp;
    char filename[256];
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    image.width = ftell(fp) / 3;
    image.height = 1;
    image.data = malloc(image.width * image.height * 3);
    fseek(fp, 0, SEEK_SET);
    fread(image.data, 1, image.width * image.height * 3, fp);
    fclose(fp);
    printf("Image dimensions: %d x %d\n", image.width, image.height);
    print_ascii_art(&image);
    free(image.data);
    return 0;
}
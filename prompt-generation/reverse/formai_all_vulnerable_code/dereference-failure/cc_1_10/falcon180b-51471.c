//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *data = malloc(filesize);
    fread(data, 1, filesize, fp);
    fclose(fp);

    Image image = { data, WIDTH, HEIGHT };
    return image;
}

void print_image(const Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            char c = image->data[y * image->width + x];
            if (c == 0) {
                printf(" ");
            } else if (c == 1) {
                printf("#");
            } else {
                printf("%c", c + 33);
            }
        }
        printf("\n");
    }
}

int main() {
    Image image = load_image("example.bmp");
    print_image(&image);

    free(image.data);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *load_image(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *data = malloc(filesize);
    if (!data) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }

    fread(data, filesize, 1, fp);
    fclose(fp);

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }

    image->width = filesize / 3;
    image->height = 1;
    image->data = data;

    return image;
}

void free_image(Image *image)
{
    free(image->data);
    free(image);
}

void draw_pixel(int x, int y, char c)
{
    if (x >= 0 && x < MAX_WIDTH && y >= 0 && y < MAX_HEIGHT) {
        printf("%c", c);
    }
}

void draw_image(Image *image)
{
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int offset = (y * image->width + x) * 3;
            int r = image->data[offset] / 16;
            int g = (image->data[offset + 1] / 16) % 6;
            int b = image->data[offset + 2] / 16;

            draw_pixel(x * 3, y, '@');
            draw_pixel(x * 3 + 1, y, r < 5? '.' : 'o');
            draw_pixel(x * 3 + 2, y, g < 5? '.' : 'O');
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
        exit(1);
    }

    Image *image = load_image(argv[1]);
    draw_image(image);

    free_image(image);

    return 0;
}
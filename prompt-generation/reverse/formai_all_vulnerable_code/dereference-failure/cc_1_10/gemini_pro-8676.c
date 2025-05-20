//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int width;
    int height;
    int stride;
    char **data;
} Image;

Image *create_image(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->stride = width * 3;
    image->data = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(sizeof(char) * image->stride);
        memset(image->data[i], 0, image->stride);
    }
    return image;
}

void destroy_image(Image *image)
{
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, char *color)
{
    char *pixel = image->data[y] + x * 3;
    pixel[0] = color[0];
    pixel[1] = color[1];
    pixel[2] = color[2];
}

void draw_text(Image *image, int x, int y, char *text, char *color)
{
    int i = 0;
    while (text[i] != '\0') {
        char *glyph = text + i;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                int bit = (1 << (7 - k));
                char *pixel = image->data[y + j] + (x + k) * 3;
                if (glyph[j] & bit) {
                    pixel[0] = color[0];
                    pixel[1] = color[1];
                    pixel[2] = color[2];
                }
            }
        }
        i++;
        x += 8;
    }
}

char *to_ppm(Image *image)
{
    int size = image->width * image->height * 3 + 100;
    char *ppm = malloc(sizeof(char) * size);
    sprintf(ppm, "P6\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        strcat(ppm, image->data[i]);
    }
    return ppm;
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s width height text [color]\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char *text = argv[3];
    char *color = argv[4] ? argv[4] : "000";

    Image *image = create_image(width, height);
    draw_text(image, 0, 0, text, color);
    char *ppm = to_ppm(image);
    printf("%s", ppm);

    destroy_image(image);
    return 0;
}
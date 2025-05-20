//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char **data;
    int width;
    int height;
} Image;

Image *image_new(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    if (!image) {
        return NULL;
    }

    image->data = malloc(sizeof(char *) * height);
    if (!image->data) {
        free(image);
        return NULL;
    }

    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(sizeof(char) * width);
        if (!image->data[i]) {
            for (int j = 0; j < i; j++) {
                free(image->data[j]);
            }
            free(image->data);
            free(image);
            return NULL;
        }

        memset(image->data[i], ' ', width);
    }

    image->width = width;
    image->height = height;

    return image;
}

void image_free(Image *image)
{
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void image_print(Image *image)
{
    for (int i = 0; i < image->height; i++) {
        printf("%s\n", image->data[i]);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];

    int width = strlen(text);
    int height = 1;

    Image *image = image_new(width, height);
    if (!image) {
        printf("Failed to create image\n");
        return 1;
    }

    strcpy(image->data[0], text);

    image_print(image);

    image_free(image);

    return 0;
}
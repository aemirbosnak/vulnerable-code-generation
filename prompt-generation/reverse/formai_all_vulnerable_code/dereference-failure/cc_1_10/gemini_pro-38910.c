//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->data = malloc(image->width * image->height);
    if (!image->data) {
        perror("malloc");
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, image->width * image->height, 1, fp);
    fclose(fp);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

char *ascii_art(Image *image) {
    int i, j;
    char *art = malloc(WIDTH * HEIGHT);
    if (!art) {
        perror("malloc");
        return NULL;
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int index = (i * image->width) + j;
            int gray = image->data[index];
            char c = " .:-=+*#%@"[gray / 16];
            art[i * WIDTH + j] = c;
        }
    }

    return art;
}

void write_ascii_art(char *art, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("fopen");
        return;
    }

    fprintf(fp, "%s", art);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image filename> <ascii art filename>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    char *art = ascii_art(image);
    if (!art) {
        free_image(image);
        return 1;
    }

    write_ascii_art(art, argv[2]);
    free(art);
    free_image(image);

    return 0;
}
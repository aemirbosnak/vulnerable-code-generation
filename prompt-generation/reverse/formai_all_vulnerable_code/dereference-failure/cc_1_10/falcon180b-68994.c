//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void loadImage(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(filesize);
    if (!img->data) {
        printf("Error: could not allocate memory for image data\n");
        exit(1);
    }

    fread(img->data, 1, filesize, fp);
    fclose(fp);

    img->width = MAX_WIDTH;
    img->height = MAX_HEIGHT;
}

void saveASCIIArt(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: could not open file %s for writing\n", filename);
        exit(1);
    }

    int x, y;
    for (y = 0; y < img->height; ++y) {
        for (x = 0; x < img->width; ++x) {
            int value = (int)img->data[y * img->width + x];
            fprintf(fp, "%c", value < 128? '.' : '*');
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    loadImage(&img, argv[1]);
    saveASCIIArt(&img, argv[2]);

    printf("ASCII art saved to %s\n", argv[2]);

    return 0;
}
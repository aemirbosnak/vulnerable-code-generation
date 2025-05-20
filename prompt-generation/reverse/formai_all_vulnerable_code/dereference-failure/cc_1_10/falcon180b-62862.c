//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

void load_image(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(size);
    fread(image->data, size, 1, fp);
    fclose(fp);

    image->width = atoi(strtok(filename, "."));
    image->height = atoi(strtok(NULL, "."));
}

void print_ascii_art(image_t *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = (y * image->width + x) * 3;

            int r = image->data[index];
            int g = image->data[index + 1];
            int b = image->data[index + 2];

            int brightness = (r + g + b) / 3;

            if (brightness > 127) {
                printf("#");
            } else if (brightness > 64) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    image_t image;
    load_image(&image, argv[1]);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", output_filename);
        exit(1);
    }

    print_ascii_art(&image);

    fclose(fp);

    printf("ASCII art saved to '%s'\n", output_filename);

    return 0;
}
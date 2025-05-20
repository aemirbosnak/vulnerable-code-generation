//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define ASCII_CHARS "./:-=+*#@&%$"

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

void load_image(image_t *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = (char *) malloc(size);
    fread(img->data, size, 1, fp);

    fclose(fp);

    img->width = atoi(strtok(filename, "."));
    img->height = atoi(strtok(NULL, "."));
}

void free_image(image_t *img) {
    free(img->data);
}

void print_ascii_art(image_t *img) {
    int i, j, x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            i = (y * img->width + x) * 3;
            j = 0;
            while (j < 3) {
                int value = img->data[i++];
                printf("%c", ASCII_CHARS[value / 32]);
                j++;
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

    image_t img;
    load_image(&img, argv[1]);
    print_ascii_art(&img);

    FILE *fp = fopen(argv[2], "w");
    if (!fp) {
        printf("Error: Cannot create file %s\n", argv[2]);
        exit(1);
    }

    fprintf(fp, "%s", img.data);
    fclose(fp);

    free_image(&img);

    return 0;
}
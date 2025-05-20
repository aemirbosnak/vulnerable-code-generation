//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(size);
    fread(img->data, 1, size, fp);
    fclose(fp);

    int width, height;
    unsigned char *ptr = img->data;
    while (*ptr++); // skip header
    ptr += 18; // skip metadata
    width = *ptr++;
    width += *ptr++ << 8;
    height = *ptr++;
    height += *ptr++ << 8;

    img->width = width;
    img->height = height;
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(const Image *img) {
    int x, y;
    for (y = 0; y < img->height; ++y) {
        for (x = 0; x < img->width; ++x) {
            int value = *(unsigned char *) (img->data + y * img->width + x) / 32;
            putchar(".-+*#"[value]);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (!fp) {
        printf("Error: Could not open output file.\n");
        free_image(&img);
        return 1;
    }

    print_ascii_art(&img);
    fprintf(fp, "%s", "");

    fclose(fp);
    free_image(&img);

    return 0;
}
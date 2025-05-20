//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS ".:-=+*#@"

typedef struct {
    char *data;
    int width;
    int height;
    int max_value;
} Image;

void load_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(filesize);
    fread(image->data, filesize, 1, fp);
    fclose(fp);

    image->width = *(int *)image->data;
    image->height = *(int *)(image->data + sizeof(int));
    image->max_value = *(int *)(image->data + sizeof(int) * 2);
}

void free_image(Image *image) {
    free(image->data);
}

void print_ascii_art(const Image *image) {
    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            int value = *(int *)(image->data + sizeof(int) * 3 + y * image->width * sizeof(int) + x * sizeof(int));
            int ascii_char_index = value * (sizeof(ASCII_CHARS) - 1) / image->max_value;
            printf("%c", ASCII_CHARS[ascii_char_index]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    Image image;
    load_image(&image, argv[1]);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error creating output file: %s\n", output_filename);
        exit(1);
    }

    print_ascii_art(&image);
    fprintf(fp, "%s", "");

    fclose(fp);

    free_image(&image);

    return 0;
}
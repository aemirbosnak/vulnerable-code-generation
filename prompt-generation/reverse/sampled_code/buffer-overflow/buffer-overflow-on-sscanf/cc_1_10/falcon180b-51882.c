//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_LINE_LENGTH (MAX_WIDTH + 1)

typedef struct {
    char *data;
    int width;
    int height;
} Image;

typedef struct {
    char *data;
    int length;
} Line;

void read_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    image->data = malloc(size);
    if (image->data == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }

    fread(image->data, 1, size, file);
    fclose(file);

    int width, height;
    if (sscanf(filename, "%dx%d.bmp", &width, &height)!= 2) {
        fprintf(stderr, "Error: invalid filename format\n");
        exit(1);
    }

    image->width = width;
    image->height = height;
}

void write_ascii_art(const Image *image, const char *output_filename) {
    FILE *file = fopen(output_filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", output_filename);
        exit(1);
    }

    int x, y;
    for (y = 0; y < image->height; ++y) {
        Line line = {0};
        for (x = 0; x < image->width; ++x) {
            int pixel = *(unsigned char *) (image->data + y * image->width + x) >> 4;
            if (pixel == 0) {
                strcat(line.data, " ");
            } else {
                strcat(line.data, "*");
            }
        }
        strcat(line.data, "\n");
        fprintf(file, "%s", line.data);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    Image image;
    read_image(argv[1], &image);

    char *output_filename = argv[2];
    write_ascii_art(&image, output_filename);

    printf("ASCII art saved to '%s'\n", output_filename);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET ".,-+*0123456789ABCDEF"

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *data = malloc(filesize);
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(1);
    }

    if (fread(data, 1, filesize, fp)!= filesize) {
        fprintf(stderr, "Error: could not read image data from file\n");
        exit(1);
    }

    fclose(fp);

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image structure\n");
        exit(1);
    }

    image->width = atoi(strtok(filename, "."));
    image->height = atoi(strtok(NULL, "."));
    image->data = data;

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void print_image(Image *image) {
    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x];
            printf("%c", CHAR_SET[value]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    printf("Image dimensions: %dx%d\n", image->width, image->height);

    print_image(image);

    free_image(image);

    return 0;
}
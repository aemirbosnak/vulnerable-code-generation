//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET ".,-~:;=!*#@"

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    if (data == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    fread(data, filesize, 1, fp);
    fclose(fp);

    int width = *(int *)data;
    int height = *(int *)(data + sizeof(int));

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    image->width = width;
    image->height = height;
    image->data = data + sizeof(int) * 2;

    return image;
}

void save_ascii_art(Image *image, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Failed to open output file.\n");
        exit(1);
    }

    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            int gray = *(image->data + y * image->width + x) / 4;
            fprintf(fp, "%c", CHAR_SET[gray % strlen(CHAR_SET)]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        exit(1);
    }

    Image *image = load_image(argv[1]);
    save_ascii_art(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}
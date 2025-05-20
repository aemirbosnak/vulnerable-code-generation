//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *data;
    int width;
    int height;
} Image;

typedef struct {
    char *data;
    int size;
} String;

void read_image(Image *image, FILE *file) {
    char header[3] = {0};
    fread(header, 1, 3, file);
    image->width = *(int *)header;
    image->height = *(int *)(header + 3);
    image->data = malloc(image->width * image->height);
    fread(image->data, 1, image->width * image->height, file);
}

void write_ascii_art(Image *image, FILE *file) {
    int i, j;
    String line = {0};
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int value = *(int *)(image->data + i * image->width + j) / 32;
            if (value > 0) {
                char c = (char) ('A' + value - 1);
                strcat(&line, &c);
            } else {
                strcat(&line, " ");
            }
        }
        fprintf(file, "%s\n", line.data);
        memset(line.data, 0, line.size);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Image image;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    read_image(&image, file);
    fclose(file);

    if (image.width > MAX_WIDTH || image.height > MAX_HEIGHT) {
        printf("Image dimensions are too large.\n");
        free(image.data);
        return 1;
    }

    file = fopen(argv[2], "w");
    if (file == NULL) {
        printf("Error opening output file.\n");
        free(image.data);
        return 1;
    }

    write_ascii_art(&image, file);
    fclose(file);

    free(image.data);
    return 0;
}
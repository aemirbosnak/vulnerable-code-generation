//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void read_image(Image *image, FILE *fp) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(size);
    fread(image->data, size, 1, fp);

    image->width = atoi(strtok(NULL, " "));
    image->height = atoi(strtok(NULL, "\n"));
}

void write_ascii_art(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            char c = image->data[i * image->width + j];
            printf("%c", c);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input image file.\n");
        return 1;
    }

    Image image;
    read_image(&image, fp_in);
    fclose(fp_in);

    FILE *fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Error: Could not open output ASCII art file.\n");
        return 1;
    }

    write_ascii_art(&image);
    fclose(fp_out);

    free(image.data);

    return 0;
}
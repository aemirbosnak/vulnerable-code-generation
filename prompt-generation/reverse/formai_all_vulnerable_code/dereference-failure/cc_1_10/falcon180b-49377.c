//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_VALUE_LENGTH 10

typedef struct {
    char *name;
    char *value;
} Color;

typedef struct {
    int width;
    int height;
    Color *colors;
} Image;

void read_image(Image *image, FILE *fp) {
    char line[MAX_WIDTH];
    char *token;

    fgets(line, MAX_WIDTH, fp);
    sscanf(line, "P%d %d %d\n", &image->width, &image->height, &image->width);

    image->colors = malloc(sizeof(Color) * image->height);

    for (int i = 0; i < image->height; i++) {
        fgets(line, MAX_WIDTH, fp);
        token = strtok(line, " ");

        image->colors[i].name = malloc(MAX_COLOR_NAME_LENGTH);
        strncpy(image->colors[i].name, token, MAX_COLOR_NAME_LENGTH);

        token = strtok(NULL, " ");
        image->colors[i].value = malloc(MAX_COLOR_VALUE_LENGTH);
        strncpy(image->colors[i].value, token, MAX_COLOR_VALUE_LENGTH);
    }
}

void write_ascii_art(Image *image, FILE *fp) {
    int x, y;

    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            fprintf(fp, "%s", image->colors[y].value);
        }
        fprintf(fp, "\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input.png output.txt\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        fprintf(stderr, "Error: could not open input file.\n");
        return 1;
    }

    FILE *fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Error: could not open output file.\n");
        fclose(fp_in);
        return 1;
    }

    Image image;
    read_image(&image, fp_in);

    write_ascii_art(&image, fp_out);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
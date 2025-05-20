//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: ./image_editor source_image_path output_image_path\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Could not open file %s for reading\n", argv[1]);
        return 1;
    }

    // read header info
    char type[3];
    fread(type, sizeof(char), 2, input_file);
    type[2] = '\0';

    int width;
    int height;

    fscanf(input_file, "%d %d", &width, &height);

    int max_value;
    fscanf(input_file, "%d", &max_value);

    // allocate memory for the image
    pixel **image = malloc(height * sizeof(pixel *));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(pixel));
    }

    // read in the pixel data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image[i][j], sizeof(pixel), 1, input_file);
        }
    }

    // image manipulation goes here...

    // write out the modified image
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Could not open file %s for writing\n", argv[2]);
        return 1;
    }

    fprintf(output_file, "%s\n%d %d\n%d\n", type, width, height, max_value);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&image[i][j], sizeof(pixel), 1, output_file);
        }
    }

    // free memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
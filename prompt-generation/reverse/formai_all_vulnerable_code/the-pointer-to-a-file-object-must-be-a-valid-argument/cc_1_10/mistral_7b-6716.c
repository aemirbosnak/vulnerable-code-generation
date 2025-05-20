//MISTRAL-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 512
#define MAX_COL 512

void readPGM(FILE *fp, unsigned char **image, int *row, int *col) {
    char magicNumber[3];
    fgets(magicNumber, 3, fp);
    if (strncmp(magicNumber, "P5", 2) != 0) {
        fprintf(stderr, "Invalid image file format.\n");
        exit(1);
    }

    fgets(magicNumber, 12, fp);
    sscanf(magicNumber, "%d %d", row, col);

    *image = (unsigned char *)calloc(*row, *col * sizeof(unsigned char));
    fread(*image, *col * sizeof(unsigned char), *row, fp);
    fclose(fp);
}

void writePGM(FILE *fp, unsigned char *image, int row, int col) {
    fprintf(fp, "P5\n%d %d\n255\n", col, row);
    fwrite(image, col * sizeof(unsigned char), row, fp);
    fclose(fp);
}

void changeBrightnessAndContrast(unsigned char *image, int row, int col, float brightness, float contrast) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            image[i * col + j] = (unsigned char)(((float)image[i * col + j] - 127.5) * contrast + brightness + 127.5);
            if (image[i * col + j] < 0) image[i * col + j] = 0;
            if (image[i * col + j] > 255) image[i * col + j] = 255;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.pgm output.pgm brightness contrast\n", argv[0]);
        return 1;
    }

    unsigned char *image;
    int row, col;
    readPGM(argv[1], &image, &row, &col);

    float brightness = atof(argv[2]);
    float contrast = atof(argv[3]);

    changeBrightnessAndContrast(image, row, col, brightness, contrast);

    writePGM(argv[1], image, row, col);

    free(image);
    return 0;
}
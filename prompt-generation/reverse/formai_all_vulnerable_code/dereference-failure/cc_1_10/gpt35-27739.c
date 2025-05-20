//FormAI DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* struct to hold image pixels */
typedef struct {
    int rows;
    int cols;
    int max_grey;
    int **pixels;
} PGM_Image;

/* function to read an image from file */
PGM_Image *read_pgm(char *filename) {
    FILE *file;
    char line[100];
    int i, j;
    PGM_Image *image = NULL;

    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: cannot open file.\n");
        exit(1);
    }

    /* check image format */
    fgets(line, 100, file);
    if(line[0] != 'P' || line[1] != '2') {
        printf("Error: not a PGM file.\n");
        exit(1);
    }

    /* allocate memory for image */
    image = (PGM_Image *) malloc(sizeof(PGM_Image));
    if(image == NULL) {
        printf("Error: cannot allocate memory.\n");
        exit(1);
    }

    /* read image dimensions and max grey value */
    fgets(line, 100, file);
    sscanf(line, "%d %d", &image->cols, &image->rows);
    fgets(line, 100, file);
    sscanf(line, "%d", &image->max_grey);

    /* allocate memory for image pixels */
    image->pixels = (int **) malloc(image->rows * sizeof(int *));
    if(image->pixels == NULL) {
        printf("Error: cannot allocate memory.\n");
        exit(1);
    }
    for(i = 0; i < image->rows; i++) {
        image->pixels[i] = (int *) malloc(image->cols * sizeof(int));
        if(image->pixels[i] == NULL) {
            printf("Error: cannot allocate memory.\n");
            exit(1);
        }
    }

    /* read image pixel values */
    for(i = 0; i < image->rows; i++) {
        for(j = 0; j < image->cols; j++) {
            fscanf(file, "%d", &image->pixels[i][j]);
        }
    }

    fclose(file);
    return image;
}

/* function to write an image to file */
void write_pgm(PGM_Image *image, char *filename) {
    FILE *file;
    int i, j;

    file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error: cannot open file.\n");
        exit(1);
    }

    /* write image format */
    fprintf(file, "P2\n");

    /* write image dimensions and max grey value */
    fprintf(file, "%d %d\n", image->cols, image->rows);
    fprintf(file, "%d\n", image->max_grey);

    /* write image pixel values */
    for(i = 0; i < image->rows; i++) {
        for(j = 0; j < image->cols; j++) {
            fprintf(file, "%d ", image->pixels[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

/* function to convert image to grayscale */
void grayscale(PGM_Image *image) {
    int i, j, gray;

    for(i = 0; i < image->rows; i++) {
        for(j = 0; j < image->cols; j++) {
            gray = (image->pixels[i][j] + image->pixels[i][j] + image->pixels[i][j]) / 3;
            image->pixels[i][j] = gray;
        }
    }
}

/* function to invert image */
void negative(PGM_Image *image) {
    int i, j, neg;

    for(i = 0; i < image->rows; i++) {
        for(j = 0; j < image->cols; j++) {
            neg = image->max_grey - image->pixels[i][j];
            image->pixels[i][j] = neg;
        }
    }
}

int main(int argc, char *argv[]) {
    PGM_Image *image;
    char *input_file, *output_file, *operation;

    /* get input arguments */
    if(argc != 4) {
        printf("Usage: image_editor <input_file> <output_file> <operation>\n");
        exit(1);
    }
    input_file = argv[1];
    output_file = argv[2];
    operation = argv[3];

    /* read image from file */
    image = read_pgm(input_file);

    /* apply chosen operation */
    if(strcmp(operation, "grayscale") == 0) {
        grayscale(image);
    }
    else if(strcmp(operation, "negative") == 0) {
        negative(image);
    }
    else {
        printf("Error: invalid operation.\n");
        exit(1);
    }

    /* write modified image to file */
    write_pgm(image, output_file);

    /* free memory */
    free(image);

    return 0;
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMG_SIZE 28
#define NUM_FEATURES (IMG_SIZE * IMG_SIZE)

/* A paranoid-style image classification system */
int main(int argc, char **argv) {
    /* Initialize variables */
    int i, j, k;
    double **w;
    double *x;
    double *y;
    int *labels;
    int num_images;
    char img_filename[256];
    char label_filename[256];

    /* Allocate memory for weight matrix */
    w = (double **) malloc(NUM_FEATURES * sizeof(double *));
    if (w == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (i = 0; i < NUM_FEATURES; i++) {
        w[i] = (double *) malloc(NUM_CLASSES * sizeof(double));
        if (w[i] == NULL) {
            printf("Memory allocation error!\n");
            return 1;
        }
    }

    /* Initialize weight matrix with random values */
    for (i = 0; i < NUM_FEATURES; i++) {
        for (j = 0; j < NUM_CLASSES; j++) {
            w[i][j] = rand() / (double) RAND_MAX;
        }
    }

    /* Allocate memory for input and output */
    x = (double *) malloc(NUM_FEATURES * sizeof(double));
    y = (double *) malloc(NUM_CLASSES * sizeof(double));
    if (x == NULL || y == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    /* Read in image and label files */
    if (argc != 3) {
        printf("Usage: %s <image file> <label file>\n", argv[0]);
        return 1;
    }

    strcpy(img_filename, argv[1]);
    strcpy(label_filename, argv[2]);

    FILE *img_file = fopen(img_filename, "rb");
    FILE *label_file = fopen(label_filename, "rb");

    if (img_file == NULL || label_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    /* Determine number of images in the file */
    fseek(img_file, 0, SEEK_END);
    long img_file_size = ftell(img_file);
    fseek(img_file, 0, SEEK_SET);

    num_images = img_file_size / (IMG_SIZE * IMG_SIZE);

    /* Allocate memory for image labels */
    labels = (int *) malloc(num_images * sizeof(int));
    if (labels == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    /* Loop through each image in file */
    for (k = 0; k < num_images; k++) {
        /* Read in current image and label */
        fread(x, sizeof(double), NUM_FEATURES, img_file);
        fread(&labels[k], sizeof(int), 1, label_file);

        /* Normalize input */
        for (i = 0; i < NUM_FEATURES; i++) {
            x[i] /= 255.0;
        }

        /* Multiply input by weight matrix */
        for (i = 0; i < NUM_CLASSES; i++) {
            y[i] = 0.0;
            for (j = 0; j < NUM_FEATURES; j++) {
                y[i] += w[j][i] * x[j];
            }
        }

        /* Determine class label with largest output */
        int predicted_label = 0;
        double max_output = y[0];
        for (i = 1; i < NUM_CLASSES; i++) {
            if (y[i] > max_output) {
                max_output = y[i];
                predicted_label = i;
            }
        }

        /* Print prediction along with true label */
        printf("Prediction: %d, True label: %d\n", predicted_label, labels[k]);

        /* Update weights */
        if (predicted_label != labels[k]) {
            for (i = 0; i < NUM_FEATURES; i++) {
                w[i][predicted_label] -= x[i];
                w[i][labels[k]] += x[i];
            }
        }
    }

    /* Free memory */
    for (i = 0; i < NUM_FEATURES; i++) {
        free(w[i]);
    }
    free(w);
    free(x);
    free(y);
    free(labels);

    return 0;
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

// Constants
#define NUM_CLASSES 4
#define IMAGE_SIZE 100 // Size of square input image

// Function to load image from file
int *load_image(char *filename) {
    FILE *fp = fopen(filename, "r");
    int *image = malloc(IMAGE_SIZE * IMAGE_SIZE * sizeof(int));
    for(int i=0; i<IMAGE_SIZE; i++) {
        for(int j=0; j<IMAGE_SIZE; j++) {
            fscanf(fp, "%d", &image[i * IMAGE_SIZE + j]);
        }
    }
    fclose(fp);
    return image;
}

// Function to classify image
int classify_image(int *image, int **classifiers) {
    int max_class = 0;
    double max_score = 0;
    for(int c=0; c<NUM_CLASSES; c++) {
        double score = 0;
        for(int i=0; i<IMAGE_SIZE*IMAGE_SIZE; i++) {
            score += classifiers[c][i] * image[i];
        }
        if(score > max_score) {
            max_score = score;
            max_class = c;
        }
    }
    return max_class;
}

// Main function
int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: ./classifier <image_filename>\n");
        return 1;
    }

    // Load classifiers from file
    int **classifiers = malloc(NUM_CLASSES * sizeof(int *));
    for(int c=0; c<NUM_CLASSES; c++) {
        char filename[100];
        sprintf(filename, "classifier_%d.txt", c);
        classifiers[c] = load_image(filename);
    }

    // Load input image from file
    char *image_filename = argv[1];
    int *image = load_image(image_filename);

    // Classify input image
    int predicted_class = classify_image(image, classifiers);

    // Print result
    printf("Input image is classified as class %d\n", predicted_class);

    // Free memory
    for(int c=0; c<NUM_CLASSES; c++) {
        free(classifiers[c]);
    }
    free(classifiers);
    free(image);

    return 0;
}
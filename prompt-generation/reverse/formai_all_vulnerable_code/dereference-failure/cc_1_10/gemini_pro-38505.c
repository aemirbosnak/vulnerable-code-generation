//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Represents an image as a 2D array of pixels
typedef struct {
    int width;
    int height;
    int** pixels;
} Image;

// Represents a classification model
typedef struct {
    int num_classes;
    double** weights;
} Model;

// Loads an image from a file
Image load_image(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    Image image;
    fscanf(file, "%d %d\n", &image.width, &image.height);

    image.pixels = malloc(sizeof(int*) * image.height);
    for (int i = 0; i < image.height; i++) {
        image.pixels[i] = malloc(sizeof(int) * image.width);
        for (int j = 0; j < image.width; j++) {
            fscanf(file, "%d ", &image.pixels[i][j]);
        }
    }

    fclose(file);

    return image;
}

// Frees the memory allocated for an image
void free_image(Image image) {
    for (int i = 0; i < image.height; i++) {
        free(image.pixels[i]);
    }
    free(image.pixels);
}

// Loads a classification model from a file
Model load_model(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    Model model;
    fscanf(file, "%d\n", &model.num_classes);

    model.weights = malloc(sizeof(double*) * model.num_classes);
    for (int i = 0; i < model.num_classes; i++) {
        model.weights[i] = malloc(sizeof(double) * 784);
        for (int j = 0; j < 784; j++) {
            fscanf(file, "%lf ", &model.weights[i][j]);
        }
    }

    fclose(file);

    return model;
}

// Frees the memory allocated for a classification model
void free_model(Model model) {
    for (int i = 0; i < model.num_classes; i++) {
        free(model.weights[i]);
    }
    free(model.weights);
}

// Classifies an image using a classification model
int classify_image(Image image, Model model) {
    double** activations = malloc(sizeof(double*) * model.num_classes);
    for (int i = 0; i < model.num_classes; i++) {
        activations[i] = malloc(sizeof(double));
        activations[i][0] = 0.0;
    }

    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            for (int k = 0; k < model.num_classes; k++) {
                activations[k][0] += image.pixels[i][j] * model.weights[k][i * image.width + j];
            }
        }
    }

    int max_class = 0;
    double max_activation = activations[0][0];
    for (int i = 1; i < model.num_classes; i++) {
        if (activations[i][0] > max_activation) {
            max_class = i;
            max_activation = activations[i][0];
        }
    }

    for (int i = 0; i < model.num_classes; i++) {
        free(activations[i]);
    }
    free(activations);

    return max_class;
}

// Main function
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <image_file> <model_file>\n", argv[0]);
        exit(1);
    }

    Image image = load_image(argv[1]);
    Model model = load_model(argv[2]);

    int classification = classify_image(image, model);

    printf("The image is classified as %d\n", classification);

    free_image(image);
    free_model(model);

    return 0;
}
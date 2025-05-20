//FormAI DATASET v1.0 Category: Image Classification system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIZE 28
#define NUM_CLASSES 10
#define NUM_FEATURES (IMAGE_SIZE * IMAGE_SIZE)

// Image structure
typedef struct {
    int label;
    double features[NUM_FEATURES];
} Image;

// Neural Network structure
typedef struct {
    double input_layer[NUM_FEATURES];
    double hidden_layer[NUM_FEATURES];
    double output_layer[NUM_CLASSES];
} NeuralNetwork;

// Function to read image data from file
void readImage(FILE *fp, Image *img) {
    // Read label
    fread(&(img->label), sizeof(int), 1, fp);

    // Read features
    for (int i = 0; i < NUM_FEATURES; i++) {
        unsigned char pixel;
        fread(&pixel, sizeof(unsigned char), 1, fp);
        img->features[i] = (double) pixel / 255.0;
    }
}

// Function to initialize neural network weights
void initializeWeights(NeuralNetwork *nn) {
    for (int i = 0; i < NUM_FEATURES; i++) {
        nn->input_layer[i] = (double) rand() / RAND_MAX;
        nn->hidden_layer[i] = (double) rand() / RAND_MAX;
    }

    for (int i = 0; i < NUM_CLASSES; i++) {
        nn->output_layer[i] = (double) rand() / RAND_MAX;
    }
}

// Function to perform feedforward operation
void feedforward(NeuralNetwork *nn, Image *img) {
    // Input layer
    for (int i = 0; i < NUM_FEATURES; i++) {
        nn->input_layer[i] = img->features[i];
    }

    // Hidden layer
    for (int j = 0; j < NUM_FEATURES; j++) {
        double sum = 0.0;
        for (int i = 0; i < NUM_FEATURES; i++) {
            sum += nn->input_layer[i] * nn->hidden_layer[j];
        }
        nn->hidden_layer[j] = 1.0 / (1.0 + exp(-sum));
    }

    // Output layer
    for (int k = 0; k < NUM_CLASSES; k++) {
        double sum = 0.0;
        for (int j = 0; j < NUM_FEATURES; j++) {
            sum += nn->hidden_layer[j] * nn->output_layer[k];
        }
        nn->output_layer[k] = exp(sum);
    }

    // Normalize output layer
    double total = 0.0;
    for (int k = 0; k < NUM_CLASSES; k++) {
        total += nn->output_layer[k];
    }
    for (int k = 0; k < NUM_CLASSES; k++) {
        nn->output_layer[k] /= total;
    }
}

int main() {
    // Read training data
    FILE *train_data = fopen("train.data", "rb");
    if (train_data == NULL) {
        printf("Error: Could not open train.data\n");
        return 1;
    }

    int num_train_images;
    fread(&num_train_images, sizeof(int), 1, train_data);

    Image *train_images = malloc(num_train_images * sizeof(Image));
    for (int i = 0; i < num_train_images; i++) {
        readImage(train_data, &(train_images[i]));
    }

    // Initialize neural network
    NeuralNetwork nn;
    initializeWeights(&nn);

    // Train neural network
    for (int epoch = 0; epoch < 10; epoch++) {
        double total_loss = 0.0;
        for (int i = 0; i < num_train_images; i++) {
            feedforward(&nn, &(train_images[i]));

            double target[NUM_CLASSES];
            for (int k = 0; k < NUM_CLASSES; k++) {
                if (k == train_images[i].label) {
                    target[k] = 1.0;
                } else {
                    target[k] = 0.0;
                }
            }

            double loss = 0.0;
            for (int k = 0; k < NUM_CLASSES; k++) {
                loss += target[k] * log(nn.output_layer[k]);
            }
            total_loss += -loss;

            // Update weights
            for (int k = 0; k < NUM_CLASSES; k++) {
                double delta_output = (nn.output_layer[k] - target[k]) / nn.output_layer[k] / (1.0 - nn.output_layer[k]);
                for (int j = 0; j < NUM_FEATURES; j++) {
                    nn.output_layer[k] -= 0.01 * delta_output * nn.hidden_layer[j];
                }
            }

            for (int j = 0; j < NUM_FEATURES; j++) {
                double sum = 0.0;
                for (int k = 0; k < NUM_CLASSES; k++) {
                    double delta_output = (nn.output_layer[k] - target[k]) / nn.output_layer[k] / (1.0 - nn.output_layer[k]);
                    sum += delta_output * nn.output_layer[k] * (1.0 - nn.output_layer[k]) * nn.output_layer[k] * nn.hidden_layer[j];
                }

                for (int i = 0; i < NUM_FEATURES; i++) {
                    double delta_hidden = sum * nn.hidden_layer[j] * (1.0 - nn.hidden_layer[j]);
                    nn.hidden_layer[j] -= 0.01 * delta_hidden * nn.input_layer[i];
                }
            }
        }

        printf("Epoch: %d, Loss: %f\n", epoch, total_loss / num_train_images);
    }

    free(train_images);
    fclose(train_data);

    return 0;
}
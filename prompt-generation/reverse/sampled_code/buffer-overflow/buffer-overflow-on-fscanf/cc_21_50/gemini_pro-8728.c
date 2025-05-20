//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 10
#define NUM_FEATURES 784

int main() {
    // Load the MNIST dataset.
    FILE *f = fopen("mnist.txt", "r");
    if (f == NULL) {
        printf("Error loading MNIST dataset.\n");
        return EXIT_FAILURE;
    }
    int data[NUM_CLASSES][NUM_FEATURES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            fscanf(f, "%d", &data[i][j]);
        }
    }
    fclose(f);

    // Create a neural network.
    int layers[] = {NUM_FEATURES, 100, NUM_CLASSES};
    int num_layers = sizeof(layers) / sizeof(layers[0]);
    float weights[num_layers - 1][layers[num_layers - 1]][layers[num_layers - 2]];
    for (int i = 0; i < num_layers - 1; i++) {
        for (int j = 0; j < layers[i + 1]; j++) {
            for (int k = 0; k < layers[i]; k++) {
                weights[i][j][k] = rand() / (float)RAND_MAX;
            }
        }
    }

    // Train the neural network.
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            // Forward pass.
            float activations[num_layers][layers[num_layers - 1]];
            for (int k = 0; k < layers[num_layers - 1]; k++) {
                activations[0][k] = data[j][k];
            }
            for (int k = 1; k < num_layers; k++) {
                for (int l = 0; l < layers[k]; l++) {
                    activations[k][l] = 0;
                    for (int m = 0; m < layers[k - 1]; m++) {
                        activations[k][l] += activations[k - 1][m] * weights[k - 1][l][m];
                    }
                    activations[k][l] = 1 / (1 + exp(-activations[k][l]));
                }
            }

            // Backward pass.
            float errors[num_layers][layers[num_layers - 1]];
            for (int k = 0; k < layers[num_layers - 1]; k++) {
                errors[num_layers - 1][k] = activations[num_layers - 1][k] - (j == k);
            }
            for (int k = num_layers - 2; k >= 0; k--) {
                for (int l = 0; l < layers[k]; l++) {
                    errors[k][l] = 0;
                    for (int m = 0; m < layers[k + 1]; m++) {
                        errors[k][l] += errors[k + 1][m] * weights[k][m][l];
                    }
                    errors[k][l] *= activations[k][l] * (1 - activations[k][l]);
                }
            }

            // Update weights.
            for (int k = 0; k < num_layers - 1; k++) {
                for (int l = 0; l < layers[k + 1]; l++) {
                    for (int m = 0; m < layers[k]; m++) {
                        weights[k][l][m] -= 0.01 * errors[k][m] * activations[k][m];
                    }
                }
            }
        }
    }

    // Evaluate the neural network.
    int correct = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        // Forward pass.
        float activations[num_layers][layers[num_layers - 1]];
        for (int j = 0; j < layers[num_layers - 1]; j++) {
            activations[0][j] = data[i][j];
        }
        for (int j = 1; j < num_layers; j++) {
            for (int k = 0; k < layers[j]; k++) {
                activations[j][k] = 0;
                for (int l = 0; l < layers[j - 1]; l++) {
                    activations[j][k] += activations[j - 1][l] * weights[j - 1][k][l];
                }
                activations[j][k] = 1 / (1 + exp(-activations[j][k]));
            }
        }

        // Check if the prediction is correct.
        int predicted_class = -1;
        float max_activation = -1;
        for (int j = 0; j < NUM_CLASSES; j++) {
            if (activations[num_layers - 1][j] > max_activation) {
                max_activation = activations[num_layers - 1][j];
                predicted_class = j;
            }
        }

        if (predicted_class == i) {
            correct++;
        }
    }
    
    printf("Accuracy: %f\n", (float)correct / NUM_CLASSES);
    
    return EXIT_SUCCESS;
}
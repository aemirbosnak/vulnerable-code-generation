//FormAI DATASET v1.0 Category: Image Classification system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRAINING_SET_SIZE 500
#define IMAGE_SIZE 784
#define HIDDEN_SIZE 30
#define CLASSES 10
#define LEARNING_RATE 0.001

void load_data(float **inputs, int *expected_outputs) {
    FILE *input_file = fopen("training_data.txt", "r");
    for (int i = 0; i < TRAINING_SET_SIZE; i++) {
        inputs[i] = (float*) malloc(IMAGE_SIZE * sizeof(float));
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fscanf(input_file, "%f", &inputs[i][j]);
        }
        fscanf(input_file, "%d", &expected_outputs[i]);
    }
    fclose(input_file);
}

void random_init(float **weights, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            weights[i][j] = ((float)rand() / (float)RAND_MAX) - 0.5;
        }
    }
}

int max_index(float *arr, int size) {
    int max_index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    float **input_data = (float**) malloc(TRAINING_SET_SIZE * sizeof(float*));
    int *expected_outputs = (int*) malloc(TRAINING_SET_SIZE * sizeof(int));

    load_data(input_data, expected_outputs);

    float **weights1 = (float**) malloc(HIDDEN_SIZE * sizeof(float*));
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        weights1[i] = (float*) malloc(IMAGE_SIZE * sizeof(float));
    }
    random_init(weights1, HIDDEN_SIZE, IMAGE_SIZE);

    float **weights2 = (float**) malloc(CLASSES * sizeof(float*));
    for (int i = 0; i < CLASSES; i++) {
        weights2[i] = (float*) malloc(HIDDEN_SIZE * sizeof(float));
    }
    random_init(weights2, CLASSES, HIDDEN_SIZE);

    for (int epoch = 0; epoch < 100; epoch++) {
        printf("Training epoch %d...\n", epoch + 1);
        for (int i = 0; i < TRAINING_SET_SIZE; i++) {
            float *input = input_data[i];
            int expected_output = expected_outputs[i];

            // Forward pass
            float hidden_layer[HIDDEN_SIZE];
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                float dot_product = 0;
                for (int k = 0; k < IMAGE_SIZE; k++) {
                    dot_product += input[k] * weights1[j][k];
                }
                hidden_layer[j] = 1 / (1 + exp(-dot_product));
            }

            float output_layer[CLASSES];
            for (int j = 0; j < CLASSES; j++) {
                float dot_product = 0;
                for (int k = 0; k < HIDDEN_SIZE; k++) {
                    dot_product += hidden_layer[k] * weights2[j][k];
                }
                output_layer[j] = exp(dot_product);
            }

            // Backward pass
            float delta_output[CLASSES];
            for (int j = 0; j < CLASSES; j++) {
                if (j == expected_output) {
                    delta_output[j] = output_layer[j] - 1.0;
                } else {
                    delta_output[j] = output_layer[j];
                }
            }

            float delta_hidden[HIDDEN_SIZE];
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                float sum = 0;
                for (int k = 0; k < CLASSES; k++) {
                    sum += weights2[k][j] * delta_output[k];
                }
                delta_hidden[j] = hidden_layer[j]*(1 - hidden_layer[j])*sum;
            }

            // Update weights
            for (int j = 0; j < HIDDEN_SIZE; j++) {
                for (int k = 0; k < IMAGE_SIZE; k++) {
                    weights1[j][k] -= LEARNING_RATE * delta_hidden[j] * input[k];
                }
            }

            for (int j = 0; j < CLASSES; j++) {
                for (int k = 0; k < HIDDEN_SIZE; k++) {
                    weights2[j][k] -= LEARNING_RATE * delta_output[j] * hidden_layer[k];
                }
            }
        }
    }

    // Test trained network
    int correct = 0;
    for (int i = 0; i < TRAINING_SET_SIZE; i++) {
        float *input = input_data[i];
        int expected_output = expected_outputs[i];

        float hidden_layer[HIDDEN_SIZE];
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            float dot_product = 0;
            for (int k = 0; k < IMAGE_SIZE; k++) {
                dot_product += input[k] * weights1[j][k];
            }
            hidden_layer[j] = 1 / (1 + exp(-dot_product));
        }

        float output_layer[CLASSES];
        for (int j = 0; j < CLASSES; j++) {
            float dot_product = 0;
            for (int k = 0; k < HIDDEN_SIZE; k++) {
                dot_product += hidden_layer[k] * weights2[j][k];
            }
            output_layer[j] = exp(dot_product);
        }

        int predicted_output = max_index(output_layer, CLASSES);
        if (predicted_output == expected_output) {
            correct++;
        }
    }

    printf("Accuracy on test set: %f%%\n", (float)correct / (float)TRAINING_SET_SIZE * 100);

    // Free allocated memory
    for (int i = 0; i < TRAINING_SET_SIZE; i++) {
        free(input_data[i]);
    }
    free(input_data);
    free(expected_outputs);

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        free(weights1[i]);
    }
    free(weights1);

    for (int i = 0; i < CLASSES; i++) {
        free(weights2[i]);
    }
    free(weights2);

    return 0;
}
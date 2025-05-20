//FormAI DATASET v1.0 Category: Image Classification system ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 784 // Input image size = 28*28
#define HIDDEN_LAYER_SIZE 30
#define OUTPUT_SIZE 10 // Number of possible output classes
#define LEARNING_RATE 0.001 // Learning rate for gradient descent

// Activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of activation function
double sigmoid_prime(double x) {
    double sig = sigmoid(x);
    return sig * (1.0 - sig);
}

int main() {
    // Load data
    FILE* data_file = fopen("data.bin", "rb");
    if (data_file == NULL) {
        printf("Error: Could not open data file.\n");
        return 1;
    }
    double* input_data = (double*) malloc(INPUT_SIZE * sizeof(double));
    int output_data;
    fread(input_data, sizeof(double), INPUT_SIZE, data_file);
    fread(&output_data, sizeof(int), 1, data_file);
    fclose(data_file);

    // Initialize weights and biases
    double input_hidden_weights[INPUT_SIZE][HIDDEN_LAYER_SIZE];
    double hidden_output_weights[HIDDEN_LAYER_SIZE][OUTPUT_SIZE];
    double hidden_biases[HIDDEN_LAYER_SIZE];
    double output_biases[OUTPUT_SIZE];
    srand(time(NULL));
    for (int i=0; i<INPUT_SIZE; ++i) {
        for (int j=0; j<HIDDEN_LAYER_SIZE; ++j) {
            input_hidden_weights[i][j] = (double)(rand() % 100 - 50) / 100.0; // Random initialization
        }
    }
    for (int i=0; i<HIDDEN_LAYER_SIZE; ++i) {
        for (int j=0; j<OUTPUT_SIZE; ++j) {
            hidden_output_weights[i][j] = (double)(rand() % 100 - 50) / 100.0; // Random initialization
        }
        hidden_biases[i] = (double)(rand() % 100 - 50) / 100.0; // Random initialization
    }
    for (int i=0; i<OUTPUT_SIZE; ++i) {
        output_biases[i] = (double)(rand() % 100 - 50) / 100.0; // Random initialization
    }

    // Forward pass
    double hidden_layer[HIDDEN_LAYER_SIZE];
    double output_layer[OUTPUT_SIZE];
    for (int i=0; i<HIDDEN_LAYER_SIZE; ++i) {
        hidden_layer[i] = 0.0;
        for (int j=0; j<INPUT_SIZE; ++j) {
            hidden_layer[i] += input_data[j] * input_hidden_weights[j][i];
        }
        hidden_layer[i] += hidden_biases[i];
        hidden_layer[i] = sigmoid(hidden_layer[i]);
    }
    for (int i=0; i<OUTPUT_SIZE; ++i) {
        output_layer[i] = 0.0;
        for (int j=0; j<HIDDEN_LAYER_SIZE; ++j) {
            output_layer[i] += hidden_layer[j] * hidden_output_weights[j][i];
        }
        output_layer[i] += output_biases[i];
        output_layer[i] = sigmoid(output_layer[i]);
    }

    // Calculate error
    double error = 0.0;
    for (int i=0; i<OUTPUT_SIZE; ++i) {
        double target = (i == output_data) ? 1.0 : 0.0; // One-hot encoding
        double delta = target - output_layer[i];
        error += delta * delta;
    }
    printf("Initial error: %f\n", error);

    // Backward pass
    double output_delta[OUTPUT_SIZE];
    double hidden_delta[HIDDEN_LAYER_SIZE];
    for (int i=0; i<OUTPUT_SIZE; ++i) {
        double target = (i == output_data) ? 1.0 : 0.0; // One-hot encoding
        output_delta[i] = (target - output_layer[i]) * sigmoid_prime(output_layer[i]);
        for (int j=0; j<HIDDEN_LAYER_SIZE; ++j) {
            hidden_output_weights[j][i] += LEARNING_RATE * hidden_layer[j] * output_delta[i];
        }
        output_biases[i] += LEARNING_RATE * output_delta[i];
    }
    for (int i=0; i<HIDDEN_LAYER_SIZE; ++i) {
        hidden_delta[i] = 0.0;
        for (int j=0; j<OUTPUT_SIZE; ++j) {
            hidden_delta[i] += output_delta[j] * hidden_output_weights[i][j];
        }
        hidden_delta[i] *= sigmoid_prime(hidden_layer[i]);
        for (int j=0; j<INPUT_SIZE; ++j) {
            input_hidden_weights[j][i] += LEARNING_RATE * input_data[j] * hidden_delta[i];
        }
        hidden_biases[i] += LEARNING_RATE * hidden_delta[i];
    }

    // Forward pass with updated weights
    for (int i=0; i<HIDDEN_LAYER_SIZE; ++i) {
        hidden_layer[i] = 0.0;
        for (int j=0; j<INPUT_SIZE; ++j) {
            hidden_layer[i] += input_data[j] * input_hidden_weights[j][i];
        }
        hidden_layer[i] += hidden_biases[i];
        hidden_layer[i] = sigmoid(hidden_layer[i]);
    }
    for (int i=0; i<OUTPUT_SIZE; ++i) {
        output_layer[i] = 0.0;
        for (int j=0; j<HIDDEN_LAYER_SIZE; ++j) {
            output_layer[i] += hidden_layer[j] * hidden_output_weights[j][i];
        }
        output_layer[i] += output_biases[i];
        output_layer[i] = sigmoid(output_layer[i]);
    }

    // Calculate error
    error = 0.0;
    for (int i=0; i<OUTPUT_SIZE; ++i) {
        double target = (i == output_data) ? 1.0 : 0.0; // One-hot encoding
        double delta = target - output_layer[i];
        error += delta * delta;
    }
    printf("Final error: %f\n", error);

    return 0;
}
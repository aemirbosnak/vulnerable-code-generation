//FormAI DATASET v1.0 Category: Image Classification system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 784 // 28 x 28
#define HIDDEN_SIZE 32
#define OUTPUT_SIZE 10

typedef struct {
    double *input;
    double *hidden;
    double *output;
    double **ih_weights;
    double **ho_weights;
} NeuralNet;

void init_weights(double **weights, int n, int m);
void init_net(NeuralNet *net);
int max_index(double *array, int n);
void feedforward(NeuralNet *net);

int main() {
    NeuralNet net;
    init_net(&net);

    // Input layer
    double input[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        input[i] = (double) rand() / RAND_MAX;
    }
    net.input = input;

    // Feedforward
    feedforward(&net);

    // Output layer's predicted value
    printf("Predicted value: %d\n", max_index(net.output, OUTPUT_SIZE));

    return 0;
}

void init_weights(double **weights, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            weights[i][j] = (double) rand() / RAND_MAX;
        }
    }
}

void init_net(NeuralNet *net) {
    // Allocate memory for hidden and output layers
    net->hidden = (double*) malloc(HIDDEN_SIZE * sizeof(double));
    net->output = (double*) malloc(OUTPUT_SIZE * sizeof(double));

    // Implement the weights
    net->ih_weights = (double**) malloc(INPUT_SIZE * sizeof(double*));
    for (int i = 0; i < INPUT_SIZE; i++) {
        net->ih_weights[i] = (double*) malloc(HIDDEN_SIZE * sizeof(double));
    }

    net->ho_weights = (double**) malloc(HIDDEN_SIZE * sizeof(double*));
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        net->ho_weights[i] = (double*) malloc(OUTPUT_SIZE * sizeof(double));
    }

    // Initialize weights with random values
    init_weights(net->ih_weights, INPUT_SIZE, HIDDEN_SIZE);
    init_weights(net->ho_weights, HIDDEN_SIZE, OUTPUT_SIZE);
}

int max_index(double *array, int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] > array[max]) {
            max = i;
        }
    }
    return max;
}

void feedforward(NeuralNet *net) {
    // Calculate hidden layer values
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += net->input[j] * net->ih_weights[j][i];
        }
        net->hidden[i] = 1 / (1 + exp(-sum));
    }

    // Calculate output layer values
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            sum += net->hidden[j] * net->ho_weights[j][i];
        }
        net->output[i] = exp(sum);
    }

    // Normalize output layer values
    double sum = 0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        sum += net->output[i];
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        net->output[i] /= sum;
    }
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NUM_CLASSES 10
#define INPUT_SIZE 28 * 28
#define HIDDEN_SIZE 128

// Neural network struct declaration
typedef struct {
    float* W1;
    float* b1;
    float* W2;
    float* b2;
    int hidden_size;
} NeuralNet;

// Function to initialize neural network weights and biases
void initialize(NeuralNet* network) {
    int count = INPUT_SIZE * network->hidden_size;
    network->W1 = malloc(count * sizeof(float));
    for(int i = 0; i < count; i++) {
        // Random initialization of weights
        network->W1[i] = ((float)rand() / RAND_MAX) - 0.5;
    }

    count = network->hidden_size;
    network->b1 = malloc(count * sizeof(float));
    for(int i = 0; i < count; i++) {
        network->b1[i] = 0.0;
    }

    count = network->hidden_size * NUM_CLASSES;
    network->W2 = malloc(count * sizeof(float));
    for(int i = 0; i < count; i++) {
        network->W2[i] = ((float)rand() / RAND_MAX) - 0.5;
    }

    count = NUM_CLASSES;
    network->b2 = malloc(count * sizeof(float));
    for(int i = 0; i < count; i++) {
        network->b2[i] = 0.0;
    }
}

// Function to compute dot product between two vectors
float dot_product(float* v1, float* v2, int size) {
    float result = 0.0;
    for(int i = 0; i < size; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to feedforward through a neural network
void feedforward(NeuralNet* network, float* input, float* output) {
    float* hidden = malloc(network->hidden_size * sizeof(float));
    for(int i = 0; i < network->hidden_size; i++) {
        hidden[i] = dot_product(input, &network->W1[i * INPUT_SIZE], INPUT_SIZE) + network->b1[i];
        hidden[i] = hidden[i] > 0 ? hidden[i] : 0; // ReLU activation function
    }
    for(int i = 0; i < NUM_CLASSES; i++) {
        output[i] = dot_product(hidden, &network->W2[i * network->hidden_size], network->hidden_size) + network->b2[i];
    }
    free(hidden);
}

// Function to compute the cross entropy loss between predicted and true labels
float compute_loss(float* predicted, float* true_labels) {
    float loss = 0.0;
    for(int i = 0; i < NUM_CLASSES; i++) {
        loss -= true_labels[i] * log(predicted[i] + 1e-10);
    }
    return loss;
}

int main() {
    // Set up neural network
    NeuralNet network;
    network.hidden_size = HIDDEN_SIZE;
    initialize(&network);

    // Load sample dataset
    FILE* fp = fopen("sample.csv", "r");
    if(fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    char* tok;
    float input[INPUT_SIZE];
    float true_labels[NUM_CLASSES];
    float predicted[NUM_CLASSES];
    int num_samples = 0;
    float total_loss = 0.0;

    while(getline(&line, &len, fp) != -1) {
        tok = strtok(line, ",");
        for(int i = 0; i < INPUT_SIZE; i++) {
            input[i] = atof(tok);
            tok = strtok(NULL, ",");
        }
        for(int i = 0; i < NUM_CLASSES; i++) {
            true_labels[i] = i == atoi(tok);
        }
        feedforward(&network, input, predicted);
        total_loss += compute_loss(predicted, true_labels);
        num_samples++;
    }

    printf("Average loss: %f\n", total_loss / num_samples);

    // Clean up
    free(network.W1);
    free(network.b1);
    free(network.W2);
    free(network.b2);
    fclose(fp);
    if(line) {
        free(line);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784  // 28x28 image pixel count
#define HIDDEN_SIZE 16   // Number of hidden layer nodes
#define OUTPUT_SIZE 10   // Number of output classes

typedef struct neuron {
    double output;
    double error;
    double *weights;
    double *past_weights;
    int num_weights;
} neuron;

// Function to initialize neural network
void init_network(neuron **hidden_layer, neuron **output_layer) {
    // Allocate memory for hidden layer
    *hidden_layer = malloc(HIDDEN_SIZE * sizeof(neuron));
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        // Allocate memory for hidden layer weights
        (*hidden_layer)[i].weights = malloc(INPUT_SIZE * sizeof(double));
        (*hidden_layer)[i].past_weights = malloc(INPUT_SIZE * sizeof(double));
        // Initialize weights randomly between -0.5 and 0.5
        for (int j = 0; j < INPUT_SIZE; j++) {
            (*hidden_layer)[i].weights[j] = (rand() / (double)RAND_MAX) - 0.5;
            (*hidden_layer)[i].past_weights[j] = (*hidden_layer)[i].weights[j];
        }
        (*hidden_layer)[i].num_weights = INPUT_SIZE;
    }

    // Allocate memory for output layer
    *output_layer = malloc(OUTPUT_SIZE * sizeof(neuron));
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        // Allocate memory for output layer weights
        (*output_layer)[i].weights = malloc(HIDDEN_SIZE * sizeof(double));
        (*output_layer)[i].past_weights = malloc(HIDDEN_SIZE * sizeof(double));
        // Initialize weights randomly between -0.5 and 0.5
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            (*output_layer)[i].weights[j] = (rand() / (double)RAND_MAX) - 0.5;
            (*output_layer)[i].past_weights[j] = (*output_layer)[i].weights[j];
        }
        (*output_layer)[i].num_weights = HIDDEN_SIZE;
    }
}

// Function to calculate sigmoid function of x
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Function to calculate derivative of sigmoid function of x
double sigmoid_derivative(double x) {
    double s = sigmoid(x);
    return s * (1 - s);
}

// Function to feed forward through neural network
void feed_forward(neuron *hidden_layer, neuron *output_layer, double *input, double *expected_output) {
    // Calculate hidden layer outputs
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += hidden_layer[i].weights[j] * input[j];
        }
        hidden_layer[i].output = sigmoid(sum);
    }

    // Calculate output layer outputs
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            sum += output_layer[i].weights[j] * hidden_layer[j].output;
        }
        output_layer[i].output = sigmoid(sum);
    }

    // Calculate output layer errors
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_layer[i].error = (expected_output[i] - output_layer[i].output) * sigmoid_derivative(output_layer[i].output);
    }

    // Calculate hidden layer errors
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            sum += output_layer[j].error * output_layer[j].weights[i];
        }
        hidden_layer[i].error = sum * sigmoid_derivative(hidden_layer[i].output);
    }
}

// Function to update weights based on errors
void update_weights(neuron *hidden_layer, neuron *output_layer, double *input, double learning_rate) {
    // Update output layer weights
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            double weight_delta = learning_rate * output_layer[i].error * hidden_layer[j].output;
            output_layer[i].weights[j] += weight_delta;
            output_layer[i].past_weights[j] = output_layer[i].weights[j];
        }
    }

    // Update hidden layer weights
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            double weight_delta = learning_rate * hidden_layer[i].error * input[j];
            hidden_layer[i].weights[j] += weight_delta;
            hidden_layer[i].past_weights[j] = hidden_layer[i].weights[j];
        }
    }
}

// Function to train neural network on input/output pairs
void train_network(neuron *hidden_layer, neuron *output_layer, double **inputs, double **expected_outputs, int num_inputs, double learning_rate, int epochs) {
    for (int epoch = 0; epoch < epochs; epoch++) {
        double total_error = 0;
        for (int i = 0; i < num_inputs; i++) {
            feed_forward(hidden_layer, output_layer, inputs[i], expected_outputs[i]);
            update_weights(hidden_layer, output_layer, inputs[i], learning_rate);

            // Calculate total error
            for (int j = 0; j < OUTPUT_SIZE; j++) {
                total_error += pow(expected_outputs[i][j] - output_layer[j].output, 2);
            }
        }
        printf("Epoch %d: Total error = %f\n", epoch+1, total_error);
    }
}

// Function to test neural network on input/output pairs
void test_network(neuron *hidden_layer, neuron *output_layer, double **inputs, double **expected_outputs, int num_inputs) {
    int num_correct = 0;
    for (int i = 0; i < num_inputs; i++) {
        feed_forward(hidden_layer, output_layer, inputs[i], expected_outputs[i]);
        int predicted_class = 0;
        double max_output = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (output_layer[j].output > max_output) {
                predicted_class = j;
                max_output = output_layer[j].output;
            }
        }
        int actual_class = -1;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            if (expected_outputs[i][j] == 1) {
                actual_class = j;
            }
        }
        if (predicted_class == actual_class) {
            num_correct++;
        }
    }
    printf("Accuracy: %f%%\n", (double)num_correct / num_inputs * 100);
}

int main() {
    // Initialize neural network
    neuron *hidden_layer;
    neuron *output_layer;
    init_network(&hidden_layer, &output_layer);

    // Load training data
    double **train_inputs = malloc(60000 * sizeof(double *));
    double **train_outputs = malloc(60000 * sizeof(double *));
    FILE *train_file = fopen("train_data.txt", "r");
    for (int i = 0; i < 60000; i++) {
        train_inputs[i] = malloc(INPUT_SIZE * sizeof(double));
        train_outputs[i] = malloc(OUTPUT_SIZE * sizeof(double));
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(train_file, "%lf", &train_inputs[i][j]);
        }
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(train_file, "%lf", &train_outputs[i][j]);
        }
    }
    fclose(train_file);

    // Load testing data
    double **test_inputs = malloc(10000 * sizeof(double *));
    double **test_outputs = malloc(10000 * sizeof(double *));
    FILE *test_file = fopen("test_data.txt", "r");
    for (int i = 0; i < 10000; i++) {
        test_inputs[i] = malloc(INPUT_SIZE * sizeof(double));
        test_outputs[i] = malloc(OUTPUT_SIZE * sizeof(double));
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(test_file, "%lf", &test_inputs[i][j]);
        }
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            fscanf(test_file, "%lf", &test_outputs[i][j]);
        }
    }
    fclose(test_file);

    // Train neural network
    train_network(hidden_layer, output_layer, train_inputs, train_outputs, 60000, 0.05, 50);

    // Test neural network
    test_network(hidden_layer, output_layer, test_inputs, test_outputs, 10000);

    // Free memory
    for (int i = 0; i < 60000; i++) {
        free(train_inputs[i]);
        free(train_outputs[i]);
    }
    for (int i = 0; i < 10000; i++) {
        free(test_inputs[i]);
        free(test_outputs[i]);
    }
    free(train_inputs);
    free(train_outputs);
    free(test_inputs);
    free(test_outputs);
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        free(hidden_layer[i].weights);
        free(hidden_layer[i].past_weights);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        free(output_layer[i].weights);
        free(output_layer[i].past_weights);
    }
    free(hidden_layer);
    free(output_layer);

    return 0;
}
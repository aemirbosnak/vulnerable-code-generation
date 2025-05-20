//FormAI DATASET v1.0 Category: Image Classification system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Defining constants
#define IMG_SIZE 784
#define NUM_CLASSES 10
#define NUM_HIDDEN_NODES 64
#define LEARNING_RATE 0.01

// Defining structures for the different layers of the neural network
typedef struct {
    double input[IMG_SIZE];
    double output[NUM_HIDDEN_NODES];
    double weights_ho[NUM_HIDDEN_NODES][NUM_CLASSES];
    double bias_o[NUM_CLASSES];
} OutputLayer;

typedef struct {
    double input[IMG_SIZE];
    double output[NUM_HIDDEN_NODES];
    double weights_ih[IMG_SIZE][NUM_HIDDEN_NODES];
    double bias_h[NUM_HIDDEN_NODES];
    OutputLayer output_layer;
} HiddenLayer;

// Function to initialize the weights and biases of the neural network with random values
void initialize_weights(HiddenLayer *hidden_layer) {
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < NUM_HIDDEN_NODES; j++) {
            hidden_layer->weights_ih[i][j] = ((double)rand() / (RAND_MAX)) - 0.5;
        }
    }

    for (int i = 0; i < NUM_HIDDEN_NODES; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            hidden_layer->output_layer.weights_ho[i][j] = ((double)rand() / (RAND_MAX)) - 0.5;
        }
        hidden_layer->bias_h[i] = ((double)rand() / (RAND_MAX)) - 0.5;
    }

    for (int i = 0; i < NUM_CLASSES; i++) {
        hidden_layer->output_layer.bias_o[i] = ((double)rand() / (RAND_MAX)) - 0.5;
    }
}

// Function to calculate the output of a layer using its inputs, weights, and biases
void calculate_layer_output(double *input, double *output, double **weights, double *bias, int input_size, int output_size) {
    for (int i = 0; i < output_size; i++) {
        double sum = 0;
        for (int j = 0; j < input_size; j++) {
            sum += input[j] * weights[j][i];
        }
        output[i] = 1 / (1 + exp(-(sum + bias[i])));
    }
}

// Function to train the neural network on a single input and label
void train_on_example(double *input, int label, HiddenLayer *hidden_layer) {
    // Feedforward
    calculate_layer_output(input, hidden_layer->output, hidden_layer->weights_ih, hidden_layer->bias_h, IMG_SIZE, NUM_HIDDEN_NODES);
    calculate_layer_output(hidden_layer->output, hidden_layer->output_layer.output, hidden_layer->output_layer.weights_ho, hidden_layer->output_layer.bias_o, NUM_HIDDEN_NODES, NUM_CLASSES);

    // Calculate output layer error and delta
    double output_layer_error[NUM_CLASSES];
    double output_layer_delta[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        output_layer_error[i] = i == label ? hidden_layer->output_layer.output[i] - 1 : hidden_layer->output_layer.output[i];
        output_layer_delta[i] = output_layer_error[i] * hidden_layer->output_layer.output[i] * (1 - hidden_layer->output_layer.output[i]);
    }

    // Calculate hidden layer delta
    double hidden_layer_delta[NUM_HIDDEN_NODES];
    for (int i = 0; i < NUM_HIDDEN_NODES; i++) {
        double weighted_sum = 0;
        for (int j = 0; j < NUM_CLASSES; j++) {
            weighted_sum += output_layer_delta[j] * hidden_layer->output_layer.weights_ho[i][j];
        }
        hidden_layer_delta[i] = weighted_sum * hidden_layer->output[i] * (1 - hidden_layer->output[i]);
    }

    // Update output layer weights and biases
    for (int i = 0; i < NUM_HIDDEN_NODES; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            hidden_layer->output_layer.weights_ho[i][j] -= LEARNING_RATE * output_layer_delta[j] * hidden_layer->output[i];
        }
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        hidden_layer->output_layer.bias_o[i] -= LEARNING_RATE * output_layer_delta[i];
    }

    // Update hidden layer weights and biases
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < NUM_HIDDEN_NODES; j++) {
            hidden_layer->weights_ih[i][j] -= LEARNING_RATE * hidden_layer_delta[j] * input[i];
        }
    }
    for (int i = 0; i < NUM_HIDDEN_NODES; i++) {
        hidden_layer->bias_h[i] -= LEARNING_RATE * hidden_layer_delta[i];
    }
}

// Function to test the neural network on a given set of inputs and labels, returning the accuracy
double test_accuracy(double **inputs, int *labels, int num_examples, HiddenLayer *hidden_layer) {
    int num_correct = 0;
    for (int i = 0; i < num_examples; i++) {
        calculate_layer_output(inputs[i], hidden_layer->output, hidden_layer->weights_ih, hidden_layer->bias_h, IMG_SIZE, NUM_HIDDEN_NODES);
        calculate_layer_output(hidden_layer->output, hidden_layer->output_layer.output, hidden_layer->output_layer.weights_ho, hidden_layer->output_layer.bias_o, NUM_HIDDEN_NODES, NUM_CLASSES);
        int max_index = 0;
        for (int j = 1; j < NUM_CLASSES; j++) {
            if (hidden_layer->output_layer.output[j] > hidden_layer->output_layer.output[max_index]) {
                max_index = j;
            }
        }
        if (max_index == labels[i]) {
            num_correct++;
        }
    }
    return ((double)num_correct) / ((double)num_examples);
}

int main() {
    // Load training and testing data
    FILE *training_file = fopen("train_data.txt", "r");
    FILE *labels_file = fopen("train_labels.txt", "r");
    FILE *testing_file = fopen("test_data.txt", "r");
    FILE *testing_labels_file = fopen("test_labels.txt", "r");

    double **training_data = malloc(60000 * sizeof(double *));
    int *training_labels = malloc(60000 * sizeof(int));
    double **testing_data = malloc(10000 * sizeof(double *));
    int *testing_labels = malloc(10000 * sizeof(int));

    for (int i = 0; i < 60000; i++) {
        training_data[i] = malloc(IMG_SIZE * sizeof(double));
        for (int j = 0; j < IMG_SIZE; j++) {
            fscanf(training_file, "%lf", &training_data[i][j]);
        }
        fscanf(labels_file, "%d", &training_labels[i]);
    }

    for (int i = 0; i < 10000; i++) {
        testing_data[i] = malloc(IMG_SIZE * sizeof(double));
        for (int j = 0; j < IMG_SIZE; j++) {
            fscanf(testing_file, "%lf", &testing_data[i][j]);
        }
        fscanf(testing_labels_file, "%d", &testing_labels[i]);
    }

    fclose(training_file);
    fclose(labels_file);
    fclose(testing_file);
    fclose(testing_labels_file);

    // Initialize neural network
    HiddenLayer hidden_layer;
    initialize_weights(&hidden_layer);

    // Train neural network on training data
    for (int epoch = 1; epoch <= 10; epoch++) {
        for (int i = 0; i < 60000; i++) {
            train_on_example(training_data[i], training_labels[i], &hidden_layer);
        }
        double accuracy = test_accuracy(testing_data, testing_labels, 10000, &hidden_layer);
        printf("Epoch %d: accuracy = %lf\n", epoch, accuracy);
    }

    // Free memory
    for (int i = 0; i < 60000; i++) {
        free(training_data[i]);
    }
    free(training_data);
    free(training_labels);
    for (int i = 0; i < 10000; i++) {
        free(testing_data[i]);
    }
    free(testing_data);
    free(testing_labels);

    return 0;
}
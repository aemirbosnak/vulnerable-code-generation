//FormAI DATASET v1.0 Category: Image Classification system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CLASSES 3
#define NUM_FEATURES 10
#define NUM_TRAINING_EXAMPLES 100
#define NUM_TEST_EXAMPLES 20
#define MAX_ITERATIONS 1000
#define LEARNING_RATE 0.05

typedef struct example {
    double* features;
    int label;
} example_t;

typedef struct network {
    double** weights;
    double* biases;
    int num_hidden_layers;
    int num_neurons_per_layer;
    int num_classes;
} network_t;

// Forward declaration of functions
void initialize_examples(example_t* examples, int num_examples, int num_features, int num_classes);
void free_examples(example_t* examples, int num_examples);
void print_example(example_t example);
void initialize_network(network_t* net, int num_features, int num_classes, int num_hidden_layers, int num_neurons_per_layer);
double sigmoid(double x);
void softmax(double* a, double* b, int n);
int predict(network_t net, double* x);
void train(network_t* net, example_t* examples, int num_examples);

int main(void) {
    example_t training_examples[NUM_TRAINING_EXAMPLES];
    initialize_examples(training_examples, NUM_TRAINING_EXAMPLES, NUM_FEATURES, NUM_CLASSES);
    printf("Training examples:\n");
    for (int i = 0; i < NUM_TRAINING_EXAMPLES; i++) {
        print_example(training_examples[i]);
    }

    network_t net;
    initialize_network(&net, NUM_FEATURES, NUM_CLASSES, 2, 5);
    printf("Initial weights and biases:\n");
    for (int i = 0; i <= net.num_hidden_layers; i++) {
        printf("Layer %d:\n", i);
        for (int j = 0; j < (i == 0 ? NUM_FEATURES : net.num_neurons_per_layer); j++) {
            printf("  Neuron %d:\n", j);
            if (i == net.num_hidden_layers) {
                printf("    Bias: %lf\n", net.biases[j]);
            }
            for (int k = 0; k < (i == 0 ? net.num_neurons_per_layer : net.num_classes); k++) {
                printf("    Weight %d: %lf\n", k, net.weights[i][j*(i==0?net.num_classes:1) + k]);
            }
        }
    }

    train(&net, training_examples, NUM_TRAINING_EXAMPLES);
    printf("Final weights and biases:\n");
    for (int i = 0; i <= net.num_hidden_layers; i++) {
        printf("Layer %d:\n", i);
        for (int j = 0; j < (i == 0 ? NUM_FEATURES : net.num_neurons_per_layer); j++) {
            printf("  Neuron %d:\n", j);
            if (i == net.num_hidden_layers) {
                printf("    Bias: %lf\n", net.biases[j]);
            }
            for (int k = 0; k < (i == 0 ? net.num_classes : net.num_classes); k++) {
                printf("    Weight %d: %lf\n", k, net.weights[i][j*(i==0?net.num_classes:1) + k]);
            }
        }
    }

    example_t test_examples[NUM_TEST_EXAMPLES];
    initialize_examples(test_examples, NUM_TEST_EXAMPLES, NUM_FEATURES, NUM_CLASSES);
    printf("Test examples:\n");
    double accuracy = 0.0;
    for (int i = 0; i < NUM_TEST_EXAMPLES; i++) {
        print_example(test_examples[i]);
        int expected_label = test_examples[i].label;
        int predicted_label = predict(net, test_examples[i].features);
        printf("  Expected label: %d\n", expected_label);
        printf("  Predicted label: %d\n", predicted_label);
        if (predicted_label == expected_label) {
            accuracy += 1.0;
        }
    }
    accuracy /= NUM_TEST_EXAMPLES;
    printf("Accuracy: %lf\n", accuracy);

    free_examples(training_examples, NUM_TRAINING_EXAMPLES);
    free_examples(test_examples, NUM_TEST_EXAMPLES);
    for (int i = 0; i <= net.num_hidden_layers; i++) {
        free(net.weights[i]);
    }
    free(net.weights);
    free(net.biases);

    return 0;
}

void initialize_examples(example_t* examples, int num_examples, int num_features, int num_classes) {
    srand(0);
    for (int i = 0; i < num_examples; i++) {
        examples[i].features = (double*)malloc(num_features * sizeof(double));
        for (int j = 0; j < num_features; j++) {
            examples[i].features[j] = (double)rand() / RAND_MAX;
        }
        examples[i].label = rand() % num_classes;
    }
}

void free_examples(example_t* examples, int num_examples) {
    for (int i = 0; i < num_examples; i++) {
        free(examples[i].features);
    }
}

void print_example(example_t example) {
    printf("Example:\n");
    printf("  Features: [ ");
    for (int i = 0; i < NUM_FEATURES; i++) {
        printf("%lf ", example.features[i]);
    }
    printf("]\n");
    printf("  Label: %d\n", example.label);
}

void initialize_network(network_t* net, int num_features, int num_classes, int num_hidden_layers, int num_neurons_per_layer) {
    net->weights = (double**)malloc((num_hidden_layers + 1) * sizeof(double*));
    for (int i = 0; i <= num_hidden_layers; i++) {
        if (i == num_hidden_layers) {
            net->weights[i] = (double*)malloc(num_neurons_per_layer * sizeof(double));
            net->biases = (double*)malloc(num_neurons_per_layer * sizeof(double));
        } else {
            net->weights[i] = (double*)malloc(num_neurons_per_layer * num_classes * sizeof(double));
        }
    }
    net->num_hidden_layers = num_hidden_layers;
    net->num_neurons_per_layer = num_neurons_per_layer;
    net->num_classes = num_classes;

    srand(1);
    for (int i = 0; i <= num_hidden_layers; i++) {
        for (int j = 0; j < (i == 0 ? num_features : num_neurons_per_layer); j++) {
            if (i == num_hidden_layers) {
                net->biases[j] = (double)rand() / RAND_MAX;
                for (int k = 0; k < num_classes; k++) {
                    net->weights[i][j*num_classes + k] = (double)rand() / RAND_MAX;
                }
            } else {
                for (int k = 0; k < num_classes; k++) {
                    net->weights[i][j*num_classes + k] = (double)rand() / RAND_MAX;
                }
            }
        }
    }
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void softmax(double* a, double* b, int n) {
    double max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        b[i] = exp(a[i] - max);
        sum += b[i];
    }
    for (int i = 0; i < n; i++) {
        b[i] /= sum;
    }
}

int predict(network_t net, double* x) {
    double* hidden = (double*)malloc(net.num_neurons_per_layer * sizeof(double));
    for (int i = 0; i < net.num_neurons_per_layer; i++) {
        double z = net.biases[i];
        for (int j = 0; j < NUM_FEATURES; j++) {
            z += net.weights[0][j*net.num_neurons_per_layer + i] * x[j];
        }
        hidden[i] = sigmoid(z);
    }

    double* output = (double*)malloc(net.num_classes * sizeof(double));
    for (int i = 0; i < net.num_classes; i++) {
        double z = net.biases[net.num_neurons_per_layer + i];
        for (int j = 0; j < net.num_neurons_per_layer; j++) {
            z += net.weights[1][j*net.num_classes + i] * hidden[j];
        }
        output[i] = z;
    }

    int predicted_label;
    softmax(output, output, net.num_classes);
    double max_prob = output[0];
    predicted_label = 0;
    for (int i = 1; i < net.num_classes; i++) {
        if (output[i] > max_prob) {
            max_prob = output[i];
            predicted_label = i;
        }
    }

    free(hidden);
    free(output);

    return predicted_label;
}

void train(network_t* net, example_t* examples, int num_examples) {
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        for (int i = 0; i < num_examples; i++) {
            double* hidden = (double*)malloc(net->num_neurons_per_layer * sizeof(double));
            double* output = (double*)malloc(net->num_classes * sizeof(double));

            // Forward pass
            for (int j = 0; j < net->num_neurons_per_layer; j++) {
                double z = net->biases[j];
                for (int k = 0; k < NUM_FEATURES; k++) {
                    z += net->weights[0][k*net->num_neurons_per_layer + j] * examples[i].features[k];
                }
                hidden[j] = sigmoid(z);
            }

            for (int j = 0; j < net->num_classes; j++) {
                double z = net->biases[net->num_neurons_per_layer + j];
                for (int k = 0; k < net->num_neurons_per_layer; k++) {
                    z += net->weights[1][k*net->num_classes + j] * hidden[k];
                }
                output[j] = z;
            }

            softmax(output, output, net->num_classes);

            // Backward pass
            double* delta_output = (double*)malloc(net->num_classes * sizeof(double));
            for (int j = 0; j < net->num_classes; j++) {
                delta_output[j] = (j == examples[i].label ? 1.0 : 0.0) - output[j];
            }

            double* delta_hidden = (double*)malloc(net->num_neurons_per_layer * sizeof(double));
            for (int j = 0; j < net->num_neurons_per_layer; j++) {
                double sum = 0.0;
                for (int k = 0; k < net->num_classes; k++) {
                    sum += net->weights[1][j*net->num_classes + k] * delta_output[k];
                }
                delta_hidden[j] = sum * hidden[j] * (1.0 - hidden[j]);
            }

            for (int j = 0; j < net->num_neurons_per_layer; j++) {
                double delta_b = delta_hidden[j] * LEARNING_RATE;
                net->biases[j] += delta_b;
                for (int k = 0; k < NUM_FEATURES; k++) {
                    net->weights[0][k*net->num_neurons_per_layer + j] += delta_b * examples[i].features[k];
                }
            }

            for (int j = 0; j < net->num_classes; j++) {
                double delta_b = delta_output[j] * LEARNING_RATE;
                net->biases[net->num_neurons_per_layer + j] += delta_b;
                for (int k = 0; k < net->num_neurons_per_layer; k++) {
                    net->weights[1][k*net->num_classes + j] += delta_b * hidden[k];
                }
            }

            free(hidden);
            free(output);
            free(delta_output);
            free(delta_hidden);
        }
    }
}
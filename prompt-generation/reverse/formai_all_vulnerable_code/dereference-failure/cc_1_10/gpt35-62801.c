//FormAI DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 50
#define OUTPUT_SIZE 10
#define BATCH_SIZE 100
#define EPOCHS 10

typedef struct {
    double *data;
    int label;
} Example;

typedef struct {
    double **weights;
    double *biases;
} Layer;

typedef struct {
    Layer hidden;
    Layer output;
} Network;

void init_layer(Layer *layer, int input_size, int output_size) {
    layer->weights = malloc(output_size * sizeof(double *));
    for (int i = 0; i < output_size; i++) {
        layer->weights[i] = malloc(input_size * sizeof(double));
        for (int j = 0; j < input_size; j++) {
            layer->weights[i][j] = (double)rand() / RAND_MAX - 0.5;
        }
    }
    layer->biases = malloc(output_size * sizeof(double));
    for (int i = 0; i < output_size; i++) {
        layer->biases[i] = 0.0;
    }
}

void free_layer(Layer *layer, int output_size) {
    for (int i = 0; i < output_size; i++) {
        free(layer->weights[i]);
    }
    free(layer->weights);
    free(layer->biases);
}

void init_network(Network *network) {
    init_layer(&network->hidden, INPUT_SIZE, HIDDEN_SIZE);
    init_layer(&network->output, HIDDEN_SIZE, OUTPUT_SIZE);
}

void free_network(Network *network) {
    free_layer(&network->hidden, HIDDEN_SIZE);
    free_layer(&network->output, OUTPUT_SIZE);
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void forward(Network *network, double *input, double *hidden, double *output) {
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += network->hidden.weights[i][j] * input[j];
        }
        hidden[i] = sigmoid(sum + network->hidden.biases[i]);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double sum = 0.0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            sum += network->output.weights[i][j] * hidden[j];
        }
        output[i] = sigmoid(sum + network->output.biases[i]);
    }
}

void backward(Network *network, double *input, double *hidden, double *output, int label) {
    double output_delta[OUTPUT_SIZE];
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double error = (i == label) ? output[i] - 1.0 : output[i];
        output_delta[i] = error * output[i] * (1.0 - output[i]);
    }
    double hidden_delta[HIDDEN_SIZE];
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double error = 0.0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            error += network->output.weights[j][i] * output_delta[j];
        }
        hidden_delta[i] = error * hidden[i] * (1.0 - hidden[i]);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            network->output.weights[i][j] -= output_delta[i] * hidden[j];
        }
        network->output.biases[i] -= output_delta[i];
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            network->hidden.weights[i][j] -= hidden_delta[i] * input[j];
        }
        network->hidden.biases[i] -= hidden_delta[i];
    }
}

double loss(double *output, int label) {
    double error = 0.0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double y = (i == label) ? 1.0 : 0.0;
        error += 0.5 * (output[i] - y) * (output[i] - y);
    }
    return error;
}

void train(Network *network, Example *examples, int num_examples) {
    int num_batches = num_examples / BATCH_SIZE;
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        double total_loss = 0.0;
        for (int batch = 0; batch < num_batches; batch++) {
            for (int i = 0; i < BATCH_SIZE; i++) {
                Example example = examples[batch * BATCH_SIZE + i];
                double hidden[HIDDEN_SIZE];
                double output[OUTPUT_SIZE];
                forward(network, example.data, hidden, output);
                backward(network, example.data, hidden, output, example.label);
                total_loss += loss(output, example.label);
            }
        }
        printf("Epoch %d loss: %f\n", epoch, total_loss / num_examples);
    }
}

int main() {
    // Load training examples
    FILE *fp = fopen("mnist_train.csv", "r");
    Example *examples = malloc(60000 * sizeof(Example));
    for (int i = 0; i < 60000; i++) {
        examples[i].data = malloc(INPUT_SIZE * sizeof(double));
        for (int j = 0; j < INPUT_SIZE; j++) {
            fscanf(fp, "%lf,", &examples[i].data[j]);
        }
        fscanf(fp, "%d", &examples[i].label);
    }
    fclose(fp);

    // Initialize network
    Network network;
    init_network(&network);

    // Train network
    train(&network, examples, 60000);

    // Free memory
    for (int i = 0; i < 60000; i++) {
        free(examples[i].data);
    }
    free(examples);
    free_network(&network);

    return 0;
}
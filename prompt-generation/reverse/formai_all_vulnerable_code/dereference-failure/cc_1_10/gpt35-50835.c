//FormAI DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 9
#define HIDDEN_SIZE 6
#define OUTPUT_SIZE 3
#define LEARNING_RATE 0.1

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}

typedef struct {
    int input_size;
    int hidden_size;
    int output_size;

    double **input_layer;
    double **hidden_layer;
    double **output_layer;

    double **weights_ih;
    double **weights_ho;

    double *bias_h;
    double *bias_o;
} NeuralNetwork;

void init_neural_network(NeuralNetwork *nn) {
    nn->input_layer = (double **) malloc(INPUT_SIZE * sizeof(double *));
    for (int i = 0; i < INPUT_SIZE; ++i) {
        nn->input_layer[i] = (double *) malloc(sizeof(double));
    }

    nn->hidden_layer = (double **) malloc(HIDDEN_SIZE * sizeof(double *));
    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        nn->hidden_layer[i] = (double *) malloc(sizeof(double));
    }

    nn->output_layer = (double **) malloc(OUTPUT_SIZE * sizeof(double *));
    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        nn->output_layer[i] = (double *) malloc(sizeof(double));
    }

    nn->weights_ih = (double **) malloc(INPUT_SIZE * sizeof(double *));
    for (int i = 0; i < INPUT_SIZE; ++i) {
        nn->weights_ih[i] = (double *) malloc(HIDDEN_SIZE * sizeof(double));
        for (int j = 0; j < HIDDEN_SIZE; ++j) {
            nn->weights_ih[i][j] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }

    nn->weights_ho = (double **) malloc(HIDDEN_SIZE * sizeof(double *));
    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        nn->weights_ho[i] = (double *) malloc(OUTPUT_SIZE * sizeof(double));
        for (int j = 0; j < OUTPUT_SIZE; ++j) {
            nn->weights_ho[i][j] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }

    nn->bias_h = (double *) malloc(HIDDEN_SIZE * sizeof(double));
    nn->bias_o = (double *) malloc(OUTPUT_SIZE * sizeof(double));

    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        nn->bias_h[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        nn->bias_o[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
}

void feed_forward(NeuralNetwork *nn) {
    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        double sum = nn->bias_h[i];
        for (int j = 0; j < INPUT_SIZE; ++j) {
            sum += nn->weights_ih[j][i] * nn->input_layer[j][0];
        }
        nn->hidden_layer[i][0] = sigmoid(sum);
    }

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        double sum = nn->bias_o[i];
        for (int j = 0; j < HIDDEN_SIZE; ++j) {
            sum += nn->weights_ho[j][i] * nn->hidden_layer[j][0];
        }
        nn->output_layer[i][0] = sigmoid(sum);
    }
}

void back_propagation(NeuralNetwork *nn, double *targets) {
    double **output_errors = (double **) malloc(OUTPUT_SIZE * sizeof(double *));
    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        output_errors[i] = (double *) malloc(sizeof(double));
        output_errors[i][0] = targets[i] - nn->output_layer[i][0];
    }

    double **hidden_errors = (double **) malloc(HIDDEN_SIZE * sizeof(double *));
    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        hidden_errors[i] = (double *) malloc(sizeof(double));
        double error = 0.0;
        for (int j = 0; j < OUTPUT_SIZE; ++j) {
            error += nn->weights_ho[i][j] * output_errors[j][0];
        }
        hidden_errors[i][0] = error;
    }

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        for (int j = 0; j < HIDDEN_SIZE; ++j) {
            double gradient = output_errors[i][0] * sigmoid_derivative(nn->output_layer[i][0]);
            nn->weights_ho[j][i] += LEARNING_RATE * nn->hidden_layer[j][0] * gradient;
            nn->bias_o[i] += LEARNING_RATE * gradient;
        }
    }

    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        for (int j = 0; j < INPUT_SIZE; ++j) {
            double gradient = hidden_errors[i][0] * sigmoid_derivative(nn->hidden_layer[i][0]);
            nn->weights_ih[j][i] += LEARNING_RATE * nn->input_layer[j][0] * gradient;
            nn->bias_h[i] += LEARNING_RATE * gradient;
        }
    }

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        free(output_errors[i]);
    }
    free(output_errors);

    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        free(hidden_errors[i]);
    }
    free(hidden_errors);
}

int main() {
    NeuralNetwork nn;
    nn.input_size = INPUT_SIZE;
    nn.hidden_size = HIDDEN_SIZE;
    nn.output_size = OUTPUT_SIZE;

    init_neural_network(&nn);

    double data[][3] = {{0, 0, 1},
                        {0, 1, 1},
                        {1, 0, 1},
                        {1, 1, 1}};
    double labels[][3] = {{0, 0, 1},
                          {0, 1, 1},
                          {1, 0, 1},
                          {1, 1, 0}};

    for (int i = 0; i < 100000; ++i) {
        int index = rand() % 4;
        for (int j = 0; j < INPUT_SIZE; ++j) {
            nn.input_layer[j][0] = data[index][j];
        }
        feed_forward(&nn);
        back_propagation(&nn, labels[index]);
    }

    printf("0 0 -> %f\n", nn.output_layer[0][0]);
    printf("0 1 -> %f\n", nn.output_layer[1][0]);
    printf("1 0 -> %f\n", nn.output_layer[2][0]);
    printf("1 1 -> %f\n", nn.output_layer[3][0]);

    for (int i = 0; i < INPUT_SIZE; ++i) {
        free(nn.input_layer[i]);
    }
    free(nn.input_layer);

    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        free(nn.hidden_layer[i]);
    }
    free(nn.hidden_layer);

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        free(nn.output_layer[i]);
    }
    free(nn.output_layer);

    for (int i = 0; i < INPUT_SIZE; ++i) {
        free(nn.weights_ih[i]);
    }
    free(nn.weights_ih);

    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        free(nn.weights_ho[i]);
    }
    free(nn.weights_ho);

    free(nn.bias_h);
    free(nn.bias_o);

    return 0;
}
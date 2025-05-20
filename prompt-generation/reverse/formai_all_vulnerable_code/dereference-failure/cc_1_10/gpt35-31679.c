//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define the neural network structure */
typedef struct network {
    int num_inputs;
    int num_hidden;
    int num_outputs;
    double **weights1;
    double **weights2;
} network;

/* Function to initialize the neural network with random weights */
void init_network(network *net) {
    int i, j;
    net->weights1 = malloc(net->num_inputs * sizeof(double *));
    net->weights2 = malloc(net->num_hidden * sizeof(double *));
    for (i = 0; i < net->num_inputs; i++) {
        net->weights1[i] = malloc(net->num_hidden * sizeof(double));
        for (j = 0; j < net->num_hidden; j++) {
            net->weights1[i][j] = ((double)rand()/(double)RAND_MAX) * 2.0 - 1.0;
        }
    }
    for (i = 0; i < net->num_hidden; i++) {
        net->weights2[i] = malloc(net->num_outputs * sizeof(double));
        for (j = 0; j < net->num_outputs; j++) {
            net->weights2[i][j] = ((double)rand()/(double)RAND_MAX) * 2.0 - 1.0;
        }
    }
}

/* Function to compute the output of the neural network */
void compute_output(network *net, double *input, double *output) {
    int i, j;
    double *hidden = malloc(net->num_hidden * sizeof(double));
    for (i = 0; i < net->num_hidden; i++) {
        hidden[i] = 0.0;
        for (j = 0; j < net->num_inputs; j++) {
            hidden[i] += input[j] * net->weights1[j][i];
        }
        hidden[i] = tanh(hidden[i]);
    }
    for (i = 0; i < net->num_outputs; i++) {
        output[i] = 0.0;
        for (j = 0; j < net->num_hidden; j++) {
            output[i] += hidden[j] * net->weights2[j][i];
        }
    }
    free(hidden);
}

/* Function to train the neural network using backpropagation */
void train_network(network *net, double *input, double *target, double learning_rate) {
    int i, j, k;
    double *hidden = malloc(net->num_hidden * sizeof(double));
    double *output = malloc(net->num_outputs * sizeof(double));
    double *delta1 = malloc(net->num_hidden * sizeof(double));
    double *delta2 = malloc(net->num_outputs * sizeof(double));

    /* Compute output and hidden layers */
    for (i = 0; i < net->num_hidden; i++) {
        hidden[i] = 0.0;
        for (j = 0; j < net->num_inputs; j++) {
            hidden[i] += input[j] * net->weights1[j][i];
        }
        hidden[i] = tanh(hidden[i]);
    }
    for (i = 0; i < net->num_outputs; i++) {
        output[i] = 0.0;
        for (j = 0; j < net->num_hidden; j++) {
            output[i] += hidden[j] * net->weights2[j][i];
        }
    }

    /* Compute error signal for output layer */
    for (i = 0; i < net->num_outputs; i++) {
        delta2[i] = (target[i] - output[i]) * (1 - output[i]*output[i]);
    }

    /* Compute error signal for hidden layer */
    for (i = 0; i < net->num_hidden; i++) {
        delta1[i] = 0.0;
        for (j = 0; j < net->num_outputs; j++) {
            delta1[i] += delta2[j] * net->weights2[i][j] * (1 - hidden[i]*hidden[i]);
        }
    }

    /* Update weights */
    for (i = 0; i < net->num_inputs; i++) {
        for (j = 0; j < net->num_hidden; j++) {
            net->weights1[i][j] += learning_rate * delta1[j] * input[i];
        }
    }
    for (i = 0; i < net->num_hidden; i++) {
        for (j = 0; j < net->num_outputs; j++) {
            net->weights2[i][j] += learning_rate * delta2[j] * hidden[i];
        }
    }
    free(hidden);
    free(output);
    free(delta1);
    free(delta2);
}

/* Function to detect an intrusion */
int detect_intrusion(network *net, double *input, double *target, int num_inputs, int num_outputs) {
    int i, j;
    double *output = malloc(num_outputs * sizeof(double));
    compute_output(net, input, output);
    for (i = 0; i < num_outputs; i++) {
        if (output[i] > target[i]) {
            free(output);
            return 1; /* Intrusion detected */
        }
    }
    free(output);
    return 0; /* No intrusion detected */
}

int main() {
    network net;
    double input[] = {1.0, 0.0, 1.0, 0.0};
    double target[] = {1.0, 0.0, 1.0, 0.0};
    int num_inputs = 4;
    int num_hidden = 2;
    int num_outputs = 4;
    double learning_rate = 0.1;

    /* Initialize neural network */
    net.num_inputs = num_inputs;
    net.num_hidden = num_hidden;
    net.num_outputs = num_outputs;
    init_network(&net);

    /* Train neural network to recognize benign traffic */
    train_network(&net, input, target, learning_rate);

    /* Detect intrusion */
    if (detect_intrusion(&net, input, target, num_inputs, num_outputs)) {
        printf("Intrusion detected!\n");
    } else {
        printf("No intrusion detected.\n");
    }
    return 0;
}
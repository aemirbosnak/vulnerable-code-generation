//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
// Initializing the neural network for log analysis
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void neuralNet(int inputLayer, int hiddenLayer, int outputLayer) {
    int i, j, k;
    double input[inputLayer];
    double hidden[hiddenLayer];
    double output[outputLayer];

    // Initializing the weights of the neural network
    double **hiddenWeights = (double **)malloc(inputLayer * sizeof(double *));
    for (i = 0; i < inputLayer; i++)
        hiddenWeights[i] = (double *)malloc(hiddenLayer * sizeof(double));
    double **outputWeights = (double **)malloc(hiddenLayer * sizeof(double *));
    for (i = 0; i < hiddenLayer; i++)
        outputWeights[i] = (double *)malloc(outputLayer * sizeof(double));
    srand(time(NULL));
    for (i = 0; i < inputLayer; i++) {
        for (j = 0; j < hiddenLayer; j++) {
            hiddenWeights[i][j] = ((double)rand()/(double)RAND_MAX)-0.5;
        }
    }
    for (i = 0; i < hiddenLayer; i++) {
        for (j = 0; j < outputLayer; j++) {
            outputWeights[i][j] = ((double)rand()/(double)RAND_MAX)-0.5;
        }
    }

    // Initializing the biases of the neural network
    double hiddenBias[hiddenLayer], outputBias[outputLayer];
    for (i = 0; i < hiddenLayer; i++) {
        hiddenBias[i] = ((double)rand()/(double)RAND_MAX)-0.5;
    }
    for (i = 0; i < outputLayer; i++) {
        outputBias[i] = ((double)rand()/(double)RAND_MAX)-0.5;
    }

    // Loading the log file
    FILE *file;
    char str[100];
    file = fopen("log.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Analyzing the log file line by line
    int lineNumber = 0;
    while (fgets(str, 100, file) != NULL) {
        lineNumber++;
        printf("Line %d: %s", lineNumber, str);
        // Converting the log line to input array
        for (i = 0; i < inputLayer; i++) {
            input[i] = (double)str[i];
        }
        // Forward propagation through the neural network
        for (i = 0; i < hiddenLayer; i++) {
            double sum = 0;
            for (j = 0; j < inputLayer; j++) {
                sum += input[j] * hiddenWeights[j][i];
            }
            hidden[i] = 1 / (1 + exp(-sum + hiddenBias[i]));
        }
        for (i = 0; i < outputLayer; i++) {
            double sum = 0;
            for (j = 0; j < hiddenLayer; j++) {
                sum += hidden[j] * outputWeights[j][i];
            }
            output[i] = 1 / (1 + exp(-sum + outputBias[i]));
        }
        // Deciding the output based on the neural network output
        if (output[0] > output[1]) {
            printf("This log line is not suspicious.\n");
        } else {
            printf("This log line is suspicious!\n");
        }
    }
}

int main() {
    // Initializing the neural network with 8 inputs, 4 hidden neurons and 2 outputs
    neuralNet(8, 4, 2);
    return 0;
}
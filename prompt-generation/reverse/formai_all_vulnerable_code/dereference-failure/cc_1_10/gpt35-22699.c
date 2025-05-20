//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void filterSamples(double* input, double* output, double* coefficients, int length, int order);

int main() {
    int i, j, order = 5, numSamples = BUFFER_SIZE, numIterations = 10;
    double *inputBuffer, *outputBuffer, *coefficients;

    // Allocate memory for input and output buffers
    inputBuffer = (double*) malloc(numSamples * sizeof(double));
    outputBuffer = (double*) malloc(numSamples * sizeof(double));

    // Initialize input buffer with random samples
    for(i = 0; i < numSamples; i++) {
        inputBuffer[i] = (double) rand() / (double) RAND_MAX;
    }

    // Allocate memory for filter coefficients
    coefficients = (double*) malloc((order + 1) * sizeof(double));

    // Initialize filter coefficients with random values
    for(i = 0; i <= order; i++) {
        coefficients[i] = (double) rand() / (double) RAND_MAX;
    }

    // Apply filter for multiple iterations
    for(i = 0; i < numIterations; i++) {
        filterSamples(inputBuffer, outputBuffer, coefficients, numSamples, order);
    }

    // Print filtered output samples
    printf("Filtered Output Samples:\n");
    for(i = 0; i < numSamples; i++) {
        printf("%f\n", outputBuffer[i]);
    }

    // Free memory
    free(inputBuffer);
    free(outputBuffer);
    free(coefficients);

    return 0;
}

void filterSamples(double* input, double* output, double* coefficients, int length, int order) {
    int i, j;
    double sum;

    for(i = order; i < length; i++) {
        sum = 0.0;
        for(j = 0; j <= order; j++) {
            sum += coefficients[j] * input[i-j];
        }
        output[i] = sum;
    }
}
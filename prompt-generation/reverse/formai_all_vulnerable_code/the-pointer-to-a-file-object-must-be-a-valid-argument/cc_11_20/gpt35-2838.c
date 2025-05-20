//FormAI DATASET v1.0 Category: Image Classification system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define neural network parameters
#define INPUT_LAYER_SIZE 784   // 28x28 image pixels
#define HIDDEN_LAYER_SIZE 50   
#define OUTPUT_LAYER_SIZE 10   // digits from 0 to 9

// Set learning rate and number of iterations 
#define ALPHA 0.5
#define ITERATIONS 10000

// Declare activation function and its derivative
double sigmoid(double x);
double sigmoid_derivative(double x);

int main() {

    // Load training data
    // Assumes a file 'train_data.txt' with 60000 rows and 785 columns
    FILE *fp;
    char data[100];
    double train_data[60000][785];
    fp = fopen("train_data.txt", "r");
    int i = 0, j = 0;
    while (fgets(data, 100, fp) != NULL) {
        char *token = strtok(data, ",");
        j = 0;
        while (token != NULL) {
            train_data[i][j] = atof(token);
            j++;
            token = strtok(NULL, ",");
        }
        i++;
    }
    fclose(fp);

    // Initialize weights randomly
    double input_hidden_weights[INPUT_LAYER_SIZE][HIDDEN_LAYER_SIZE];
    double hidden_output_weights[HIDDEN_LAYER_SIZE][OUTPUT_LAYER_SIZE];
    for (i=0; i<INPUT_LAYER_SIZE; i++) {
        for (j=0; j<HIDDEN_LAYER_SIZE; j++) {
            input_hidden_weights[i][j] = rand() / (double) RAND_MAX;
        }
    }
    for (i=0; i<HIDDEN_LAYER_SIZE; i++) {
        for (j=0; j<OUTPUT_LAYER_SIZE; j++) {
            hidden_output_weights[i][j] = rand() / (double) RAND_MAX;
        }
    }

    // Train neural network with backpropagation
    int k, m, n;
    double output[OUTPUT_LAYER_SIZE];
    double error[OUTPUT_LAYER_SIZE];
    for (k=0; k<ITERATIONS; k++) {
        double loss = 0;
        for (m=0; m<60000; m++) {

            // Forward propagation
            double hidden[HIDDEN_LAYER_SIZE];
            for (i=0; i<HIDDEN_LAYER_SIZE; i++) {
                double sum = 0;
                for (j=0; j<INPUT_LAYER_SIZE; j++) {
                    sum += train_data[m][j] * input_hidden_weights[j][i];
                }
                hidden[i] = sigmoid(sum);
            }
            for (i=0; i<OUTPUT_LAYER_SIZE; i++) {
                double sum = 0;
                for (j=0; j<HIDDEN_LAYER_SIZE; j++) {
                    sum += hidden[j] * hidden_output_weights[j][i];
                }
                output[i] = sigmoid(sum);
            }

            // Calculate error
            for (i=0; i<OUTPUT_LAYER_SIZE; i++) {
                error[i] = train_data[m][784] == i ? output[i] - 1 : output[i];
                loss += error[i] * error[i];
            }

            // Backpropagation
            double hidden_error[HIDDEN_LAYER_SIZE];
            for (i=0; i<HIDDEN_LAYER_SIZE; i++) {
                double sum = 0;
                for (j=0; j<OUTPUT_LAYER_SIZE; j++) {
                    sum += error[j] * hidden_output_weights[i][j];
                }
                hidden_error[i] = sum * sigmoid_derivative(hidden[i]);
            }

            // Update weights
            for (i=0; i<HIDDEN_LAYER_SIZE; i++) {
                for (j=0; j<OUTPUT_LAYER_SIZE; j++) {
                    hidden_output_weights[i][j] += ALPHA * error[j] * hidden[i];
                }
            }
            for (i=0; i<INPUT_LAYER_SIZE; i++) {
                for (j=0; j<HIDDEN_LAYER_SIZE; j++) {
                    input_hidden_weights[i][j] += ALPHA * hidden_error[j] * train_data[m][i];
                }
            }
        }
        printf("Iteration %d, loss=%f\n", k, loss);
    }

    // Load test data
    // Assumes a file 'test_data.txt' with 10000 rows and 785 columns
    double test_data[10000][785];
    fp = fopen("test_data.txt", "r");
    i = 0;
    j = 0;
    while (fgets(data, 100, fp) != NULL) {
        char *token = strtok(data, ",");
        j = 0;
        while (token != NULL) {
            test_data[i][j] = atof(token);
            j++;
            token = strtok(NULL, ",");
        }
        i++;
    }
    fclose(fp);

    // Test neural network on test data
    int correct = 0;
    for (m=0; m<10000; m++) {
        double hidden[HIDDEN_LAYER_SIZE];
        for (i=0; i<HIDDEN_LAYER_SIZE; i++) {
            double sum = 0;
            for (j=0; j<INPUT_LAYER_SIZE; j++) {
                sum += test_data[m][j] * input_hidden_weights[j][i];
            }
            hidden[i] = sigmoid(sum);
        }
        for (i=0; i<OUTPUT_LAYER_SIZE; i++) {
            double sum = 0;
            for (j=0; j<HIDDEN_LAYER_SIZE; j++) {
                sum += hidden[j] * hidden_output_weights[j][i];
            }
            output[i] = sigmoid(sum);
        }
        int prediction = 0;
        double max_output = 0;
        for (i=0; i<OUTPUT_LAYER_SIZE; i++) {
            if (output[i] > max_output) {
                prediction = i;
                max_output = output[i];
            }
        }
        if (test_data[m][784] == prediction) {
            correct++;
        }
    }
    double accuracy = (double) correct / 10000;
    printf("Accuracy on test data: %f\n", accuracy);

    return 0;
}

// Sigmoid activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Derivative of sigmoid activation function
double sigmoid_derivative(double x) {
    double sigmoid_x = sigmoid(x);
    return sigmoid_x * (1 - sigmoid_x);
}
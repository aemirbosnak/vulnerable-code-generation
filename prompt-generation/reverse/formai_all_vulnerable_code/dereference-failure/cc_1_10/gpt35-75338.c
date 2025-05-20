//FormAI DATASET v1.0 Category: Image Classification system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define NUM_FEATURES 784 // number of features for each image
#define NUM_CLASSES 10 // number of image classes
#define NUM_HIDDEN_LAYERS 2 // number of hidden layers
#define HIDDEN_LAYER_SIZE 256 // size of each hidden layer
#define LEARNING_RATE 0.001

// Define struct for the neural network
typedef struct {
    double w1[NUM_FEATURES*HIDDEN_LAYER_SIZE]; // weights for input to first hidden layer
    double b1[HIDDEN_LAYER_SIZE]; // biases for first hidden layer
    double w2[HIDDEN_LAYER_SIZE*HIDDEN_LAYER_SIZE]; // weights for first hidden layer to second hidden layer
    double b2[HIDDEN_LAYER_SIZE]; // biases for second hidden layer
    double w3[HIDDEN_LAYER_SIZE*NUM_CLASSES]; // weights for second hidden layer to output layer
    double b3[NUM_CLASSES]; // biases for output layer
} NeuralNetwork;

// Define sigmoid activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Define softmax activation function
void softmax(double* x, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        x[i] = exp(x[i]);
        total += x[i];
    }
    for (int i = 0; i < size; i++) {
        x[i] /= total;
    }
}

// Define function to forward propagate through neural network
void forward(NeuralNetwork* nn, double* x, double* y) {
    // Compute values for first hidden layer
    double h1[HIDDEN_LAYER_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        h1[i] = 0;
        for (int j = 0; j < NUM_FEATURES; j++) {
            h1[i] += nn->w1[j*HIDDEN_LAYER_SIZE+i] * x[j];
        }
        h1[i] += nn->b1[i];
        h1[i] = sigmoid(h1[i]);
    }

    // Compute values for second hidden layer
    double h2[HIDDEN_LAYER_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        h2[i] = 0;
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            h2[i] += nn->w2[j*HIDDEN_LAYER_SIZE+i] * h1[j];
        }
        h2[i] += nn->b2[i];
        h2[i] = sigmoid(h2[i]);
    }

    // Compute output values
    for (int i = 0; i < NUM_CLASSES; i++) {
        y[i] = 0;
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            y[i] += nn->w3[j*NUM_CLASSES+i] * h2[j];
        }
        y[i] += nn->b3[i];
    }
    softmax(y, NUM_CLASSES);
}

// Define function to backward propagate through neural network
void backward(NeuralNetwork* nn, double* x, double* y, int label) {
    double d3[NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        d3[i] = label == i ? y[i] - 1 : y[i];
    }

    double d2[HIDDEN_LAYER_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        d2[i] = 0;
        for (int j = 0; j < NUM_CLASSES; j++) {
            d2[i] += d3[j] * nn->w3[i*NUM_CLASSES+j];
        }
        d2[i] *= sigmoid(nn->b2[i]);
    }

    double d1[HIDDEN_LAYER_SIZE];
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        d1[i] = 0;
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            d1[i] += d2[j] * nn->w2[j*HIDDEN_LAYER_SIZE+i];
        }
        d1[i] *= sigmoid(nn->b1[i]);
    }

    // Update weights and biases
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            nn->w1[j*HIDDEN_LAYER_SIZE+i] -= LEARNING_RATE * d1[i] * x[j];
        }
        nn->b1[i] -= LEARNING_RATE * d1[i];
    }

    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            nn->w2[j*HIDDEN_LAYER_SIZE+i] -= LEARNING_RATE * d2[i] * sigmoid(nn->b1[j]);
        }
        nn->b2[i] -= LEARNING_RATE * d2[i];
    }

    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            nn->w3[j*NUM_CLASSES+i] -= LEARNING_RATE * d3[i] * sigmoid(nn->b2[j]);
        }
        nn->b3[i] -= LEARNING_RATE * d3[i];
    }
}

int main() {
    // Load MNIST dataset
    double** x_train = malloc(sizeof(double*) * 60000);
    int* y_train = malloc(sizeof(int) * 60000);
    for (int i = 0; i < 60000; i++) {
        x_train[i] = malloc(sizeof(double) * NUM_FEATURES);
        FILE* f = fopen("train-images-idx3-ubyte", "rb");
        fseek(f, 16 + i*NUM_FEATURES, SEEK_SET);
        fread(&(x_train[i][0]), sizeof(char), NUM_FEATURES, f);
        fclose(f);
        FILE* g = fopen("train-labels-idx1-ubyte", "rb");
        fseek(g, 8 + i, SEEK_SET);
        fread(&(y_train[i]), sizeof(char), 1, g);
        fclose(g);
    }

    double** x_test = malloc(sizeof(double*) * 10000);
    int* y_test = malloc(sizeof(int) * 10000);
    for (int i = 0; i < 10000; i++) {
        x_test[i] = malloc(sizeof(double) * NUM_FEATURES);
        FILE* f = fopen("t10k-images-idx3-ubyte", "rb");
        fseek(f, 16 + i*NUM_FEATURES, SEEK_SET);
        fread(&(x_test[i][0]), sizeof(char), NUM_FEATURES, f);
        fclose(f);
        FILE* g = fopen("t10k-labels-idx1-ubyte", "rb");
        fseek(g, 8 + i, SEEK_SET);
        fread(&(y_test[i]), sizeof(char), 1, g);
        fclose(g);
    }

    // Train neural network
    NeuralNetwork nn;
    srand(42);
    for (int i = 0; i < NUM_FEATURES*HIDDEN_LAYER_SIZE; i++) {
        nn.w1[i] = (double) rand() / RAND_MAX - 0.5;
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        nn.b1[i] = 0;
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE*HIDDEN_LAYER_SIZE; i++) {
        nn.w2[i] = (double) rand() / RAND_MAX - 0.5;
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        nn.b2[i] = 0;
    }
    for (int i = 0; i < HIDDEN_LAYER_SIZE*NUM_CLASSES; i++) {
        nn.w3[i] = (double) rand() / RAND_MAX - 0.5;
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        nn.b3[i] = 0;
    }

    for (int epoch = 0; epoch < 10; epoch++) {
        printf("Epoch %d\n", epoch+1);
        for (int i = 0; i < 60000; i++) {
            if (i % 1000 == 0) {
                printf("Training image %d\n", i+1);
            }
            double y[NUM_CLASSES];
            forward(&nn, x_train[i], y);
            backward(&nn, x_train[i], y, y_train[i]);
        }
    }

    // Evaluate neural network
    int num_correct = 0;
    for (int i = 0; i < 10000; i++) {
        double y[NUM_CLASSES];
        forward(&nn, x_test[i], y);
        int max_index = 0;
        for (int j = 1; j < NUM_CLASSES; j++) {
            if (y[j] > y[max_index]) {
                max_index = j;
            }
        }
        if (max_index == y_test[i]) {
            num_correct++;
        }
    }
    printf("Accuracy: %lf\n", (double) num_correct / 10000);

    // Free memory
    for (int i = 0; i < 60000; i++) {
        free(x_train[i]);
    }
    free(x_train);
    free(y_train);
    for (int i = 0; i < 10000; i++) {
        free(x_test[i]);
    }
    free(x_test);
    free(y_test);

    return 0;
}
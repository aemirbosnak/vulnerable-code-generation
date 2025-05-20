//FormAI DATASET v1.0 Category: Image Classification system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_INPUTS 784
#define NUM_HIDDEN 16
#define NUM_OUTPUTS 10

// Activation function
float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

// Forward propagation
void forward(float *inputs, float *hidden, float *outputs, float *h_weights, float *o_weights, float *h_biases, float *o_biases) {
    // Calculate hidden layer values
    for (int i = 0; i < NUM_HIDDEN; i++) {
        hidden[i] = 0.0;
        for (int j = 0; j < NUM_INPUTS; j++) {
            hidden[i] += inputs[j] * h_weights[j * NUM_HIDDEN + i];
        }
        hidden[i] += h_biases[i];
        hidden[i] = sigmoid(hidden[i]);
    }

    // Calculate output layer values
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        outputs[i] = 0.0;
        for (int j = 0; j < NUM_HIDDEN; j++) {
            outputs[i] += hidden[j] * o_weights[j * NUM_OUTPUTS + i];
        }
        outputs[i] += o_biases[i];
        outputs[i] = sigmoid(outputs[i]);
    }
}

// Train the neural network
void train(float *inputs, int label, float *h_weights, float *o_weights, float *h_biases, float *o_biases, float learning_rate) {
    float hidden[NUM_HIDDEN];
    float outputs[NUM_OUTPUTS];
    float label_data[NUM_OUTPUTS] = {0.0};
    label_data[label] = 1.0;

    // Forward propagation
    forward(inputs, hidden, outputs, h_weights, o_weights, h_biases, o_biases);

    // Backpropagation for output layer
    float o_delta[NUM_OUTPUTS];
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        float err = label_data[i] - outputs[i];
        o_delta[i] = err * outputs[i] * (1.0 - outputs[i]);
        for (int j = 0; j < NUM_HIDDEN; j++) {
            o_weights[j * NUM_OUTPUTS + i] += learning_rate * hidden[j] * o_delta[i];
        }
        o_biases[i] += learning_rate * o_delta[i];
    }

    // Backpropagation for hidden layer
    float h_delta[NUM_HIDDEN];
    for (int i = 0; i < NUM_HIDDEN; i++) {
        float err = 0.0;
        for (int j = 0; j < NUM_OUTPUTS; j++) {
            err += o_delta[j] * o_weights[i * NUM_OUTPUTS + j];
        }
        h_delta[i] = err * hidden[i] * (1.0 - hidden[i]);
        for (int j = 0; j < NUM_INPUTS; j++) {
            h_weights[j * NUM_HIDDEN + i] += learning_rate * inputs[j] * h_delta[i];
        }
        h_biases[i] += learning_rate * h_delta[i];
    }
}

// Test the neural network
int test(float *inputs, int label, float *h_weights, float *o_weights, float *h_biases, float *o_biases) {
    float hidden[NUM_HIDDEN];
    float outputs[NUM_OUTPUTS];

    // Forward propagation
    forward(inputs, hidden, outputs, h_weights, o_weights, h_biases, o_biases);

    int max_index = 0;
    float max_output = 0.0;
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        if (outputs[i] > max_output) {
            max_output = outputs[i];
            max_index = i;
        }
    }

    return (max_index == label) ? 1 : 0;
}

int main() {
    // Load MNIST data
    printf("Loading MNIST data...\n");
    float *train_images = (float*) malloc(sizeof(float) * 60000 * 784);
    float *train_labels = (float*) malloc(sizeof(float) * 60000);
    float *test_images = (float*) malloc(sizeof(float) * 10000 * 784);
    float *test_labels = (float*) malloc(sizeof(float) * 10000);
    FILE *fp1 = fopen("train-images-idx3-ubyte", "rb");
    FILE *fp2 = fopen("train-labels-idx1-ubyte", "rb");
    FILE *fp3 = fopen("t10k-images-idx3-ubyte", "rb");
    FILE *fp4 = fopen("t10k-labels-idx1-ubyte", "rb");
    fseek(fp1, 16, SEEK_SET);
    fseek(fp2, 8, SEEK_SET);
    fseek(fp3, 16, SEEK_SET);
    fseek(fp4, 8, SEEK_SET);
    for (int i = 0; i < 60000; i++) {
        for (int j = 0; j < 784; j++) {
	    unsigned char temp = 0;
            fread(&temp, 1, 1, fp1);
            train_images[i * 784 + j] = ((float) temp) / 255.0;
        }
        unsigned char label_data;
        fread(&label_data, 1, 1, fp2);
        train_labels[i] = (float) label_data;
    }
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 784; j++) {
	    unsigned char temp = 0;
            fread(&temp, 1, 1, fp3);
            test_images[i * 784 + j] = ((float) temp) / 255.0;
        }
        unsigned char label_data;
        fread(&label_data, 1, 1, fp4);
        test_labels[i] = (float) label_data;
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    
    // Initialize weights and biases
    printf("Initializing weights and biases...\n");
    float *h_weights = (float*) malloc(sizeof(float) * NUM_INPUTS * NUM_HIDDEN);
    float *o_weights = (float*) malloc(sizeof(float) * NUM_HIDDEN * NUM_OUTPUTS);
    float *h_biases = (float*) malloc(sizeof(float) * NUM_HIDDEN);
    float *o_biases = (float*) malloc(sizeof(float) * NUM_OUTPUTS);
    for (int i = 0; i < NUM_INPUTS * NUM_HIDDEN; i++) {
        h_weights[i] = ((float) rand() / RAND_MAX) * 0.1 - 0.05;
    }
    for (int i = 0; i < NUM_HIDDEN * NUM_OUTPUTS; i++) {
        o_weights[i] = ((float) rand() / RAND_MAX) * 0.1 - 0.05;
    }
    for (int i = 0; i < NUM_HIDDEN; i++) {
        h_biases[i] = ((float) rand() / RAND_MAX) * 0.1 - 0.05;
    }
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        o_biases[i] = ((float) rand() / RAND_MAX) * 0.1 - 0.05;
    }
    
    // Train the neural network
    printf("Training...\n");
    int num_epochs = 30;
    float learning_rate = 0.1;
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        int num_correct = 0;
        for (int i = 0; i < 60000; i++) {
            train(&train_images[i * 784], (int) train_labels[i], h_weights, o_weights, h_biases, o_biases, learning_rate);
        }
        for (int i = 0; i < 10000; i++) {
            num_correct += test(&test_images[i * 784], (int) test_labels[i], h_weights, o_weights, h_biases, o_biases);
        }
        float accuracy = (float) num_correct / 10000.0;
        printf("Epoch %d: accuracy = %f\n", epoch, accuracy);
    }
    
    // Clean up
    free(train_images);
    free(train_labels);
    free(test_images);
    free(test_labels);
    free(h_weights);
    free(o_weights);
    free(h_biases);
    free(o_biases);
    
    return 0;
}
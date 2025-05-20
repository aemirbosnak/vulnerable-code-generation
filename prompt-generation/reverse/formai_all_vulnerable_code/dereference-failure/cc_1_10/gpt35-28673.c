//FormAI DATASET v1.0 Category: Image Classification system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 100
#define IMG_SIZE 28
#define IMG_PIXELS (IMG_SIZE * IMG_SIZE)
#define CLASSES 10
#define HIDDEN_LAYER_SIZE 16
#define EPOCHS 20
#define BATCH_SIZE 10
#define LEARNING_RATE 0.01

double vector_dot_product(double *v1, double *v2, int size) {
    double result = 0.0;
    for(int i = 0; i < size; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

void feedforward(double **weights1, double **weights2, double *input, double *hidden_layer_output, double *output) {
    // Calculate hidden layer output
    for(int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        hidden_layer_output[i] = sigmoid(vector_dot_product(input, weights1[i], IMG_PIXELS));
    }

    // Calculate output layer output
    for(int i = 0; i < CLASSES; i++) {
        output[i] = sigmoid(vector_dot_product(hidden_layer_output, weights2[i], HIDDEN_LAYER_SIZE));
    }
}

void train(double **weights1, double **weights2, double **images, int *labels, int num_images) {
    for(int epoch = 0; epoch < EPOCHS; epoch++) {
        printf("Epoch %d\n", epoch+1);
        for(int i = 0; i < num_images; i+=BATCH_SIZE) {
            double *batch_inputs[BATCH_SIZE];
            int batch_labels[BATCH_SIZE];

            // Select batch inputs and labels
            for(int j = 0; j < BATCH_SIZE; j++) {
                if(i+j >= num_images) {
                    break;
                }
                batch_inputs[j] = images[i+j];
                batch_labels[j] = labels[i+j];
            }

            // Initialize gradient variables
            double grad_weights1[HIDDEN_LAYER_SIZE][IMG_PIXELS], grad_weights2[CLASSES][HIDDEN_LAYER_SIZE] = {0};
            double delta_output[CLASSES], delta_hidden_layer[HIDDEN_LAYER_SIZE];

            // Compute gradients for each image in the batch
            for(int j = 0; j < BATCH_SIZE && i+j < num_images; j++) {
                double hidden_layer_output[HIDDEN_LAYER_SIZE], output[CLASSES];
                feedforward(weights1, weights2, batch_inputs[j], hidden_layer_output, output);

                // Compute output layer delta
                for(int k = 0; k < CLASSES; k++) {
                    delta_output[k] = (batch_labels[j] == k) - output[k];
                }

                // Compute delta for hidden layer
                for(int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    double weighted_delta_output[CLASSES], delta_output_weighted_sum = 0.0;
                    for(int l = 0; l < CLASSES; l++) {
                        weighted_delta_output[l] = delta_output[l] * weights2[l][k];
                        delta_output_weighted_sum += weighted_delta_output[l];
                    }
                    delta_hidden_layer[k] = delta_output_weighted_sum * sigmoid_derivative(hidden_layer_output[k]);
                }

                // Update gradients for weights2
                for(int k = 0; k < CLASSES; k++) {
                    for(int l = 0; l < HIDDEN_LAYER_SIZE; l++) {
                        grad_weights2[k][l] += delta_output[k] * hidden_layer_output[l];
                    }
                }

                // Update gradients for weights1
                for(int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    for(int l = 0; l < IMG_PIXELS; l++) {
                        grad_weights1[k][l] += delta_hidden_layer[k] * batch_inputs[j][l];
                    }
                }
            }

            // Perform weight updates
            for(int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
                for(int k = 0; k < IMG_PIXELS; k++) {
                    weights1[j][k] += LEARNING_RATE * grad_weights1[j][k] / BATCH_SIZE;
                }
            }

            for(int j = 0; j < CLASSES; j++) {
                for(int k = 0; k < HIDDEN_LAYER_SIZE; k++) {
                    weights2[j][k] += LEARNING_RATE * grad_weights2[j][k] / BATCH_SIZE;
                }
            }
        }
    }
}

int predict(double **weights1, double **weights2, double *input) {
    double hidden_layer_output[HIDDEN_LAYER_SIZE], output[CLASSES];
    feedforward(weights1, weights2, input, hidden_layer_output, output);

    int max_index = 0;
    for(int i = 1; i < CLASSES; i++) {
        if(output[i] > output[max_index]) {
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    // Load MNIST data
    FILE *fp;
    fp = fopen("train-images-idx3-ubyte", "rb");
    int magic_number = 0, num_images = 0, num_rows = 0, num_cols = 0;
    fread(&magic_number, sizeof(int), 1, fp);
    fread(&num_images, sizeof(int), 1, fp);
    fread(&num_rows, sizeof(int), 1, fp);
    fread(&num_cols, sizeof(int), 1, fp);
    num_rows = num_cols = IMG_SIZE; // Resize images to 28x28

    double **images = (double **) malloc(num_images * sizeof(double *));
    for(int i = 0; i < num_images; i++) {
        images[i] = (double *) malloc(IMG_PIXELS * sizeof(double));
        unsigned char image[IMG_SIZE * IMG_SIZE];
        fread(&image, sizeof(unsigned char), IMG_SIZE * IMG_SIZE, fp);
        for(int j = 0; j < IMG_SIZE * IMG_SIZE; j++) {
            images[i][j] = ((double) image[j]) / 255.0;
        }
    }
    fclose(fp);

    fp = fopen("train-labels-idx1-ubyte", "rb");
    fread(&magic_number, sizeof(int), 1, fp);
    fread(&num_images, sizeof(int), 1, fp);

    int *labels = (int *) malloc(num_images * sizeof(int));
    fread(labels, sizeof(unsigned char), num_images, fp);
    fclose(fp);

    // Initialize weights
    double **weights1 = (double **) malloc(HIDDEN_LAYER_SIZE * sizeof(double *));
    for(int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
        weights1[i] = (double *) malloc(IMG_PIXELS * sizeof(double));
        for(int j = 0; j < IMG_PIXELS; j++) {
            weights1[i][j] = ((double) rand()) / RAND_MAX;
        }
    }

    double **weights2 = (double **) malloc(CLASSES * sizeof(double *));
    for(int i = 0; i < CLASSES; i++) {
        weights2[i] = (double *) malloc(HIDDEN_LAYER_SIZE * sizeof(double));
        for(int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
            weights2[i][j] = ((double) rand()) / RAND_MAX;
        }
    }

    // Train model
    printf("Training model...\n");
    train(weights1, weights2, images, labels, num_images);
    printf("Model trained!\n");

    // Load test data
    fp = fopen("t10k-images-idx3-ubyte", "rb");
    fread(&magic_number, sizeof(int), 1, fp);
    fread(&num_images, sizeof(int), 1, fp);
    fread(&num_rows, sizeof(int), 1, fp);
    fread(&num_cols, sizeof(int), 1, fp);
    num_rows = num_cols = IMG_SIZE; // Resize images to 28x28

    double **test_images = (double **) malloc(num_images * sizeof(double *));
    for(int i = 0; i < num_images; i++) {
        test_images[i] = (double *) malloc(IMG_PIXELS * sizeof(double));
        unsigned char image[IMG_SIZE * IMG_SIZE];
        fread(&image, sizeof(unsigned char), IMG_SIZE * IMG_SIZE, fp);
        for(int j = 0; j < IMG_SIZE * IMG_SIZE; j++) {
            test_images[i][j] = ((double) image[j]) / 255.0;
        }
    }
    fclose(fp);

    fp = fopen("t10k-labels-idx1-ubyte", "rb");
    fread(&magic_number, sizeof(int), 1, fp);
    fread(&num_images, sizeof(int), 1, fp);

    int *test_labels = (int *) malloc(num_images * sizeof(int));
    fread(test_labels, sizeof(unsigned char), num_images, fp);
    fclose(fp);

    // Evaluate model on test set
    int num_correct = 0;
    for(int i = 0; i < num_images; i++) {
        int predicted_label = predict(weights1, weights2, test_images[i]);
        if(predicted_label == test_labels[i]) {
            num_correct++;
        }
    }

    printf("Accuracy on test set: %.2f%% (%d/%d)\n", ((double) num_correct) / num_images * 100.0, num_correct, num_images);

    return 0;
}
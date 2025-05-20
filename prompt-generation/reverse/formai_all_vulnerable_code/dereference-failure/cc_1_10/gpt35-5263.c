//FormAI DATASET v1.0 Category: Image Classification system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define constant variables
#define TRAIN_DATA_SIZE 1000
#define TEST_DATA_SIZE 500
#define IMAGE_SIZE 784
#define NUM_CLASSES 10
#define NUM_ITERATIONS 1000
#define LEARNING_RATE 0.01

// Initialize train and test data arrays
int train_data[TRAIN_DATA_SIZE][IMAGE_SIZE];
int train_labels[TRAIN_DATA_SIZE];
int test_data[TEST_DATA_SIZE][IMAGE_SIZE];
int test_labels[TEST_DATA_SIZE];

// Initialize weight and bias arrays
float weights[NUM_CLASSES][IMAGE_SIZE];
float biases[NUM_CLASSES];

// Function to read in MNIST dataset
void read_mnist(char *filename, int num_images, int num_rows, int num_cols, int data[num_images][num_rows*num_cols], int labels[num_images]) {
    FILE *fp = fopen(filename, "rb");
    if (fp != NULL) {
        // Read in number of images and image size
        int magic_number = 0;
        fread(&magic_number, sizeof(magic_number), 1, fp);
        magic_number = ntohl(magic_number);
        if (magic_number != 2051) {
            fprintf(stderr, "Error: Invalid MNIST image file format.\n");
            exit(1);
        }
        int num_images_read = 0;
        fread(&num_images_read, sizeof(num_images_read), 1, fp);
        num_images_read = ntohl(num_images_read);
        if (num_images_read != num_images) {
            fprintf(stderr, "Error: Incorrect number of MNIST images.\n");
            exit(1);
        }
        int num_rows_read = 0;
        fread(&num_rows_read, sizeof(num_rows_read), 1, fp);
        num_rows_read = ntohl(num_rows_read);
        if (num_rows_read != num_rows) {
            fprintf(stderr, "Error: Incorrect MNIST image row size.\n");
            exit(1);
        }
        int num_cols_read = 0;
        fread(&num_cols_read, sizeof(num_cols_read), 1, fp);
        num_cols_read = ntohl(num_cols_read);
        if (num_cols_read != num_cols) {
            fprintf(stderr, "Error: Incorrect MNIST image column size.\n");
            exit(1);
        }
        // Read in pixel data and labels
        for (int i = 0; i < num_images; i++) {
            for (int j = 0; j < num_rows*num_cols; j++) {
                int pixel = 0;
                fread(&pixel, sizeof(pixel), 1, fp);
                data[i][j] = ntohl(pixel);
            }
            int label = 0;
            fread(&label, sizeof(label), 1, fp);
            labels[i] = ntohl(label);
        }
    }
    fclose(fp);
}

// Function to train classifier
void train_classifier() {
    // Initialize weight and bias arrays with random values
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            weights[i][j] = (float)rand() / (float)RAND_MAX;
        }
        biases[i] = (float)rand() / (float)RAND_MAX;
    }
    // Perform gradient descent for each image
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        for (int j = 0; j < TRAIN_DATA_SIZE; j++) {
            // Calculate dot product of weight vector and image vector
            float dot_product[NUM_CLASSES];
            for (int k = 0; k < NUM_CLASSES; k++) {
                dot_product[k] = 0.0;
                for (int m = 0; m < IMAGE_SIZE; m++) {
                    dot_product[k] += weights[k][m] * train_data[j][m];
                }
                dot_product[k] += biases[k];
            }
            // Softmax activation function
            float softmax[NUM_CLASSES];
            float total = 0.0;
            for (int k = 0; k < NUM_CLASSES; k++) {
                softmax[k] = exp(dot_product[k]);
                total += softmax[k];
            }
            for (int k = 0; k < NUM_CLASSES; k++) {
                softmax[k] /= total;
            }
            // Calculate cross-entropy loss for given label
            float loss = -log(softmax[train_labels[j]]);
            // Calculate gradient of loss for each weight and bias
            float weight_gradient[NUM_CLASSES][IMAGE_SIZE];
            float bias_gradient[NUM_CLASSES];
            for (int k = 0; k < NUM_CLASSES; k++) {
                bias_gradient[k] = softmax[k];
                if (k == train_labels[j]) {
                    bias_gradient[k] -= 1.0;
                }
                for (int m = 0; m < IMAGE_SIZE; m++) {
                    weight_gradient[k][m] = train_data[j][m] * softmax[k];
                    if (k == train_labels[j]) {
                        weight_gradient[k][m] -= train_data[j][m];
                    }
                }
            }
            // Update weights and biases using gradient descent
            for (int k = 0; k < NUM_CLASSES; k++) {
                for (int m = 0; m < IMAGE_SIZE; m++) {
                    weights[k][m] -= LEARNING_RATE * weight_gradient[k][m];
                }
                biases[k] -= LEARNING_RATE * bias_gradient[k];
            }
        }
    }
}

// Function to test classifier
void test_classifier() {
    // Initialize variables to track accuracy and confusion matrix
    int correct = 0;
    int count_matrix[NUM_CLASSES][NUM_CLASSES];
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            count_matrix[i][j] = 0;
        }
    }
    // Classify each test image and update accuracy and confusion matrix
    for (int i = 0; i < TEST_DATA_SIZE; i++) {
        // Calculate dot product of weight vector and image vector
        float dot_product[NUM_CLASSES];
        for (int k = 0; k < NUM_CLASSES; k++) {
            dot_product[k] = 0.0;
            for (int m = 0; m < IMAGE_SIZE; m++) {
                dot_product[k] += weights[k][m] * test_data[i][m];
            }
            dot_product[k] += biases[k];
        }
        // Softmax activation function
        float softmax[NUM_CLASSES];
        float total = 0.0;
        for (int k = 0; k < NUM_CLASSES; k++) {
            softmax[k] = exp(dot_product[k]);
            total += softmax[k];
        }
        for (int k = 0; k < NUM_CLASSES; k++) {
            softmax[k] /= total;
        }
        // Find index of highest value in softmax output
        int prediction = 0;
        float max_value = 0.0;
        for (int k = 0; k < NUM_CLASSES; k++) {
            if (softmax[k] > max_value) {
                max_value = softmax[k];
                prediction = k;
            }
        }
        if (prediction == test_labels[i]) {
            correct++;
        }
        count_matrix[test_labels[i]][prediction]++;
    }
    // Print accuracy and confusion matrix
    printf("Accuracy: %.2f%%\n\n", (float)correct / (float)TEST_DATA_SIZE * 100.0);
    printf("Confusion matrix:\n\n");
    printf("       ");
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("%5d ", i);
    }
    printf("\n");
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("%5d: ", i);
        for (int j = 0; j < NUM_CLASSES; j++) {
            printf("%5d ", count_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Read in MNIST training and testing data
    read_mnist("train-images-idx3-ubyte", TRAIN_DATA_SIZE, IMAGE_SIZE, 1, train_data, train_labels);
    read_mnist("t10k-images-idx3-ubyte", TEST_DATA_SIZE, IMAGE_SIZE, 1, test_data, test_labels);
    // Train classifier and test accuracy
    train_classifier();
    test_classifier();
    return 0;
}
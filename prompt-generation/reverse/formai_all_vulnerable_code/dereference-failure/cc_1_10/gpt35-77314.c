//FormAI DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 500
#define NUM_FEATURES 784
#define NUM_CLASSES 10
#define LEARNING_RATE 0.1
#define MAX_EPOCHS 1000

// Struct to encapsulate training data
typedef struct {
    float** data;
    int* labels;
    int num_samples;
} TrainingData;

// Helper function to allocate memory for training data
TrainingData* create_training_data(int num_samples, int num_features) {
    TrainingData* data = malloc(sizeof(TrainingData));
    data->num_samples = num_samples;
    data->data = malloc(num_samples * sizeof(float*));
    for (int i = 0; i < num_samples; i++) {
        data->data[i] = malloc(num_features * sizeof(float));
    }
    data->labels = malloc(num_samples * sizeof(int));
    return data;
}

// Helper function to read in MNIST data
TrainingData* read_mnist_data(char* images_file, char* labels_file) {
    TrainingData* data = create_training_data(NUM_SAMPLES, NUM_FEATURES);
    FILE* images_fp = fopen(images_file, "rb");
    FILE* labels_fp = fopen(labels_file, "rb");
    if (images_fp == NULL || labels_fp == NULL) {
        fprintf(stderr, "Error opening input files!\n");
        exit(1);
    }
    // Skip header data in MNIST files
    fseek(images_fp, 16, SEEK_SET);
    fseek(labels_fp, 8, SEEK_SET);
    // Read in image data
    for (int i = 0; i < NUM_SAMPLES; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            unsigned char pixel = 0;
            if (!fread(&pixel, sizeof(unsigned char), 1, images_fp)) {
                fprintf(stderr, "Error reading image data!\n");
                exit(1);
            }
            data->data[i][j] = pixel / 255.0;
        }
        unsigned char label = 0;
        if (!fread(&label, sizeof(unsigned char), 1, labels_fp)) {
            fprintf(stderr, "Error reading label data!\n");
            exit(1);
        }
        data->labels[i] = label;
    }
    fclose(images_fp);
    fclose(labels_fp);
    return data;
}

// Compute softmax probabilities for given input data and weights
void softmax(float* x, float* w, float* p) {
    float sum = 0.0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        float dot = 0.0;
        for (int j = 0; j < NUM_FEATURES; j++) {
            dot += w[i * NUM_FEATURES + j] * x[j];
        }
        p[i] = exp(dot);
        sum += p[i];
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        p[i] /= sum;
    }
}

// Compute gradient of cross-entropy loss with respect to the weights
void compute_gradient(float* x, int y, float* w, float* gradient) {
    float p[NUM_CLASSES];
    softmax(x, w, p);
    for (int i = 0; i < NUM_CLASSES; i++) {
        gradient[i] = p[i];
    }
    gradient[y] -= 1.0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        gradient[i * NUM_CLASSES + y] *= x[i];
    }
}

// Train the model on the given data for a set number of epochs
float* train_model(TrainingData* data) {
    float* weights = malloc(NUM_CLASSES * NUM_FEATURES * sizeof(float));
    for (int i = 0; i < NUM_CLASSES * NUM_FEATURES; i++) {
        weights[i] = ((float)rand() / (float)RAND_MAX) * 2.0 - 1.0;
    }
    for (int epoch = 0; epoch < MAX_EPOCHS; epoch++) {
        float loss = 0.0;
        for (int i = 0; i < data->num_samples; i++) {
            float gradient[NUM_CLASSES * NUM_FEATURES];
            compute_gradient(data->data[i], data->labels[i], weights, gradient);
            for (int j = 0; j < NUM_CLASSES * NUM_FEATURES; j++) {
                weights[j] -= LEARNING_RATE * gradient[j];
            }
            float p[NUM_CLASSES];
            softmax(data->data[i], weights, p);
            loss += -log(p[data->labels[i]]);
        }
        printf("Epoch %d: loss=%f\n", epoch, loss / (float)data->num_samples);
    }
    return weights;
}

// Test the trained model on a set of input data
float test_model(float* weights, float** test_data, int* test_labels, int num_test_samples) {
    int num_correct = 0;
    for (int i = 0; i < num_test_samples; i++) {
        float p[NUM_CLASSES];
        softmax(test_data[i], weights, p);
        int predicted_label = 0;
        float max_prob = 0.0;
        for (int j = 0; j < NUM_CLASSES; j++) {
            if (p[j] > max_prob) {
                predicted_label = j;
                max_prob = p[j];
            }
        }
        if (predicted_label == test_labels[i]) {
            num_correct++;
        }
    }
    return (float)num_correct / (float)num_test_samples;
}

int main() {
    TrainingData* train_data = read_mnist_data("train-images.idx3-ubyte", "train-labels.idx1-ubyte");
    TrainingData* test_data = read_mnist_data("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
    float* weights = train_model(train_data);
    printf("Training accuracy: %f\n", test_model(weights, train_data->data, train_data->labels, train_data->num_samples));
    printf("Test accuracy: %f\n", test_model(weights, test_data->data, test_data->labels, test_data->num_samples));
    free(weights);
    for (int i = 0; i < NUM_SAMPLES; i++) {
        free(train_data->data[i]);
        free(test_data->data[i]);
    }
    free(train_data->data);
    free(test_data->data);
    free(train_data->labels);
    free(test_data->labels);
    free(train_data);
    free(test_data);
    return 0;
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRAIN_SIZE 1000
#define TEST_SIZE 200
#define IMAGE_SIZE 28

// Define a struct for each image
typedef struct {
    unsigned char pixels[IMAGE_SIZE][IMAGE_SIZE];
    char label;
} Image;

// Define a struct for the neural network
typedef struct {
    double weights[10][IMAGE_SIZE * IMAGE_SIZE];
} Network;

// Normalize pixel values
void normalize(unsigned char pixels[IMAGE_SIZE][IMAGE_SIZE], double normalized[IMAGE_SIZE][IMAGE_SIZE]) {
    double max_pixel = 255.0;
    for(int i = 0; i < IMAGE_SIZE; i++) {
        for(int j = 0; j < IMAGE_SIZE; j++) {
            normalized[i][j] = (double)pixels[i][j] / max_pixel;
        }
    }
}

// Calculate sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Calculate softmax activation function
void softmax(double x[], int n) {
    double max = x[0];
    for(int i = 1; i < n; i++) {
        if(x[i] > max) {
            max = x[i];
        }
    }
    double scale = 0.0;
    for(int i = 0; i < n; i++) {
        x[i] = exp(x[i] - max);
        scale += x[i];
    }
    for(int i = 0; i < n; i++) {
        x[i] /= scale;
    }
}

// Make a prediction using the neural network
int predict(Image image, Network net) {
    double normalized[IMAGE_SIZE][IMAGE_SIZE];
    normalize(image.pixels, normalized);
    double inputs[IMAGE_SIZE * IMAGE_SIZE];
    for(int i = 0; i < IMAGE_SIZE; i++) {
        for(int j = 0; j < IMAGE_SIZE; j++) {
            inputs[i * IMAGE_SIZE + j] = normalized[i][j];
        }
    }
    double activations[10];
    for(int i = 0; i < 10; i++) {
        double sum = 0.0;
        for(int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            sum += net.weights[i][j] * inputs[j];
        }
        activations[i] = sigmoid(sum);
    }
    softmax(activations, 10);
    int max_index = 0;
    double max_value = activations[0];
    for(int i = 1; i < 10; i++) {
        if(activations[i] > max_value) {
            max_index = i;
            max_value = activations[i];
        }
    }
    return max_index;
}

// Train the neural network using backpropagation
void train(Network *net, Image images[TRAIN_SIZE], int epochs, double learning_rate) {
    for(int e = 1; e <= epochs; e++) {
        for(int i = 0; i < TRAIN_SIZE; i++) {
            Image image = images[i];
            double normalized[IMAGE_SIZE][IMAGE_SIZE];
            normalize(image.pixels, normalized);
            double inputs[IMAGE_SIZE * IMAGE_SIZE];
            for(int j = 0; j < IMAGE_SIZE; j++) {
                for(int k = 0; k < IMAGE_SIZE; k++) {
                    inputs[j * IMAGE_SIZE + k] = normalized[j][k];
                }
            }
            double activations[10];
            for(int j = 0; j < 10; j++) {
                double sum = 0.0;
                for(int k = 0; k < IMAGE_SIZE * IMAGE_SIZE; k++) {
                    sum += net->weights[j][k] * inputs[k];
                }
                activations[j] = sigmoid(sum);
            }
            softmax(activations, 10);
            double targets[10];
            memset(targets, 0, sizeof(targets));
            targets[image.label] = 1.0;
            double errors[10];
            for(int j = 0; j < 10; j++) {
                errors[j] = activations[j] - targets[j];
            }
            double gradients[10][IMAGE_SIZE * IMAGE_SIZE];
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < IMAGE_SIZE * IMAGE_SIZE; k++) {
                    gradients[j][k] = errors[j] * activations[j] * (1.0 - activations[j]) * inputs[k];
                    net->weights[j][k] -= learning_rate * gradients[j][k];
                }
            }
        }
        printf("Epoch %d complete\n", e);
    }
}

int main() {
    // Load training images and labels
    FILE *f1 = fopen("train-images-idx3-ubyte", "rb");
    FILE *f2 = fopen("train-labels-idx1-ubyte", "rb");
    if(!f1 || !f2) {
        printf("Failed to open training files\n");
        return 1;
    }
    unsigned char buffer[4];
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f2);
    fread(buffer, 1, 4, f2);
    int train_labels[TRAIN_SIZE];
    for(int i = 0; i < TRAIN_SIZE; i++) {
        unsigned char pixels[IMAGE_SIZE][IMAGE_SIZE];
        fread(pixels, 1, IMAGE_SIZE * IMAGE_SIZE, f1);
        train_labels[i] = fgetc(f2);
    }
    fclose(f1);
    fclose(f2);
    // Load test images and labels
    f1 = fopen("t10k-images-idx3-ubyte", "rb");
    f2 = fopen("t10k-labels-idx1-ubyte", "rb");
    if(!f1 || !f2) {
        printf("Failed to open test files\n");
        return 1;
    }
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f1);
    fread(buffer, 1, 4, f2);
    fread(buffer, 1, 4, f2);
    Image test_images[TEST_SIZE];
    int test_labels[TEST_SIZE];
    for(int i = 0; i < TEST_SIZE; i++) {
        unsigned char pixels[IMAGE_SIZE][IMAGE_SIZE];
        fread(pixels, 1, IMAGE_SIZE * IMAGE_SIZE, f1);
        test_images[i].label = fgetc(f2);
        memcpy(test_images[i].pixels, pixels, sizeof(pixels));
        test_labels[i] = test_images[i].label;
    }
    fclose(f1);
    fclose(f2);
    // Train the neural network
    Network net;
    srand(0);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < IMAGE_SIZE * IMAGE_SIZE; j++) {
            net.weights[i][j] = (double)rand() / RAND_MAX;
        }
    }
    train(&net, test_images, 10, 0.1);
    // Make predictions on test images
    int correct = 0;
    for(int i = 0; i < TEST_SIZE; i++) {
        int prediction = predict(test_images[i], net);
        if(prediction == test_labels[i]) {
            correct++;
        }
    }
    double accuracy = (double)correct / TEST_SIZE * 100;
    printf("Classification accuracy: %.2f%%\n", accuracy);
    return 0;
}
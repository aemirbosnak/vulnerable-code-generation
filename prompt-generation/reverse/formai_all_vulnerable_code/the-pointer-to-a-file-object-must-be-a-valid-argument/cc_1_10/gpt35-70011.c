//FormAI DATASET v1.0 Category: Image Classification system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 5
#define IMAGE_SIZE 64
#define NUM_IMAGES 500

typedef struct Image {
    int label;
    int pixels[IMAGE_SIZE][IMAGE_SIZE];
} Image;

typedef struct Classifier {
    double weights[NUM_CLASSES][IMAGE_SIZE][IMAGE_SIZE];
    double bias[NUM_CLASSES];
} Classifier;

void train(Classifier* clf, Image* images, int num_images, int num_epochs);
int predict(Classifier* clf, Image* image);
double sigmoid(double x);
double dot(double* x, double* y, int size);

int main() {
    Image images[NUM_IMAGES];
    Classifier clf;

    // Load image and label data
    FILE* file = fopen("data.txt", "r");
    char line[IMAGE_SIZE*IMAGE_SIZE+2];
    for (int i = 0; i < NUM_IMAGES; i++) {
        fgets(line, IMAGE_SIZE*IMAGE_SIZE+2, file);
        images[i].label = line[0] - '0';
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                images[i].pixels[j][k] = line[2+j*IMAGE_SIZE+k] - '0';
            }
        }
    }
    fclose(file);

    // Train classifier
    train(&clf, images, NUM_IMAGES, 100);

    // Test classifier on random image
    Image test_image;
    printf("Enter 64 pixels (0 or 1):\n");
    for (int j = 0; j < IMAGE_SIZE; j++) {
        for (int k = 0; k < IMAGE_SIZE; k++) {
            scanf("%d", &test_image.pixels[j][k]);
        }
    }
    printf("Predicted class: %d\n", predict(&clf, &test_image));

    return 0;
}

void train(Classifier* clf, Image* images, int num_images, int num_epochs) {
    // Initialize weights and bias randomly
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int k = 0; k < IMAGE_SIZE; k++) {
                clf->weights[i][j][k] = (double)rand() / RAND_MAX;
            }
        }
        clf->bias[i] = (double)rand() / RAND_MAX;
    }

    // Train classifier using stochastic gradient descent
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        for (int i = 0; i < num_images; i++) {
            // Compute activation for each class
            double activations[NUM_CLASSES];
            for (int j = 0; j < NUM_CLASSES; j++) {
                double* weights = clf->weights[j][0];
                double* pixels = images[i].pixels[0];
                activations[j] = sigmoid(dot(weights, pixels, IMAGE_SIZE*IMAGE_SIZE) + clf->bias[j]);
            }

            // Compute gradient for each class
            double gradients[NUM_CLASSES];
            for (int j = 0; j < NUM_CLASSES; j++) {
                gradients[j] = activations[j] - (j == images[i].label ? 1 : 0);
            }

            // Update weights and bias using gradients
            for (int j = 0; j < NUM_CLASSES; j++) {
                double* weights = clf->weights[j][0];
                double* pixels = images[i].pixels[0];
                double learning_rate = 0.1;
                for (int k = 0; k < IMAGE_SIZE*IMAGE_SIZE; k++) {
                    weights[k] -= learning_rate * gradients[j] * pixels[k];
                }
                clf->bias[j] -= learning_rate * gradients[j];
            }
        }
        printf("Epoch %d complete\n", epoch+1);
    }
}

int predict(Classifier* clf, Image* image) {
    // Compute activation for each class
    double activations[NUM_CLASSES];
    for (int j = 0; j < NUM_CLASSES; j++) {
        double* weights = clf->weights[j][0];
        double* pixels = image->pixels[0];
        activations[j] = sigmoid(dot(weights, pixels, IMAGE_SIZE*IMAGE_SIZE) + clf->bias[j]);
    }

    // Return index of class with highest activation
    int max_index = 0;
    double max_activation = activations[0];
    for (int j = 1; j < NUM_CLASSES; j++) {
        if (activations[j] > max_activation) {
            max_index = j;
            max_activation = activations[j];
        }
    }
    return max_index;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double dot(double* x, double* y, int size) {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += x[i] * y[i];
    }
    return result;
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGES 5000
#define IMAGE_SIZE 784
#define NUM_CLASSES 10
#define LEARNING_RATE 0.001

float weights[NUM_CLASSES][IMAGE_SIZE];
float bias[NUM_CLASSES];
int train_images[MAX_IMAGES][IMAGE_SIZE];
int train_labels[MAX_IMAGES];
int test_images[MAX_IMAGES][IMAGE_SIZE];
int test_labels[MAX_IMAGES];
float activation[NUM_CLASSES];

void load_data(char *filename, int **images, int *labels, int max_images) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int label;
    for (int i = 0; i < max_images; ++i) {
        fread(&label, sizeof(unsigned char), 1, fp);
        labels[i] = label;

        for (int j = 0; j < IMAGE_SIZE; ++j) {
            fread(&images[i][j], sizeof(unsigned char), 1, fp);
        }
    }

    fclose(fp);
}

void init_weights_and_bias(float scale) {
    for (int i = 0; i < NUM_CLASSES; ++i) {
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            weights[i][j] = scale * ((float)rand() / RAND_MAX);
        }
        bias[i] = scale * ((float)rand() / RAND_MAX);
    }
}

void train(int num_images, int num_epochs) {
    for (int epoch = 0; epoch < num_epochs; ++epoch) {
        for (int i = 0; i < num_images; ++i) {
            memset(activation, 0, sizeof(activation));
            for (int c = 0; c < NUM_CLASSES; ++c) {
                for (int j = 0; j < IMAGE_SIZE; ++j) {
                    activation[c] += weights[c][j] * train_images[i][j];
                }
                activation[c] += bias[c];
            }

            float max_activation = -INFINITY;
            int max_index = -1;
            for (int c = 0; c < NUM_CLASSES; ++c) {
                if (activation[c] > max_activation) {
                    max_activation = activation[c];
                    max_index = c;
                }
            }

            if (train_labels[i] != max_index) {
                for (int j = 0; j < IMAGE_SIZE; ++j) {
                    weights[train_labels[i]][j] += LEARNING_RATE * train_images[i][j];
                    weights[max_index][j] -= LEARNING_RATE * train_images[i][j];
                }
                bias[train_labels[i]] += LEARNING_RATE;
                bias[max_index] -= LEARNING_RATE;
            }
        }
    }
}

int test(int num_images) {
    int num_correct = 0;
    for (int i = 0; i < num_images; ++i) {
        memset(activation, 0, sizeof(activation));
        for (int c = 0; c < NUM_CLASSES; ++c) {
            for (int j = 0; j < IMAGE_SIZE; ++j) {
                activation[c] += weights[c][j] * test_images[i][j];
            }
            activation[c] += bias[c];
        }

        float max_activation = -INFINITY;
        int max_index = -1;
        for (int c = 0; c < NUM_CLASSES; ++c) {
            if (activation[c] > max_activation) {
                max_activation = activation[c];
                max_index = c;
            }
        }

        if (test_labels[i] == max_index) {
            ++num_correct;
        }
    }
    return num_correct;
}

int main() {
    // Load data
    load_data("train-images.idx3-ubyte", train_images, train_labels, MAX_IMAGES);
    load_data("t10k-images.idx3-ubyte", test_images, test_labels, MAX_IMAGES);

    // Initialize weights and bias
    init_weights_and_bias(0.01);

    // Train model
    int num_epochs = 10;
    train(MAX_IMAGES, num_epochs);

    // Test model
    int num_correct = test(MAX_IMAGES);
    float accuracy = (float)num_correct / MAX_IMAGES * 100.0;
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}
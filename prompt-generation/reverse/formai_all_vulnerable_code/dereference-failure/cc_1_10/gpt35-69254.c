//FormAI DATASET v1.0 Category: Image Classification system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define WIDTH 28
#define HEIGHT 28
#define LABELS 10
#define TOTAL_IMAGES 500

// Declare variables
float image_data[TOTAL_IMAGES][WIDTH * HEIGHT];
int label_data[TOTAL_IMAGES];

// Load image and label data from files
void load_data() {
    FILE *image_file = fopen("images.dat", "rb");
    FILE *label_file = fopen("labels.dat", "rb");

    if (image_file == NULL || label_file == NULL) {
        printf("Error: Could not open data files.\n");
        exit(1);
    }

    // Load images
    for (int i = 0; i < TOTAL_IMAGES; i++) {
        fread(image_data[i], sizeof(float), WIDTH * HEIGHT, image_file);
    }

    // Load labels
    for (int i = 0; i < TOTAL_IMAGES; i++) {
        fread(&label_data[i], sizeof(int), 1, label_file);
    }

    // Close files
    fclose(image_file);
    fclose(label_file);
}

// Classify an image using a simple neural network
int classify_image(float *image) {
    // Define weights and biases
    float hidden_weights[WIDTH * HEIGHT][32];
    float hidden_biases[32];
    float output_weights[32][LABELS];
    float output_biases[LABELS];

    // Initialize weights and biases randomly
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        for (int j = 0; j < 32; j++) {
            hidden_weights[i][j] = (float)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < 32; i++) {
        hidden_biases[i] = (float)rand() / RAND_MAX;
    }

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < LABELS; j++) {
            output_weights[i][j] = (float)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < LABELS; i++) {
        output_biases[i] = (float)rand() / RAND_MAX;
    }

    // Feed forward through network
    float hidden_values[32];
    float output_values[LABELS];

    for (int i = 0; i < 32; i++) {
        float sum = 0.0;

        for (int j = 0; j < WIDTH * HEIGHT; j++) {
            sum += image[j] * hidden_weights[j][i];
        }

        hidden_values[i] = sum + hidden_biases[i];
        hidden_values[i] = hidden_values[i] > 0 ? hidden_values[i] : 0;
    }

    for (int i = 0; i < LABELS; i++) {
        float sum = 0.0;

        for (int j = 0; j < 32; j++) {
            sum += hidden_values[j] * output_weights[j][i];
        }

        output_values[i] = sum + output_biases[i];
    }

    // Find index of highest output value
    int max_index = 0;

    for (int i = 1; i < LABELS; i++) {
        if (output_values[i] > output_values[max_index]) {
            max_index = i;
        }
    }

    return max_index;
}

// Test the network on a set of images
void test_network() {
    int num_correct = 0;

    for (int i = 0; i < TOTAL_IMAGES; i++) {
        int label = label_data[i];
        int prediction = classify_image(image_data[i]);

        if (prediction == label) {
            num_correct++;
        }
    }

    float accuracy = (float)num_correct / TOTAL_IMAGES * 100;
    printf("Accuracy: %.2f%%\n", accuracy);
}

int main() {
    load_data();
    test_network();

    return 0;
}
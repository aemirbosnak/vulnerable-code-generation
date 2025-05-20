//FormAI DATASET v1.0 Category: Image Classification system ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_CLASSES 10
#define NUM_SAMPLES 1000
#define NUM_FEATURES 784

float weights[NUM_CLASSES][NUM_FEATURES];
int labels[NUM_SAMPLES];
float features[NUM_SAMPLES][NUM_FEATURES];

// Utility function to load data from files
void loadData() {
    FILE *f1, *f2, *f3;
    int i, j;

    f1 = fopen("weights.txt", "r");
    f2 = fopen("labels.txt", "r");
    f3 = fopen("features.txt", "r");

    if (f1 == NULL || f2 == NULL || f3 == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Load weights
    for (i = 0; i < NUM_CLASSES; i++) {
        for (j = 0; j < NUM_FEATURES; j++) {
            fscanf(f1, "%f", &weights[i][j]);
        }
    }

    // Load labels
    for (i = 0; i < NUM_SAMPLES; i++) {
        fscanf(f2, "%d", &labels[i]);
    }

    // Load features
    for (i = 0; i < NUM_SAMPLES; i++) {
        for (j = 0; j < NUM_FEATURES; j++) {
            fscanf(f3, "%f", &features[i][j]);
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

// Calculate dot product of two vectors
float dotproduct(float *a, float *b, int n) {
    float sum = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }

    return sum;
}

// Calculate softmax of the outputs
void softmax(float *a, int n) {
    float max_val = a[0];
    int i;

    for (i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    float sum = 0.0;

    for (i = 0; i < n; i++) {
        a[i] = exp(a[i] - max_val);
        sum += a[i];
    }

    for (i = 0; i < n; i++) {
        a[i] /= sum;
    }
}

// Perform forward pass to get output
int forwardpass(float *features_sample) {
    int i, j;
    float outputs[NUM_CLASSES];

    for (i = 0; i < NUM_CLASSES; i++) {
        outputs[i] = dotproduct(weights[i], features_sample, NUM_FEATURES);
    }

    softmax(outputs, NUM_CLASSES);

    int max_output = 0;

    for (i = 1; i < NUM_CLASSES; i++) {
        if (outputs[i] > outputs[max_output]) {
            max_output = i;
        }
    }

    return max_output;
}

int main() {
    loadData();

    int correct = 0;

    // Perform classification on each test sample
    for (int i = 0; i < NUM_SAMPLES; i++) {
        int predicted_label = forwardpass(features[i]);

        if (predicted_label == labels[i]) {
            correct++;
        }
    }

    // Print accuracy
    printf("Accuracy: %.2f\n", (float)correct / NUM_SAMPLES);

    return 0;
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMG_HEIGHT 28
#define IMG_WIDTH 28
#define NUM_PIXELS IMG_HEIGHT * IMG_WIDTH

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

void forward(float *weights, float *inputs, float *outputs) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_PIXELS; j++) {
            sum += weights[i * NUM_PIXELS + j] * inputs[j];
        }
        outputs[i] = sigmoid(sum);
    }
}

int predict(float *weights, float *inputs) {
    float outputs[NUM_CLASSES];
    forward(weights, inputs, outputs);
    int max_idx = 0;
    float max_val = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (outputs[i] > max_val) {
            max_val = outputs[i];
            max_idx = i;
        }
    }
    return max_idx;
}

float cross_entropy_loss(float *outputs, int label) {
    float loss = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (i == label) {
            loss -= log(outputs[i]);
        } else {
            loss -= log(1 - outputs[i]);
        }
    }
    return loss;
}

void backward(float *weights, float *inputs, float *outputs, int label, float learning_rate) {
    float grad[NUM_CLASSES][NUM_PIXELS];
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_PIXELS; j++) {
            grad[i][j] = 0;
        }
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < NUM_PIXELS; j++) {
            grad[i][j] = (outputs[i] - (i == label ? 1 : 0)) * inputs[j];
            weights[i * NUM_PIXELS + j] -= learning_rate * grad[i][j];
        }
    }
}

int main() {
    // Load data
    FILE *fp = fopen("train.csv", "r");
    if (fp == NULL) {
        printf("Could not open train.csv\n");
        exit(1);
    }
    char line[1024];
    fgets(line, 1024, fp); // Skip header line
    float *inputs = (float *) malloc(NUM_PIXELS * sizeof(float));
    int label = 0;
    int num_correct = 0;
    float *weights = (float *) malloc(NUM_CLASSES * NUM_PIXELS * sizeof(float));
    for (int i = 0; i < NUM_CLASSES * NUM_PIXELS; i++) {
        weights[i] = 0;
    }
    int t = 0;
    while (fgets(line, 1024, fp)) {
        char *token = strtok(line, ",");
        label = atoi(token);
        int i = 0;
        while (token != NULL) {
            token = strtok(NULL, ",");
            if (token != NULL) {
                inputs[i] = atoi(token) / 255.0;
                i++;
            }
        }

        printf("Example %d\n", t);
        printf("True label: %d\n", label);
        int prediction = predict(weights, inputs);
        printf("Prediction: %d\n", prediction);
        if (prediction == label) num_correct++;
        float outputs[NUM_CLASSES];
        forward(weights, inputs, outputs);
        float loss = cross_entropy_loss(outputs, label);
        printf("Loss: %f\n", loss);
        backward(weights, inputs, outputs, label, 0.1);

        t++;
    }
    printf("Accuracy: %f\n", (float) num_correct / t);

    return 0;
}
//FormAI DATASET v1.0 Category: Image Classification system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define NUM_FEATURES 784
#define NUM_CLASSES 10

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

typedef struct {
    double weights[NUM_FEATURES];
    double bias;
} Classifier;

typedef struct {
    double features[NUM_FEATURES];
    int label;
} Sample;

double inner_product(double arr1[], double arr2[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr1[i] * arr2[i];
    }
    return sum;
}

int predict(Classifier clf, Sample sample) {
    double dot_product = inner_product(clf.weights, sample.features, NUM_FEATURES);
    double prediction = sigmoid(dot_product + clf.bias);
    return (prediction > 0.5) ? 1 : 0;
}

int train(Classifier *clf, Sample data[], int num_samples, double learning_rate, int num_epochs) {
    for (int epoch = 0; epoch < num_epochs; epoch++) {
        for (int i = 0; i < num_samples; i++) {
            Sample sample = data[i];
            double dot_product = inner_product(clf->weights, sample.features, NUM_FEATURES);
            double prediction = sigmoid(dot_product + clf->bias);
            double error = sample.label - prediction;

            for (int j = 0; j < NUM_FEATURES; j++) {
                clf->weights[j] += learning_rate * error * sample.features[j];
            }
            clf->bias += learning_rate * error;
        }
        printf("Epoch %d complete\n", epoch);
    }
    return 0;
}

int main() {
    // Load in MNIST dataset
    Sample *training_data = malloc(sizeof(Sample) * 5000);
    FILE *data_file = fopen("mnist_training_data.csv", "r");
    char line[1000];

    int index = 0;
    while (fgets(line, sizeof(line), data_file)) {
        char *token;
        int feature_index = 0;
        double features[NUM_FEATURES];
        token = strtok(line, ",");
        while (token != NULL) {
            if (feature_index == 0) {
                training_data[index].label = atoi(token);
            } else {
                features[feature_index - 1] = atof(token);
            }
            feature_index++;
            token = strtok(NULL, ",");
        }
        for (int i = 0; i < NUM_FEATURES; i++) {
            training_data[index].features[i] = features[i];
        }
        index++;
    }
    fclose(data_file);

    // Train classifier
    Classifier clf;
    for (int i = 0; i < NUM_FEATURES; i++) {
        clf.weights[i] = 0;
    }
    clf.bias = 0;

    train(&clf, training_data, 5000, 0.01, 100);

    // Test classifier
    Sample sample = training_data[0];
    int prediction = predict(clf, sample);
    printf("Predicted label for first training sample: %d\n", prediction);
    
    free(training_data);

    return 0;
}
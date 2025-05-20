//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

int main() {
    char buf[MAX_LINE_LEN];
    FILE* train_file = fopen("train_data.txt", "r");
    FILE* test_file = fopen("test_data.txt", "r");

    // Read training data
    int num_train;
    fscanf(train_file, "%d", &num_train);
    int train_labels[num_train];
    float train_features[num_train][10];

    for (int i = 0; i < num_train; i++) {
        fscanf(train_file, "%d", &train_labels[i]);
        for (int j = 0; j < 10; j++) {
            fscanf(train_file, "%f", &train_features[i][j]);
        }
    }
    fclose(train_file);

    // Read test data
    int num_test;
    fscanf(test_file, "%d", &num_test);
    int test_labels[num_test];
    float test_features[num_test][10];

    for (int i = 0; i < num_test; i++) {
        fscanf(test_file, "%d", &test_labels[i]);
        for (int j = 0; j < 10; j++) {
            fscanf(test_file, "%f", &test_features[i][j]);
        }
    }
    fclose(test_file);

    // Train model
    float weights[10];
    float learning_rate = 0.1;
    int num_epochs = 100;

    for (int epoch = 0; epoch < num_epochs; epoch++) {
        for (int i = 0; i < num_train; i++) {
            // Compute prediction
            float prediction = 0;
            for (int j = 0; j < 10; j++) {
                prediction += weights[j] * train_features[i][j];
            }

            // Compute error
            float error = train_labels[i] - prediction;

            // Update weights
            for (int j = 0; j < 10; j++) {
                weights[j] += learning_rate * error * train_features[i][j];
            }
        }
    }

    // Test model
    int num_correct = 0;

    for (int i = 0; i < num_test; i++) {
        // Compute prediction
        float prediction = 0;
        for (int j = 0; j < 10; j++) {
            prediction += weights[j] * test_features[i][j];
        }

        // Make classification
        int classification = prediction >= 0.5 ? 1 : 0;

        // Check if correct
        if (classification == test_labels[i]) {
            num_correct++;
        }
    }

    float accuracy = (float) num_correct / (float) num_test;
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#define MAX_DATA_POINTS 1000000
#define MAX_FEATURES 100

double data[MAX_DATA_POINTS][MAX_FEATURES];
int labels[MAX_DATA_POINTS];

// Load data from a CSV file
void load_data(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int i = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *p = strtok(line, ",");
        labels[i] = atoi(p);
        p = strtok(NULL, ",");
        int j = 0;
        while (p != NULL) {
            data[i][j++] = atof(p);
            p = strtok(NULL, ",");
        }
        i++;
    }

    fclose(fp);
}

// Normalize data
void normalize_data() {
    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        double sum = 0.0;
        for (int j = 0; j < MAX_FEATURES; j++) {
            sum += data[i][j] * data[i][j];
        }
        sum = sqrt(sum);
        for (int j = 0; j < MAX_FEATURES; j++) {
            data[i][j] /= sum;
        }
    }
}

// Train a linear regression model
void train_model(double *w, double *b) {
    // Initialize weights and bias
    for (int i = 0; i < MAX_FEATURES; i++) {
        w[i] = 0.0;
    }
    *b = 0.0;

    // Learning rate
    double alpha = 0.01;

    // Number of iterations
    int num_iterations = 1000;

    for (int iter = 0; iter < num_iterations; iter++) {
        // Update weights and bias
        for (int i = 0; i < MAX_DATA_POINTS; i++) {
            double y_pred = 0.0;
            for (int j = 0; j < MAX_FEATURES; j++) {
                y_pred += w[j] * data[i][j];
            }
            y_pred += *b;

            for (int j = 0; j < MAX_FEATURES; j++) {
                w[j] -= alpha * (y_pred - labels[i]) * data[i][j];
            }
            *b -= alpha * (y_pred - labels[i]);
        }
    }
}

// Predict labels for new data points
void predict_labels(double *w, double *b, int *pred_labels, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        double y_pred = 0.0;
        for (int j = 0; j < MAX_FEATURES; j++) {
            y_pred += w[j] * data[i][j];
        }
        y_pred += *b;

        if (y_pred > 0.5) {
            pred_labels[i] = 1;
        } else {
            pred_labels[i] = 0;
        }
    }
}

// Evaluate model performance
void evaluate_model(int *pred_labels, int num_data_points) {
    int num_correct = 0;
    for (int i = 0; i < num_data_points; i++) {
        if (pred_labels[i] == labels[i]) {
            num_correct++;
        }
    }

    double accuracy = (double)num_correct / num_data_points;
    printf("Accuracy: %f\n", accuracy);
}

int main() {
    // Load data
    load_data("data.csv");

    // Normalize data
    normalize_data();

    // Split data into training and testing sets
    int num_train_data_points = MAX_DATA_POINTS * 0.8;
    int num_test_data_points = MAX_DATA_POINTS * 0.2;

    double w[MAX_FEATURES];
    double b;

    // Train model
    train_model(w, &b);

    // Predict labels for test data
    int pred_labels[num_test_data_points];
    predict_labels(w, &b, pred_labels, num_test_data_points);

    // Evaluate model performance
    evaluate_model(pred_labels, num_test_data_points);

    return 0;
}
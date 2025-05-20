//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define the number of data points
#define NUM_DATA_POINTS 100

// Define the number of features
#define NUM_FEATURES 10

// Define the data structure for a data point
typedef struct {
    double features[NUM_FEATURES];
    int label;
} DataPoint;

// Generate a random data point
DataPoint generate_data_point() {
    DataPoint data_point;
    for (int i = 0; i < NUM_FEATURES; i++) {
        data_point.features[i] = (double)rand() / RAND_MAX;
    }
    data_point.label = rand() % 2;
    return data_point;
}

// Generate a random dataset
DataPoint* generate_dataset(int num_data_points) {
    DataPoint* dataset = malloc(sizeof(DataPoint) * num_data_points);
    for (int i = 0; i < num_data_points; i++) {
        dataset[i] = generate_data_point();
    }
    return dataset;
}

// Print a data point
void print_data_point(DataPoint data_point) {
    printf("Features: ");
    for (int i = 0; i < NUM_FEATURES; i++) {
        printf("%f ", data_point.features[i]);
    }
    printf("\nLabel: %d\n", data_point.label);
}

// Print a dataset
void print_dataset(DataPoint* dataset, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        print_data_point(dataset[i]);
    }
}

// Main function
int main() {
    // Generate a random dataset
    DataPoint* dataset = generate_dataset(NUM_DATA_POINTS);

    // Print the dataset
    print_dataset(dataset, NUM_DATA_POINTS);

    // Free the dataset
    free(dataset);

    return 0;
}
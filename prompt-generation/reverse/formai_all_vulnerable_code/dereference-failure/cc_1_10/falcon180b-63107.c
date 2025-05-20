//Falcon-180B DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} DataSet;

// Function to create a new dataset
DataSet *create_dataset(int size) {
    DataSet *dataset = (DataSet *) malloc(sizeof(DataSet));
    dataset->data = (int *) malloc(size * sizeof(int));
    dataset->size = size;
    return dataset;
}

// Function to add an element to the dataset
void add_element(DataSet *dataset, int element) {
    dataset->data[dataset->size++] = element;
}

// Function to calculate the mean of a dataset
double calculate_mean(DataSet *dataset) {
    int sum = 0;
    for (int i = 0; i < dataset->size; i++) {
        sum += dataset->data[i];
    }
    return (double) sum / dataset->size;
}

// Function to calculate the variance of a dataset
double calculate_variance(DataSet *dataset, double mean) {
    int sum = 0;
    for (int i = 0; i < dataset->size; i++) {
        sum += pow((dataset->data[i] - mean), 2);
    }
    return (double) sum / dataset->size;
}

// Function to calculate the standard deviation of a dataset
double calculate_standard_deviation(DataSet *dataset, double mean) {
    return sqrt(calculate_variance(dataset, mean));
}

// Function to print the dataset
void print_dataset(DataSet *dataset) {
    for (int i = 0; i < dataset->size; i++) {
        printf("%d ", dataset->data[i]);
    }
    printf("\n");
}

int main() {
    DataSet *dataset = create_dataset(MAX_SIZE);
    int element;

    // Add elements to the dataset
    add_element(dataset, 1);
    add_element(dataset, 2);
    add_element(dataset, 3);
    add_element(dataset, 4);
    add_element(dataset, 5);

    // Print the dataset
    printf("Dataset: ");
    print_dataset(dataset);

    // Calculate the mean, variance, and standard deviation
    double mean = calculate_mean(dataset);
    double variance = calculate_variance(dataset, mean);
    double standard_deviation = calculate_standard_deviation(dataset, mean);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", standard_deviation);

    return 0;
}
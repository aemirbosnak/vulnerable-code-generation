//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 1000
#define MAX_FEATURES 10
#define THRESHOLD 0.5

// Structure to hold data instances
typedef struct {
    double features[MAX_FEATURES];
    int label;
} Instance;

// Function prototypes
void load_data(const char *filename, Instance *data, int *num_instances);
double euclidean_distance(double *a, double *b, int num_features);
void k_nearest_neighbors(Instance *data, int num_instances, double *query, int k, int *predicted_label);
void classify_based_on_neighbors(int *neighbors, int k, int *predicted_label);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int k = atoi(argv[2]);
    double query[MAX_FEATURES];

    // Populate the query instance features
    for (int i = 0; i < MAX_FEATURES; i++) {
        query[i] = atof(argv[3 + i]);
    }

    Instance data[MAX_DATA];
    int num_instances = 0;
    
    // Load data
    load_data(filename, data, &num_instances);

    int predicted_label = -1;
    k_nearest_neighbors(data, num_instances, query, k, &predicted_label);

    printf("The predicted label for the query instance is: %d\n", predicted_label);
    return EXIT_SUCCESS;
}

void load_data(const char *filename, Instance *data, int *num_instances) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%lf,%lf,%lf,%d",
                  &data[*num_instances].features[0],
                  &data[*num_instances].features[1],
                  &data[*num_instances].features[2],
                  &data[*num_instances].label) != EOF) {
        (*num_instances)++;
        if (*num_instances >= MAX_DATA) {
            printf("Maximum number of data instances reached.\n");
            break;
        }
    }
    
    fclose(file);
}

double euclidean_distance(double *a, double *b, int num_features) {
    double sum = 0.0;
    for (int i = 0; i < num_features; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

void k_nearest_neighbors(Instance *data, int num_instances, double *query, int k, int *predicted_label) {
    double distances[MAX_DATA];
    int neighbors[MAX_DATA];

    // Calculate distances from query to each instance
    for (int i = 0; i < num_instances; i++) {
        distances[i] = euclidean_distance(data[i].features, query, MAX_FEATURES);
        neighbors[i] = i;
    }

    // Simple selection sort to find the k-nearest neighbors
    for (int i = 0; i < num_instances - 1; i++) {
        for (int j = 0; j < num_instances - i - 1; j++) {
            if (distances[j] > distances[j + 1]) {
                // Swap distances
                double temp_dist = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp_dist;

                // Swap neighbors
                int temp_index = neighbors[j];
                neighbors[j] = neighbors[j + 1];
                neighbors[j + 1] = temp_index;
            }
        }
    }

    // Classify based on the neighbors
    classify_based_on_neighbors(neighbors, k, predicted_label);
}

void classify_based_on_neighbors(int *neighbors, int k, int *predicted_label) {
    int count_classes[10] = {0}; // Assuming a maximum of 10 classes

    for (int i = 0; i < k; i++) {
        int label = neighbors[i]; // You would need to access actual instances
        count_classes[label]++;
    }

    int max_count = 0;
    for (int i = 0; i < 10; i++) {
        if (count_classes[i] > max_count) {
            max_count = count_classes[i];
            *predicted_label = i;
        }
    }
}

void print_usage() {
    printf("Usage: ./dataminer <data_file> <k> <feature_1> <feature_2> <feature_3>\n");
    printf("Example: ./dataminer data.txt 3 5.1 3.5 1.4\n");
}
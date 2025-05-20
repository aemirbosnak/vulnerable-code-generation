//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of data points
#define MAX_DATA_POINTS 1000

// Define the maximum number of features
#define MAX_FEATURES 100

// Define the data point structure
typedef struct data_point {
    float features[MAX_FEATURES];
    float label;
} data_point;

// Define the data set structure
typedef struct data_set {
    data_point data_points[MAX_DATA_POINTS];
    int num_data_points;
    int num_features;
} data_set;

// Load the data set from a file
data_set *load_data_set(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    data_set *data_set = malloc(sizeof(data_set));
    if (data_set == NULL) {
        fprintf(stderr, "Error: could not allocate memory for data set\n");
        fclose(file);
        return NULL;
    }

    // Read the number of data points and features
    fscanf(file, "%d %d\n", &data_set->num_data_points, &data_set->num_features);

    // Read the data points
    for (int i = 0; i < data_set->num_data_points; i++) {
        for (int j = 0; j < data_set->num_features; j++) {
            fscanf(file, "%f ", &data_set->data_points[i].features[j]);
        }
        fscanf(file, "%f\n", &data_set->data_points[i].label);
    }

    fclose(file);

    return data_set;
}

// Free the memory allocated for the data set
void free_data_set(data_set *data_set) {
    free(data_set);
}

// Print the data set
void print_data_set(data_set *data_set) {
    for (int i = 0; i < data_set->num_data_points; i++) {
        for (int j = 0; j < data_set->num_features; j++) {
            printf("%f ", data_set->data_points[i].features[j]);
        }
        printf("%f\n", data_set->data_points[i].label);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a filename
    if (argc < 2) {
        fprintf(stderr, "Error: please specify the filename of the data set\n");
        return 1;
    }

    // Load the data set
    data_set *data_set = load_data_set(argv[1]);
    if (data_set == NULL) {
        return 1;
    }

    // Print the data set
    print_data_set(data_set);

    // Free the memory allocated for the data set
    free_data_set(data_set);

    return 0;
}
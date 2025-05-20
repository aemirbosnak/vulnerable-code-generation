//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A data point in a dataset
typedef struct {
    int id;
    float* features;
    int num_features;
} data_point;

// A dataset
typedef struct {
    data_point* points;
    int num_points;
    int num_features;
} dataset;

// Create a new dataset
dataset* create_dataset(int num_points, int num_features) {
    dataset* ds = malloc(sizeof(dataset));
    ds->points = malloc(sizeof(data_point) * num_points);
    ds->num_points = num_points;
    ds->num_features = num_features;

    for (int i = 0; i < num_points; i++) {
        ds->points[i].id = i;
        ds->points[i].features = malloc(sizeof(float) * num_features);
        ds->points[i].num_features = num_features;
    }

    return ds;
}

// Free a dataset
void free_dataset(dataset* ds) {
    for (int i = 0; i < ds->num_points; i++) {
        free(ds->points[i].features);
    }
    free(ds->points);
    free(ds);
}

// Load a dataset from a file
dataset* load_dataset(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    int num_points, num_features;
    fscanf(file, "%d %d", &num_points, &num_features);

    dataset* ds = create_dataset(num_points, num_features);

    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < num_features; j++) {
            fscanf(file, "%f", &ds->points[i].features[j]);
        }
    }

    fclose(file);

    return ds;
}

// Save a dataset to a file
void save_dataset(dataset* ds, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", ds->num_points, ds->num_features);

    for (int i = 0; i < ds->num_points; i++) {
        for (int j = 0; j < ds->num_features; j++) {
            fprintf(file, "%f ", ds->points[i].features[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Print a dataset
void print_dataset(dataset* ds) {
    for (int i = 0; i < ds->num_points; i++) {
        printf("Data point %d:\n", ds->points[i].id);
        for (int j = 0; j < ds->num_features; j++) {
            printf("  Feature %d: %f\n", j, ds->points[i].features[j]);
        }
    }
}

int main() {
    // Create a dataset
    dataset* ds = create_dataset(100, 10);

    // Load a dataset from a file
    ds = load_dataset("data.txt");

    // Save a dataset to a file
    save_dataset(ds, "data.txt");

    // Print a dataset
    print_dataset(ds);

    // Free a dataset
    free_dataset(ds);

    return 0;
}
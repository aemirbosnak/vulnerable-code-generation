//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SAMPLES 1000
#define MAX_FEATURES 10

typedef struct {
    double features[MAX_FEATURES];
    double label;
} Sample;

double euclidean_distance(Sample a, Sample b) {
    double distance = 0.0;
    for (int i = 0; i < MAX_FEATURES; i++) {
        distance += pow(a.features[i] - b.features[i], 2);
    }
    distance = sqrt(distance);
    return distance;
}

int find_nearest_neighbor(Sample* data, int size, Sample query) {
    double min_distance = INFINITY;
    int nearest_index = -1;
    for (int i = 0; i < size; i++) {
        double distance = euclidean_distance(data[i], query);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_index = i;
        }
    }
    return nearest_index;
}

int main() {
    Sample* data;
    int num_samples = 0;
    int num_features = 0;

    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Could not open data file.\n");
        return 1;
    }

    fscanf(file, "%d,%d\n", &num_samples, &num_features);
    data = (Sample*) calloc(num_samples, sizeof(Sample));

    for (int i = 0; i < num_samples; i++) {
        fscanf(file, "%lf", &data[i].label);
        for (int j = 0; j < num_features; j++) {
            fscanf(file, "%lf", &data[i].features[j]);
        }
        fgetc(file); // consume newline character
    }

    fclose(file);

    Sample query;
    scanf("%lf", &query.label);
    for (int i = 0; i < num_features; i++) {
        scanf("%lf", &query.features[i]);
    }

    int nearest_index = find_nearest_neighbor(data, num_samples, query);
    printf("Nearest neighbor label: %lf\n", data[nearest_index].label);

    free(data);
    return 0;
}
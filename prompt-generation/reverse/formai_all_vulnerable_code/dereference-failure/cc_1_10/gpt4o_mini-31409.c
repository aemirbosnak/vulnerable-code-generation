//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 1000
#define MAX_FEATURES 10
#define THRESHOLD 0.5

typedef struct {
    double features[MAX_FEATURES];
    int label;
} DataPoint;

void load_data(const char *filename, DataPoint *data, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }

    while (fscanf(file, "%lf %lf %d", &data[*count].features[0], &data[*count].features[1], &data[*count].label) == 3) {
        (*count)++;
    }
    fclose(file);
}

double euclidean_distance(DataPoint a, DataPoint b, int num_features) {
    double sum = 0;
    for (int i = 0; i < num_features; i++) {
        sum += pow(a.features[i] - b.features[i], 2);
    }
    return sqrt(sum);
}

int classify(DataPoint *data, int count, DataPoint sample, int k) {
    double distances[MAX_DATA];
    for (int i = 0; i < count; i++) {
        distances[i] = euclidean_distance(data[i], sample, MAX_FEATURES);
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < count; j++) {
            if (distances[i] > distances[j]) {
                double temp_d = distances[i];
                distances[i] = distances[j];
                distances[j] = temp_d;

                int temp_l = data[i].label;
                data[i].label = data[j].label;
                data[j].label = temp_l;
            }
        }
    }

    int vote_count[2] = {0, 0};
    for (int i = 0; i < k; i++) {
        vote_count[data[i].label]++;
    }

    return (vote_count[0] > vote_count[1]) ? 0 : 1;
}

void evaluate_model(DataPoint *data, int count, int k) {
    int correct = 0;
    for (int i = 0; i < count; i++) {
        DataPoint sample = data[i];
        int predicted_label = classify(data, count, sample, k);
        if (predicted_label == sample.label) {
            correct++;
        }
    }
    printf("Accuracy: %.2f%%\n", (double)correct / count * 100);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <datafile> <k>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DataPoint data[MAX_DATA];
    int count = 0;
    load_data(argv[1], data, &count);

    int k = atoi(argv[2]);
    if (k <= 0 || k > count) {
        fprintf(stderr, "Invalid value for k: %d\n", k);
        return EXIT_FAILURE;
    }

    evaluate_model(data, count, k);
    return EXIT_SUCCESS;
}
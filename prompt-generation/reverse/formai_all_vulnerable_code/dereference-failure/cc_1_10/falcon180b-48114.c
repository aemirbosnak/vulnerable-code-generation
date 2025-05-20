//Falcon-180B DATASET v1.0 Category: Data mining ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATA_SIZE 10000
#define MAX_NUM_DATA 1000
#define NUM_PATTERNS 10
#define NUM_CLASSES 10
#define NUM_FEATURES 10

typedef struct {
    int num_data;
    int num_classes;
    int num_features;
    int *data;
    int *labels;
} DataSet;

void generate_random_data(DataSet *dataset) {
    srand(time(NULL));
    dataset->num_data = rand() % MAX_DATA_SIZE + 1;
    dataset->num_classes = rand() % NUM_CLASSES + 1;
    dataset->num_features = rand() % NUM_FEATURES + 1;

    dataset->data = (int *)malloc(sizeof(int) * dataset->num_data * dataset->num_features);
    dataset->labels = (int *)malloc(sizeof(int) * dataset->num_data);

    for (int i = 0; i < dataset->num_data; i++) {
        for (int j = 0; j < dataset->num_features; j++) {
            dataset->data[i * dataset->num_features + j] = rand() % 100;
        }
        dataset->labels[i] = rand() % dataset->num_classes;
    }
}

void print_data(DataSet *dataset) {
    for (int i = 0; i < dataset->num_data; i++) {
        for (int j = 0; j < dataset->num_features; j++) {
            printf("%d ", dataset->data[i * dataset->num_features + j]);
        }
        printf("%d\n", dataset->labels[i]);
    }
}

void free_data(DataSet *dataset) {
    free(dataset->data);
    free(dataset->labels);
}

int main() {
    DataSet dataset;
    generate_random_data(&dataset);
    print_data(&dataset);
    free_data(&dataset);

    return 0;
}
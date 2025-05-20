//Falcon-180B DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA 100000
#define MAX_ATTRIBUTES 10
#define MAX_CLASSES 5

typedef struct {
    int *data;
    char **attributes;
    int num_attributes;
    int num_classes;
    int *class_labels;
} dataset;

void generate_random_data(dataset *data) {
    srand(time(NULL));
    data->num_attributes = rand() % MAX_ATTRIBUTES + 1;
    data->num_classes = rand() % MAX_CLASSES + 1;
    data->attributes = malloc(data->num_attributes * sizeof(char *));
    for (int i = 0; i < data->num_attributes; i++) {
        data->attributes[i] = malloc(10 * sizeof(char));
        sprintf(data->attributes[i], "attribute_%d", i);
    }
    data->class_labels = malloc(data->num_classes * sizeof(int));
    for (int i = 0; i < data->num_classes; i++) {
        data->class_labels[i] = rand() % 10;
    }
    data->data = malloc(MAX_DATA * sizeof(int));
    for (int i = 0; i < MAX_DATA; i++) {
        data->data[i] = rand() % 100;
    }
}

void print_dataset(dataset *data) {
    printf("Dataset:\n");
    printf("Number of attributes: %d\n", data->num_attributes);
    for (int i = 0; i < data->num_attributes; i++) {
        printf("Attribute %d: %s\n", i, data->attributes[i]);
    }
    printf("Number of classes: %d\n", data->num_classes);
    for (int i = 0; i < data->num_classes; i++) {
        printf("Class %d: %d\n", i, data->class_labels[i]);
    }
}

void free_dataset(dataset *data) {
    for (int i = 0; i < data->num_attributes; i++) {
        free(data->attributes[i]);
    }
    free(data->attributes);
    free(data->class_labels);
    free(data->data);
}

int main() {
    dataset data;
    generate_random_data(&data);
    print_dataset(&data);
    free_dataset(&data);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_FEATURES 100

typedef struct {
    char *name;
    int num_features;
    float features[MAX_FEATURES];
} Image;

typedef struct {
    char *name;
    int num_classes;
    Image *images[MAX_CLASSES];
} Dataset;

Dataset *load_dataset(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Dataset *dataset = (Dataset *)malloc(sizeof(Dataset));
    dataset->name = (char *)malloc(100 * sizeof(char));
    fscanf(fp, "%s", dataset->name);

    fscanf(fp, "%d", &dataset->num_classes);
    for (int i = 0; i < dataset->num_classes; i++) {
        dataset->images[i] = (Image *)malloc(sizeof(Image));
        dataset->images[i]->name = (char *)malloc(100 * sizeof(char));
        fscanf(fp, "%s", dataset->images[i]->name);

        fscanf(fp, "%d", &dataset->images[i]->num_features);
        for (int j = 0; j < dataset->images[i]->num_features; j++) {
            fscanf(fp, "%f", &dataset->images[i]->features[j]);
        }
    }

    fclose(fp);

    return dataset;
}

void print_dataset(Dataset *dataset) {
    printf("Dataset: %s\n", dataset->name);
    printf("Number of classes: %d\n", dataset->num_classes);
    for (int i = 0; i < dataset->num_classes; i++) {
        printf("Class: %s\n", dataset->images[i]->name);
        printf("Number of features: %d\n", dataset->images[i]->num_features);
        for (int j = 0; j < dataset->images[i]->num_features; j++) {
            printf("%f ", dataset->images[i]->features[j]);
        }
        printf("\n");
    }
}

int main() {
    Dataset *dataset = load_dataset("dataset.txt");
    if (dataset == NULL) {
        printf("Error loading dataset.\n");
        return 1;
    }

    print_dataset(dataset);

    return 0;
}
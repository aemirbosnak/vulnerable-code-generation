//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold data points
typedef struct {
    float feature1;
    float feature2;
    int class_label;
} DataPoint;

// Function to read data from a file
int readData(const char* filename, DataPoint** data, int* data_size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    int size = 0;
    while (!feof(file)) {
        float f1, f2;
        int cl;
        if (fscanf(file, "%f,%f,%d\n", &f1, &f2, &cl) == 3) {
            size++;
        }
    }
    rewind(file);

    *data = (DataPoint*)malloc(size * sizeof(DataPoint));
    if (!(*data)) {
        perror("Memory allocation failed");
        fclose(file);
        return -1;
    }

    int index = 0;
    while (!feof(file)) {
        float f1, f2;
        int cl;
        if (fscanf(file, "%f,%f,%d\n", &f1, &f2, &cl) == 3) {
            (*data)[index].feature1 = f1;
            (*data)[index].feature2 = f2;
            (*data)[index].class_label = cl;
            index++;
        }
    }

    fclose(file);
    *data_size = size;
    return 0;
}

// Function to calculate the average feature values for each class
void calculateClassAverages(DataPoint* data, int data_size) {
    float sum_feature1[3] = {0};
    float sum_feature2[3] = {0};
    int count[3] = {0};

    for (int i = 0; i < data_size; i++) {
        int class_index = data[i].class_label;
        sum_feature1[class_index] += data[i].feature1;
        sum_feature2[class_index] += data[i].feature2;
        count[class_index]++;
    }

    printf("Average features for each class:\n");
    for (int i = 0; i < 3; i++) {
        if (count[i] != 0) {
            printf("Class %d: Feature1: %.2f, Feature2: %.2f\n", i, sum_feature1[i] / count[i], sum_feature2[i] / count[i]);
        }
    }
}

// Function to calculate the correlation coefficient
float calculateCorrelation(DataPoint* data, int data_size) {
    float mean_feature1 = 0, mean_feature2 = 0;
    float sum_feature1 = 0, sum_feature2 = 0;
    float sum_feature1_sq = 0, sum_feature2_sq = 0;
    float sum_product = 0;

    for (int i = 0; i < data_size; i++) {
        sum_feature1 += data[i].feature1;
        sum_feature2 += data[i].feature2;
        sum_feature1_sq += data[i].feature1 * data[i].feature1;
        sum_feature2_sq += data[i].feature2 * data[i].feature2;
        sum_product += data[i].feature1 * data[i].feature2;
    }

    mean_feature1 = sum_feature1 / data_size;
    mean_feature2 = sum_feature2 / data_size;

    float numerator = sum_product - data_size * mean_feature1 * mean_feature2;
    float denominator = sqrt((sum_feature1_sq - data_size * mean_feature1 * mean_feature1) * (sum_feature2_sq - data_size * mean_feature2 * mean_feature2));

    return (denominator == 0) ? 0 : numerator / denominator;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <data_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DataPoint* data = NULL;
    int data_size = 0;

    if (readData(argv[1], &data, &data_size) != 0) {
        return EXIT_FAILURE;
    }

    calculateClassAverages(data, data_size);

    float correlation = calculateCorrelation(data, data_size);
    printf("Correlation coefficient between feature1 and feature2: %.2f\n", correlation);

    free(data);
    return EXIT_SUCCESS;
}
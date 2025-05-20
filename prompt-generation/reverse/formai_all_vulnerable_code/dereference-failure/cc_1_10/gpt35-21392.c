//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a data point
typedef struct {
    int x;
    float y;
    char *label;
} DataPoint;

// Define a struct to represent a dataset
typedef struct {
    int size;
    DataPoint *points;
} DataSet;

// Function to print a data point
void printDataPoint(DataPoint *point) {
    printf("(%d, %f, %s)\n", point->x, point->y, point->label);
}

// Function to initialize a new dataset
DataSet* createDataSet(int size) {
    DataSet *dataSet = malloc(sizeof(DataSet));
    dataSet->size = size;
    dataSet->points = malloc(sizeof(DataPoint) * size);
    return dataSet;
}

// Function to free a dataset
void freeDataSet(DataSet *dataSet) {
    free(dataSet->points);
    free(dataSet);
}

// Function to populate a dataset with random data
void generateDataSet(DataSet *dataSet) {
    int i;
    for (i = 0; i < dataSet->size; i++) {
        DataPoint *point = &(dataSet->points[i]);
        point->x = rand() % 100;
        point->y = (float)(rand() % 10000) / 100.0;
        point->label = (i % 2 == 0) ? "even" : "odd";
    }
}

int main() {
    // Create a dataset with 10 points
    DataSet *dataSet = createDataSet(10);

    // Populate the dataset with random data
    generateDataSet(dataSet);

    // Print all the data points in the dataset
    int i;
    for (i = 0; i < dataSet->size; i++) {
        printf("Point %d: ", i);
        printDataPoint(&(dataSet->points[i]));
    }

    // Free the dataset
    freeDataSet(dataSet);

    return 0;
}
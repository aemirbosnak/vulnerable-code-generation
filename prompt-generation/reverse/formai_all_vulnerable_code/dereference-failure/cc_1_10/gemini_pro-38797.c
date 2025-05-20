//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA_SIZE 1000

// Structure to hold a data point
typedef struct {
    int x;
    int y;
} DataPoint;

// Function to generate a random data point
DataPoint generate_random_data_point() {
    DataPoint data_point;
    data_point.x = rand() % MAX_DATA_SIZE;
    data_point.y = rand() % MAX_DATA_SIZE;
    return data_point;
}

// Function to generate a random dataset
DataPoint* generate_random_dataset(int size) {
    DataPoint* dataset = malloc(sizeof(DataPoint) * size);
    for (int i = 0; i < size; i++) {
        dataset[i] = generate_random_data_point();
    }
    return dataset;
}

// Function to print a data point
void print_data_point(DataPoint data_point) {
    printf("(%d, %d)", data_point.x, data_point.y);
}

// Function to print a dataset
void print_dataset(DataPoint* dataset, int size) {
    for (int i = 0; i < size; i++) {
        print_data_point(dataset[i]);
        printf(" ");
    }
    printf("\n");
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random dataset
    int size = 100;
    DataPoint* dataset = generate_random_dataset(size);

    // Print the dataset
    printf("Dataset:\n");
    print_dataset(dataset, size);

    // Perform data mining tasks here

    // Free the dataset
    free(dataset);

    return 0;
}
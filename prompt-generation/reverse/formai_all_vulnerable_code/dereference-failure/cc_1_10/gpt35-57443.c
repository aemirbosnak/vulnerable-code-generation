//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the struct for holding data points
typedef struct DataPoint {
    float x;
    float y;
} DataPoint;

int main() {
    // Create an array to hold data points
    DataPoint *dataset = malloc(sizeof(DataPoint)*5);
    
    // Populate the dataset with sample data
    dataset[0].x = 0.0;
    dataset[0].y = 0.0;
    dataset[1].x = 1.0;
    dataset[1].y = 1.0;
    dataset[2].x = 2.0;
    dataset[2].y = 2.0;
    dataset[3].x = 3.0;
    dataset[3].y = 3.0;
    dataset[4].x = 4.0;
    dataset[4].y = 4.0;
    
    // Print out the original dataset
    printf("Original Dataset:\n");
    for (int i = 0; i < 5; i++) {
        printf("(%f, %f)\n", dataset[i].x, dataset[i].y);
    }
    
    // Calculate the mean of x and y values
    float x_mean = 0.0;
    float y_mean = 0.0;
    for (int i = 0; i < 5; i++) {
        x_mean += dataset[i].x;
        y_mean += dataset[i].y;
    }
    x_mean /= 5.0;
    y_mean /= 5.0;
    
    // Calculate the standard deviation of x and y values
    float x_stddev = 0.0;
    float y_stddev = 0.0;
    for (int i = 0; i < 5; i++) {
        x_stddev += (dataset[i].x - x_mean) * (dataset[i].x - x_mean);
        y_stddev += (dataset[i].y - y_mean) * (dataset[i].y - y_mean);
    }
    x_stddev = sqrt(x_stddev / 5.0);
    y_stddev = sqrt(y_stddev / 5.0);
    
    // Normalize the dataset
    for (int i = 0; i < 5; i++) {
        dataset[i].x = (dataset[i].x - x_mean) / x_stddev;
        dataset[i].y = (dataset[i].y - y_mean) / y_stddev;
    }
    
    // Print out the normalized dataset
    printf("Normalized Dataset:\n");
    for (int i = 0; i < 5; i++) {
        printf("(%f, %f)\n", dataset[i].x, dataset[i].y);
    }
    
    // Free the memory used by the dataset
    free(dataset);
    
    return 0;
}
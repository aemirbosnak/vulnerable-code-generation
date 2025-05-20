//FormAI DATASET v1.0 Category: Data mining ; Style: Donald Knuth
// Donald Knuth Style C Data Mining Example Program

#include <stdio.h>
#include <stdlib.h>

// Define constants
#define NUM_DATA_POINTS 1000
#define MAX_VALUE 100

// Define functions
int *generate_data();
int find_min(int *, int);
int find_max(int *, int);
float find_mean(int *, int);
float find_std_dev(int *, int);

int main() {

    // Generate test data
    int *data = generate_data();

    // Find min and max values
    int min_value = find_min(data, NUM_DATA_POINTS);
    int max_value = find_max(data, NUM_DATA_POINTS);
    printf("Min value: %d\n", min_value);
    printf("Max value: %d\n", max_value);

    // Find mean and standard deviation
    float mean = find_mean(data, NUM_DATA_POINTS);
    float std_dev = find_std_dev(data, NUM_DATA_POINTS);
    printf("Mean value: %f\n", mean);
    printf("Standard deviation: %f\n", std_dev);

    // Free memory of test data
    free(data);

    return 0;
}

// Generate random data points
int *generate_data() {
    int *data = (int *) malloc(NUM_DATA_POINTS * sizeof(int));
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        data[i] = rand() % MAX_VALUE + 1;
    }
    return data;
}

// Find minimum value in data set
int find_min(int *data, int num_points) {
    int min_value = data[0];
    for (int i = 1; i < num_points; i++) {
        if (data[i] < min_value) {
            min_value = data[i];
        }
    }
    return min_value;
}

// Find maximum value in data set
int find_max(int *data, int num_points) {
    int max_value = data[0];
    for (int i = 1; i < num_points; i++) {
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }
    return max_value;
}

// Find mean value of data set
float find_mean(int *data, int num_points) {
    float sum = 0;
    for (int i = 0; i < num_points; i++) {
        sum += data[i];
    }
    return sum / num_points;
}

// Find standard deviation of data set
float find_std_dev(int *data, int num_points) {
    float sum = 0;
    float mean = find_mean(data, num_points);
    for (int i = 0; i < num_points; i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum / num_points);
}
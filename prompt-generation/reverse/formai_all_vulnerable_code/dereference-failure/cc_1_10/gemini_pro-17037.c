//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

// Data structure to store a data point
typedef struct data_point {
    double values[MAX_COLS];
    int label;
} data_point;

// Data structure to store a dataset
typedef struct dataset {
    data_point points[MAX_ROWS];
    int num_rows;
    int num_cols;
} dataset;

// Function to read a dataset from a CSV file
dataset* read_dataset(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header line
    char line[1024];
    fgets(line, 1024, file);

    // Get the number of columns
    char* token = strtok(line, ",");
    int num_cols = 0;
    while (token != NULL) {
        num_cols++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the dataset
    dataset* data = malloc(sizeof(dataset));
    data->num_rows = 0;
    data->num_cols = num_cols;

    // Read the data points
    while (fgets(line, 1024, file) != NULL) {
        // Get the values
        token = strtok(line, ",");
        int i = 0;
        while (token != NULL) {
            data->points[data->num_rows].values[i] = atof(token);
            i++;
            token = strtok(NULL, ",");
        }

        // Get the label
        data->points[data->num_rows].label = atoi(token);

        // Increment the number of rows
        data->num_rows++;
    }

    // Close the file
    fclose(file);

    // Return the dataset
    return data;
}

// Function to print a dataset
void print_dataset(dataset* data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%f ", data->points[i].values[j]);
        }
        printf("%d\n", data->points[i].label);
    }
}

// Function to calculate the mean of a column
double mean(dataset* data, int col) {
    double sum = 0;
    for (int i = 0; i < data->num_rows; i++) {
        sum += data->points[i].values[col];
    }
    return sum / data->num_rows;
}

// Function to calculate the standard deviation of a column
double stddev(dataset* data, int col) {
    double mean_value = mean(data, col);
    double sum_of_squares = 0;
    for (int i = 0; i < data->num_rows; i++) {
        sum_of_squares += pow(data->points[i].values[col] - mean_value, 2);
    }
    return sqrt(sum_of_squares / (data->num_rows - 1));
}

// Function to normalize a column
void normalize_column(dataset* data, int col) {
    double mean_value = mean(data, col);
    double stddev_value = stddev(data, col);
    for (int i = 0; i < data->num_rows; i++) {
        data->points[i].values[col] = (data->points[i].values[col] - mean_value) / stddev_value;
    }
}

// Function to normalize a dataset
void normalize_dataset(dataset* data) {
    for (int i = 0; i < data->num_cols; i++) {
        normalize_column(data, i);
    }
}

// Main function
int main() {
    // Read the dataset from a CSV file
    dataset* data = read_dataset("data.csv");

    // Print the dataset
    printf("Original dataset:\n");
    print_dataset(data);

    // Normalize the dataset
    normalize_dataset(data);

    // Print the normalized dataset
    printf("\nNormalized dataset:\n");
    print_dataset(data);

    // Free the memory allocated for the dataset
    free(data);

    return 0;
}
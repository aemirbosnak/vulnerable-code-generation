//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to read a file and return a 2D array of integers representing the data
int** get_data(const char* filename) {
    // Open file
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    // Get line count
    int line_count = 0;
    char c;
    while ((c = fgetc(fp))!= EOF) {
        ++line_count;
    }
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for 2D array
    int** data = (int**)malloc(line_count * sizeof(int*));
    for (int i = 0; i < line_count; ++i) {
        data[i] = (int*)malloc(sizeof(int));
    }

    // Read data from file into 2D array
    int index = 0;
    while (fscanf(fp, "%d", &data[index][0]) == 1) {
        index++;
    }
    fclose(fp);

    return data;
}

// Function to calculate the average value of a 2D array of integers
double calculate_average(int** arr, int rows, int cols) {
    double sum = 0.0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
        }
    }
    return sum / (rows * cols);
}

// Function to find the index of the maximum value in a 2D array of integers
int find_max(int** arr, int rows, int cols) {
    double max_val = arr[0][0];
    int max_index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
                max_index = i * cols + j;
            }
        }
    }
    return max_index;
}

// Function to find the index of the minimum value in a 2D array of integers
int find_min(int** arr, int rows, int cols) {
    double min_val = arr[0][0];
    int min_index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] < min_val) {
                min_val = arr[i][j];
                min_index = i * cols + j;
            }
        }
    }
    return min_index;
}

// Main function
int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Get data from file
    int** data = get_data(argv[1]);

    // Calculate average
    double avg = calculate_average(data, data[0][0], data[0][1]);
    printf("Average: %.2f\n", avg);

    // Find maximum
    int max_index = find_max(data, data[0][0], data[0][1]);
    printf("Maximum index: %d, value: %d\n", max_index / data[0][1], data[max_index / data[0][1]][max_index % data[0][1]]);

    // Find minimum
    int min_index = find_min(data, data[0][0], data[0][1]);
    printf("Minimum index: %d, value: %d\n", min_index / data[0][1], data[min_index / data[0][1]][min_index % data[0][1]]);

    // Free memory
    for (int i = 0; i < data[0][0]; ++i) {
        free(data[i]);
    }
    free(data);

    return 0;
}
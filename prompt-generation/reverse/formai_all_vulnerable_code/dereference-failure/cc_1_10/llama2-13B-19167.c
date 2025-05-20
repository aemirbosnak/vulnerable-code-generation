//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

// Structure to store data point
typedef struct {
    double x;
    double y;
} data_point;

// Function to generate random data points
data_point* generate_random_data(int num_rows, int num_cols) {
    data_point* data = (data_point*) calloc(num_rows, sizeof(data_point));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            data[i].x = (double)rand() / RAND_MAX;
            data[i].y = (double)rand() / RAND_MAX;
        }
    }
    return data;
}

// Function to visualize the data
void visualize_data(data_point* data, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%.2f,%.2f ", data[i].x, data[i].y);
            if (j < num_cols - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    // Generate random data points
    data_point* data = generate_random_data(MAX_ROWS, MAX_COLS);

    // Visualize the data
    visualize_data(data, MAX_ROWS, MAX_COLS);

    // Free the memory
    free(data);

    return 0;
}
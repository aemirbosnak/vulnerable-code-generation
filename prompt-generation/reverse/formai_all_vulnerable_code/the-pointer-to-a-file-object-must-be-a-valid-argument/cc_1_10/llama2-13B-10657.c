//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

// Structure to hold the data
typedef struct {
    int id;
    double value;
} data_t;

// Function to read the data from a file
data_t* read_data(const char* file_name) {
    data_t* data = (data_t*)calloc(MAX_ROWS, sizeof(data_t));
    FILE* file = fopen(file_name, "r");
    char line[100];
    int i = 0;

    while (fgets(line, 100, file)) {
        // Ignore the header row
        if (i == 0) {
            continue;
        }

        // Extract the values
        char* token = strtok(line, ",");
        data[i].id = atoi(token);
        token = strtok(NULL, ",");
        data[i].value = atof(token);

        i++;
    }

    fclose(file);
    return data;
}

// Function to calculate the mean and standard deviation
void calculate_stats(data_t* data, int num_rows) {
    double mean = 0;
    double std_dev = 0;
    int i = 0;

    for (i = 0; i < num_rows; i++) {
        mean += data[i].value;
        std_dev += (data[i].value - mean) * (data[i].value - mean);
    }

    mean /= num_rows;
    std_dev /= num_rows;
    std_dev = sqrt(std_dev);

    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", std_dev);
}

int main() {
    // Load the data
    data_t* data = read_data("data.csv");

    // Calculate the stats
    calculate_stats(data, MAX_ROWS);

    // Free the memory
    free(data);

    return 0;
}
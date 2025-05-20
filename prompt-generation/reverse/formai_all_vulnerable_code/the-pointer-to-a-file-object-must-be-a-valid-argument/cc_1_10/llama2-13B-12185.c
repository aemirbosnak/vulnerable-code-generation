//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_LENGTH 1000
#define MIN_VALUE -100
#define MAX_VALUE 100

struct file_data {
    int num_records;
    double mean;
    double stddev;
    double min_value;
    double max_value;
};

void read_file(const char *filename, struct file_data *data) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LENGTH];
    int i = 0;

    // Calculate the mean and standard deviation of the file
    data->mean = 0;
    data->stddev = 0;
    data->min_value = MIN_VALUE;
    data->max_value = MAX_VALUE;

    while (fgets(line, MAX_LENGTH, file)) {
        double value = atof(line);
        data->num_records++;

        if (i == 0) {
            data->mean = value;
        } else {
            data->mean = (data->mean * data->num_records + value) / (i + 1);
            data->stddev = sqrt(((value - data->mean) * (value - data->mean)) / (i - 1));
        }

        if (value < data->min_value) {
            data->min_value = value;
        }

        if (value > data->max_value) {
            data->max_value = value;
        }

        i++;
    }

    fclose(file);
}

int main() {
    struct file_data data;
    char filename[] = "example.txt";

    // Read the file
    read_file(filename, &data);

    // Print the summary statistics
    printf("Summary Statistics:\n");
    printf("Mean: %f\n", data.mean);
    printf("Standard Deviation: %f\n", data.stddev);
    printf("Minimum Value: %f\n", data.min_value);
    printf("Maximum Value: %f\n", data.max_value);

    return 0;
}
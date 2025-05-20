//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 10000
#define MAX_STRING_LENGTH 50

// Structure to store data points
typedef struct {
    char *name;
    int age;
    float income;
} data_point_t;

// Function to read data from a file
void read_data(const char *file_name, data_point_t *data) {
    FILE *file = fopen(file_name, "r");
    char line[100];
    int i = 0;

    while (fgets(line, 100, file) != NULL) {
        // Skip comments and empty lines
        if (line[0] == '#' || strcmp(line, "") == 0) {
            continue;
        }

        // Split the line into name, age, and income
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        float income = atof(strtok(NULL, "."));

        // Store the data point in the array
        data[i++] = (data_point_t) {
            .name = name,
            .age = age,
            .income = income
        };
    }

    fclose(file);
}

// Function to print the data points
void print_data(data_point_t *data, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%s %d %f\n", data[i].name, data[i].age, data[i].income);
    }
}

int main() {
    // Load the data from a file
    data_point_t data[DATABASE_SIZE];
    read_data("data.txt", data);

    // Filter the data to only include people with an income above $50,000
    int count = 0;
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (data[i].income > 50000.0) {
            count++;
            data[count] = data[i];
        }
    }

    // Print the filtered data
    print_data(data, count);

    return 0;
}
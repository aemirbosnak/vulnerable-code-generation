//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#define MAX_LEN 1024
#define MIN_LEN 1

// Define the data structure for the happy data
typedef struct {
    int happiness; // The happiness level, 1-10
    int reason;   // The reason for the happiness, 1-10
} happy_data;

// Function to read the happy data from a file
happy_data* read_happy_data(const char* file_name) {
    // Open the file in read mode
    FILE* file = fopen(file_name, "r");
    assert(file != NULL);

    // Read the file line by line
    char line[MAX_LEN];
    happy_data* data = NULL;
    int i = 0;
    while (fgets(line, MAX_LEN, file) != NULL) {
        // Extract the happiness level and reason from the line
        int happiness = atoi(line + 1);
        int reason = atoi(strchr(line, ':') + 1);

        // Add the data to the list
        data = realloc(data, (i + 1) * sizeof(happy_data));
        data[i].happiness = happiness;
        data[i].reason = reason;
        i++;
    }

    // Close the file
    fclose(file);

    return data;
}

// Function to print the happy data
void print_happy_data(happy_data* data, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%d: %s\n", data[i].happiness, data[i].reason);
    }
}

// Function to calculate the average happiness
double calculate_average_happiness(happy_data* data, int count) {
    int i;
    double sum = 0;
    for (i = 0; i < count; i++) {
        sum += data[i].happiness;
    }
    return sum / count;
}

int main() {
    // Read the happy data from a file
    happy_data* data = read_happy_data("happy_data.txt");

    // Print the happy data
    print_happy_data(data, 10);

    // Calculate the average happiness
    double average = calculate_average_happiness(data, 10);
    printf("Average happiness: %f\n", average);

    // Free the memory
    free(data);

    return 0;
}
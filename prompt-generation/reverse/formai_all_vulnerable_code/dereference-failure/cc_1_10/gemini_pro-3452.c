//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a custom data structure for performance-critical data
typedef struct {
    int id;
    char *name;
    double value;
} PerformanceCriticalData;

// Define a function to initialize performance-critical data
PerformanceCriticalData *init_performance_critical_data(int id, char *name, double value) {
    PerformanceCriticalData *data = malloc(sizeof(PerformanceCriticalData));
    data->id = id;
    data->name = strdup(name);
    data->value = value;
    return data;
}

// Define a function to free performance-critical data
void free_performance_critical_data(PerformanceCriticalData *data) {
    free(data->name);
    free(data);
}

// Define a function to perform a performance-critical operation on data
double perform_performance_critical_operation(PerformanceCriticalData *data) {
    // Simulate a performance-critical operation by sleeping for a random amount of time
    srand(time(NULL));
    int sleep_time = rand() % 1000;
    usleep(sleep_time * 1000);

    // Return a random value as the result of the operation
    return (double)rand() / RAND_MAX;
}

// Define a main function to test the performance-critical component
int main() {
    // Create a performance-critical data object
    PerformanceCriticalData *data = init_performance_critical_data(1, "Example Data", 0.0);

    // Perform a performance-critical operation on the data multiple times
    for (int i = 0; i < 1000000; i++) {
        double result = perform_performance_critical_operation(data);
        printf("Result: %f\n", result);
    }

    // Free the performance-critical data object
    free_performance_critical_data(data);

    return 0;
}
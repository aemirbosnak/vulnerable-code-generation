//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int steps;
    int calories;
    int distance;
    int active_minutes;
    int sleep_minutes;
    int heart_rate;
} fitness_data;

fitness_data *create_fitness_data(char *name) {
    fitness_data *data = malloc(sizeof(fitness_data));
    data->name = strdup(name);
    data->steps = 0;
    data->calories = 0;
    data->distance = 0;
    data->active_minutes = 0;
    data->sleep_minutes = 0;
    data->heart_rate = 0;
    return data;
}

void destroy_fitness_data(fitness_data *data) {
    free(data->name);
    free(data);
}

void print_fitness_data(fitness_data *data) {
    printf("Name: %s\n", data->name);
    printf("Steps: %d\n", data->steps);
    printf("Calories: %d\n", data->calories);
    printf("Distance: %d\n", data->distance);
    printf("Active minutes: %d\n", data->active_minutes);
    printf("Sleep minutes: %d\n", data->sleep_minutes);
    printf("Heart rate: %d\n", data->heart_rate);
}

int main() {
    fitness_data *data = create_fitness_data("John Doe");

    // Simulate some fitness activity
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        data->steps += rand() % 1000;
        data->calories += rand() % 100;
        data->distance += rand() % 10;
        data->active_minutes += rand() % 60;
        data->sleep_minutes += rand() % 60;
        data->heart_rate += rand() % 100;
    }

    // Print the fitness data
    print_fitness_data(data);

    // Destroy the fitness data
    destroy_fitness_data(data);

    return 0;
}
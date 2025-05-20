//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the data structures and functions for the fitness tracker
typedef struct {
    char *name;
    int age;
    double weight;
    double height;
    int steps;
    int calories;
    int distance;
    int active_minutes;
    int sleep_hours;
    int sleep_quality;
} FitnessData;

FitnessData *create_fitness_data(char *name, int age, double weight, double height, int steps, int calories, int distance, int active_minutes, int sleep_hours, int sleep_quality) {
    FitnessData *data = malloc(sizeof(FitnessData));
    data->name = strdup(name);
    data->age = age;
    data->weight = weight;
    data->height = height;
    data->steps = steps;
    data->calories = calories;
    data->distance = distance;
    data->active_minutes = active_minutes;
    data->sleep_hours = sleep_hours;
    data->sleep_quality = sleep_quality;
    return data;
}

void print_fitness_data(FitnessData *data) {
    printf("Name: %s\n", data->name);
    printf("Age: %d\n", data->age);
    printf("Weight: %f\n", data->weight);
    printf("Height: %f\n", data->height);
    printf("Steps: %d\n", data->steps);
    printf("Calories: %d\n", data->calories);
    printf("Distance: %d\n", data->distance);
    printf("Active minutes: %d\n", data->active_minutes);
    printf("Sleep hours: %d\n", data->sleep_hours);
    printf("Sleep quality: %d\n", data->sleep_quality);
}

// Define the main function
int main() {
    // Create a FitnessData object for yourself
    FitnessData *my_data = create_fitness_data("John Doe", 30, 80.0, 1.80, 10000, 2000, 5, 60, 8, 4);

    // Print your fitness data to the console
    print_fitness_data(my_data);

    // Free the memory allocated for the FitnessData object
    free(my_data->name);
    free(my_data);

    return 0;
}
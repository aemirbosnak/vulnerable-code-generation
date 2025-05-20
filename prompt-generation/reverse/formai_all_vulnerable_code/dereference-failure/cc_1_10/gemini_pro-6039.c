//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fitness tracker data structure
typedef struct fitness_tracker {
    int steps;
    int distance;
    int calories;
    int heart_rate;
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *ft = malloc(sizeof(fitness_tracker));
    ft->steps = 0;
    ft->distance = 0;
    ft->calories = 0;
    ft->heart_rate = 0;
    return ft;
}

// Destroy a fitness tracker
void destroy_fitness_tracker(fitness_tracker *ft) {
    free(ft);
}

// Get the number of steps taken
int get_steps(fitness_tracker *ft) {
    return ft->steps;
}

// Set the number of steps taken
void set_steps(fitness_tracker *ft, int steps) {
    ft->steps = steps;
}

// Get the distance traveled
int get_distance(fitness_tracker *ft) {
    return ft->distance;
}

// Set the distance traveled
void set_distance(fitness_tracker *ft, int distance) {
    ft->distance = distance;
}

// Get the number of calories burned
int get_calories(fitness_tracker *ft) {
    return ft->calories;
}

// Set the number of calories burned
void set_calories(fitness_tracker *ft, int calories) {
    ft->calories = calories;
}

// Get the heart rate
int get_heart_rate(fitness_tracker *ft) {
    return ft->heart_rate;
}

// Set the heart rate
void set_heart_rate(fitness_tracker *ft, int heart_rate) {
    ft->heart_rate = heart_rate;
}

// Print the fitness tracker data
void print_fitness_tracker(fitness_tracker *ft) {
    printf("Steps: %d\n", get_steps(ft));
    printf("Distance: %d\n", get_distance(ft));
    printf("Calories: %d\n", get_calories(ft));
    printf("Heart rate: %d\n", get_heart_rate(ft));
}

// Main function
int main() {
    // Create a fitness tracker
    fitness_tracker *ft = create_fitness_tracker();

    // Set the fitness tracker data
    set_steps(ft, 10000);
    set_distance(ft, 5000);
    set_calories(ft, 2000);
    set_heart_rate(ft, 120);

    // Print the fitness tracker data
    print_fitness_tracker(ft);

    // Destroy the fitness tracker
    destroy_fitness_tracker(ft);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures

typedef struct {
    char* name;
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    int distance;
    int active_minutes;
    int sleep_duration;
    int sleep_quality;
} fitness_tracker;

// Functions

fitness_tracker* create_fitness_tracker(char* name, int age, int weight, int height) {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->name = strdup(name);
    tracker->age = age;
    tracker->weight = weight;
    tracker->height = height;
    tracker->steps = 0;
    tracker->calories = 0;
    tracker->distance = 0;
    tracker->active_minutes = 0;
    tracker->sleep_duration = 0;
    tracker->sleep_quality = 0;
    return tracker;
}

void destroy_fitness_tracker(fitness_tracker* tracker) {
    free(tracker->name);
    free(tracker);
}

void add_steps(fitness_tracker* tracker, int steps) {
    tracker->steps += steps;
}

void add_calories(fitness_tracker* tracker, int calories) {
    tracker->calories += calories;
}

void add_distance(fitness_tracker* tracker, int distance) {
    tracker->distance += distance;
}

void add_active_minutes(fitness_tracker* tracker, int minutes) {
    tracker->active_minutes += minutes;
}

void add_sleep_duration(fitness_tracker* tracker, int minutes) {
    tracker->sleep_duration += minutes;
}

void add_sleep_quality(fitness_tracker* tracker, int quality) {
    tracker->sleep_quality += quality;
}

void print_fitness_tracker(fitness_tracker* tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Weight: %d\n", tracker->weight);
    printf("Height: %d\n", tracker->height);
    printf("Steps: %d\n", tracker->steps);
    printf("Calories: %d\n", tracker->calories);
    printf("Distance: %d\n", tracker->distance);
    printf("Active minutes: %d\n", tracker->active_minutes);
    printf("Sleep duration: %d\n", tracker->sleep_duration);
    printf("Sleep quality: %d\n", tracker->sleep_quality);
}

// Main program

int main() {
    // Creare a fitness tracker for yourself
    fitness_tracker* tracker = create_fitness_tracker("Your Name", 25, 70, 180);

    // Add some steps, calories, and distance
    add_steps(tracker, 10000);
    add_calories(tracker, 2000);
    add_distance(tracker, 5);

    // Add some active minutes and sleep duration
    add_active_minutes(tracker, 60);
    add_sleep_duration(tracker, 8);

    // Print the fitness tracker
    print_fitness_tracker(tracker);

    // Destroy the fitness tracker
    destroy_fitness_tracker(tracker);

    return 0;
}
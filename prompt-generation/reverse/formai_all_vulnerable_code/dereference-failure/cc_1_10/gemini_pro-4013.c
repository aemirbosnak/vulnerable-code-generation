//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Fitness Tracker Data Structure
typedef struct fitness_tracker {
    char name[32];          // User's name
    int age;                // User's age
    int height;             // User's height in cm
    int weight;             // User's weight in kg
    int steps_per_day;      // User's average steps per day
    int active_minutes;     // User's average active minutes per day
    int sleep_hours;        // User's average sleep hours per night
    int resting_heart_rate; // User's resting heart rate in bpm
} fitness_tracker;

// Function to create a new fitness tracker
fitness_tracker* create_fitness_tracker(char* name, int age, int height, int weight,
                                       int steps_per_day, int active_minutes,
                                       int sleep_hours, int resting_heart_rate) {
    fitness_tracker* tracker = (fitness_tracker*)malloc(sizeof(fitness_tracker));
    if (tracker == NULL) {
        return NULL;
    }
    strcpy(tracker->name, name);
    tracker->age = age;
    tracker->height = height;
    tracker->weight = weight;
    tracker->steps_per_day = steps_per_day;
    tracker->active_minutes = active_minutes;
    tracker->sleep_hours = sleep_hours;
    tracker->resting_heart_rate = resting_heart_rate;
    return tracker;
}

// Function to print a fitness tracker
void print_fitness_tracker(fitness_tracker* tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Height: %d cm\n", tracker->height);
    printf("Weight: %d kg\n", tracker->weight);
    printf("Steps per day: %d\n", tracker->steps_per_day);
    printf("Active minutes: %d\n", tracker->active_minutes);
    printf("Sleep hours: %d\n", tracker->sleep_hours);
    printf("Resting heart rate: %d bpm\n", tracker->resting_heart_rate);
}

// Function to calculate the user's BMI
float calculate_bmi(fitness_tracker* tracker) {
    float bmi = (float)tracker->weight / ((float)tracker->height * (float)tracker->height / 10000);
    return bmi;
}

// Function to calculate the user's TDEE
float calculate_tdee(fitness_tracker* tracker) {
    float tdee = (10 * (float)tracker->weight) + (6.25 * (float)tracker->height) - (5 * (float)tracker->age) + 5;
    return tdee;
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker* tracker = create_fitness_tracker("John Doe", 30, 180, 80, 10000, 60, 7, 60);

    // Print the fitness tracker
    print_fitness_tracker(tracker);

    // Calculate the user's BMI
    float bmi = calculate_bmi(tracker);
    printf("BMI: %.2f\n", bmi);

    // Calculate the user's TDEE
    float tdee = calculate_tdee(tracker);
    printf("TDEE: %.2f\n", tdee);

    return 0;
}
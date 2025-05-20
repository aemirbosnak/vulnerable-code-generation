//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int steps;
    int calories;
    int distance;
} FitnessData;

typedef struct {
    int id;
    char* name;
    int age;
    FitnessData fitnessData;
} FitnessTracker;

// Creates a new fitness tracker with the given parameters.
FitnessTracker* createFitnessTracker(int id, char* name, int age) {
    FitnessTracker* tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    tracker->id = id;
    tracker->name = name;
    tracker->age = age;
    tracker->fitnessData.steps = 0;
    tracker->fitnessData.calories = 0;
    tracker->fitnessData.distance = 0;
    return tracker;
}

// Adds the given steps to the fitness tracker's total steps.
void addSteps(FitnessTracker* tracker, int steps) {
    tracker->fitnessData.steps += steps;
}

// Adds the given calories to the fitness tracker's total calories.
void addCalories(FitnessTracker* tracker, int calories) {
    tracker->fitnessData.calories += calories;
}

// Adds the given distance to the fitness tracker's total distance.
void addDistance(FitnessTracker* tracker, int distance) {
    tracker->fitnessData.distance += distance;
}

// Prints the fitness tracker's data to the console.
void printFitnessData(FitnessTracker* tracker) {
    printf("ID: %d\n", tracker->id);
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Steps: %d\n", tracker->fitnessData.steps);
    printf("Calories: %d\n", tracker->fitnessData.calories);
    printf("Distance: %d\n", tracker->fitnessData.distance);
}

// Generates a random fitness tracker with random data.
FitnessTracker* generateRandomFitnessTracker() {
    srand(time(NULL));
    int id = rand() % 10000;
    char* name = (char*)malloc(sizeof(char) * 10);
    for (int i = 0; i < 9; i++) {
        name[i] = 'a' + rand() % 26;
    }
    name[9] = '\0';
    int age = rand() % 100;
    FitnessTracker* tracker = createFitnessTracker(id, name, age);
    tracker->fitnessData.steps = rand() % 10000;
    tracker->fitnessData.calories = rand() % 1000;
    tracker->fitnessData.distance = rand() % 100;
    return tracker;
}

int main() {
    // Create a fitness tracker.
    FitnessTracker* tracker = createFitnessTracker(1, "John Doe", 25);

    // Add some data to the fitness tracker.
    addSteps(tracker, 1000);
    addCalories(tracker, 500);
    addDistance(tracker, 5);

    // Print the fitness tracker's data to the console.
    printFitnessData(tracker);

    // Free the memory allocated for the fitness tracker.
    free(tracker->name);
    free(tracker);

    return 0;
}
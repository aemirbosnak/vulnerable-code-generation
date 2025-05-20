//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Workout {
    char type[50];
    int duration; // in minutes
    int caloriesBurned;
} Workout;

typedef struct FitnessTracker {
    Workout *workouts;
    int count;
    int capacity;
} FitnessTracker;

// Function prototypes
FitnessTracker* createFitnessTracker(int capacity);
void addWorkout(FitnessTracker *tracker, char *type, int duration, int calories);
void displayWorkouts(FitnessTracker *tracker);
void totalCalories(FitnessTracker *tracker);
void freeTracker(FitnessTracker *tracker);

int main() {
    printf("Ah, Watson! Welcome to our latest endeavor—the fitness tracker. A most peculiar yet necessary tool for the modern gentleman.\n");

    FitnessTracker *tracker = createFitnessTracker(5);

    addWorkout(tracker, "Running", 30, 300);
    addWorkout(tracker, "Cycling", 45, 500);
    addWorkout(tracker, "Swimming", 60, 700);
    addWorkout(tracker, "Yoga", 30, 200);
    addWorkout(tracker, "Walking", 45, 250);

    printf("\nLet us document our notable exertions, shall we?\n");
    displayWorkouts(tracker);

    printf("\nAnd now, to calculate the grand total of calories burned during our exercises...\n");
    totalCalories(tracker);

    printf("\nBut my dear Watson, I must now attend to other matters of importance. \n");
    freeTracker(tracker);

    return 0;
}

FitnessTracker* createFitnessTracker(int capacity) {
    FitnessTracker *tracker = (FitnessTracker *)malloc(sizeof(FitnessTracker));
    tracker->workouts = (Workout *)malloc(sizeof(Workout) * capacity);
    tracker->count = 0;
    tracker->capacity = capacity;
    printf("A fitness tracker has been created, equipped to record %d workouts.\n", capacity);
    return tracker;
}

void addWorkout(FitnessTracker *tracker, char *type, int duration, int calories) {
    if (tracker->count < tracker->capacity) {
        strcpy(tracker->workouts[tracker->count].type, type);
        tracker->workouts[tracker->count].duration = duration;
        tracker->workouts[tracker->count].caloriesBurned = calories;
        tracker->count++;
        printf("Added workout: %s for %d minutes, burning %d calories.\n", type, duration, calories);
    } else {
        printf("Alas, my dear Watson! Our tracker is full, and we cannot record any more workouts.\n");
    }
}

void displayWorkouts(FitnessTracker *tracker) {
    printf("Here is a comprehensive list of our workouts:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. Type: %s, Duration: %d minutes, Calories Burned: %d\n", 
            i + 1, tracker->workouts[i].type, tracker->workouts[i].duration, tracker->workouts[i].caloriesBurned);
    }
}

void totalCalories(FitnessTracker *tracker) {
    int total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->workouts[i].caloriesBurned;
    }
    printf("Total calories burned in this session: %d calories.\n", total);
}

void freeTracker(FitnessTracker *tracker) {
    free(tracker->workouts);
    free(tracker);
    printf("The fitness tracker has been freed from memory, Watson.\n");
}
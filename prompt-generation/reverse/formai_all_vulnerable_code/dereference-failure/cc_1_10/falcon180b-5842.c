//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a workout session
typedef struct {
    char* exercise;
    int duration;
    int calories;
} Workout;

// Define the structure of a fitness plan
typedef struct {
    int numWorkouts;
    Workout* workouts;
} FitnessPlan;

// Function to print the current date and time
void printDateTime() {
    time_t now = time(NULL);
    struct tm* dt = localtime(&now);
    printf("Current date and time: %d/%d/%d %d:%d:%d\n", dt->tm_mday, dt->tm_mon+1, dt->tm_year+1900, dt->tm_hour, dt->tm_min, dt->tm_sec);
}

// Function to calculate the number of calories burned based on exercise type and duration
int calculateCalories(char* exercise, int duration) {
    if (strcmp(exercise, "Running") == 0) {
        return duration * 10;
    } else if (strcmp(exercise, "Cycling") == 0) {
        return duration * 8;
    } else if (strcmp(exercise, "Swimming") == 0) {
        return duration * 12;
    } else {
        return 0;
    }
}

// Function to display the details of a workout session
void displayWorkout(Workout w) {
    printf("Exercise: %s\n", w.exercise);
    printf("Duration: %d minutes\n", w.duration);
    printf("Calories burned: %d\n\n", w.calories);
}

// Function to display the details of a fitness plan
void displayFitnessPlan(FitnessPlan fp) {
    printf("Fitness Plan:\n");
    for (int i = 0; i < fp.numWorkouts; i++) {
        displayWorkout(fp.workouts[i]);
    }
}

// Main function to create and display a fitness plan
int main() {
    printDateTime();

    // Define the workout sessions
    Workout workouts[] = {
        {"Running", 30, 0},
        {"Cycling", 45, 0},
        {"Swimming", 60, 0}
    };

    // Calculate the calories burned for each workout session
    for (int i = 0; i < 3; i++) {
        workouts[i].calories = calculateCalories(workouts[i].exercise, workouts[i].duration);
    }

    // Define the fitness plan
    FitnessPlan fp = {3, workouts};

    // Display the fitness plan
    displayFitnessPlan(fp);

    return 0;
}
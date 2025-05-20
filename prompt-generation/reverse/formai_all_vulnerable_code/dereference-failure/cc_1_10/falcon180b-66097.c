//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of exercises
#define MAX_EXERCISES 10

// Define the structure of an exercise
typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

// Define the structure of a workout session
typedef struct {
    int numExercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

// Function to print the current date and time
void printDateTime() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("Current date and time: %d/%d/%d %02d:%02d:%02d\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
}

// Function to get user input for an exercise
void getExerciseInput(Exercise *exercise) {
    printf("Enter exercise name: ");
    scanf("%s", exercise->name);

    printf("Enter exercise duration (in minutes): ");
    scanf("%d", &exercise->duration);

    printf("Enter exercise calories burned: ");
    scanf("%d", &exercise->calories);
}

// Function to get user input for a workout session
void getWorkoutInput(Workout *workout) {
    printf("Enter number of exercises: ");
    scanf("%d", &workout->numExercises);

    for (int i = 0; i < workout->numExercises; i++) {
        getExerciseInput(&workout->exercises[i]);
    }
}

// Function to calculate total calories burned in a workout session
int calculateTotalCalories(Workout *workout) {
    int totalCalories = 0;

    for (int i = 0; i < workout->numExercises; i++) {
        totalCalories += workout->exercises[i].calories;
    }

    return totalCalories;
}

// Function to print workout session summary
void printWorkoutSummary(Workout *workout) {
    printf("Workout summary:\n");
    printf("Number of exercises: %d\n", workout->numExercises);
    printf("Total calories burned: %d\n", calculateTotalCalories(workout));
}

int main() {
    printDateTime();

    Workout workout;
    getWorkoutInput(&workout);

    printWorkoutSummary(&workout);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the maximum number of exercises
#define MAX_EXERCISES 10

// Define the structure of an exercise
typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

// Define the structure of a workout
typedef struct {
    int num_exercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

void add_exercise(Workout* workout, char* name, int duration, int calories) {
    if (workout->num_exercises >= MAX_EXERCISES) {
        printf("Error: Maximum number of exercises reached.\n");
        return;
    }
    
    strcpy(workout->exercises[workout->num_exercises].name, name);
    workout->exercises[workout->num_exercises].duration = duration;
    workout->exercises[workout->num_exercises].calories = calories;
    
    workout->num_exercises++;
}

void print_workout(Workout* workout) {
    printf("Workout:\n");
    for (int i = 0; i < workout->num_exercises; i++) {
        printf("%s - Duration: %d minutes - Calories burned: %d\n", workout->exercises[i].name, workout->exercises[i].duration, workout->exercises[i].calories);
    }
}

void calculate_total_calories(Workout* workout) {
    int total_calories = 0;
    
    for (int i = 0; i < workout->num_exercises; i++) {
        total_calories += workout->exercises[i].calories;
    }
    
    printf("Total calories burned: %d\n", total_calories);
}

void calculate_average_calories(Workout* workout) {
    int total_calories = 0;
    int total_duration = 0;
    
    for (int i = 0; i < workout->num_exercises; i++) {
        total_calories += workout->exercises[i].calories;
        total_duration += workout->exercises[i].duration;
    }
    
    float average_calories = (float)total_calories / total_duration;
    
    printf("Average calories burned per minute: %.2f\n", average_calories);
}

int main() {
    Workout workout;
    
    add_exercise(&workout, "Running", 30, 300);
    add_exercise(&workout, "Swimming", 45, 400);
    add_exercise(&workout, "Cycling", 60, 500);
    
    print_workout(&workout);
    
    calculate_total_calories(&workout);
    calculate_average_calories(&workout);
    
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of exercises
#define MAX_EXERCISES 10

// Define the structure for an exercise
typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

// Define the structure for a workout session
typedef struct {
    int num_exercises;
    Exercise exercises[MAX_EXERCISES];
} WorkoutSession;

// Function to add an exercise to a workout session
void add_exercise(WorkoutSession *session, char *name, int duration, int calories) {
    if (session->num_exercises >= MAX_EXERCISES) {
        printf("Error: Maximum number of exercises reached.\n");
        return;
    }

    strcpy(session->exercises[session->num_exercises].name, name);
    session->exercises[session->num_exercises].duration = duration;
    session->exercises[session->num_exercises].calories = calories;

    session->num_exercises++;
}

// Function to start a workout session
void start_workout(WorkoutSession *session) {
    time_t start_time, end_time;

    time(&start_time);

    printf("Workout started.\n");

    for (int i = 0; i < session->num_exercises; i++) {
        printf("Starting exercise: %s\n", session->exercises[i].name);
        fflush(stdout);

        time(&end_time);
        while (difftime(end_time, start_time) < session->exercises[i].duration) {
            time(&end_time);
        }

        printf("Finished exercise: %s\n", session->exercises[i].name);
        fflush(stdout);
    }

    printf("Workout completed.\n");
}

// Function to calculate the total calories burned during a workout session
int calculate_calories(WorkoutSession *session) {
    int total_calories = 0;

    for (int i = 0; i < session->num_exercises; i++) {
        total_calories += session->exercises[i].calories;
    }

    return total_calories;
}

int main() {
    WorkoutSession session;

    add_exercise(&session, "Running", 30, 300);
    add_exercise(&session, "Cycling", 45, 500);

    start_workout(&session);

    int total_calories = calculate_calories(&session);

    printf("Total calories burned: %d\n", total_calories);

    return 0;
}
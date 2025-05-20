//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    char *name;
    int duration;
    int calories;
    int heart_rate;
} exercise;

void add_exercise(exercise *workout, char *name, int duration, int calories, int heart_rate) {
    workout->name = name;
    workout->duration = duration;
    workout->calories = calories;
    workout->heart_rate = heart_rate;
}

void print_workout(exercise workout) {
    printf("Name: %s\n", workout.name);
    printf("Duration: %d minutes\n", workout.duration);
    printf("Calories burned: %d\n", workout.calories);
    printf("Average heart rate: %d bpm\n", workout.heart_rate);
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_exercises;
    printf("How many exercises did you complete today? ");
    scanf("%d", &num_exercises);

    exercise workout[num_exercises];

    for (int i = 0; i < num_exercises; i++) {
        char exercise_name[20];
        sprintf(exercise_name, "Exercise %d", i+1);
        add_exercise(&workout[i], exercise_name, rand() % 60 + 1, rand() % 500 + 1, rand() % 200 + 1);
    }

    printf("Your workout summary for today:\n");

    for (int i = 0; i < num_exercises; i++) {
        print_workout(workout[i]);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 5

typedef struct {
    char *name;
    int duration;
    int calories;
} Workout;

void add_workout(Workout *workouts, int num_workouts, char *name, int duration, int calories) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Cannot add more than %d workouts.\n", MAX_WORKOUTS);
        return;
    }

    workouts[num_workouts].name = name;
    workouts[num_workouts].duration = duration;
    workouts[num_workouts].calories = calories;

    num_workouts++;
}

void print_workouts(Workout *workouts, int num_workouts) {
    printf("Workout Name\tDuration\tCalories\n");

    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t\t%d\t\t%d\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        char *name = malloc(10 * sizeof(char));
        sprintf(name, "Workout %d", i + 1);

        int duration = rand() % 60 + 1;
        int calories = rand() % 100 + 1;

        add_workout(workouts, num_workouts, name, duration, calories);
    }

    print_workouts(workouts, num_workouts);

    return 0;
}
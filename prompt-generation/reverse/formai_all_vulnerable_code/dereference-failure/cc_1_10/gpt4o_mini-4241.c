//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Workout {
    char type[30];
    float distance;
    int duration; // in minutes
} Workout;

typedef struct FitnessTracker {
    Workout *workouts;
    int count;
    int capacity;
} FitnessTracker;

FitnessTracker* createTracker() {
    FitnessTracker *tracker = malloc(sizeof(FitnessTracker));
    tracker->count = 0;
    tracker->capacity = 2; // Initial capacity
    tracker->workouts = malloc(tracker->capacity * sizeof(Workout));
    return tracker;
}

void addWorkout(FitnessTracker *tracker, const char *type, float distance, int duration) {
    if (tracker->count >= tracker->capacity) {
        tracker->capacity *= 2;
        tracker->workouts = realloc(tracker->workouts, tracker->capacity * sizeof(Workout));
    }
    
    strncpy(tracker->workouts[tracker->count].type, type, 30);
    tracker->workouts[tracker->count].distance = distance;
    tracker->workouts[tracker->count].duration = duration;
    tracker->count++;
    printf("Workout added: %s, Distance: %.2f km, Duration: %d minutes\n", type, distance, duration);
}

void viewWorkouts(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged.\n");
        return;
    }

    printf("\nWorkout History:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s | Distance: %.2f km | Duration: %d minutes\n", 
                i + 1, tracker->workouts[i].type, tracker->workouts[i].distance, tracker->workouts[i].duration);
    }
}

void freeTracker(FitnessTracker *tracker) {
    free(tracker->workouts);
    free(tracker);
}

int main() {
    FitnessTracker *tracker = createTracker();
    int choice;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Workout\n");
        printf("2. View Workouts\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char type[30];
            float distance;
            int duration;
            printf("Enter workout type (e.g. Running, Cycling): ");
            scanf("%s", type);
            printf("Enter distance (in km): ");
            scanf("%f", &distance);
            printf("Enter duration (in minutes): ");
            scanf("%d", &duration);
            addWorkout(tracker, type, distance, duration);
        } else if (choice == 2) {
            viewWorkouts(tracker);
        } else if (choice == 3) {
            printf("Exiting program...\n");
        } else {
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    freeTracker(tracker);
    return 0;
}
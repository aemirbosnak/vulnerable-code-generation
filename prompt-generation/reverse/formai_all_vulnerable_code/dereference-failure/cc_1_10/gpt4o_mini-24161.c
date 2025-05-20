//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DAYS 30
#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    float calories; // in kilocalories
} Activity;

typedef struct {
    Activity activities[MAX_DAYS];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addActivity(FitnessTracker *tracker, int steps, float distance, float calories) {
    if (tracker->count >= MAX_DAYS) {
        printf("Error: Maximum day limit reached.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(tracker->activities[tracker->count].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    tracker->activities[tracker->count].steps = steps;
    tracker->activities[tracker->count].distance = distance;
    tracker->activities[tracker->count].calories = calories;

    tracker->count++;
}

void displayReport(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No activities recorded.\n");
        return;
    }

    printf("Fitness Tracker Report:\n");
    printf("%-12s %-10s %-10s %-10s\n", "Date", "Steps", "Distance", "Calories");
    printf("----------------------------------------\n");

    for (int i = 0; i < tracker->count; i++) {
        printf("%-12s %-10d %-10.2f %-10.2f\n",
               tracker->activities[i].date,
               tracker->activities[i].steps,
               tracker->activities[i].distance,
               tracker->activities[i].calories);
    }
}

void calculateTotals(FitnessTracker *tracker, int *totalSteps, float *totalDistance, float *totalCalories) {
    *totalSteps = 0;
    *totalDistance = 0.0;
    *totalCalories = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        *totalSteps += tracker->activities[i].steps;
        *totalDistance += tracker->activities[i].distance;
        *totalCalories += tracker->activities[i].calories;
    }
}

void displaySummary(FitnessTracker *tracker) {
    int totalSteps;
    float totalDistance, totalCalories;

    calculateTotals(tracker, &totalSteps, &totalDistance, &totalCalories);

    printf("Summary:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f kcal\n", totalCalories);
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);

    int choice, steps;
    float distance, calories;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Activity\n");
        printf("2. Display Report\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter steps: ");
                scanf("%d", &steps);
                printf("Enter distance (in km): ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%f", &calories);
                addActivity(&tracker, steps, distance, calories);
                break;
                
            case 2:
                displayReport(&tracker);
                break;

            case 3:
                displaySummary(&tracker);
                break;

            case 4:
                exit(0);
            
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
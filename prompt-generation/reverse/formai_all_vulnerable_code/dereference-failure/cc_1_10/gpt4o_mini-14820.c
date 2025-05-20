//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* O dear heart, as I embark upon this quest, 
To fashion a tracker, the finest in zest, 
For fitness, for love, and the bonds we hold true, 
With heartbeats as rhythm, and calories anew. */

// Structure for a user of the fitness tracker
typedef struct {
    char name[30];
    int age;
    float weight; // in kg
    float height; // in meters
} User;

// Structure for tracking daily activities
typedef struct {
    char activity[30];
    float duration; // in minutes
    float caloriesBurned;
} ActivityLog;

// Structure for the fitness tracker itself
typedef struct {
    User user;
    ActivityLog* logs; // Dynamic array for activities
    int totalActivities;
    float targetCalories; // Daily target for calories to burn
} FitnessTracker;

// Function declarations
void initTracker(FitnessTracker* tracker);
void recordActivity(FitnessTracker* tracker);
void displayReport(FitnessTracker* tracker);
void cleanupTracker(FitnessTracker* tracker);

void initTracker(FitnessTracker* tracker) {
    printf("O fair user, present thy name: ");
    fgets(tracker->user.name, 30, stdin);
    strtok(tracker->user.name, "\n"); // Remove the newline character
    printf("O gentle soul, pardon thy age: ");
    scanf("%d", &tracker->user.age);
    printf("To thine own self be true, state thy weight (kg): ");
    scanf("%f", &tracker->user.weight);
    printf("And last, measure thy height (m): ");
    scanf("%f", &tracker->user.height);
    
    tracker->logs = malloc(sizeof(ActivityLog) * 100); // Assume max 100 activities
    tracker->totalActivities = 0;
    tracker->targetCalories = 500; // Set a default calorie goal
    printf("With thy details, thy journey begins!\n");
}

void recordActivity(FitnessTracker* tracker) {
    if (tracker->totalActivities < 100) {
        ActivityLog* log = &tracker->logs[tracker->totalActivities];
        printf("Enter the name of thy activity, noble one: ");
        getchar(); // Consume newline left by previous scanf
        fgets(log->activity, 30, stdin);
        strtok(log->activity, "\n"); // Remove the newline character
        printf("For how many minutes didst thou engage in this activity? ");
        scanf("%f", &log->duration);
        log->caloriesBurned = (log->duration * 5); // Simplified formula for calories
        printf("Thou hast burned %.2f calories!\n", log->caloriesBurned);
        tracker->totalActivities++;
    } else {
        printf("Alas! Thy record is full, no more activities can be logged.\n");
    }
}

void displayReport(FitnessTracker* tracker) {
    printf("Forsooth! O noble %s, behold thy fitness report:\n", tracker->user.name);
    printf("Age: %d\n", tracker->user.age);
    printf("Weight: %.2f kg\n", tracker->user.weight);
    printf("Height: %.2f m\n", tracker->user.height);
    printf("Target Calories to Burn: %.2f\n", tracker->targetCalories);
    
    float totalCalories = 0;
    for (int i = 0; i < tracker->totalActivities; i++) {
        totalCalories += tracker->logs[i].caloriesBurned;
        printf("Activity %d: %s, Duration: %.2f minutes, Calories Burned: %.2f\n", 
               i + 1, tracker->logs[i].activity, 
               tracker->logs[i].duration, 
               tracker->logs[i].caloriesBurned);
    }

    printf("Total Calories Burned: %.2f\n", totalCalories);
    if (totalCalories >= tracker->targetCalories) {
        printf("Thou hast met thy noble goal! Huzzah!\n");
    } else {
        printf("Thou art yet short of thy goal. Strive harder!\n");
    }
}

void cleanupTracker(FitnessTracker* tracker) {
    free(tracker->logs);
}

int main() {
    FitnessTracker myTracker;
    initTracker(&myTracker);
    
    int choice = 0;
    while (choice != 3) {
        printf("\nEnter thy choice:\n");
        printf("1. Record Activity\n");
        printf("2. Display Report\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            recordActivity(&myTracker);
            break;
        case 2:
            displayReport(&myTracker);
            break;
        case 3:
            printf("Farewell, dear user! Until we meet again!\n");
            break;
        default:
            printf("Alas! Thy choice was not valid!\n");
            break;
        }
    }
    
    cleanupTracker(&myTracker);
    return 0;
}
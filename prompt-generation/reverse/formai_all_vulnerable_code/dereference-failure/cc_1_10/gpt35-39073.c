//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of exercises to track
#define MAX_EXERCISES 10

// Declare the exercise struct
typedef struct Exercise {
    char name[30]; // Name of the exercise
    int sets; // Number of sets
    int reps; // Number of reps per set
    float weight; // Weight lifted per set
} Exercise;

// Declare the fitness tracker struct
typedef struct FitnessTracker {
    char username[30]; // The username of the person using the fitness tracker
    Exercise exercises[MAX_EXERCISES]; // An array of exercises to track
    int num_exercises; // The number of exercises being tracked
} FitnessTracker;

// Function to add a new exercise to the fitness tracker
void addExercise(FitnessTracker *tracker) {
    if(tracker->num_exercises == MAX_EXERCISES) {
        printf("Maximum number of exercises reached!\n");
        return;
    }
    
    Exercise newExercise;
    printf("\nEnter exercise name: ");
    scanf("%s", newExercise.name);
    printf("Enter number of sets: ");
    scanf("%d", &newExercise.sets);
    printf("Enter number of reps per set: ");
    scanf("%d", &newExercise.reps);
    printf("Enter weight lifted per set: ");
    scanf("%f", &newExercise.weight);
    
    tracker->exercises[tracker->num_exercises++] = newExercise;
    printf("\nExercise added successfully!\n");
}

// Function to view all exercises currently being tracked
void viewExercises(FitnessTracker tracker) {
    if(tracker.num_exercises == 0) {
        printf("\nNo exercises currently being tracked.\n");
        return;
    }
    
    printf("\nExercises being tracked:\n");
    for(int i=0; i<tracker.num_exercises; i++) {
        printf("%d. %s - %d sets x %d reps @ %.2f lbs\n", i+1, tracker.exercises[i].name, tracker.exercises[i].sets, tracker.exercises[i].reps, tracker.exercises[i].weight);
    }
}

// Function to calculate the total weight lifted for a given exercise
float calculateTotalWeightLifted(FitnessTracker tracker, char *exerciseName) {
    float totalWeight = 0;
    
    for(int i=0; i<tracker.num_exercises; i++) {
        if(strcmp(tracker.exercises[i].name, exerciseName) == 0) {
            totalWeight += tracker.exercises[i].sets * tracker.exercises[i].reps * tracker.exercises[i].weight;
        }
    }
    
    return totalWeight;
}

// Function to view the total weight lifted for a given exercise
void viewTotalWeightLifted(FitnessTracker tracker) {
    char exerciseName[30];
    printf("\nEnter the name of the exercise to view total weight lifted: ");
    scanf("%s", exerciseName);
    
    float totalWeight = calculateTotalWeightLifted(tracker, exerciseName);
    printf("\nTotal weight lifted for %s: %.2f lbs\n", exerciseName, totalWeight);
}

int main() {
    // Create a new FitnessTracker struct and input the username
    FitnessTracker tracker;
    printf("Welcome to the fitness tracker app!\n\n");
    printf("Please enter your username: ");
    scanf("%s", tracker.username);
    
    // Display the menu and loop until the user chooses to exit
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add exercise\n");
        printf("2. View exercises\n");
        printf("3. View total weight lifted for an exercise\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                viewExercises(tracker);
                break;
            case 3:
                viewTotalWeightLifted(tracker);
                break;
            case 4:
                printf("\nExiting program. Goodbye, %s!\n", tracker.username);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}
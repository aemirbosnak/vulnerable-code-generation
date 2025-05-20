//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void displayMenu();
void addExercise();
void viewLog();
void viewStats();

// Global variables
int numExercises = 0;
char** exerciseNames;
int* exerciseCalories;
int* exerciseDays;
int* exerciseHours;

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Allocate memory for the arrays
    exerciseNames = (char**) malloc(sizeof(char*) * 100);
    for (int i = 0; i < 100; i++) {
        exerciseNames[i] = (char*) malloc(sizeof(char) * 50);
    }
    exerciseCalories = (int*) malloc(sizeof(int) * 100);
    exerciseDays = (int*) malloc(sizeof(int) * 100);
    exerciseHours = (int*) malloc(sizeof(int) * 100);
    
    // Display the menu and get the user's choice
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        // Handle the user's choice
        switch (choice) {
            case 1:
                addExercise();
                break;
            case 2:
                viewLog();
                break;
            case 3:
                viewStats();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    // Free the memory used by the arrays
    for (int i = 0; i < 100; i++) {
        free(exerciseNames[i]);
    }
    free(exerciseNames);
    free(exerciseCalories);
    free(exerciseDays);
    free(exerciseHours);
    
    return 0;
}

// Display the main menu
void displayMenu() {
    printf("=================\n");
    printf("Fitness Tracker\n");
    printf("=================\n");
    printf("1. Add Exercise\n");
    printf("2. View Log\n");
    printf("3. View Statistics\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Add a new exercise to the log
void addExercise() {
    // Get the exercise name and calories burned
    printf("Exercise name: ");
    scanf("%s", exerciseNames[numExercises]);
    printf("Calories burned: ");
    scanf("%d", &exerciseCalories[numExercises]);
    
    // Get the day and hour of the exercise (randomly generated)
    exerciseDays[numExercises] = rand() % 7;
    exerciseHours[numExercises] = rand() % 24;
    
    printf("Exercise added.\n");
    
    numExercises++;
}

// View the exercise log
void viewLog() {
    printf("=================\n");
    printf("Exercise Log\n");
    printf("=================\n");
    
    if (numExercises == 0) {
        printf("No exercises logged.\n");
        return;
    }
    
    // Print the header row
    printf("%-20s%s\n", "Exercise", "Calories");
    
    // Print each exercise
    for (int i = 0; i < numExercises; i++) {
        printf("%-20s%d\n", exerciseNames[i], exerciseCalories[i]);
    }
}

// View statistics about the exercises
void viewStats() {
    printf("=================\n");
    printf("Exercise Statistics\n");
    printf("=================\n");
    
    if (numExercises == 0) {
        printf("No exercises logged.\n");
        return;
    }
    
    // Calculate the total number of calories burned
    int totalCalories = 0;
    for (int i = 0; i < numExercises; i++) {
        totalCalories += exerciseCalories[i];
    }
    
    // Calculate the average calories burned per exercise
    float avgCalories = (float) totalCalories / numExercises;
    
    // Calculate the most popular day for exercising
    int dayCounts[7] = {0};
    int maxDay = 0;
    int maxCount = 0;
    for (int i = 0; i < numExercises; i++) {
        dayCounts[exerciseDays[i]]++;
        if (dayCounts[exerciseDays[i]] > maxCount) {
            maxCount = dayCounts[exerciseDays[i]];
            maxDay = exerciseDays[i];
        }
    }
    
    // Calculate the most popular hour for exercising
    int hourCounts[24] = {0};
    int maxHour = 0;
    maxCount = 0;
    for (int i = 0; i < numExercises; i++) {
        hourCounts[exerciseHours[i]]++;
        if (hourCounts[exerciseHours[i]] > maxCount) {
            maxCount = hourCounts[exerciseHours[i]];
            maxHour = exerciseHours[i];
        }
    }
    
    // Print the statistics
    printf("Total calories burned: %d\n", totalCalories);
    printf("Average calories burned per exercise: %.2f\n", avgCalories);
    printf("Most popular day for exercising: ");
    switch (maxDay) {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }
    printf("Most popular hour for exercising: %d:00\n", maxHour);
}
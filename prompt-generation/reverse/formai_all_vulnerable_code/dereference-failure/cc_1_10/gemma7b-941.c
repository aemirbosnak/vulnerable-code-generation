//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTracker {
    int stepsTaken;
    float distanceTraveled;
    int caloriesBurned;
    char mood;
} FitnessTracker;

// Function to calculate the number of steps taken
int calculateSteps(int minutes) {
    return minutes * 100;
}

// Function to calculate the distance traveled
float calculateDistance(int steps) {
    return (steps / 1000.0) * 2;
}

// Function to calculate the number of calories burned
int calculateCalories(int steps, float distance) {
    return (steps * 10) + (distance * 20);
}

// Main function
int main() {
    // Create a fitness tracker object
    FitnessTracker fitnessTracker;

    // Get the user's input
    printf("Enter the number of minutes you spent exercising: ");
    int minutes = atoi(fgets(NULL, 10, stdin));

    // Calculate the number of steps taken
    fitnessTracker.stepsTaken = calculateSteps(minutes);

    // Calculate the distance traveled
    fitnessTracker.distanceTraveled = calculateDistance(fitnessTracker.stepsTaken);

    // Calculate the number of calories burned
    fitnessTracker.caloriesBurned = calculateCalories(fitnessTracker.stepsTaken, fitnessTracker.distanceTraveled);

    // Display the fitness tracker data
    printf("Number of steps taken: %d\n", fitnessTracker.stepsTaken);
    printf("Distance traveled: %.2f miles\n", fitnessTracker.distanceTraveled);
    printf("Number of calories burned: %d\n", fitnessTracker.caloriesBurned);

    // Get the user's mood
    printf("How are you feeling? (Happy, Sad, Neutral) ");
    fitnessTracker.mood = fgets(NULL, 10, stdin)[0];

    // Display the user's mood
    printf("Your mood is: %c\n", fitnessTracker.mood);

    return 0;
}
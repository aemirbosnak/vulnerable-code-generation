//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of steps that can be tracked
#define MAX_STEPS 1000

// Define the maximum number of calories that can be burned
#define MAX_CALORIES 2000

// Define the maximum number of hours of sleep that can be tracked
#define MAX_HOURS 12

// Create a struct to store fitness data
typedef struct FitnessData {
    int stepsTaken;
    int caloriesBurned;
    int hoursSlept;
} FitnessData;

// Function to calculate the number of steps taken
int calculateStepsTaken(int distance) {
    return distance * 2;
}

// Function to calculate the number of calories burned
int calculateCaloriesBurned(int weight, int distance) {
    return (weight * distance) / 2;
}

// Function to calculate the number of hours slept
int calculateHoursSlept(int timeInBed) {
    return timeInBed / 8;
}

// Main function
int main() {
    // Create a variable to store the fitness data
    FitnessData fitnessData;

    // Get the user's input
    printf("Enter the distance traveled in miles: ");
    int distance = atoi(stdin);

    printf("Enter your weight in kilograms: ");
    int weight = atoi(stdin);

    printf("Enter the time you spent in bed in hours: ");
    int timeInBed = atoi(stdin);

    // Calculate the number of steps taken, calories burned, and hours slept
    fitnessData.stepsTaken = calculateStepsTaken(distance);
    fitnessData.caloriesBurned = calculateCaloriesBurned(weight, distance);
    fitnessData.hoursSlept = calculateHoursSlept(timeInBed);

    // Display the fitness data
    printf("Your total number of steps taken: %d\n", fitnessData.stepsTaken);
    printf("Your total number of calories burned: %d\n", fitnessData.caloriesBurned);
    printf("Your total number of hours slept: %d\n", fitnessData.hoursSlept);

    return 0;
}
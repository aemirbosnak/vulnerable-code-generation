//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store fitness data
typedef struct FitnessData {
    int stepsTaken;
    float distanceTraveled;
    double totalTime;
} FitnessData;

// Function to calculate the number of steps taken
int calculateStepsTaken(int minutes, int speed) {
    return (minutes * speed) * 20;
}

// Function to calculate the distance traveled
float calculateDistanceTraveled(int stepsTaken) {
    return (stepsTaken / 1000.0) * 3.8;
}

// Function to calculate the total time spent
double calculateTotalTime(int stepsTaken) {
    return (stepsTaken / 1000.0) * 0.02;
}

int main() {
    // Create a structure to store fitness data
    FitnessData fitnessData;

    // Get the user's input
    printf("Enter the number of minutes you spent exercising: ");
    int minutes = atoi(stdin);

    printf("Enter your average speed in miles per hour: ");
    int speed = atoi(stdin);

    // Calculate the number of steps taken
    fitnessData.stepsTaken = calculateStepsTaken(minutes, speed);

    // Calculate the distance traveled
    fitnessData.distanceTraveled = calculateDistanceTraveled(fitnessData.stepsTaken);

    // Calculate the total time spent
    fitnessData.totalTime = calculateTotalTime(fitnessData.stepsTaken);

    // Print the fitness data
    printf("Your total number of steps taken: %d\n", fitnessData.stepsTaken);
    printf("Your total distance traveled: %.2f miles\n", fitnessData.distanceTraveled);
    printf("Your total time spent exercising: %.2f hours\n", fitnessData.totalTime);

    return 0;
}
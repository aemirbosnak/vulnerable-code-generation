//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>   // Standard Input/Output Library
#include <stdbool.h> // Standard Boolean Library
#include <time.h>    // Time Library

// Define a struct for date and time
struct DateTime {
    int year, month, day, hour, minute, second;
};

// Define a struct for fitness data
struct FitnessData {
    char name[50];
    int age;
    float height, weight, bmi;
    int steps, calories, distance;
    struct DateTime dateTime;
};

// Function to get current date and time
void getCurrentDateTime(struct DateTime *dt) {
    time_t t = time(NULL);
    struct tm *timePtr = localtime(&t);

    dt->year = timePtr->tm_year + 1900;
    dt->month = timePtr->tm_mon + 1;
    dt->day = timePtr->tm_mday;
    dt->hour = timePtr->tm_hour;
    dt->minute = timePtr->tm_min;
    dt->second = timePtr->tm_sec;
}

int main() {
    struct FitnessData data;

    // Get user input for fitness data
    printf("Enter name: ");
    scanf("%[^\n]s", data.name);
    printf("Enter age: ");
    scanf("%d", &data.age);
    printf("Enter height (in meters): ");
    scanf("%f", &data.height);
    printf("Enter weight (in kg): ");
    scanf("%f", &data.weight);
    printf("Enter number of steps: ");
    scanf("%d", &data.steps);
    printf("Enter number of calories burned: ");
    scanf("%d", &data.calories);
    printf("Enter distance walked (in meters): ");
    scanf("%d", &data.distance);

    // Calculate BMI
    data.bmi = data.weight / (data.height * data.height);

    // Get current date and time
    getCurrentDateTime(&data.dateTime);

    // Display fitness data
    printf("\nFitness Data:\n");
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Height: %.2f m\n", data.height);
    printf("Weight: %.2f kg\n", data.weight);
    printf("BMI: %.2f\n", data.bmi);
    printf("Steps: %d\n", data.steps);
    printf("Calories Burned: %d\n", data.calories);
    printf("Distance Walked: %d m\n", data.distance);
    printf("Date: %d/%d/%d %02d:%02d:%02d\n", data.dateTime.day, data.dateTime.month, data.dateTime.year, data.dateTime.hour, data.dateTime.minute, data.dateTime.second);

    return 0;
}
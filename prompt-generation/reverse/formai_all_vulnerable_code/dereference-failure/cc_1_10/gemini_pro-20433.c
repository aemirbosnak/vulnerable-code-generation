//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: introspective
// Fitness Tracker: An Introspection into My Health

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data Structures
typedef struct {
    int id;
    char* name;
    int steps;
    int calories;
    int distance;
} FitnessData;

// Function Declarations
void initializeData(FitnessData**);
void trackSteps(FitnessData**, int);
void trackCalories(FitnessData**, int);
void trackDistance(FitnessData**, int);
void printData(FitnessData**);

// Main Function
int main() {
    // Introspection: Embracing the Journey of Health
    printf("\nEmbarking on a journey of introspection and empowerment, I initiate my fitness tracker.\n");

    // Initialize Data Structure
    FitnessData** data = malloc(sizeof(FitnessData*) * 3);
    initializeData(data);

    // Tracking My Steps: Quantifying Progress
    printf("\nReflecting upon my daily strides, I diligently track my steps.\n");
    trackSteps(data, 10000);

    // Counting Calories: Calibrating Energy Intake
    printf("\nMindful of my caloric intake, I meticulously record my consumption.\n");
    trackCalories(data, 2000);

    // Measuring Distance: Expanding Horizons
    printf("\nVisualizing my physical efforts, I measure the distance I traverse.\n");
    trackDistance(data, 5);

    // Introspection: Reflection and Gratitude
    printf("\nThrough this introspective process, I gain insights into my health.\n");
    printData(data);

    // Farewell: Embracing a Healthier Self
    printf("\nAs I conclude this introspective journey, I am filled with gratitude.\n");

    // Deallocate Memory
    free(data);

    return 0;
}

// Function Definitions
void initializeData(FitnessData** data) {
    // Initializing Data Points
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    for (int i = 0; i < 3; i++) {
        data[i] = malloc(sizeof(FitnessData));
        data[i]->id = i + 1;
        data[i]->name = malloc(20);
        sprintf(data[i]->name, "Data%d", i + 1);
        data[i]->steps = 0;
        data[i]->calories = 0;
        data[i]->distance = 0;
    }
}

void trackSteps(FitnessData** data, int steps) {
    // Incrementing Step Count
    for (int i = 0; i < 3; i++) {
        data[i]->steps += steps;
    }
}

void trackCalories(FitnessData** data, int calories) {
    // Accumulating Caloric Intake
    for (int i = 0; i < 3; i++) {
        data[i]->calories += calories;
    }
}

void trackDistance(FitnessData** data, int distance) {
    // Measuring Traveled Distance
    for (int i = 0; i < 3; i++) {
        data[i]->distance += distance;
    }
}

void printData(FitnessData** data) {
    // Displaying Fitness Data
    printf("\n**Fitness Data Summary**\n");
    for (int i = 0; i < 3; i++) {
        printf("Data ID: %d\n", data[i]->id);
        printf("Name: %s\n", data[i]->name);
        printf("Steps: %d\n", data[i]->steps);
        printf("Calories: %d\n", data[i]->calories);
        printf("Distance (km): %.2f\n", data[i]->distance / 1000.0);
        printf("\n");
    }
}
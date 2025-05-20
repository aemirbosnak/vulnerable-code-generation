//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct FitnessTracker {
    char *name;
    int age;
    int weight;
    int height;
    char *gender;
    int steps;
    int calories;
    int distance;
    time_t timestamp;
};

struct FitnessTracker *createFitnessTracker(char *name, int age, int weight, int height, char *gender, int steps, int calories, int distance, time_t timestamp) {
    struct FitnessTracker *fitnessTracker = malloc(sizeof(struct FitnessTracker));
    fitnessTracker->name = malloc(strlen(name) + 1);
    strcpy(fitnessTracker->name, name);
    fitnessTracker->age = age;
    fitnessTracker->weight = weight;
    fitnessTracker->height = height;
    fitnessTracker->gender = malloc(strlen(gender) + 1);
    strcpy(fitnessTracker->gender, gender);
    fitnessTracker->steps = steps;
    fitnessTracker->calories = calories;
    fitnessTracker->distance = distance;
    fitnessTracker->timestamp = timestamp;
    return fitnessTracker;
}

void printFitnessTracker(struct FitnessTracker *fitnessTracker) {
    printf("Name: %s\n", fitnessTracker->name);
    printf("Age: %d\n", fitnessTracker->age);
    printf("Weight: %d\n", fitnessTracker->weight);
    printf("Height: %d\n", fitnessTracker->height);
    printf("Gender: %s\n", fitnessTracker->gender);
    printf("Steps: %d\n", fitnessTracker->steps);
    printf("Calories: %d\n", fitnessTracker->calories);
    printf("Distance: %d\n", fitnessTracker->distance);
    printf("Timestamp: %s\n", ctime(&fitnessTracker->timestamp));
}

int main() {
    struct FitnessTracker *fitnessTracker = createFitnessTracker("John Doe", 30, 180, 72, "Male", 10000, 500, 5, time(NULL));
    printFitnessTracker(fitnessTracker);
    return 0;
}
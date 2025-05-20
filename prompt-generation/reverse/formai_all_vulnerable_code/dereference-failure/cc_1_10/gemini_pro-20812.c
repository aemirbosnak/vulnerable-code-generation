//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    int distance;
} FitnessTracker;

FitnessTracker *createFitnessTracker(char *name, int age, int weight, int height) {
    FitnessTracker *ft = malloc(sizeof(FitnessTracker));
    ft->name = strdup(name);
    ft->age = age;
    ft->weight = weight;
    ft->height = height;
    ft->steps = 0;
    ft->calories = 0;
    ft->distance = 0;
    return ft;
}

void destroyFitnessTracker(FitnessTracker *ft) {
    free(ft->name);
    free(ft);
}

void addSteps(FitnessTracker *ft, int steps) {
    ft->steps += steps;
    ft->calories += steps * 0.05;
    ft->distance += steps * 0.0005;
}

void printFitnessTracker(FitnessTracker *ft) {
    printf("Name: %s\n", ft->name);
    printf("Age: %d\n", ft->age);
    printf("Weight: %d lbs\n", ft->weight);
    printf("Height: %d inches\n", ft->height);
    printf("Steps: %d\n", ft->steps);
    printf("Calories: %d\n", ft->calories);
    printf("Distance: %.2f miles\n", ft->distance);
}

int main() {
    FitnessTracker *ft = createFitnessTracker("John Doe", 30, 180, 72);
    addSteps(ft, 10000);
    printFitnessTracker(ft);
    destroyFitnessTracker(ft);
    return 0;
}
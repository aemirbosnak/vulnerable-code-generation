//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the two lovers.
typedef struct {
    char *name;
    int age;
    double weight;
    double height;
} Lover;

// Define the fitness tracker.
typedef struct {
    int steps;
    int calories;
    int distance;
    double duration;
} FitnessTracker;

// Define the love story.
typedef struct {
    Lover romeo;
    Lover juliet;
    FitnessTracker fitnessTracker;
} LoveStory;

// Create a new lover.
Lover *createLover(char *name, int age, double weight, double height) {
    Lover *lover = malloc(sizeof(Lover));
    lover->name = malloc(strlen(name) + 1);
    strcpy(lover->name, name);
    lover->age = age;
    lover->weight = weight;
    lover->height = height;
    return lover;
}

// Create a new love story.
LoveStory *createLoveStory(Lover *romeo, Lover *juliet, FitnessTracker *fitnessTracker) {
    LoveStory *loveStory = malloc(sizeof(LoveStory));
    loveStory->romeo = *romeo;
    loveStory->juliet = *juliet;
    loveStory->fitnessTracker = *fitnessTracker;
    return loveStory;
}

// Print the love story.
void printLoveStory(LoveStory *loveStory) {
    printf("Romeo and Juliet, a love story for the ages.\n");
    printf("Romeo is %d years old, weighs %.1f kg, and is %.1f cm tall.\n", loveStory->romeo.age, loveStory->romeo.weight, loveStory->romeo.height);
    printf("Juliet is %d years old, weighs %.1f kg, and is %.1f cm tall.\n", loveStory->juliet.age, loveStory->juliet.weight, loveStory->juliet.height);
    printf("Together, they have walked %d steps, burned %d calories, and traveled %.1f km.\n", loveStory->fitnessTracker.steps, loveStory->fitnessTracker.calories, loveStory->fitnessTracker.distance);
    printf("Their love has lasted for %.1f hours.\n", loveStory->fitnessTracker.duration);
}

// Free the memory allocated for the love story.
void freeLoveStory(LoveStory *loveStory) {
    free(loveStory->romeo.name);
    free(loveStory->juliet.name);
    free(loveStory);
}

// Main function.
int main() {
    // Create the two lovers.
    Lover *romeo = createLover("Romeo", 16, 70.0, 175.0);
    Lover *juliet = createLover("Juliet", 14, 50.0, 160.0);

    // Create the fitness tracker.
    FitnessTracker *fitnessTracker = malloc(sizeof(FitnessTracker));
    fitnessTracker->steps = 10000;
    fitnessTracker->calories = 500;
    fitnessTracker->distance = 5.0;
    fitnessTracker->duration = 1.0;

    // Create the love story.
    LoveStory *loveStory = createLoveStory(romeo, juliet, fitnessTracker);

    // Print the love story.
    printLoveStory(loveStory);

    // Free the memory allocated for the love story.
    freeLoveStory(loveStory);

    return 0;
}
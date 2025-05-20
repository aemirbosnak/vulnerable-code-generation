//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our cyberpunk-style data structures
typedef struct {
    int steps;
    int calories;
    int distance;
    int floors;
} FitnessData;

typedef struct {
    char *name;
    FitnessData data;
} CyberpunkRunner;

// Generate a random CyberpunkRunner
CyberpunkRunner *generateCyberpunkRunner() {
    // Create a new CyberpunkRunner
    CyberpunkRunner *runner = malloc(sizeof(CyberpunkRunner));

    // Generate a random name
    char *names[] = {"Neo", "Trinity", "Morpheus", "Tank", "Cypher"};
    int nameIndex = rand() % 5;
    runner->name = strdup(names[nameIndex]);

    // Generate random fitness data
    runner->data.steps = rand() % 10000;
    runner->data.calories = rand() % 1000;
    runner->data.distance = rand() % 100;
    runner->data.floors = rand() % 10;

    return runner;
}

// Print the fitness data of a CyberpunkRunner
void printCyberpunkRunnerData(CyberpunkRunner *runner) {
    printf("Name: %s\n", runner->name);
    printf("Steps: %d\n", runner->data.steps);
    printf("Calories: %d\n", runner->data.calories);
    printf("Distance: %d\n", runner->data.distance);
    printf("Floors: %d\n", runner->data.floors);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random CyberpunkRunner
    CyberpunkRunner *runner = generateCyberpunkRunner();

    // Print the fitness data of the CyberpunkRunner
    printCyberpunkRunnerData(runner);

    // Free the memory allocated for the CyberpunkRunner
    free(runner->name);
    free(runner);

    return 0;
}
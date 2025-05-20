//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100

// Struct to hold conspiracy theory data
typedef struct {
    char* name;
    char* description;
} ConspiracyTheory;

// Function to generate a random conspiracy theory
ConspiracyTheory generateRandomConspiracyTheory() {
    ConspiracyTheory theory;
    theory.name = malloc(50 * sizeof(char));
    theory.description = malloc(200 * sizeof(char));

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random name for the conspiracy theory
    int nameLength = rand() % 50 + 1;
    for (int i = 0; i < nameLength; i++) {
        theory.name[i] = rand() % 26 + 'a';
    }
    theory.name[nameLength] = '\0';

    // Generate a random description for the conspiracy theory
    int descriptionLength = rand() % 200 + 1;
    for (int i = 0; i < descriptionLength; i++) {
        theory.description[i] = rand() % 26 + 'a';
    }
    theory.description[descriptionLength] = '\0';

    return theory;
}

// Function to print a conspiracy theory
void printConspiracyTheory(ConspiracyTheory theory) {
    printf("Name: %s\n", theory.name);
    printf("Description: %s\n", theory.description);
}

// Function to free memory allocated for a conspiracy theory
void freeConspiracyTheory(ConspiracyTheory theory) {
    free(theory.name);
    free(theory.description);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a list of conspiracy theories
    ConspiracyTheory* theories = malloc(MAX_CONSPIRACIES * sizeof(ConspiracyTheory));
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        theories[i] = generateRandomConspiracyTheory();
    }

    // Print the list of conspiracy theories
    printf("Conspiracy Theories:\n");
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        printConspiracyTheory(theories[i]);
    }

    // Free memory allocated for the conspiracy theories
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        freeConspiracyTheory(theories[i]);
    }
    free(theories);

    return 0;
}
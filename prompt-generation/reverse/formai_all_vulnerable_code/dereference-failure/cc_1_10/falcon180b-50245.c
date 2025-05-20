//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100

// Struct to hold a conspiracy theory
typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

// Array of conspiracy theories
ConspiracyTheory conspiracies[MAX_CONSPIRACIES];
int numConspiracies = 0;

// Function to generate a random name for a conspiracy theory
char *generateName() {
    char *result = malloc(10 * sizeof(char));
    for (int i = 0; i < 10; i++) {
        result[i] = 'A' + rand() % 26;
    }
    result[10] = '\0';
    return result;
}

// Function to generate a random description for a conspiracy theory
char *generateDescription() {
    char *result = malloc(100 * sizeof(char));
    for (int i = 0; i < 100; i++) {
        result[i] = 'A' + rand() % 26;
    }
    result[100] = '\0';
    return result;
}

// Function to add a new conspiracy theory to the array
void addConspiracy(char *name, char *description) {
    if (numConspiracies >= MAX_CONSPIRACIES) {
        printf("Too many conspiracies!\n");
        return;
    }
    conspiracies[numConspiracies].name = name;
    conspiracies[numConspiracies].description = description;
    numConspiracies++;
}

// Function to print a random conspiracy theory
void printConspiracy() {
    int index = rand() % numConspiracies;
    printf("Name: %s\n", conspiracies[index].name);
    printf("Description: %s\n", conspiracies[index].description);
}

int main() {
    srand(time(NULL));

    // Add some initial conspiracy theories
    addConspiracy("The Lizard People", "A secret race of reptilian humanoids controls world governments.");
    addConspiracy("Flat Earth Society", "The Earth is flat and all evidence to the contrary is a conspiracy.");
    addConspiracy("Moon Landing Hoax", "The Apollo moon landings were faked by NASA and filmed in a studio.");

    // Generate and print 10 more random conspiracy theories
    for (int i = 0; i < 10; i++) {
        char *name = generateName();
        char *description = generateDescription();
        addConspiracy(name, description);
        printConspiracy();
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 20
#define MAX_NAMES 50

typedef struct {
    char name[MAX_NAMES];
    char description[MAX_CONSPIRACY_LENGTH];
} Conspiracy;

void generate_conspiracy(Conspiracy *conspiracy) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random name for the conspiracy
    char name[MAX_NAMES];
    sprintf(name, "The %s Conspiracy", rand() % 2? "Red" : "Blue");
    strcpy(conspiracy->name, name);

    // Generate a random description for the conspiracy
    char description[MAX_CONSPIRACY_LENGTH];
    sprintf(description, "A secret group of %s operatives are working behind the scenes to %s.", rand() % 2? "left-wing" : "right-wing", rand() % 2? "control" : "destroy");
    strcpy(conspiracy->description, description);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number of conspiracies
    int num_conspiracies = rand() % 10 + 1;

    // Allocate memory for the conspiracies
    Conspiracy *conspiracies = malloc(num_conspiracies * sizeof(Conspiracy));

    // Generate the conspiracies
    for (int i = 0; i < num_conspiracies; i++) {
        generate_conspiracy(&conspiracies[i]);
    }

    // Print the conspiracies
    for (int i = 0; i < num_conspiracies; i++) {
        printf("Conspiracy #%d:\n", i + 1);
        printf("Name: %s\n", conspiracies[i].name);
        printf("Description: %s\n\n", conspiracies[i].description);
    }

    // Free the memory for the conspiracies
    free(conspiracies);

    return 0;
}
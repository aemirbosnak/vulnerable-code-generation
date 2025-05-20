//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define NUM_CONSPIRACIES 10

typedef struct {
    char* name;
    char* description;
} Conspiracy;

Conspiracy conspiracies[NUM_CONSPIRACIES] = {
    {"Illuminati", "A secret society that controls world events"},
    {"Area 51", "A top-secret government facility where aliens are studied"},
    {"Flat Earth", "The belief that the Earth is flat instead of round"},
    {"Lizard People", "The idea that shape-shifting reptilian creatures control world events"},
    {"Moon Landing Hoax", "The belief that the Apollo moon landings were faked"},
    {"Chemtrails", "The theory that the trails left by airplanes are actually chemicals being sprayed into the atmosphere"},
    {"9/11 Inside Job", "The belief that the US government was involved in the 9/11 terrorist attacks"},
    {"Bigfoot", "A large, hairy, human-like creature that is said to inhabit the forests of North America"},
    {"Marilyn Monroe Murder", "The theory that actress Marilyn Monroe was murdered instead of dying by suicide"},
    {"Paul is Dead", "The belief that Paul McCartney of the Beatles died and was replaced by a lookalike"}
};

int main() {
    srand(time(NULL));

    int numConspiracies = rand() % NUM_CONSPIRACIES + 1;
    Conspiracy* chosenConspiracies = malloc(numConspiracies * sizeof(Conspiracy));

    for (int i = 0; i < numConspiracies; i++) {
        int index = rand() % NUM_CONSPIRACIES;
        chosenConspiracies[i] = conspiracies[index];
    }

    char* conspiracyString = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    int stringLength = 0;

    for (int i = 0; i < numConspiracies; i++) {
        strcat(conspiracyString, chosenConspiracies[i].name);
        strcat(conspiracyString, " ");
        stringLength += strlen(chosenConspiracies[i].name) + 1;

        if (stringLength >= MAX_CONSPIRACY_LENGTH) {
            break;
        }
    }

    printf("The government doesn't want you to know about the %s!\n", conspiracyString);

    free(chosenConspiracies);
    free(conspiracyString);

    return 0;
}
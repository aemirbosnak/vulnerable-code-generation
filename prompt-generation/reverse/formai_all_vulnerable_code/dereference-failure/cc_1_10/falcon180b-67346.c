//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIVILIZATIONS 1000
#define MAX_TIME 1000
#define CHANCE_OF_INVASION 0.1
#define CHANCE_OF_DESTRUCTION 0.01

struct Civilization {
    int id;
    int destroyed;
};

void createCivilizations(struct Civilization civilizations[], int numCivilizations) {
    for(int i = 0; i < numCivilizations; i++) {
        civilizations[i].id = i;
        civilizations[i].destroyed = 0;
    }
}

void simulateInvasion(struct Civilization civilizations[], int numCivilizations, int numInvasions) {
    srand(time(NULL));
    for(int i = 0; i < numInvasions; i++) {
        int civilizationId = rand() % numCivilizations;
        civilizations[civilizationId].destroyed = 1;
    }
}

int main() {
    int numCivilizations;
    printf("Enter the number of civilizations: ");
    scanf("%d", &numCivilizations);

    struct Civilization civilizations[MAX_CIVILIZATIONS];
    createCivilizations(civilizations, numCivilizations);

    int numInvasions;
    printf("Enter the number of invasions to simulate: ");
    scanf("%d", &numInvasions);

    simulateInvasion(civilizations, numCivilizations, numInvasions);

    int numDestroyedCivilizations = 0;
    for(int i = 0; i < numCivilizations; i++) {
        if(civilizations[i].destroyed) {
            numDestroyedCivilizations++;
        }
    }

    double chanceOfInvasion = CHANCE_OF_INVASION;
    double chanceOfDestruction = CHANCE_OF_DESTRUCTION;

    printf("Number of destroyed civilizations: %d\n", numDestroyedCivilizations);
    printf("Chance of invasion: %.2f%%\n", chanceOfInvasion * 100);
    printf("Chance of destruction: %.2f%%\n", chanceOfDestruction * 100);

    return 0;
}
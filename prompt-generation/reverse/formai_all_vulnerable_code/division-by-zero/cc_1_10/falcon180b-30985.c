//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACTORS 10
#define MAX_DISTANCES 10
#define MAX_PLANETS 100
#define MAX_INVASIONS 1000

struct Planet {
    char name[50];
    double distance;
    int invaded;
};

struct Invasion {
    int year;
    int planetIndex;
};

void generatePlanets(struct Planet planets[], int numPlanets) {
    srand(time(NULL));
    for (int i = 0; i < numPlanets; i++) {
        planets[i].invaded = 0;
        planets[i].distance = rand() % 1000;
        sprintf(planets[i].name, "Planet %d", i + 1);
    }
}

void generateInvasions(struct Invasion invasions[], int numInvasions, int numPlanets) {
    srand(time(NULL));
    for (int i = 0; i < numInvasions; i++) {
        int planetIndex = rand() % numPlanets;
        invasions[i].planetIndex = planetIndex;
        invasions[i].year = rand() % 1000 + 2000;
    }
}

int main() {
    int numPlanets, numInvasions;
    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);
    printf("Enter the number of invasions: ");
    scanf("%d", &numInvasions);

    struct Planet planets[MAX_PLANETS];
    generatePlanets(planets, numPlanets);

    struct Invasion invasions[MAX_INVASIONS];
    generateInvasions(invasions, numInvasions, numPlanets);

    double totalDistance = 0;
    int numInvadedPlanets = 0;

    for (int i = 0; i < numInvasions; i++) {
        int planetIndex = invasions[i].planetIndex;
        if (planets[planetIndex].invaded == 0) {
            totalDistance += planets[planetIndex].distance;
            planets[planetIndex].invaded = 1;
            numInvadedPlanets++;
        }
    }

    double averageDistance = totalDistance / numInvadedPlanets;
    double probability = 1 - (averageDistance / 1000);

    printf("The average distance between invaded planets is %.2f light years.\n", averageDistance);
    printf("The probability of an alien invasion is %.2f%%.\n", probability * 100);

    return 0;
}
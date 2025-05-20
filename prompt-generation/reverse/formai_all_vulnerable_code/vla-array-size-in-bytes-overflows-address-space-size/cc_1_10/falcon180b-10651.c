//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 10000
#define MAX_POPULATION 1000000
#define MAX_TECHNOLOGY 1000
#define MAX_TIME 10000
#define INVADERS_PER_YEAR 10
#define YEARS_TO_INVADE 100

typedef struct {
    int distance;
    int population;
    int technology;
} Planet;

void generatePlanets(Planet planets[], int numPlanets) {
    srand(time(NULL));
    for (int i = 0; i < numPlanets; i++) {
        planets[i].distance = rand() % MAX_DISTANCE;
        planets[i].population = rand() % MAX_POPULATION;
        planets[i].technology = rand() % MAX_TECHNOLOGY;
    }
}

int main() {
    int numPlanets;
    printf("Enter the number of planets to simulate: ");
    scanf("%d", &numPlanets);

    Planet planets[numPlanets];
    generatePlanets(planets, numPlanets);

    int numInvaders = 0;
    int yearsPassed = 0;

    while (numInvaders < numPlanets && yearsPassed < YEARS_TO_INVADE) {
        for (int i = 0; i < numPlanets; i++) {
            if (planets[i].population > 0 && planets[i].technology >= 50) {
                numInvaders++;
                planets[i].population = 0;
            }
        }
        yearsPassed++;
        for (int i = 0; i < numPlanets; i++) {
            if (planets[i].population > 0) {
                planets[i].population += INVADERS_PER_YEAR;
            }
        }
    }

    double probability = ((double)numInvaders / numPlanets) * 100;
    printf("The probability of alien invasion is %.2f%%\n", probability);

    return 0;
}
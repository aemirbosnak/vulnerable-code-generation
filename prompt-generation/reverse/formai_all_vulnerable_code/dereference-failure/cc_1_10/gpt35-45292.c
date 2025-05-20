//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generatePlanets(int planets[][3], int numPlanets);
int randomNum(int lower, int upper);
void printPlanets(int planets[][3], int numPlanets);
void visitPlanet(int planets[][3], int planetIndex);

int main()
{
    const int NUM_PLANETS = 10;
    int planets[NUM_PLANETS][3]; // 2D array to store planet data

    // Generate random planets
    generatePlanets(planets, NUM_PLANETS);

    printf("Welcome to the space adventure game!\n");
    printf("You have arrived at a new galaxy with %d planets to explore.\n", NUM_PLANETS);
    printf("Choose a planet to visit (1-%d):\n", NUM_PLANETS);

    // Print planet options
    printPlanets(planets, NUM_PLANETS);

    // Get user input for selected planet
    int selectedPlanet;
    scanf("%d", &selectedPlanet);

    // Visit selected planet
    visitPlanet(planets, selectedPlanet - 1);

    printf("Thanks for playing!\n");

    return 0;
}

// Generates random planet data and stores it in the planets array
void generatePlanets(int planets[][3], int numPlanets)
{
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < numPlanets; i++)
    {
        planets[i][0] = i + 1; // Planet index
        planets[i][1] = randomNum(-100, 100); // X-coordinate
        planets[i][2] = randomNum(-100, 100); // Y-coordinate
    }
}

// Generates a random number between lower and upper (inclusive)
int randomNum(int lower, int upper)
{
    return rand() % (upper - lower + 1) + lower;
}

// Prints out the planet options for the user to choose from
void printPlanets(int planets[][3], int numPlanets)
{
    for (int i = 0; i < numPlanets; i++)
    {
        printf("%d: Planet %d (%d, %d)\n", i + 1, planets[i][0], planets[i][1], planets[i][2]);
    }
}

// Visits the selected planet and displays information about it
void visitPlanet(int planets[][3], int planetIndex)
{
    printf("Travelling to Planet %d...\n", planets[planetIndex][0]);
    printf("You have arrived!\n");
    printf("Planet coordinates: (%d, %d)\n", planets[planetIndex][1], planets[planetIndex][2]);

    // Generate random events
    int numEvents = randomNum(1, 3);
    for (int i = 0; i < numEvents; i++)
    {
        int event = randomNum(1, 3);
        if (event == 1)
        {
            printf("You have discovered a new species on this planet!\n");
        }
        else if (event == 2)
        {
            printf("You have found a treasure on this planet!\n");
        }
        else if (event == 3)
        {
            printf("You have encountered hostile aliens on this planet!\n");
        }
    }
}
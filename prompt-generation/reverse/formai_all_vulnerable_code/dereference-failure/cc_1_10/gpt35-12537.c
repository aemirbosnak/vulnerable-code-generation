//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    const int MAX_PLANETS = 10;
    const int MAX_DISTANCE = 1000;
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You have been assigned a mission to explore the galaxy and search for new planets.\n");
    printf("Your spaceships can travel up to %d lightyears per day.\n", MAX_DISTANCE);
    printf("Your mission is to find at least %d habitable planets in the galaxy.\n", MAX_PLANETS);
    printf("Good luck on your adventure!\n\n");

    // Generate the galaxy
    int num_planets = 0;
    int galaxy_size = 100;
    int **galaxy = (int **) malloc(galaxy_size * sizeof(int *));
    for(int i = 0; i < galaxy_size; i++)
    {
        galaxy[i] = (int *) calloc(galaxy_size, sizeof(int));
    }

    // Randomly place planets in the galaxy
    while(num_planets < MAX_PLANETS)
    {
        int x = rand() % galaxy_size;
        int y = rand() % galaxy_size;
        if(galaxy[x][y] == 0)
        {
            galaxy[x][y] = 1;
            num_planets++;
        }
    }

    // Game loop
    int x = galaxy_size / 2;
    int y = galaxy_size / 2;
    int days = 0;
    int planets_discovered = 0;

    while(planets_discovered < MAX_PLANETS)
    {
        // Display current position and status
        printf("Day %d: You are at (%d, %d).\n", days, x, y);
        if(galaxy[x][y] == 1)
        {
            printf("You have discovered a new planet!\n");
            planets_discovered++;
        }
        else
        {
            printf("No new planets found yet.\n");
        }

        // Move to a new location
        int dx = rand() % MAX_DISTANCE - (MAX_DISTANCE / 2);
        int dy = rand() % MAX_DISTANCE - (MAX_DISTANCE / 2);

        x += dx;
        y += dy;
        days++;
    }

    printf("\nCongratulations! You have discovered all %d habitable planets in the galaxy.\n", MAX_PLANETS);

    // Free memory
    for(int i = 0; i < galaxy_size; i++)
    {
        free(galaxy[i]);
    }
    free(galaxy);

    return 0;
}
//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototype
void generateGalaxy(char galaxy[][10][10], int numPlanets, int planetSize);
void displayGalaxy(char galaxy[][10][10], int numPlanets);
void visitPlanet(char galaxy[][10][10], int planetSize);

// main function
int main() {
    int numPlanets, planetSize;

    // seed the random number generator
    srand(time(NULL));

    // prompt user for galaxy size and planet size
    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);
    printf("Enter planet size (n x n): ");
    scanf("%d", &planetSize);

    // declare galaxy
    char galaxy[numPlanets][10][10];

    // generate the galaxy
    generateGalaxy(galaxy, numPlanets, planetSize);

    // display the galaxy
    displayGalaxy(galaxy, numPlanets);

    // visit a planet
    visitPlanet(galaxy, planetSize);

    return 0;
}

// function to generate galaxy
void generateGalaxy(char galaxy[][10][10], int numPlanets, int planetSize) {
    int i, j, k;
    for (i = 0; i < numPlanets; i++) {
        sprintf(galaxy[i][0], "Planet %d", i + 1); // planet name
        for (j = 1; j <= planetSize; j++) {
            for (k = 1; k <= planetSize; k++) {
                galaxy[i][j][k] = (rand() % 2 == 0) ? '*' : '.'; // randomly populate planet
            }
        }
    }
}

// function to display galaxy
void displayGalaxy(char galaxy[][10][10], int numPlanets) {
    int i, j, k;
    printf("\n==== GALAXY MAP ====\n");
    for (i = 0; i < numPlanets; i++) {
        printf("\n%s:\n", galaxy[i][0]);
        for (j = 1; j <= 10; j++) {
            for (k = 1; k <= 10; k++) {
                printf("%c ", galaxy[i][j][k]); // display planet
            }
            printf("\n");
        }
    }
}

// function to visit a planet
void visitPlanet(char galaxy[][10][10], int planetSize) {
    int planetNum, i, j, k;
    printf("\nEnter planet number to visit: ");
    scanf("%d", &planetNum);
    printf("\n==== VISITING PLANET %d ====\n", planetNum);
    printf("%s:\n", galaxy[planetNum - 1][0]);
    for (i = 1; i <= planetSize; i++) {
        for (j = 1; j <= planetSize; j++) {
            printf("%c ", galaxy[planetNum - 1][i][j]); // display visited planet
        }
        printf("\n");
    }
}
//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Romeo and Juliet characters
struct Romeo {
    char *name;
    int age;
    char *planet;
};

struct Juliet {
    char *name;
    int age;
    char *planet;
};

// Create a function to generate a random Romeo character
struct Romeo *createRomeo() {
    // Allocate memory for the Romeo character
    struct Romeo *romeo = malloc(sizeof(struct Romeo));

    // Generate a random name for Romeo
    char *romeoNames[] = {"Romeo", "Montague", "Capulet", "Tybalt", "Mercutio"};
    int randomRomeoNameIndex = rand() % 5;
    romeo->name = romeoNames[randomRomeoNameIndex];

    // Generate a random age for Romeo
    romeo->age = rand() % 20 + 16;

    // Generate a random planet for Romeo
    char *romeoPlanets[] = {"Earth", "Mars", "Venus", "Jupiter", "Saturn"};
    int randomRomeoPlanetIndex = rand() % 5;
    romeo->planet = romeoPlanets[randomRomeoPlanetIndex];

    // Return the Romeo character
    return romeo;
}

// Create a function to generate a random Juliet character
struct Juliet *createJuliet() {
    // Allocate memory for the Juliet character
    struct Juliet *juliet = malloc(sizeof(struct Juliet));

    // Generate a random name for Juliet
    char *julietNames[] = {"Juliet", "Capulet", "Montague", "Rosaline", "Lady Capulet"};
    int randomJulietNameIndex = rand() % 5;
    juliet->name = julietNames[randomJulietNameIndex];

    // Generate a random age for Juliet
    juliet->age = rand() % 20 + 16;

    // Generate a random planet for Juliet
    char *julietPlanets[] = {"Earth", "Mars", "Venus", "Jupiter", "Saturn"};
    int randomJulietPlanetIndex = rand() % 5;
    juliet->planet = julietPlanets[randomJulietPlanetIndex];

    // Return the Juliet character
    return juliet;
}

// Create a function to print the Romeo and Juliet characters
void printRomeoAndJuliet(struct Romeo *romeo, struct Juliet *juliet) {
    printf("Romeo:\n");
    printf("  Name: %s\n", romeo->name);
    printf("  Age: %d\n", romeo->age);
    printf("  Planet: %s\n", romeo->planet);

    printf("\nJuliet:\n");
    printf("  Name: %s\n", juliet->name);
    printf("  Age: %d\n", juliet->age);
    printf("  Planet: %s\n", juliet->planet);
}

// Create a function to free the memory allocated for the Romeo and Juliet characters
void freeRomeoAndJuliet(struct Romeo *romeo, struct Juliet *juliet) {
    free(romeo);
    free(juliet);
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Create Romeo and Juliet characters
    struct Romeo *romeo = createRomeo();
    struct Juliet *juliet = createJuliet();

    // Print the Romeo and Juliet characters
    printRomeoAndJuliet(romeo, juliet);

    // Free the memory allocated for the Romeo and Juliet characters
    freeRomeoAndJuliet(romeo, juliet);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STARSYSTEMS 1000
#define STARS 10000
#define PLANETS 100000

typedef struct StarSystem {
    char name[20];
    int x, y, z; // Coordinates in 3D space
    int numStars;
    int *stars;
} StarSystem;

typedef struct Star {
    char name[20];
    int x, y, z; // Coordinates in 3D space
    int size;
    int numPlanets;
    int *planets;
} Star;

typedef struct Planet {
    char name[20];
    int x, y, z; // Coordinates in 3D space
    int size;
    char type; // 'R' for rocky, 'G' for gas giant, 'I' for ice giant
    int numMoons;
    int *moons;
} Planet;

// Function to generate a random name for an object
char *generateName() {
    int length = rand() % 10 + 5; // Generate a random length for the name
    char *name = malloc(length + 1); // Allocate memory for the name
    for (int i = 0; i < length; i++) {
        name[i] = 'A' + rand() % 26; // Generate a random letter for the name
    }
    name[length] = '\0'; // Null-terminate the name
    return name;
}

// Function to generate a random star system
StarSystem *generateStarSystem() {
    StarSystem *starSystem = malloc(sizeof(StarSystem)); // Allocate memory for the star system
    strcpy(starSystem->name, generateName()); // Generate a random name for the star system
    starSystem->x = rand() % 1000000; // Generate a random x coordinate for the star system
    starSystem->y = rand() % 1000000; // Generate a random y coordinate for the star system
    starSystem->z = rand() % 1000000; // Generate a random z coordinate for the star system
    starSystem->numStars = rand() % 100 + 1; // Generate a random number of stars in the star system
    starSystem->stars = malloc(starSystem->numStars * sizeof(int)); // Allocate memory for the stars in the star system
    for (int i = 0; i < starSystem->numStars; i++) {
        starSystem->stars[i] = rand() % STARS; // Generate a random star ID for each star in the star system
    }
    return starSystem;
}

// Function to generate a random star
Star *generateStar() {
    Star *star = malloc(sizeof(Star)); // Allocate memory for the star
    strcpy(star->name, generateName()); // Generate a random name for the star
    star->x = rand() % 1000000; // Generate a random x coordinate for the star
    star->y = rand() % 1000000; // Generate a random y coordinate for the star
    star->z = rand() % 1000000; // Generate a random z coordinate for the star
    star->size = rand() % 100 + 1; // Generate a random size for the star
    star->numPlanets = rand() % 100 + 1; // Generate a random number of planets around the star
    star->planets = malloc(star->numPlanets * sizeof(int)); // Allocate memory for the planets around the star
    for (int i = 0; i < star->numPlanets; i++) {
        star->planets[i] = rand() % PLANETS; // Generate a random planet ID for each planet around the star
    }
    return star;
}

// Function to generate a random planet
Planet *generatePlanet() {
    Planet *planet = malloc(sizeof(Planet)); // Allocate memory for the planet
    strcpy(planet->name, generateName()); // Generate a random name for the planet
    planet->x = rand() % 1000000; // Generate a random x coordinate for the planet
    planet->y = rand() % 1000000; // Generate a random y coordinate for the planet
    planet->z = rand() % 1000000; // Generate a random z coordinate for the planet
    planet->size = rand() % 100 + 1; // Generate a random size for the planet
    planet->type = 'R' + rand() % 3; // Generate a random type for the planet
    planet->numMoons = rand() % 10 + 1; // Generate a random number of moons around the planet
    planet->moons = malloc(planet->numMoons * sizeof(int)); // Allocate memory for the moons around the planet
    for (int i = 0; i < planet->numMoons; i++) {
        planet->moons[i] = rand() % 100000; // Generate a random moon ID for each moon around the planet
    }
    return planet;
}

// Function to print a star system
void printStarSystem(StarSystem *starSystem) {
    printf("Star System: %s\n", starSystem->name);
    printf("Coordinates: (%d, %d, %d)\n", starSystem->x, starSystem->y, starSystem->z);
    printf("Number of Stars: %d\n", starSystem->numStars);
    for (int i = 0; i < starSystem->numStars; i++) {
        printf("Star %d: %d\n", i + 1, starSystem->stars[i]);
    }
    printf("\n");
}

// Function to print a star
void printStar(Star *star) {
    printf("Star: %s\n", star->name);
    printf("Coordinates: (%d, %d, %d)\n", star->x, star->y, star->z);
    printf("Size: %d\n", star->size);
    printf("Number of Planets: %d\n", star->numPlanets);
    for (int i = 0; i < star->numPlanets; i++) {
        printf("Planet %d: %d\n", i + 1, star->planets[i]);
    }
    printf("\n");
}

// Function to print a planet
void printPlanet(Planet *planet) {
    printf("Planet: %s\n", planet->name);
    printf("Coordinates: (%d, %d, %d)\n", planet->x, planet->y, planet->z);
    printf("Size: %d\n", planet->size);
    printf("Type: %c\n", planet->type);
    printf("Number of Moons: %d\n", planet->numMoons);
    for (int i = 0; i < planet->numMoons; i++) {
        printf("Moon %d: %d\n", i + 1, planet->moons[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Generate a random star system
    StarSystem *starSystem = generateStarSystem();

    // Print the star system
    printStarSystem(starSystem);

    // Generate a random star
    Star *star = generateStar();

    // Print the star
    printStar(star);

    // Generate a random planet
    Planet *planet = generatePlanet();

    // Print the planet
    printPlanet(planet);

    return 0;
}
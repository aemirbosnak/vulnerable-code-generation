//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the struct for a star system
typedef struct StarSystem {
  // Coordinates {x, y} of the star inside the Milky Way galaxy
  double coord[2];

  // Number of planets discovered in the system
  int nplanets;

  // Array of pointers to the planets in the system
  struct Planet **planets;
} StarSystem;

// Define the struct for a planet
typedef struct Planet {
  // Coordinates {x, y} of the planet inside its star system
  double coord[2];

  // Name of the planet
  char *name;
  
  // Age of the planet
  double age;

  // Radius of the planet
  double radius;

  // Mass of the planet
  double mass;
} Planet;

// Initialize the function to generate a random star system
StarSystem *generateStarSystem() {
  
  // Allocate memory for the star system using malloc
  StarSystem *ss = (StarSystem *)malloc(sizeof(StarSystem));

  // Generate random coordinates for the star system using fmod
  ss->coord[0] = 2 * M_PI * fmod(rand(), 1.0);
  ss->coord[1] = M_PI * fmod(rand(), 1.0);

  // Generate random number of planets discovered in the system using rand
  ss->nplanets = rand() % 10 + 1;

  // Allocate memory for the planets array
  ss->planets = (Planet **)malloc(ss->nplanets * sizeof(Planet *));

  // Generate planets and store them in the array
  for (int p = 0; p < ss->nplanets; p++) {

    // Allocate memory for the planet
    Planet *planet = (Planet *)malloc(sizeof(Planet));

    // Generate random coordinates for the planet
    planet->coord[0] = 2.0 * M_PI * fmod(rand(), 1.0);
    planet->coord[1] = M_PI * fmod(rand(), 1.0);

    // Generate a random name for the planet
    planet->name = (char *)malloc(4 * sizeof(char));
    sprintf(planet->name, "p%d", p + 1);

    // Generate a random age for the planet within the range of 100 million to 10 billion years
    planet->age = (rand() % 99000000000) + 100000000;

    // Generate a random size for the planet within the range of 1 to 10 Earth radii
    planet->radius = (rand() % 9) + 1;

    // Generate random mass for the planet within the range of 1 to 10 Earth masses
    planet->mass = (rand() % 9) + 1;

    // Store the planet in the array
    ss->planets[p] = planet;
  }
  
  // Return ss pointer
  return ss;
}

// Initialize the function to print the star system
void printStarSystem(StarSystem *ss) {
  
  printf("\n\nStar System:\n\n");

  // Print star system coordinates
  printf("System Coordinates: (%0.2f, %0.2f)\n\n", ss->coord[0], ss->coord[1]);

  // Loop over the planets array
  for (int p = 0; p < ss->nplanets; p++) {
    
    // Print the planet data
    Planet *planet = ss->planets[p];
    printf("\nPlanet %d:\n", p + 1);
    printf("Name: %s\n", planet->name);
    printf("Coordinates: (%0.2f, %0.2f)\n", planet->coord[0], planet->coord[1]);
    printf("Age: %.2lf billion years\n", planet->age / 1000000000.0);
    printf("Radius: %.2lf Earth radii\n", planet->radius);
    printf("Mass: %.2lf Earth masses\n", planet->mass);
  }
}

// Free the allocated memory
void freeStarSystem(StarSystem *ss) {

  // Free the planets array
  for (int p = 0; p < ss->nplanets; p++) {
    free(ss->planets[p]);
  }
  free(ss->planets);

  // Free the star system
  free(ss);
}

// Main function to generate and print a star system
int main() {
  
  // Generate the star system
  StarSystem *ss = generateStarSystem();

  // Print the star system
  printStarSystem(ss);

  // Free the memory 
  freeStarSystem(ss);
  
  return 0;
}
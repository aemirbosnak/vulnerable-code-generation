//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the star system
typedef struct star_system {
  char *name;
  int num_planets;
  struct planet *planets;
} star_system;

// Define the planet
typedef struct planet {
  char *name;
  int size;
  int population;
  int resources;
} planet;

// Create a new star system
star_system *create_star_system() {
  // Allocate memory for the star system
  star_system *system = malloc(sizeof(star_system));

  // Set the star system's name
  system->name = "Sol";

  // Set the number of planets in the star system
  system->num_planets = 3;

  // Allocate memory for the planets in the star system
  system->planets = malloc(sizeof(planet) * system->num_planets);

  // Create the planets in the star system
  system->planets[0].name = "Mercury";
  system->planets[0].size = 1;
  system->planets[0].population = 0;
  system->planets[0].resources = 0;

  system->planets[1].name = "Venus";
  system->planets[1].size = 2;
  system->planets[1].population = 0;
  system->planets[1].resources = 0;

  system->planets[2].name = "Earth";
  system->planets[2].size = 3;
  system->planets[2].population = 7000000000;
  system->planets[2].resources = 10000000000;

  // Return the star system
  return system;
}

// Destroy a star system
void destroy_star_system(star_system *system) {
  // Free the memory allocated for the planets in the star system
  free(system->planets);

  // Free the memory allocated for the star system
  free(system);
}

// Print the star system
void print_star_system(star_system *system) {
  // Print the star system's name
  printf("Star system: %s\n", system->name);

  // Print the number of planets in the star system
  printf("Number of planets: %d\n", system->num_planets);

  // Print the planets in the star system
  for (int i = 0; i < system->num_planets; i++) {
    printf("Planet %d:\n", i + 1);
    printf("  Name: %s\n", system->planets[i].name);
    printf("  Size: %d\n", system->planets[i].size);
    printf("  Population: %d\n", system->planets[i].population);
    printf("  Resources: %d\n", system->planets[i].resources);
  }
}

// Main function
int main() {
  // Create a star system
  star_system *system = create_star_system();

  // Print the star system
  print_star_system(system);

  // Destroy the star system
  destroy_star_system(system);

  return 0;
}
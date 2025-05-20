//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the galaxy size and the number of stars
#define GALAXY_SIZE 1000
#define NUM_STARS 100

// Define the star types
typedef enum {
  RED_DWARF,
  WHITE_DWARF,
  YELLOW_DWARF,
  BLUE_GIANT,
  RED_GIANT,
  SUPERGIANT
} star_type;

// Define the planet types
typedef enum {
  ROCKY,
  GAS_GIANT,
  ICE_GIANT
} planet_type;

// Define the structure of a star
typedef struct {
  char name[20];
  star_type type;
  int mass;
  int radius;
  int temperature;
} star;

// Define the structure of a planet
typedef struct {
  char name[20];
  planet_type type;
  int mass;
  int radius;
  int distance_from_star;
} planet;

// Define the structure of a galaxy
typedef struct {
  star stars[NUM_STARS];
  planet planets[NUM_STARS * 10];
} galaxy;

// Create a new galaxy
galaxy *create_galaxy() {
  galaxy *g = malloc(sizeof(galaxy));
  
  // Create the stars
  for (int i = 0; i < NUM_STARS; i++) {
    // Generate a random name for the star
    sprintf(g->stars[i].name, "Star %d", i);

    // Generate a random type for the star
    g->stars[i].type = rand() % 6;

    // Generate a random mass for the star
    g->stars[i].mass = rand() % 10000 + 1000;

    // Generate a random radius for the star
    g->stars[i].radius = rand() % 100 + 10;

    // Generate a random temperature for the star
    g->stars[i].temperature = rand() % 10000 + 1000;
  }

  // Create the planets
  for (int i = 0; i < NUM_STARS * 10; i++) {
    // Generate a random name for the planet
    sprintf(g->planets[i].name, "Planet %d", i);

    // Generate a random type for the planet
    g->planets[i].type = rand() % 3;

    // Generate a random mass for the planet
    g->planets[i].mass = rand() % 1000 + 100;

    // Generate a random radius for the planet
    g->planets[i].radius = rand() % 100 + 10;

    // Generate a random distance from the star for the planet
    g->planets[i].distance_from_star = rand() % 1000 + 100;
  }

  return g;
}

// Print the galaxy
void print_galaxy(galaxy *g) {
  for (int i = 0; i < NUM_STARS; i++) {
    printf("Star %d:\n", i);
    printf("  Name: %s\n", g->stars[i].name);
    printf("  Type: %d\n", g->stars[i].type);
    printf("  Mass: %d\n", g->stars[i].mass);
    printf("  Radius: %d\n", g->stars[i].radius);
    printf("  Temperature: %d\n", g->stars[i].temperature);
    
    for (int j = 0; j < 10; j++) {
      printf("  Planet %d:\n", j);
      printf("    Name: %s\n", g->planets[i * 10 + j].name);
      printf("    Type: %d\n", g->planets[i * 10 + j].type);
      printf("    Mass: %d\n", g->planets[i * 10 + j].mass);
      printf("    Radius: %d\n", g->planets[i * 10 + j].radius);
      printf("    Distance from star: %d\n", g->planets[i * 10 + j].distance_from_star);
    }
  }
}

// Free the memory allocated for the galaxy
void free_galaxy(galaxy *g) {
  free(g);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new galaxy
  galaxy *g = create_galaxy();

  // Print the galaxy
  print_galaxy(g);

  // Free the memory allocated for the galaxy
  free_galaxy(g);

  return 0;
}
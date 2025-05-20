//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system data
typedef struct {
  char name[32];
  int num_planets;
  int num_moons;
  int num_stars;
} StarSystem;

// Planet data
typedef struct {
  char name[32];
  int size; // in Earth masses
  int distance_from_star; // in AU
  int num_moons;
} Planet;

// Moon data
typedef struct {
  char name[32];
  int size; // in Earth masses
  int distance_from_planet; // in AU
} Moon;

// Star data
typedef struct {
  char name[32];
  int size; // in solar masses
  int temperature; // in Kelvin
} Star;

// Generate a random star system
StarSystem* generate_star_system() {
  StarSystem* star_system = malloc(sizeof(StarSystem));

  // Generate a random name
  for (int i = 0; i < 32; i++) {
    star_system->name[i] = 'a' + rand() % 26;
  }

  // Generate a random number of planets, moons, and stars
  star_system->num_planets = rand() % 10 + 1;
  star_system->num_moons = rand() % 10 + 1;
  star_system->num_stars = rand() % 10 + 1;

  return star_system;
}

// Generate a random planet
Planet* generate_planet(StarSystem* star_system) {
  Planet* planet = malloc(sizeof(Planet));

  // Generate a random name
  for (int i = 0; i < 32; i++) {
    planet->name[i] = 'a' + rand() % 26;
  }

  // Generate a random size, distance from star, and number of moons
  planet->size = rand() % 1000 + 1; // in Earth masses
  planet->distance_from_star = rand() % 100 + 1; // in AU
  planet->num_moons = rand() % 10 + 1;

  return planet;
}

// Generate a random moon
Moon* generate_moon(Planet* planet) {
  Moon* moon = malloc(sizeof(Moon));

  // Generate a random name
  for (int i = 0; i < 32; i++) {
    moon->name[i] = 'a' + rand() % 26;
  }

  // Generate a random size and distance from planet
  moon->size = rand() % 100 + 1; // in Earth masses
  moon->distance_from_planet = rand() % 10 + 1; // in AU

  return moon;
}

// Generate a random star
Star* generate_star(StarSystem* star_system) {
  Star* star = malloc(sizeof(Star));

  // Generate a random name
  for (int i = 0; i < 32; i++) {
    star->name[i] = 'a' + rand() % 26;
  }

  // Generate a random size and temperature
  star->size = rand() % 10000 + 1; // in solar masses
  star->temperature = rand() % 10000 + 1; // in Kelvin

  return star;
}

// Print a star system
void print_star_system(StarSystem* star_system) {
  printf("Star system: %s\n", star_system->name);
  printf("  Number of planets: %d\n", star_system->num_planets);
  printf("  Number of moons: %d\n", star_system->num_moons);
  printf("  Number of stars: %d\n", star_system->num_stars);

  // Print the planets
  for (int i = 0; i < star_system->num_planets; i++) {
    Planet* planet = generate_planet(star_system);
    printf("  Planet: %s\n", planet->name);
    printf("    Size: %d Earth masses\n", planet->size);
    printf("    Distance from star: %d AU\n", planet->distance_from_star);
    printf("    Number of moons: %d\n", planet->num_moons);

    // Print the moons
    for (int j = 0; j < planet->num_moons; j++) {
      Moon* moon = generate_moon(planet);
      printf("    Moon: %s\n", moon->name);
      printf("      Size: %d Earth masses\n", moon->size);
      printf("      Distance from planet: %d AU\n", moon->distance_from_planet);
    }

    free(planet);
  }

  // Print the stars
  for (int i = 0; i < star_system->num_stars; i++) {
    Star* star = generate_star(star_system);
    printf("  Star: %s\n", star->name);
    printf("    Size: %d solar masses\n", star->size);
    printf("    Temperature: %d Kelvin\n", star->temperature);

    free(star);
  }

  free(star_system);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random star system
  StarSystem* star_system = generate_star_system();

  // Print the star system
  print_star_system(star_system);

  return 0;
}
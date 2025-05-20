//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Linus Torvalds style constants and macros
#define MIN_STARS 1000000000
#define MAX_STARS 1000000000000000000
#define MIN_PLANETS 1
#define MAX_PLANETS 1000
#define MIN_INTELLIGENT_LIFE_CHANCE 0
#define MAX_INTELLIGENT_LIFE_CHANCE 1

// Function prototypes
double calculate_alien_invasion_probability(int stars, int planets, double intelligent_life_chance);
void print_alien_invasion_probability(double probability);

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided the correct number of arguments
  if (argc != 4) {
    printf("Usage: %s <stars> <planets> <intelligent_life_chance>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the arguments
  int stars = atoi(argv[1]);
  int planets = atoi(argv[2]);
  double intelligent_life_chance = atof(argv[3]);

  // Check if the arguments are valid
  if (stars < MIN_STARS || stars > MAX_STARS) {
    printf("Invalid number of stars: %d\n", stars);
    return EXIT_FAILURE;
  }

  if (planets < MIN_PLANETS || planets > MAX_PLANETS) {
    printf("Invalid number of planets: %d\n", planets);
    return EXIT_FAILURE;
  }

  if (intelligent_life_chance < MIN_INTELLIGENT_LIFE_CHANCE || intelligent_life_chance > MAX_INTELLIGENT_LIFE_CHANCE) {
    printf("Invalid intelligent life chance: %f\n", intelligent_life_chance);
    return EXIT_FAILURE;
  }

  // Calculate the alien invasion probability
  double probability = calculate_alien_invasion_probability(stars, planets, intelligent_life_chance);

  // Print the alien invasion probability
  print_alien_invasion_probability(probability);

  return EXIT_SUCCESS;
}

// Function to calculate the alien invasion probability
double calculate_alien_invasion_probability(int stars, int planets, double intelligent_life_chance) {
  // Calculate the number of planets with intelligent life
  double planets_with_intelligent_life = planets * intelligent_life_chance;

  // Calculate the probability of an alien invasion
  double probability = planets_with_intelligent_life / stars;

  return probability;
}

// Function to print the alien invasion probability
void print_alien_invasion_probability(double probability) {
  printf("The alien invasion probability is: %f\n", probability);
}
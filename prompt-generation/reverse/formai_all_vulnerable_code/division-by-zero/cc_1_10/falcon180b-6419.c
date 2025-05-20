//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int calculate_invasion_probability(int num_civilizations, int num_planets, int num_years);
int generate_random_civilization(int num_civilizations);
int generate_random_planet(int num_planets);

int main() {
  int num_civilizations, num_planets, num_years;
  int invasion_probability;

  // get user input for number of civilizations, planets, and years
  printf("Enter the number of civilizations: ");
  scanf("%d", &num_civilizations);
  printf("Enter the number of planets: ");
  scanf("%d", &num_planets);
  printf("Enter the number of years to simulate: ");
  scanf("%d", &num_years);

  // calculate invasion probability
  invasion_probability = calculate_invasion_probability(num_civilizations, num_planets, num_years);

  // print results
  printf("The probability of an alien invasion is %d%%\n", invasion_probability);

  return 0;
}

// function to calculate invasion probability
int calculate_invasion_probability(int num_civilizations, int num_planets, int num_years) {
  int i, j;
  int invasion_count = 0;

  // simulate num_years years of alien activity
  for (i = 0; i < num_years; i++) {
    // for each year, simulate num_civilizations civilizations attempting to invade
    for (j = 0; j < num_civilizations; j++) {
      // generate a random planet for this civilization to invade
      int planet_index = generate_random_planet(num_planets);

      // check if the planet is already inhabited by another civilization
      if (planet_inhabited(planet_index, num_civilizations)) {
        // if so, this civilization will not invade this planet
        continue;
      }

      // this civilization successfully invades the planet
      invasion_count++;
    }
  }

  // calculate invasion probability as a percentage
  int probability = (int) ((float) invasion_count / (num_civilizations * num_planets * num_years) * 100.0);

  return probability;
}

// function to generate a random planet index
int generate_random_planet(int num_planets) {
  return rand() % num_planets;
}

// function to check if a planet is already inhabited by another civilization
int planet_inhabited(int planet_index, int num_civilizations) {
  // TODO: implement this function
  return 0;
}
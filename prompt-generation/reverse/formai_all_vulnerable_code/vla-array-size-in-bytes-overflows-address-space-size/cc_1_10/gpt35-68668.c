//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float alienProb; // Probability of alien invasion
  int numCities, numDays; // Number of cities and days

  // Seed the random number generator
  srand(time(NULL));

  // Get input from user
  printf("Enter the number of cities: ");
  scanf("%d", &numCities);

  printf("Enter the number of days: ");
  scanf("%d", &numDays);

  // Generate a random probability for each city
  float cityProbs[numCities];
  for (int i = 0; i < numCities; i++) {
    cityProbs[i] = (float)rand() / RAND_MAX;
  }

  // Calculate the overall probability of an alien invasion
  alienProb = 1.0; // initialize to 1
  for (int i = 0; i < numCities; i++) {
    alienProb *= (1 - cityProbs[i]); // Probability of not being invaded
  }
  alienProb = 1 - alienProb; // Probability of being invaded

  // Calculate the probability of an alien invasion in each city
  float cityInvasionProbs[numCities][numDays];
  for (int i = 0; i < numCities; i++) {
    for (int j = 0; j < numDays; j++) {
      cityInvasionProbs[i][j] = 1 - pow(1 - cityProbs[i], j+1); // Probability of being invaded in the jth day
    }
  }

  // Print results
  printf("\nOverall probability of an alien invasion: %.2f%%\n", alienProb*100);

  printf("\nProbability of an alien invasion in each city:\n");
  for (int i = 0; i < numCities; i++) {
    printf("City %d: %.2f%%\n", i+1, cityProbs[i]*100);
  }

  printf("\nProbability of an alien invasion in each city over time:\n");
  for (int i = 0; i < numCities; i++) {
    printf("\nCity %d:\n", i+1);
    for (int j = 0; j < numDays; j++) {
      printf("Day %d: %.2f%%\n", j+1, cityInvasionProbs[i][j]*100);
    }
  }

  return 0;
}
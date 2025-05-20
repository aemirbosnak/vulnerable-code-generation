//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>

// Define a struct to represent a single baggage
typedef struct Baggage {
  int weight; // in kilograms
  int id; // unique identifier
} Baggage;

// Define a function that generates random bags with weights between 10 and 50 kg
Baggage generateBag(int id) {
  Baggage bag;
  bag.id = id;
  bag.weight = rand() % 41 + 10; // Random number between 10 and 50

  return bag;
}

// Define a function that simulates the arriving baggage at the airport
void simulateArrivingBaggage(Baggage* baggageList, int numBags) {
  printf("Simulating arriving baggage...\n");

  for (int i = 0; i < numBags; i++) {
    baggageList[i] = generateBag(i+1);
    printf("Generated baggage with ID %d and weight %dkg\n", baggageList[i].id, baggageList[i].weight);
  }
}

// Define a function that simulates the sorting of baggage based on their weight
void simulateSortingBaggage(Baggage* baggageList, int numBags) {
  printf("Simulating sorting baggage...\n");

  // Use bubble sort to sort the baggage by weight
  for (int i = 0; i < numBags-1; i++) {
    for (int j = 0; j < numBags-i-1; j++) {
      if (baggageList[j].weight > baggageList[j+1].weight) {
        Baggage temp = baggageList[j];
        baggageList[j] = baggageList[j+1];
        baggageList[j+1] = temp;
      }
    }
  }

  for (int i = 0; i < numBags; i++) {
    printf("Sorted baggage with ID %d and weight %dkg\n", baggageList[i].id, baggageList[i].weight);
  }
}

// Define a function that simulates the loading of baggage onto the plane
void simulateLoadingBaggage(Baggage* baggageList, int numBags) {
  printf("Simulating loading baggage...\n");

  int totalWeight = 0;
  for (int i = 0; i < numBags; i++) {
    totalWeight += baggageList[i].weight;
  }

  printf("Total weight of baggage loaded onto plane: %dkg\n", totalWeight);
}

int main() {
  srand(time(0)); // Seed the random number generator with the current time

  int numBags;
  printf("Enter the number of bags: ");
  scanf("%d", &numBags);

  Baggage* baggageList = (Baggage*) calloc(numBags, sizeof(Baggage)); // Allocate memory for baggage list

  simulateArrivingBaggage(baggageList, numBags);

  simulateSortingBaggage(baggageList, numBags);

  simulateLoadingBaggage(baggageList, numBags);

  free(baggageList); // Free memory used by baggage list

  return 0;
}
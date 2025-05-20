//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE_WEIGHT 50 // Maximum weight of a single piece of baggage
#define MAX_BAGGAGE_PER_PASS 5 // Maximum number of baggage pieces per passenger
#define MAX_PASSENGERS 100 // Maximum number of passengers in a single flight
#define MAX_CART_CAPACITY 100 // Maximum capacity of a single baggage cart

// Generates a random number between min and max
int random_number(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// Represents a single baggage piece with weight and owner information
typedef struct Baggage {
  int weight;
  int owner_id;
} Baggage;

// Represents a passenger with a unique ID and a number of baggage pieces
typedef struct Passenger {
  int id;
  int num_bags;
  Baggage* bags[MAX_BAGGAGE_PER_PASS];
} Passenger;

// Represents a baggage cart with a unique ID and a capacity
typedef struct Cart {
  int id;
  int capacity;
  int num_bags;
  Baggage* bags[MAX_CART_CAPACITY];
} Cart;

int main() {
  srand(time(0)); // Initialize random seed with current time
  int num_passengers = random_number(1, MAX_PASSENGERS); // Generate random number of passengers
  Passenger passengers[num_passengers]; // Create an array of passengers

  // Generate baggage for each passenger
  for (int i = 0; i < num_passengers; i++) {
    passengers[i].id = i + 1; // Set passenger ID
    passengers[i].num_bags = random_number(1, MAX_BAGGAGE_PER_PASS); // Generate random number of baggage pieces

    // Generate baggage pieces for this passenger
    for (int j = 0; j < passengers[i].num_bags; j++) {
      Baggage* bag = malloc(sizeof(Baggage)); // Allocate memory for new baggage piece
      bag->weight = random_number(1, MAX_BAGGAGE_WEIGHT); // Generate random weight
      bag->owner_id = passengers[i].id; // Set owner ID
      passengers[i].bags[j] = bag; // Add baggage to passenger's array of baggage pieces
    }
  }

  // Create an array of baggage carts
  int num_carts = (num_passengers / 10) + 1; // Generate number of carts based on number of passengers
  Cart carts[num_carts];

  // Initialize each cart with a unique ID and maximum capacity
  for (int i = 0; i < num_carts; i++) {
    carts[i].id = i + 1; // Set cart ID
    carts[i].capacity = MAX_CART_CAPACITY; // Set cart capacity
    carts[i].num_bags = 0; // Initialize number of baggage pieces in the cart to zero
  }

  // Load baggage into carts
  for (int i = 0; i < num_passengers; i++) {
    for (int j = 0; j < passengers[i].num_bags; j++) {
      int cart_index = random_number(0, num_carts - 1); // Select a random cart
      Baggage* bag = passengers[i].bags[j]; // Get baggage piece
      // Check if there is enough space in the cart for this baggage piece
      if (carts[cart_index].num_bags + 1 <= carts[cart_index].capacity && bag->weight <= MAX_BAGGAGE_WEIGHT) {
        carts[cart_index].bags[carts[cart_index].num_bags] = bag; // Add baggage to cart
        carts[cart_index].num_bags++; // Increment number of baggage pieces in cart
      }
    }
  }

  // Print summary of loaded baggage
  printf("Loaded baggage into %d carts:\n", num_carts);
  for (int i = 0; i < num_carts; i++) {
    printf("Cart %d - %d baggage pieces (", carts[i].id, carts[i].num_bags);
    for (int j = 0; j < carts[i].num_bags; j++) {
      printf("B%d:%d ", j + 1, carts[i].bags[j]->owner_id);
    }
    printf(")\n");
  }

  // Free allocated memory for all baggage pieces
  for (int i = 0; i < num_passengers; i++) {
    for (int j = 0; j < passengers[i].num_bags; j++) {
      free(passengers[i].bags[j]);
    }
  }

  return 0;
}
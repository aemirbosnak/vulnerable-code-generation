//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bags that can be on the conveyor belt at any one time
#define MAX_BAGS_ON_BELT 10

// Define the maximum weight of a bag
#define MAX_BAG_WEIGHT 50

// Define the maximum number of bags that can be loaded onto a plane at any one time
#define MAX_BAGS_ON_PLANE 100

// Define the different types of bags
typedef enum {
  REGULAR,
  OVERSIZED,
  HEAVY
} bag_type;

// Define the structure of a bag
typedef struct {
  bag_type type;
  int weight;
} bag;

// Define the structure of the conveyor belt
typedef struct {
  bag *bags[MAX_BAGS_ON_BELT];
  int num_bags;
} conveyor_belt;

// Define the structure of the plane
typedef struct {
  bag *bags[MAX_BAGS_ON_PLANE];
  int num_bags;
} plane;

// Create a new bag
bag *create_bag(bag_type type, int weight) {
  bag *new_bag = malloc(sizeof(bag));
  new_bag->type = type;
  new_bag->weight = weight;
  return new_bag;
}

// Add a bag to the conveyor belt
void add_bag_to_belt(conveyor_belt *belt, bag *bag) {
  if (belt->num_bags < MAX_BAGS_ON_BELT) {
    belt->bags[belt->num_bags] = bag;
    belt->num_bags++;
  } else {
    printf("The conveyor belt is full!\n");
  }
}

// Remove a bag from the conveyor belt
bag *remove_bag_from_belt(conveyor_belt *belt) {
  if (belt->num_bags > 0) {
    bag *bag = belt->bags[belt->num_bags - 1];
    belt->num_bags--;
    return bag;
  } else {
    return NULL;
  }
}

// Load a bag onto the plane
void load_bag_onto_plane(plane *plane, bag *bag) {
  if (plane->num_bags < MAX_BAGS_ON_PLANE) {
    plane->bags[plane->num_bags] = bag;
    plane->num_bags++;
  } else {
    printf("The plane is full!\n");
  }
}

// Unload a bag from the plane
bag *unload_bag_from_plane(plane *plane) {
  if (plane->num_bags > 0) {
    bag *bag = plane->bags[plane->num_bags - 1];
    plane->num_bags--;
    return bag;
  } else {
    return NULL;
  }
}

// Print the contents of the conveyor belt
void print_conveyor_belt(conveyor_belt *belt) {
  printf("Conveyor belt: ");
  for (int i = 0; i < belt->num_bags; i++) {
    bag *bag = belt->bags[i];
    printf("%d ", bag->weight);
  }
  printf("\n");
}

// Print the contents of the plane
void print_plane(plane *plane) {
  printf("Plane: ");
  for (int i = 0; i < plane->num_bags; i++) {
    bag *bag = plane->bags[i];
    printf("%d ", bag->weight);
  }
  printf("\n");
}

// Main function
int main() {
  // Create a new conveyor belt
  conveyor_belt belt;
  belt.num_bags = 0;

  // Create a new plane
  plane plane;
  plane.num_bags = 0;

  // Create a random number generator
  srand(time(NULL));

  // Generate 100 bags
  for (int i = 0; i < 100; i++) {
    // Generate a random bag type
    bag_type type = rand() % 3;

    // Generate a random bag weight
    int weight = rand() % 50 + 1;

    // Create a new bag
    bag *bag = create_bag(type, weight);

    // Add the bag to the conveyor belt
    add_bag_to_belt(&belt, bag);
  }

  // Print the contents of the conveyor belt
  print_conveyor_belt(&belt);

  // Load the bags onto the plane
  while (belt.num_bags > 0) {
    // Remove a bag from the conveyor belt
    bag *bag = remove_bag_from_belt(&belt);

    // Load the bag onto the plane
    load_bag_onto_plane(&plane, bag);
  }

  // Print the contents of the plane
  print_plane(&plane);

  // Unload the bags from the plane
  while (plane.num_bags > 0) {
    // Unload a bag from the plane
    bag *bag = unload_bag_from_plane(&plane);

    // Print the weight of the bag
    printf("Unloaded bag: %d\n", bag->weight);

    // Free the bag
    free(bag);
  }

  return 0;
}
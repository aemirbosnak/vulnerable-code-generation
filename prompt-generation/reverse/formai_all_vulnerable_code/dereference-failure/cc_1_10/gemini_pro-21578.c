//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
// A tale of love and chromatic choices

#include <stdio.h>
#include <stdlib.h>

// Our cast of characters, each with their own unique color preference
typedef struct {
  char *name;
  int color;
} Person;

// The colors available for our lovers to choose from
typedef enum {
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  INDIGO,
  VIOLET
} Color;

// Our star-crossed lovers, longing for a harmonious union
Person lovers[] = {
  {"Romeo", RED},
  {"Juliet", BLUE},
  // ... additional lovers with their preferred colors
};

// The number of lovers in our story
#define NUM_LOVERS (sizeof(lovers) / sizeof(Person))

// A function to check if two lovers can be seated together without clashing colors
int is_compatible(Person *lover1, Person *lover2) {
  return lover1->color != lover2->color;
}

// A function to find a valid seating arrangement for our lovers using backtracking
int find_seating_arrangement(int index, int *arrangement) {
  // Base case: we've found a valid seating arrangement for all lovers
  if (index == NUM_LOVERS) {
    return 1;
  }

  // Try all possible seating arrangements for the current lover
  for (int i = 0; i < NUM_LOVERS; i++) {
    // Check if the current arrangement is compatible with the previous lovers
    if (is_compatible(&lovers[index], &lovers[arrangement[i]])) {
      // If compatible, assign the current lover to the seat
      arrangement[index] = i;

      // Recursively find a valid seating arrangement for the remaining lovers
      if (find_seating_arrangement(index + 1, arrangement)) {
        return 1;
      }
    }
  }

  // No valid seating arrangement found for the current lover
  return 0;
}

int main() {
  // Create an array to store the seating arrangement
  int arrangement[NUM_LOVERS];

  // Find a valid seating arrangement using backtracking
  if (find_seating_arrangement(0, arrangement)) {
    // If a valid arrangement is found, print it out
    printf("Seating arrangement found:\n");
    for (int i = 0; i < NUM_LOVERS; i++) {
      printf("%s sits next to %s\n", lovers[i].name, lovers[arrangement[i]].name);
    }
  } else {
    printf("No valid seating arrangement found.\n");
  }

  return 0;
}
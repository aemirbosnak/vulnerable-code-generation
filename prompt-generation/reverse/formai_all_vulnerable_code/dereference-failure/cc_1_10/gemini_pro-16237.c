//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: lively
// Performance-Critical Component: The Battle of the Bytes

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the battleground, an arena of bytes
#define ARENA_SIZE 1024 * 1024 * 16

// Create the combatants: two armies of bytes
unsigned char *army_a, *army_b;

// Randomize the armies: let chaos reign!
void scramble_army(unsigned char *army, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) army[i] = rand() % 256;
}

// The main event: a clash of bytes
void clash_of_bytes() {
  // Loop through the arena, one byte at a time
  for (int i = 0; i < ARENA_SIZE; i++) {
    // If the bytes are different, it's a clash!
    if (army_a[i] != army_b[i]) {
      printf("Clash! Byte %d: %d vs %d\n", i, army_a[i], army_b[i]);
      return;
    }
  }

  // No clashes? It's a stalemate!
  printf("Stalemate: no clashes found.\n");
}

int main() {
  // Allocate the armies and scramble them
  army_a = malloc(ARENA_SIZE);
  army_b = malloc(ARENA_SIZE);
  scramble_army(army_a, ARENA_SIZE);
  scramble_army(army_b, ARENA_SIZE);

  // Prepare for the clash
  printf("Armies assembled! The battle is about to begin...\n");

  // Time the clash and print the results
  clock_t start = clock();
  clash_of_bytes();
  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Clash completed in %.3f seconds.\n", time_taken);

  // Free the armies, their battle done
  free(army_a);
  free(army_b);

  return 0;
}
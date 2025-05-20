//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3
#define NUM_DISKS 8

typedef struct {
  int num_disks;
  int disks[NUM_DISKS];
} tower_t;

// Create a new tower with the given number of disks.
tower_t *create_tower(int num_disks) {
  tower_t *tower = malloc(sizeof(tower_t));
  if (tower == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for tower.\n");
    exit(1);
  }

  tower->num_disks = num_disks;
  for (int i = 0; i < num_disks; i++) {
    tower->disks[i] = i + 1;
  }

  return tower;
}

// Free the given tower.
void free_tower(tower_t *tower) {
  free(tower);
}

// Print the given tower.
void print_tower(tower_t *tower) {
  for (int i = tower->num_disks - 1; i >= 0; i--) {
    printf("%d", tower->disks[i]);
  }
  printf("\n");
}

// Move the top disk from the given tower to the given destination tower.
void move_disk(tower_t *source_tower, tower_t *destination_tower) {
  if (source_tower->num_disks == 0) {
    fprintf(stderr, "Error: Cannot move disk from empty tower.\n");
    exit(1);
  }

  int disk = source_tower->disks[source_tower->num_disks - 1];
  source_tower->num_disks--;
  destination_tower->disks[destination_tower->num_disks++] = disk;
}

// Solve the Tower of Hanoi problem.
void solve_tower_of_hanoi(int num_disks, tower_t *towers) {
  // Move the disks from the first tower to the third tower.
  for (int i = 0; i < num_disks; i++) {
    move_disk(towers, towers + 2);
    
    // Print the intermediate state of the towers.
    for (int j = 0; j < NUM_TOWERS; j++) {
      print_tower(towers + j);
    }
    printf("\n");
  }
}

int main() {
  // Create the three towers.
  tower_t *towers[NUM_TOWERS];
  for (int i = 0; i < NUM_TOWERS; i++) {
    towers[i] = create_tower(0);
  }

  // Initialize the first tower with the disks.
  tower_t *source_tower = towers;
  for (int i = NUM_DISKS - 1; i >= 0; i--) {
    move_disk(source_tower, towers + 1);
  }

  // Solve the Tower of Hanoi problem.
  solve_tower_of_hanoi(NUM_DISKS, towers);

  // Free the towers.
  for (int i = 0; i < NUM_TOWERS; i++) {
    free_tower(towers[i]);
  }

  return 0;
}
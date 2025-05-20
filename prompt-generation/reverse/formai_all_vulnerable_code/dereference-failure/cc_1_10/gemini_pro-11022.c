//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the tower structure
typedef struct tower {
  int num_disks;
  int *disks;
} tower;

// Create a new tower
tower *create_tower(int num_disks) {
  tower *t = malloc(sizeof(tower));
  t->num_disks = num_disks;
  t->disks = malloc(sizeof(int) * num_disks);
  for (int i = 0; i < num_disks; i++) {
    t->disks[i] = i + 1;
  }
  return t;
}

// Print the tower
void print_tower(tower *t) {
  for (int i = 0; i < t->num_disks; i++) {
    printf("%d ", t->disks[i]);
  }
  printf("\n");
}

// Move a disk from one tower to another
void move_disk(tower *from, tower *to) {
  int disk = from->disks[from->num_disks - 1];
  from->num_disks--;
  to->disks[to->num_disks] = disk;
  to->num_disks++;
}

// Solve the Tower of Hanoi problem
void hanoi(tower *from, tower *to, tower *aux, int num_disks) {
  if (num_disks == 1) {
    move_disk(from, to);
  } else {
    hanoi(from, aux, to, num_disks - 1);
    move_disk(from, to);
    hanoi(aux, to, from, num_disks - 1);
  }
}

// Main function
int main() {
  // Create the towers
  tower *a = create_tower(3);
  tower *b = create_tower(0);
  tower *c = create_tower(0);

  // Print the initial state of the towers
  printf("Initial state:\n");
  print_tower(a);
  print_tower(b);
  print_tower(c);

  // Solve the Tower of Hanoi problem
  hanoi(a, c, b, 3);

  // Print the final state of the towers
  printf("\nFinal state:\n");
  print_tower(a);
  print_tower(b);
  print_tower(c);

  return 0;
}
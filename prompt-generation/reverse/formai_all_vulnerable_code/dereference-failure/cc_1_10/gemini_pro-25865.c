//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the towers
#define TOWER_A 1
#define TOWER_B 2
#define TOWER_C 3

// Define the error codes
#define ERROR_INVALID_TOWER -1
#define ERROR_INVALID_MOVE -2
#define ERROR_INVALID_ARGUMENT -3

// Define the maximum number of disks
#define MAX_DISKS 10

// Define the structure of a disk
typedef struct disk {
  int size;
  struct disk *next;
} disk;

// Define the structure of a tower
typedef struct tower {
  int id;
  disk *top;
} tower;

// Define the function to create a new disk
disk *create_disk(int size) {
  disk *new_disk = (disk *)malloc(sizeof(disk));
  if (new_disk == NULL) {
    return NULL;
  }
  new_disk->size = size;
  new_disk->next = NULL;
  return new_disk;
}

// Define the function to create a new tower
tower *create_tower(int id) {
  tower *new_tower = (tower *)malloc(sizeof(tower));
  if (new_tower == NULL) {
    return NULL;
  }
  new_tower->id = id;
  new_tower->top = NULL;
  return new_tower;
}

// Define the function to push a disk onto a tower
int push_disk(tower *tower, disk *disk) {
  if (tower == NULL || disk == NULL) {
    return ERROR_INVALID_ARGUMENT;
  }
  disk->next = tower->top;
  tower->top = disk;
  return 0;
}

// Define the function to pop a disk from a tower
disk *pop_disk(tower *tower) {
  if (tower == NULL) {
    return NULL;
  }
  disk *popped_disk = tower->top;
  if (popped_disk != NULL) {
    tower->top = popped_disk->next;
  }
  return popped_disk;
}

// Define the function to move a disk from one tower to another
int move_disk(tower *from_tower, tower *to_tower) {
  if (from_tower == NULL || to_tower == NULL) {
    return ERROR_INVALID_TOWER;
  }
  disk *from_disk = pop_disk(from_tower);
  if (from_disk == NULL) {
    return ERROR_INVALID_MOVE;
  }
  int to_disk_size = to_tower->top == NULL ? 0 : to_tower->top->size;
  if (from_disk->size > to_disk_size) {
    return ERROR_INVALID_MOVE;
  }
  push_disk(to_tower, from_disk);
  return 0;
}

// Define the function to solve the Tower of Hanoi problem
int solve_tower_of_hanoi(int num_disks, tower *from_tower, tower *to_tower, tower *aux_tower) {
  if (num_disks == 1) {
    return move_disk(from_tower, to_tower);
  }
  int result = 0;
  result = solve_tower_of_hanoi(num_disks - 1, from_tower, aux_tower, to_tower);
  if (result != 0) {
    return result;
  }
  result = move_disk(from_tower, to_tower);
  if (result != 0) {
    return result;
  }
  result = solve_tower_of_hanoi(num_disks - 1, aux_tower, to_tower, from_tower);
  return result;
}

// Define the function to print the towers
void print_towers(tower *tower_a, tower *tower_b, tower *tower_c) {
  printf("Tower A: ");
  disk *disk = tower_a->top;
  while (disk != NULL) {
    printf("%d ", disk->size);
    disk = disk->next;
  }
  printf("\n");
  printf("Tower B: ");
  disk = tower_b->top;
  while (disk != NULL) {
    printf("%d ", disk->size);
    disk = disk->next;
  }
  printf("\n");
  printf("Tower C: ");
  disk = tower_c->top;
  while (disk != NULL) {
    printf("%d ", disk->size);
    disk = disk->next;
  }
  printf("\n");
}

// Define the main function
int main() {
  // Create the towers
  tower *tower_a = create_tower(TOWER_A);
  tower *tower_b = create_tower(TOWER_B);
  tower *tower_c = create_tower(TOWER_C);

  // Create the disks
  disk *disk1 = create_disk(1);
  disk *disk2 = create_disk(2);
  disk *disk3 = create_disk(3);
  disk *disk4 = create_disk(4);
  disk *disk5 = create_disk(5);

  // Push the disks onto Tower A
  push_disk(tower_a, disk1);
  push_disk(tower_a, disk2);
  push_disk(tower_a, disk3);
  push_disk(tower_a, disk4);
  push_disk(tower_a, disk5);

  // Print the towers
  print_towers(tower_a, tower_b, tower_c);

  // Solve the Tower of Hanoi problem
  int result = solve_tower_of_hanoi(5, tower_a, tower_c, tower_b);
  if (result != 0) {
    printf("Error: %d\n", result);
    return result;
  }

  // Print the towers
  print_towers(tower_a, tower_b, tower_c);

  // Free the memory
  free(disk1);
  free(disk2);
  free(disk3);
  free(disk4);
  free(disk5);
  free(tower_a);
  free(tower_b);
  free(tower_c);

  return 0;
}
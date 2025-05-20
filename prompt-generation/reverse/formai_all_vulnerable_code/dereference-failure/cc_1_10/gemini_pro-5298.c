//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

// Define the maximum number of disks.
#define MAX_DISKS 10

// Define the three rods.
#define ROD_A 0
#define ROD_B 1
#define ROD_C 2

// Define the semaphore for each rod.
sem_t rod_semaphores[3];

// Define the mutex for the tower of hanoi.
pthread_mutex_t tower_of_hanoi_mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the condition variable for the tower of hanoi.
pthread_cond_t tower_of_hanoi_condition = PTHREAD_COND_INITIALIZER;

// Define the number of disks.
int num_disks;

// Define the number of moves.
int num_moves = 0;

// Define the rod that the disks are currently on.
int current_rod = ROD_A;

// Define the rod that the disks are going to.
int next_rod;

// Define the function to move a disk from one rod to another.
void move_disk(int from_rod, int to_rod) {
  // Lock the mutex for the tower of hanoi.
  pthread_mutex_lock(&tower_of_hanoi_mutex);

  // Wait for the semaphore for the from rod.
  sem_wait(&rod_semaphores[from_rod]);

  // Move the disk to the to rod.
  printf("Move disk %d from rod %d to rod %d\n", num_disks, from_rod, to_rod);
  current_rod = to_rod;

  // Signal the semaphore for the to rod.
  sem_post(&rod_semaphores[to_rod]);

  // Unlock the mutex for the tower of hanoi.
  pthread_mutex_unlock(&tower_of_hanoi_mutex);

  // Increment the number of moves.
  num_moves++;
}

// Define the function to solve the tower of hanoi problem.
void solve_tower_of_hanoi(int n, int from_rod, int to_rod, int via_rod) {
  // Base case: If there is only one disk, move it to the to rod.
  if (n == 1) {
    move_disk(from_rod, to_rod);
    return;
  }

  // Recursive case: Move the top n-1 disks to the via rod.
  solve_tower_of_hanoi(n - 1, from_rod, via_rod, to_rod);

  // Move the nth disk to the to rod.
  move_disk(from_rod, to_rod);

  // Move the n-1 disks from the via rod to the to rod.
  solve_tower_of_hanoi(n - 1, via_rod, to_rod, from_rod);
}

// Define the function to run the tower of hanoi problem.
void* run_tower_of_hanoi(void* args) {
  // Get the number of disks from the args.
  int* num_disks_ptr = (int*)args;
  num_disks = *num_disks_ptr;

  // Initialize the semaphores for each rod.
  for (int i = 0; i < 3; i++) {
    sem_init(&rod_semaphores[i], 0, 1);
  }

  // Solve the tower of hanoi problem.
  solve_tower_of_hanoi(num_disks, ROD_A, ROD_C, ROD_B);

  // Print the number of moves.
  printf("Number of moves: %d\n", num_moves);

  // Destroy the semaphores for each rod.
  for (int i = 0; i < 3; i++) {
    sem_destroy(&rod_semaphores[i]);
  }

  // Destroy the mutex for the tower of hanoi.
  pthread_mutex_destroy(&tower_of_hanoi_mutex);

  // Destroy the condition variable for the tower of hanoi.
  pthread_cond_destroy(&tower_of_hanoi_condition);

  return NULL;
}

// Define the main function.
int main(int argc, char** argv) {
  // Get the number of disks from the command line arguments.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number of disks>\n", argv[0]);
    return EXIT_FAILURE;
  }

  num_disks = atoi(argv[1]);

  // Check if the number of disks is valid.
  if (num_disks < 1 || num_disks > MAX_DISKS) {
    fprintf(stderr, "Error: The number of disks must be between 1 and %d\n", MAX_DISKS);
    return EXIT_FAILURE;
  }

  // Create a thread to run the tower of hanoi problem.
  pthread_t thread;
  if (pthread_create(&thread, NULL, run_tower_of_hanoi, &num_disks) != 0) {
    perror("pthread_create");
    return EXIT_FAILURE;
  }

  // Join the thread.
  if (pthread_join(thread, NULL) != 0) {
    perror("pthread_join");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
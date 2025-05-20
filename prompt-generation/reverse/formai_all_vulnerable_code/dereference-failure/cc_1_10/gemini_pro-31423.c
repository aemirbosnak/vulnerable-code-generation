//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Shared variables
int num_floors;
int num_elevators;
int num_passengers;
int current_floor;
int current_direction;
pthread_mutex_t elevator_lock;
pthread_cond_t elevator_cond;

// Thread functions
void *elevator_thread(void *arg);
void *passenger_thread(void *arg);

// Main function
int main(int argc, char **argv) {
  // Parse command line arguments
  if (argc < 4) {
    printf("Usage: %s <num_floors> <num_elevators> <num_passengers>\n", argv[0]);
    exit(1);
  }
  num_floors = atoi(argv[1]);
  num_elevators = atoi(argv[2]);
  num_passengers = atoi(argv[3]);

  // Initialize shared variables
  current_floor = 0;
  current_direction = 0;
  pthread_mutex_init(&elevator_lock, NULL);
  pthread_cond_init(&elevator_cond, NULL);

  // Create elevator threads
  pthread_t elevator_threads[num_elevators];
  for (int i = 0; i < num_elevators; i++) {
    pthread_create(&elevator_threads[i], NULL, elevator_thread, NULL);
  }

  // Create passenger threads
  pthread_t passenger_threads[num_passengers];
  for (int i = 0; i < num_passengers; i++) {
    pthread_create(&passenger_threads[i], NULL, passenger_thread, NULL);
  }

  // Join elevator threads
  for (int i = 0; i < num_elevators; i++) {
    pthread_join(elevator_threads[i], NULL);
  }

  // Join passenger threads
  for (int i = 0; i < num_passengers; i++) {
    pthread_join(passenger_threads[i], NULL);
  }

  // Destroy shared variables
  pthread_mutex_destroy(&elevator_lock);
  pthread_cond_destroy(&elevator_cond);

  return 0;
}

// Elevator thread function
void *elevator_thread(void *arg) {
  while (1) {
    // Acquire elevator lock
    pthread_mutex_lock(&elevator_lock);

    // Wait for passengers
    while (current_floor == 0 && current_direction == 0) {
      pthread_cond_wait(&elevator_cond, &elevator_lock);
    }

    // Move elevator to next floor
    if (current_direction == 1) {
      current_floor++;
    } else if (current_direction == -1) {
      current_floor--;
    }

    // Release elevator lock
    pthread_mutex_unlock(&elevator_lock);

    // Unload passengers
    printf("Elevator at floor %d\n", current_floor);
    // ...

    // Load passengers
    // ...
  }
  return NULL;
}

// Passenger thread function
void *passenger_thread(void *arg) {
  // Generate random floor destination
  int destination = rand() % num_floors + 1;

  // Wait for elevator
  pthread_mutex_lock(&elevator_lock);
  while (current_floor != destination) {
    if (current_floor < destination) {
      current_direction = 1;
    } else if (current_floor > destination) {
      current_direction = -1;
    }
    pthread_cond_signal(&elevator_cond);
    pthread_cond_wait(&elevator_cond, &elevator_lock);
  }

  // Enter elevator
  // ...

  // Release elevator lock
  pthread_mutex_unlock(&elevator_lock);

  return NULL;
}
//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Elevator states
enum elevator_state { IDLE, MOVING_UP, MOVING_DOWN };

// Elevator structure
struct elevator {
  int current_floor;
  int destination_floor;
  enum elevator_state state;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
};

// Create an elevator
struct elevator* create_elevator() {
  struct elevator* elevator = malloc(sizeof(struct elevator));
  elevator->current_floor = 0;
  elevator->destination_floor = 0;
  elevator->state = IDLE;
  pthread_mutex_init(&elevator->mutex, NULL);
  pthread_cond_init(&elevator->cond, NULL);
  return elevator;
}

// Destroy an elevator
void destroy_elevator(struct elevator* elevator) {
  pthread_mutex_destroy(&elevator->mutex);
  pthread_cond_destroy(&elevator->cond);
  free(elevator);
}

// Move the elevator up
void move_elevator_up(struct elevator* elevator) {
  pthread_mutex_lock(&elevator->mutex);
  while (elevator->state != IDLE) {
    pthread_cond_wait(&elevator->cond, &elevator->mutex);
  }
  elevator->state = MOVING_UP;
  elevator->current_floor++;
  if (elevator->current_floor == elevator->destination_floor) {
    elevator->state = IDLE;
    pthread_cond_signal(&elevator->cond);
  }
  pthread_mutex_unlock(&elevator->mutex);
}

// Move the elevator down
void move_elevator_down(struct elevator* elevator) {
  pthread_mutex_lock(&elevator->mutex);
  while (elevator->state != IDLE) {
    pthread_cond_wait(&elevator->cond, &elevator->mutex);
  }
  elevator->state = MOVING_DOWN;
  elevator->current_floor--;
  if (elevator->current_floor == elevator->destination_floor) {
    elevator->state = IDLE;
    pthread_cond_signal(&elevator->cond);
  }
  pthread_mutex_unlock(&elevator->mutex);
}

// Request the elevator to move to a floor
void request_elevator(struct elevator* elevator, int floor) {
  pthread_mutex_lock(&elevator->mutex);
  elevator->destination_floor = floor;
  if (elevator->state == IDLE) {
    if (floor > elevator->current_floor) {
      move_elevator_up(elevator);
    } else if (floor < elevator->current_floor) {
      move_elevator_down(elevator);
    }
  }
  pthread_mutex_unlock(&elevator->mutex);
}

// Main function
int main() {
  // Create an elevator
  struct elevator* elevator = create_elevator();

  // Request the elevator to move to the 5th floor
  request_elevator(elevator, 5);

  // Wait for the elevator to reach the 5th floor
  pthread_mutex_lock(&elevator->mutex);
  while (elevator->current_floor != 5) {
    pthread_cond_wait(&elevator->cond, &elevator->mutex);
  }
  pthread_mutex_unlock(&elevator->mutex);

  // Request the elevator to move to the 1st floor
  request_elevator(elevator, 1);

  // Wait for the elevator to reach the 1st floor
  pthread_mutex_lock(&elevator->mutex);
  while (elevator->current_floor != 1) {
    pthread_cond_wait(&elevator->cond, &elevator->mutex);
  }
  pthread_mutex_unlock(&elevator->mutex);

  // Destroy the elevator
  destroy_elevator(elevator);

  return 0;
}
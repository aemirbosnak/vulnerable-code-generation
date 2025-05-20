//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CARS 10

// Create semaphores to control access to the intersection
sem_t intersection;
sem_t north_light;
sem_t east_light;
sem_t south_light;
sem_t west_light;

// Create a mutex to protect the shared variable `num_cars`
pthread_mutex_t num_cars_mutex;

// Initialize the shared variable `num_cars` to 0
int num_cars = 0;

// Create a thread function for each car
void *car(void *arg) {
  int car_id = *(int *)arg;

  // Arrive at the intersection
  printf("Car %d has arrived at the intersection.\n", car_id);

  // Wait for the semaphore for the car's direction to turn green
  switch (car_id % 4) {
  case 0:
    sem_wait(&north_light);
    break;
  case 1:
    sem_wait(&east_light);
    break;
  case 2:
    sem_wait(&south_light);
    break;
  case 3:
    sem_wait(&west_light);
    break;
  }

  // Enter the intersection
  pthread_mutex_lock(&num_cars_mutex);
  num_cars++;
  pthread_mutex_unlock(&num_cars_mutex);

  // Cross the intersection
  printf("Car %d is crossing the intersection.\n", car_id);
  sleep(1);

  // Exit the intersection
  pthread_mutex_lock(&num_cars_mutex);
  num_cars--;
  pthread_mutex_unlock(&num_cars_mutex);

  // Signal to the semaphore for the car's direction that the car has left the intersection
  switch (car_id % 4) {
  case 0:
    sem_post(&north_light);
    break;
  case 1:
    sem_post(&east_light);
    break;
  case 2:
    sem_post(&south_light);
    break;
  case 3:
    sem_post(&west_light);
    break;
  }

  // Leave the intersection
  printf("Car %d has left the intersection.\n", car_id);

  return NULL;
}

int main() {
  // Initialize the semaphores
  sem_init(&intersection, 0, 1);
  sem_init(&north_light, 0, 1);
  sem_init(&east_light, 0, 0);
  sem_init(&south_light, 0, 0);
  sem_init(&west_light, 0, 0);

  // Initialize the mutex
  pthread_mutex_init(&num_cars_mutex, NULL);

  // Create the cars
  pthread_t cars[NUM_CARS];
  for (int i = 0; i < NUM_CARS; i++) {
    int *car_id = malloc(sizeof(int));
    *car_id = i;
    pthread_create(&cars[i], NULL, car, car_id);
  }

  // Join the cars
  for (int i = 0; i < NUM_CARS; i++) {
    pthread_join(cars[i], NULL);
  }

  // Destroy the semaphores
  sem_destroy(&intersection);
  sem_destroy(&north_light);
  sem_destroy(&east_light);
  sem_destroy(&south_light);
  sem_destroy(&west_light);

  // Destroy the mutex
  pthread_mutex_destroy(&num_cars_mutex);

  return 0;
}
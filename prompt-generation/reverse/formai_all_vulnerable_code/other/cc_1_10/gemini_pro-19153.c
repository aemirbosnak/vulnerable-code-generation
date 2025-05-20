//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define the number of lanes and cars
#define NUM_LANES 3
#define NUM_CARS 10

// Define the traffic light states
#define GREEN 1
#define YELLOW 2
#define RED 3

// Define the semaphore variables
sem_t traffic_light;
sem_t lane_mutexes[NUM_LANES];

// Define the car thread function
void *car_thread(void *arg)
{
  int lane = (int)arg;

  while (1)
  {
    // Wait for the traffic light to turn green
    sem_wait(&traffic_light);

    // Enter the lane
    sem_wait(&lane_mutexes[lane]);

    // Drive through the intersection
    printf("Car %d driving through lane %d\n", (int)pthread_self(), lane);
    sleep(1);

    // Exit the lane
    sem_post(&lane_mutexes[lane]);

    // Wait for the traffic light to turn red
    sem_post(&traffic_light);

    // Sleep for a random amount of time
    sleep(rand() % 5);
  }

  return NULL;
}

// Define the traffic light thread function
void *traffic_light_thread(void *arg)
{
  while (1)
  {
    // Turn the traffic light green
    sem_post(&traffic_light);

    // Sleep for a random amount of time
    sleep(rand() % 5);

    // Turn the traffic light yellow
    sem_wait(&traffic_light);

    // Sleep for a random amount of time
    sleep(rand() % 5);

    // Turn the traffic light red
    sem_post(&traffic_light);

    // Sleep for a random amount of time
    sleep(rand() % 5);
  }

  return NULL;
}

// Main function
int main()
{
  // Initialize the semaphore variables
  sem_init(&traffic_light, 0, 1);
  for (int i = 0; i < NUM_LANES; i++)
  {
    sem_init(&lane_mutexes[i], 0, 1);
  }

  // Create the car threads
  pthread_t car_threads[NUM_CARS];
  for (int i = 0; i < NUM_CARS; i++)
  {
    pthread_create(&car_threads[i], NULL, car_thread, (void *)i);
  }

  // Create the traffic light thread
  pthread_t traffic_light_thread;
  pthread_create(&traffic_light_thread, NULL, traffic_light_thread, NULL);

  // Join the threads
  for (int i = 0; i < NUM_CARS; i++)
  {
    pthread_join(car_threads[i], NULL);
  }
  pthread_join(traffic_light_thread, NULL);

  // Destroy the semaphore variables
  sem_destroy(&traffic_light);
  for (int i = 0; i < NUM_LANES; i++)
  {
    sem_destroy(&lane_mutexes[i]);
  }

  return 0;
}
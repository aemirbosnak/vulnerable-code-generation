//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Traffic light states
#define GREEN 1
#define YELLOW 2
#define RED 3

sem_t green_sem;
sem_t yellow_sem;
sem_t red_sem;

void* traffic_light_controller(void* arg) {
  // Get the traffic light state
  int state = *(int*)arg;

  while (1) {
    // Wait for the semaphore to be signaled
    sem_wait(&green_sem);

    // Display the green light
    printf("Green light on\n");
    sleep(10);

    // Signal the yellow semaphore
    sem_post(&yellow_sem);

    // Wait for the semaphore to be signaled
    sem_wait(&yellow_sem);

    // Display the yellow light
    printf("Yellow light on\n");
    sleep(5);

    // Signal the red semaphore
    sem_post(&red_sem);

    // Wait for the semaphore to be signaled
    sem_wait(&red_sem);

    // Display the red light
    printf("Red light on\n");
    sleep(15);

    // Signal the green semaphore
    sem_post(&green_sem);
  }

  return NULL;
}

int main() {
  // Initialize the semaphores
  sem_init(&green_sem, 0, 1);
  sem_init(&yellow_sem, 0, 0);
  sem_init(&red_sem, 0, 0);

  // Create the traffic light controller thread
  pthread_t thread;
  pthread_create(&thread, NULL, traffic_light_controller, NULL);

  // Join the thread
  pthread_join(thread, NULL);

  // Destroy the semaphores
  sem_destroy(&green_sem);
  sem_destroy(&yellow_sem);
  sem_destroy(&red_sem);

  return 0;
}
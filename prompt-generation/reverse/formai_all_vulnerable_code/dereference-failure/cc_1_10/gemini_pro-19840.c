//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Traffic light states
enum {
  RED_LIGHT,
  YELLOW_LIGHT,
  GREEN_LIGHT
};

// Shared memory for traffic light state
volatile int *traffic_light_state;

// Mutex for synchronizing access to shared memory
pthread_mutex_t lock;

// Initialize traffic light state
void init_traffic_light() {
  traffic_light_state = malloc(sizeof(int));
  *traffic_light_state = RED_LIGHT;
  pthread_mutex_init(&lock, NULL);
}

// Display the traffic light state
void display_traffic_light() {
  switch (*traffic_light_state) {
    case RED_LIGHT:
      printf(RED "   0   \n  #####  \n  #####  \n  #####  \n\n" RESET);
      break;
    case YELLOW_LIGHT:
      printf(YELLOW "   0   \n  #####  \n  #####  \n##### #####  \n\n" RESET);
      break;
    case GREEN_LIGHT:
      printf(GREEN "   0   \n##### #####  \n##### #####  \n##### #####  \n\n" RESET);
      break;
  }
}

// Toggle the traffic light state
void toggle_traffic_light() {
  pthread_mutex_lock(&lock);
  switch (*traffic_light_state) {
    case RED_LIGHT:
      *traffic_light_state = GREEN_LIGHT;
      break;
    case GREEN_LIGHT:
      *traffic_light_state = YELLOW_LIGHT;
      break;
    case YELLOW_LIGHT:
      *traffic_light_state = RED_LIGHT;
      break;
  }
  pthread_mutex_unlock(&lock);
}

// Main thread function
void *main_thread(void *args) {
  while (1) {
    // Toggle the traffic light state
    toggle_traffic_light();

    // Display the traffic light state
    display_traffic_light();

    // Sleep for 1 second
    sleep(1);
  }

  return NULL;
}

// Main function
int main() {
  // Initialize the traffic light
  init_traffic_light();

  // Create the main thread
  pthread_t main_thread_id;
  pthread_create(&main_thread_id, NULL, main_thread, NULL);

  // Join the main thread
  pthread_join(main_thread_id, NULL);

  // Free the shared memory
  free(traffic_light_state);

  return 0;
}
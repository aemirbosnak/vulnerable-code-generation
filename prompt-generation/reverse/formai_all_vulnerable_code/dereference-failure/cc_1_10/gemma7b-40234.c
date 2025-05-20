//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: relaxed
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_SPEED 10

typedef struct Car {
  int lane;
  int speed;
  int position;
  struct Car* next;
} Car;

void initialize_traffic_flow(Car** head) {
  *head = malloc(sizeof(Car));
  (*head)->lane = 0;
  (*head)->speed = MAX_SPEED;
  (*head)->position = 0;
  (*head)->next = NULL;

  // Create the remaining cars
  Car* tail = *head;
  for (int i = 1; i < NUM_LANE; i++) {
    tail->next = malloc(sizeof(Car));
    tail = tail->next;
    tail->lane = i;
    tail->speed = MAX_SPEED;
    tail->position = 0;
    tail->next = NULL;
  }
}

void simulate_traffic_flow(Car* head) {
  time_t start_time = time(NULL);

  // Move the cars
  while (time(NULL) - start_time < 10) {
    Car* current = head;
    while (current) {
      current->position++;
      if (current->position >= 100) {
        current->position = 0;
      }

      current = current->next;
    }

    // Randomize the speed of each car
    for (current = head; current; current++) {
      current->speed = rand() % MAX_SPEED;
    }

    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  initialize_traffic_flow(&head);
  simulate_traffic_flow(head);

  return 0;
}
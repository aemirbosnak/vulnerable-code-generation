//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FitnessTracker {
  char name[MAX_BUFFER_SIZE];
  int steps_taken;
  int distance_traveled;
  double total_time;
  struct FitnessTracker* next;
} FitnessTracker;

void insert_fitness_tracker(FitnessTracker** head, char* name, int steps_taken, int distance_traveled, double total_time) {
  FitnessTracker* new_tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
  strcpy(new_tracker->name, name);
  new_tracker->steps_taken = steps_taken;
  new_tracker->distance_traveled = distance_traveled;
  new_tracker->total_time = total_time;
  new_tracker->next = NULL;

  if (*head == NULL) {
    *head = new_tracker;
  } else {
    (*head)->next = new_tracker;
  }
}

void print_fitness_tracker(FitnessTracker* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Steps taken: %d\n", head->steps_taken);
    printf("Distance traveled: %d\n", head->distance_traveled);
    printf("Total time: %.2f hours\n", head->total_time);
    printf("\n");
    head = head->next;
  }
}

int main() {
  FitnessTracker* head = NULL;

  insert_fitness_tracker(&head, "John Doe", 10000, 5000, 3.5);
  insert_fitness_tracker(&head, "Jane Doe", 8000, 4000, 2.0);
  insert_fitness_tracker(&head, "Peter Pan", 12000, 6000, 4.0);

  print_fitness_tracker(head);

  return 0;
}
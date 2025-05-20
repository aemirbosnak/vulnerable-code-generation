//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct FitnessTracker {
  char name[MAX_SIZE];
  int stepsTaken;
  float distanceTraveled;
  int heartRate;
  struct FitnessTracker* next;
} FitnessTracker;

void createFitnessTracker(FitnessTracker** head) {
  *head = (FitnessTracker*)malloc(sizeof(FitnessTracker));
  (*head)->name[0] = '\0';
  (*head)->stepsTaken = 0;
  (*head)->distanceTraveled = 0.0f;
  (*head)->heartRate = 0;
  (*head)->next = NULL;
}

void addFitnessTracker(FitnessTracker* head, char* name, int stepsTaken, float distanceTraveled, int heartRate) {
  FitnessTracker* newNode = (FitnessTracker*)malloc(sizeof(FitnessTracker));
  strcpy(newNode->name, name);
  newNode->stepsTaken = stepsTaken;
  newNode->distanceTraveled = distanceTraveled;
  newNode->heartRate = heartRate;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void displayFitnessTracker(FitnessTracker* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Steps Taken: %d\n", head->stepsTaken);
    printf("Distance Traveled: %.2f km\n", head->distanceTraveled);
    printf("Heart Rate: %d\n", head->heartRate);
    printf("\n");
    head = head->next;
  }
}

int main() {
  FitnessTracker* head = NULL;

  createFitnessTracker(&head);
  addFitnessTracker(head, "John Doe", 1000, 2.5f, 70);
  addFitnessTracker(head, "Jane Doe", 1200, 3.0f, 60);
  addFitnessTracker(head, "Peter Pan", 1500, 3.5f, 80);

  displayFitnessTracker(head);

  return 0;
}
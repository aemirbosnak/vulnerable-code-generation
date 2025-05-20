//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct FitnessTracker {
  Node* head;
  int totalSteps;
  char name[MAX_NUMBER];
} FitnessTracker;

void insertNode(FitnessTracker* tracker, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (tracker->head == NULL) {
    tracker->head = newNode;
  } else {
    tracker->head->next = newNode;
  }
}

void updateTotalSteps(FitnessTracker* tracker, int steps) {
  tracker->totalSteps += steps;
}

void printFitnessTracker(FitnessTracker* tracker) {
  printf("Name: %s\n", tracker->name);
  printf("Total Steps: %d\n", tracker->totalSteps);

  printf("Steps: ");
  for (Node* node = tracker->head; node; node = node->next) {
    printf("%d ", node->data);
  }
  printf("\n");
}

int main() {
  FitnessTracker* tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
  tracker->head = NULL;
  tracker->totalSteps = 0;
  strcpy(tracker->name, "Donald Knuth");

  insertNode(tracker, 100);
  insertNode(tracker, 200);
  insertNode(tracker, 300);

  updateTotalSteps(tracker, 50);

  printFitnessTracker(tracker);

  free(tracker);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct FitnessTracker {
  Node* head;
  int size;
  time_t timestamp;
} FitnessTracker;

void insertNode(FitnessTracker* tracker, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (tracker->head == NULL) {
    tracker->head = newNode;
  } else {
    tracker->head->next = newNode;
  }

  tracker->size++;
}

void printNodes(FitnessTracker* tracker) {
  Node* current = tracker->head;

  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main() {
  FitnessTracker* tracker = malloc(sizeof(FitnessTracker));
  tracker->head = NULL;
  tracker->size = 0;
  tracker->timestamp = time(NULL);

  insertNode(tracker, 50);
  insertNode(tracker, 60);
  insertNode(tracker, 70);
  insertNode(tracker, 80);
  insertNode(tracker, 90);

  printNodes(tracker);

  free(tracker);

  return 0;
}
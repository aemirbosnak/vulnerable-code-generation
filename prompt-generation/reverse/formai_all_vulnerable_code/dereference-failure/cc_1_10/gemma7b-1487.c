//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KnuthFitnessTracker {
  char name[50];
  int age;
  double weight;
  double height;
  int stepsTaken;
  double totalDistanceTraveled;
  struct KnuthFitnessTracker* next;
} KnuthFitnessTracker;

KnuthFitnessTracker* createKnuthFitnessTracker(char* name, int age, double weight, double height, int stepsTaken, double totalDistanceTraveled) {
  KnuthFitnessTracker* tracker = malloc(sizeof(KnuthFitnessTracker));
  strcpy(tracker->name, name);
  tracker->age = age;
  tracker->weight = weight;
  tracker->height = height;
  tracker->stepsTaken = stepsTaken;
  tracker->totalDistanceTraveled = totalDistanceTraveled;
  tracker->next = NULL;
  return tracker;
}

void addKnuthFitnessTracker(KnuthFitnessTracker* head, char* name, int age, double weight, double height, int stepsTaken, double totalDistanceTraveled) {
  KnuthFitnessTracker* tracker = createKnuthFitnessTracker(name, age, weight, height, stepsTaken, totalDistanceTraveled);
  if (head == NULL) {
    head = tracker;
  } else {
    tracker->next = head;
    head = tracker;
  }
}

void printKnuthFitnessTracker(KnuthFitnessTracker* head) {
  while (head) {
    printf("%s, %d, %.2lf, %.2lf, %d, %.2lf\n", head->name, head->age, head->weight, head->height, head->stepsTaken, head->totalDistanceTraveled);
    head = head->next;
  }
}

int main() {
  KnuthFitnessTracker* head = NULL;
  addKnuthFitnessTracker(head, "Donald Knuth", 80, 80.0, 1.8, 10000, 50.0);
  addKnuthFitnessTracker(head, "Terry Tao", 60, 70.0, 1.7, 8000, 20.0);
  addKnuthFitnessTracker(head, "Stephen Hawking", 65, 60.0, 1.6, 6000, 10.0);
  printKnuthFitnessTracker(head);

  return 0;
}
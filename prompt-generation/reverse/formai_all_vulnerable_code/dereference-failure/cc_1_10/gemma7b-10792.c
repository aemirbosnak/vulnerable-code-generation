//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_READING 10

typedef struct Node {
  struct Node* next;
  int reading;
} Node;

void insertReading(Node** head, int reading) {
  Node* newNode = malloc(sizeof(Node));
  newNode->reading = reading;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int main() {
  time_t t = time(NULL);
  struct Node* head = NULL;

  for (int i = 0; i < MAX_READING; i++) {
    insertReading(&head, rand() % 100);
  }

  printf("Average reading: %.2f\n", averageReading(head));
  printf("Latest reading: %d\n", latestReading(head));

  return 0;
}

int averageReading(Node* head) {
  int totalReading = 0;
  int numReadings = 0;

  for (Node* current = head; current; current = current->next) {
    totalReading += current->reading;
    numReadings++;
  }

  return totalReading / numReadings;
}

int latestReading(Node* head) {
  Node* latestNode = head;

  for (Node* current = head; current->next; current = current->next) {
    latestNode = current;
  }

  return latestNode->reading;
}
//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct Node {
  struct Node* next;
  char data;
} Node;

typedef struct Tracker {
  Node* head;
  int steps;
  char name[20];
} Tracker;

Tracker* tracker_init(char* name, int steps) {
  Tracker* t = malloc(sizeof(Tracker));
  t->head = NULL;
  t->steps = steps;
  strcpy(t->name, name);
  return t;
}

void tracker_add_step(Tracker* t, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->next = t->head;
  t->head = newNode;
  newNode->data = data;
}

void tracker_print(Tracker* t) {
  Node* current = t->head;
  printf("%s: ", t->name);
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Tracker* t = tracker_init("Donny", 10);
  tracker_add_step(t, 'a');
  tracker_add_step(t, 'b');
  tracker_add_step(t, 'c');
  tracker_add_step(t, 'd');
  tracker_print(t);
  return 0;
}
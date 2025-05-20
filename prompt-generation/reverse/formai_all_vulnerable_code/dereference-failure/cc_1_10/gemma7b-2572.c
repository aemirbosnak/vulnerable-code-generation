//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct Node {
  double value;
  struct Node* next;
} Node;

void insert(Node* head, double value) {
  Node* newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void simulate(Node* head) {
  double time = 0;
  int samples = 0;

  while (samples < BUFFER_SIZE) {
    double output = 0;

    for (Node* node = head; node; node = node->next) {
      output += node->value * sin(2 * M_PI * time);
    }

    insert(head, output);

    time += 1/SAMPLE_RATE;
    samples++;
  }
}

int main() {
  Node* head = NULL;

  insert(head, 2);
  insert(head, 4);
  insert(head, 6);

  simulate(head);

  return 0;
}
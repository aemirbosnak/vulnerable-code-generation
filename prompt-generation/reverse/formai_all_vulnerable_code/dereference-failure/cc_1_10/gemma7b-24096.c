//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct Node {
  double value;
  struct Node* next;
} Node;

Node* newNode(double value) {
  Node* node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

void simulate(Node* head) {
  int i;
  double time = 0;
  double samplingInterval = 1 / SAMPLE_RATE;
  int buffer[BUFFER_SIZE];

  for (i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = 0;
  }

  while (head) {
    double output = head->value * sin(time);
    int index = (int) (time * SAMPLE_RATE) % BUFFER_SIZE;
    buffer[index] = output;
    time += samplingInterval;
    head = head->next;
  }

  for (i = 0; i < BUFFER_SIZE; i++) {
    printf("%f ", buffer[i]);
  }

  printf("\n");
}

int main() {
  Node* head = newNode(5);
  head->next = newNode(10);
  head->next->next = newNode(15);

  simulate(head);

  return 0;
}
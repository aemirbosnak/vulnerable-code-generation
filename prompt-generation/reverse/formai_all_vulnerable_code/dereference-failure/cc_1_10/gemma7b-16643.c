//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEM 1000
#define MAX_ITERATIONS 10000

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert_node(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
  head = newNode;
}

void traverse_list(Node* head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;
  clock_t start_time, end_time;

  // Inserting nodes into the linked list
  for (int i = 0; i < NUM_ELEM; i++) {
    insert_node(head, rand() % MAX_ITERATIONS);
  }

  // Timing the traversal
  start_time = clock();
  traverse_list(head);
  end_time = clock();

  // Calculating the time taken
  int time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

  // Printing the time taken
  printf("Time taken: %d seconds\n", time_taken);

  return 0;
}
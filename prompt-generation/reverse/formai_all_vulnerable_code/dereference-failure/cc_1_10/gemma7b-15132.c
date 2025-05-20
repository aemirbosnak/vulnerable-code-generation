//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void printList(Node* head) {
  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {

  // Create a linked list
  Node* head = NULL;

  // Insert some nodes into the list
  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtTail(head, 40);
  insertAtTail(head, 50);

  // Print the list
  printList(head);

  // Simulate CPU scheduling algorithm
  time_t start = time(NULL);
  for (int i = 0; i < MAX; i++) {
    // Randomly select a node from the list
    int randomNode = rand() % MAX;

    // Print the selected node
    printf("Selected node: %d\n", randomNode);

    // Simulate processing time
    sleep(1);
  }

  time_t end = time(NULL);
  printf("Total time: %ld seconds\n", end - start);

  return 0;
}
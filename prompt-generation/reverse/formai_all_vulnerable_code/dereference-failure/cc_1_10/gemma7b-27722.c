//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insert(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void playGame(Node* head) {
  int size = 0;
  Node* current = head;

  while (current) {
    size++;
    current = current->next;
  }

  int guessNumber = rand() % size;

  current = head;

  for (int i = 0; i < guessNumber; i++) {
    current = current->next;
  }

  printf("The answer is: %d\n", current->data);
}

int main() {
  Node* head = insert(NULL, 10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);

  playGame(head);

  return 0;
}
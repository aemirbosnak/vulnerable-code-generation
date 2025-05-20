//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int searchSurreal(struct Node* head, int target) {
  while (head) {
    if (head->data == target) {
      return 1;
    } else if (head->data < target) {
      head = head->next;
    } else if (head->data > target) {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  struct Node* head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);

  if (searchSurreal(head, 3) == 1) {
    printf("Target found!\n");
  } else {
    printf("Target not found.\n");
  }

  return 0;
}
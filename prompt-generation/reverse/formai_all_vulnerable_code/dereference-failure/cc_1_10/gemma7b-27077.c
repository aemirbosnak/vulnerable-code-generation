//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100

struct Node {
  int data;
  struct Node* next;
};

struct Node* insertAtTail(struct Node* head, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int search(struct Node* head, int target) {
  while (head) {
    if (head->data == target) {
      return 1;
    } else if (head->data < target) {
      head = head->next;
    } else {
      return 0;
    }
  }

  return 0;
}

int main() {
  struct Node* head = NULL;
  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtTail(head, 40);

  if (search(head, 30) == 1) {
    printf("Target found!\n");
  } else {
    printf("Target not found.\n");
  }

  return 0;
}
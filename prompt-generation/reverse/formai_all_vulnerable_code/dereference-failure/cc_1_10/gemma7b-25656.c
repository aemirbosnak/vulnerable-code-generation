//Gemma-7B DATASET v1.0 Category: Firewall ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
  char data[MAX_SIZE];
  struct Node* next;
} Node;

Node* insert(Node* head, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data[0] = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int search(Node* head, char data) {
  while (head) {
    if (head->data[0] == data) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;
  head = insert(head, 'a');
  head = insert(head, 'b');
  head = insert(head, 'c');
  head = insert(head, 'd');

  if (search(head, 'b') == 1) {
    printf("The letter b is in the list.\n");
  } else {
    printf("The letter b is not in the list.\n");
  }

  return 0;
}
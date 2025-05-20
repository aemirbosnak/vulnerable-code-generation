//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
  char name[MAX_INDEX_SIZE];
  struct Node* next;
} Node;

Node* insert(Node* head, char name[]) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int search(Node* head, char name[]) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;
  head = insert(head, "Ada Lovelace");
  head = insert(head, "Charles Babbage");
  head = insert(head, "Grace Hopper");
  head = insert(head, "John von Neumann");

  if (search(head, "Ada Lovelace") == 1) {
    printf("Ada Lovelace is found!\n");
  }

  if (search(head, "Charles Babbage") == 1) {
    printf("Charles Babbage is found!\n");
  }

  return 0;
}
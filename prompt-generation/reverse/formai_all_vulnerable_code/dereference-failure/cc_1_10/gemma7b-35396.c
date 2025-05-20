//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
  int key;
  struct Node* next;
};

int hash(int key) {
  return key % MAX;
}

struct Node* insert(struct Node* head, int key) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->key = key;
  newNode->next = NULL;

  int index = hash(key);

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

struct Node* search(struct Node* head, int key) {
  int index = hash(key);

  struct Node* temp = head;
  while (temp) {
    if (temp->key == key) {
      return temp;
    } else if (temp->next == NULL) {
      return NULL;
    } else {
      temp = temp->next;
    }
  }

  return NULL;
}

int main() {
  struct Node* head = NULL;
  insert(head, 10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);

  struct Node* result = search(head, 30);

  if (result) {
    printf("Data found: %d\n", result->key);
  } else {
    printf("Data not found\n");
  }

  return 0;
}
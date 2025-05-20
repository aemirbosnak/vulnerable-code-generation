//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <string.h>

#define KEY_LENGTH 16
#define HASH_SIZE 1024

typedef struct Node {
  char key[KEY_LENGTH];
  struct Node* next;
} Node;

void insert(Node* head, char* key) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->key, key);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newNode;
  }
}

int main() {
  Node* head = NULL;

  insert(head, "abc");
  insert(head, "bcd");
  insert(head, "cde");

  char* key = "bcd";
  Node* search = head;

  while (search) {
    if (strcmp(key, search->key) == 0) {
      printf("Key found: %s\n", search->key);
      break;
    }
    search = search->next;
  }

  if (search == NULL) {
    printf("Key not found\n");
  }

  return 0;
}
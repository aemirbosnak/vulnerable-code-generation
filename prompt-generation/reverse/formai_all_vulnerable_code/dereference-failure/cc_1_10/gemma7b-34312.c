//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* insert_tail(Node* head, char data) {
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

void encrypt(Node* head, char key[]) {
  int i = 0;
  int keyLength = strlen(key);
  for (Node* current = head; current; current = current->next) {
    int offset = key[i] - 'a';
    current->data = (current->data - 'a' + offset) % keyLength + 'a';
    i++;
  }
}

int main() {
  Node* head = insert_tail(NULL, 'a');
  insert_tail(head, 'b');
  insert_tail(head, 'c');

  char key[] = "abc";

  encrypt(head, key);

  for (Node* current = head; current; current = current->next) {
    printf("%c ", current->data);
  }

  printf("\n");

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 32

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* createNode(char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertNode(Node* head, char data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

char generatePassword(Node* head) {
  int i = 0;
  char password[PASSWORD_LENGTH];
  for (i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = head->data;
    head = head->next;
  }
  return *password;
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Node* head = NULL;
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    insertNode(head, (char)rand() % 26 + 65);
  }

  char password = generatePassword(head);
  printf("%s", password);

  return 0;
}
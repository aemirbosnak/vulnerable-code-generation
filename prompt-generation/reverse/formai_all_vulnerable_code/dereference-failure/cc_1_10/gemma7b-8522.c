//Gemma-7B DATASET v1.0 Category: Firewall ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Firewall {
  Node* head;
  int size;
} Firewall;

Firewall* createFirewall(int size) {
  Firewall* firewall = malloc(sizeof(Firewall));
  firewall->head = NULL;
  firewall->size = size;
  return firewall;
}

void addToFirewall(Firewall* firewall, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (firewall->head == NULL) {
    firewall->head = newNode;
  } else {
    Node* current = firewall->head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }
  firewall->size++;
}

int searchFirewall(Firewall* firewall, char data) {
  Node* current = firewall->head;
  while (current) {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

int main() {
  Firewall* firewall = createFirewall(MAX_SIZE);
  addToFirewall(firewall, 'a');
  addToFirewall(firewall, 'b');
  addToFirewall(firewall, 'c');
  addToFirewall(firewall, 'd');

  if (searchFirewall(firewall, 'c')) {
    printf("Character c is in the firewall.\n");
  } else {
    printf("Character c is not in the firewall.\n");
  }

  return 0;
}
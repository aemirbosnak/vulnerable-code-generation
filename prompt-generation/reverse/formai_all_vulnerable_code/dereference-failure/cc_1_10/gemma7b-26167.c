//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_SIZE 100

typedef struct Node {
  char name[20];
  struct Node* next;
  struct Node* prev;
  int position;
  int connections;
} Node;

void insertNode(Node** head, char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->position = 0;
  newNode->connections = 0;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->prev)->next = newNode;
    (*head)->prev = newNode;
  }
}

void connectNodes(Node* node1, Node* node2) {
  node1->connections++;
  node2->connections++;

  node1->prev = node2;
  node2->next = node1;
}

void printTopology(Node* head) {
  Node* current = head;
  while (current) {
    printf("%s: %d connections\n", current->name, current->connections);
    current = current->next;
  }
}

int main() {
  Node* head = NULL;

  insertNode(&head, "A");
  insertNode(&head, "B");
  insertNode(&head, "C");
  insertNode(&head, "D");

  connectNodes(head->next, head);
  connectNodes(head, head->next->next);
  connectNodes(head->next->next, head->next);

  printTopology(head);

  return 0;
}
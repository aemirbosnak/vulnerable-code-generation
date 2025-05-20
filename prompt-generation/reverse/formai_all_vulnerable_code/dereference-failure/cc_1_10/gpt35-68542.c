//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

struct Node {
  int value;
  struct Node* next;
};

typedef struct Node Node;

Node* create_node(int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

void add_node(Node** head, Node* node) {
  if (*head == NULL) {
    *head = node;
  } else {
    Node* cur = *head;
    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = node;
  }
}

void print_list(Node* head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }
  printf("NULL\n");
}

int main() {
  Node* nodes[MAX_NODES];
  memset(nodes, 0, sizeof(nodes));

  printf("Welcome to the surprise Data Structures program!\n\n");

  printf("We are going to create a Linked List using %d nodes.\n", MAX_NODES);
  printf("Get ready to visualize it!\n\n");

  for (int i = 0; i < MAX_NODES; i++) {
    nodes[i] = create_node(i + 1);
    add_node(&nodes[0], nodes[i]);
    printf("Added Node %d to the List.\n", i + 1);
    printf("Current List: ");
    print_list(nodes[0]);
    printf("\n");
  }

  printf("Amazing! We have successfully created a Linked List.\n");
  printf("Let's take a look at the visual representation of the List:\n\n");

  for (int i = 0; i < MAX_NODES; i++) {
    printf("%d -> [%d]\n", nodes[i]->value, (nodes[i]->next == NULL) ? 0 : nodes[i]->next->value);
  }

  printf("Hope you enjoyed this unique visualization of Data Structures!\n");

  return 0;
}
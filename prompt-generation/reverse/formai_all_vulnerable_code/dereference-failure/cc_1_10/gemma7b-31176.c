//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 100

typedef struct Node {
  int index;
  struct Node* next;
} Node;

void topologicalSort(Node* head) {
  int i, count = 0, inDegree[MAX_Vertices] = {0};
  Node* current = head;

  // Calculate in-degree for each vertex
  while (current) {
    inDegree[current->index]++;
    current = current->next;
  }

  // Create a queue for vertices with an in-degree of 0
  Node* queue = NULL;
  for (i = 0; i < MAX_Vertices; i++) {
    if (inDegree[i] == 0) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->index = i;
      newNode->next = queue;
      queue = newNode;
    }
  }

  // Traverse the queue and print the vertices in order
  current = queue;
  while (current) {
    printf("%d ", current->index);
    current = current->next;
  }

  printf("\n");
}

int main() {
  Node* head = (Node*)malloc(sizeof(Node));
  head->index = 0;
  head->next = (Node*)malloc(sizeof(Node));
  head->next->index = 1;
  head->next->next = (Node*)malloc(sizeof(Node));
  head->next->next->index = 2;

  topologicalSort(head);

  return 0;
}
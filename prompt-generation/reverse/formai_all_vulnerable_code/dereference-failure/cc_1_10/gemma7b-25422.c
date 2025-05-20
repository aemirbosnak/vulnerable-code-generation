//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

int graphColoring(Node* graph) {
  int* colors = malloc(MAX * sizeof(int));
  for (int i = 0; i < MAX; i++) {
    colors[i] = -1;
  }

  int currentColor = 0;
  for (Node* node = graph; node; node = node->next) {
    int color = colors[node->data];
    if (color == -1) {
      colors[node->data] = currentColor++;
    }
  }

  free(colors);
  return currentColor;
}

int main() {
  Node* graph = NULL;
  insert(&graph, 1);
  insert(&graph, 2);
  insert(&graph, 3);
  insert(&graph, 4);
  insert(&graph, 5);

  int numColors = graphColoring(graph);

  printf("The number of colors used is: %d\n", numColors);

  return 0;
}
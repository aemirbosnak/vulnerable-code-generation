//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char data;
  struct node* next;
  struct node* prev;
  struct node* child;
  struct node* sibling;
};

struct graph {
  struct node* head;
  struct node* tail;
  int size;
  struct graph* next;
  struct graph* prev;
  struct graph* child;
  struct graph* sibling;
};

struct graph* createGraph() {
  struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
  graph->head = NULL;
  graph->tail = NULL;
  graph->size = 0;
  graph->next = NULL;
  graph->prev = NULL;
  graph->child = NULL;
  graph->sibling = NULL;
  return graph;
}

void insertNode(struct graph* graph, char data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  node->child = NULL;
  node->sibling = NULL;

  if (graph->head == NULL) {
    graph->head = node;
    graph->tail = node;
  } else {
    graph->tail->next = node;
    graph->tail = node;
  }

  graph->size++;
}

int main() {
  struct graph* graph = createGraph();
  insertNode(graph, 'a');
  insertNode(graph, 'b');
  insertNode(graph, 'c');
  insertNode(graph, 'd');

  struct node* node = graph->head;
  while (node) {
    printf("%c ", node->data);
    node = node->next;
  }

  return 0;
}
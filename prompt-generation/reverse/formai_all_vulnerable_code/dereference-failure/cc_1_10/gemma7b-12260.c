//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFFER_SIZE 4096

typedef struct Node {
  struct Node* next;
  int data;
} Node;

typedef struct List {
  Node* head;
  Node* tail;
} List;

void insert_at_tail(List* list, int data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void traverse(List* list) {
  Node* current = list->head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  List* list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;

  clock_t start_time, end_time;
  int i;
  for (i = 0; i < MAX_BUFFER_SIZE; i++) {
    insert_at_tail(list, i);
  }

  start_time = clock();
  traverse(list);
  end_time = clock();

  printf("Time taken: %ld ms\n", end_time - start_time);

  return 0;
}
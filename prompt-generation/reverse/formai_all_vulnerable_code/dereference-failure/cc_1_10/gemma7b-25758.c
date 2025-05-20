//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct List {
  Node* head;
  Node* tail;
} List;

List* CreateList() {
  List* list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void AppendToTail(List* list, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }
}

int main() {
  List* list = CreateList();

  for (int i = 0; i < MAX_STRING_LENGTH; i++) {
    AppendToTail(list, rand() % 26 + 'a');
  }

  time_t start = time(NULL);

  for (int i = 0; i < MAX_STRING_LENGTH; i++) {
    char data = list->head->data;
    list->head = list->head->next;
  }

  time_t end = time(NULL);

  printf("Time taken: %f seconds\n", (double)(end - start) / MAX_STRING_LENGTH);

  return 0;
}
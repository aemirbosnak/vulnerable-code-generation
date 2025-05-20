//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 255
#define MAX_LIST_SIZE 10

typedef struct Node {
  char name[MAX_NAME_LEN];
  struct Node* next;
} Node;

struct List {
  Node* head;
  int size;
};

void insert(struct List* list, char* name) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    list->head->next = newNode;
  }

  list->size++;
}

void printList(struct List* list) {
  Node* current = list->head;
  while (current) {
    printf("%s ", current->name);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct List* list = malloc(sizeof(struct List));
  list->head = NULL;
  list->size = 0;

  insert(list, "John Doe");
  insert(list, "Jane Doe");
  insert(list, "Peter Pan");

  printList(list);

  return 0;
}
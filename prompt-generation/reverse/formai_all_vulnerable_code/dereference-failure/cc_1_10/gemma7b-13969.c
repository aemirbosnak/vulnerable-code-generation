//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 255
#define MAX_LIST_SIZE 100

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  struct Node* next;
} Node;

typedef struct List {
  Node* head;
  int size;
} List;

List* CreateList() {
  List* list = (List*)malloc(sizeof(List));
  list->head = NULL;
  list->size = 0;
  return list;
}

void AddToList(List* list, char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

void PrintList(List* list) {
  Node* current = list->head;
  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }
}

int main() {
  List* myList = CreateList();
  AddToList(myList, "John Doe");
  AddToList(myList, "Jane Doe");
  AddToList(myList, "Bill Smith");
  PrintList(myList);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char name[50];
  int quantity;
  struct Node* next;
} Node;

typedef struct MedicalStore {
  Node* head;
  Node* tail;
  int totalItems;
} MedicalStore;

void insertItem(MedicalStore* store, char* name, int quantity) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (store->head == NULL) {
    store->head = newNode;
    store->tail = newNode;
  } else {
    store->tail->next = newNode;
    store->tail = newNode;
  }

  store->totalItems++;
}

void printItems(MedicalStore* store) {
  Node* current = store->head;
  while (current) {
    printf("%s - %d\n", current->name, current->quantity);
    current = current->next;
  }
}

int main() {
  MedicalStore* store = malloc(sizeof(MedicalStore));
  store->head = NULL;
  store->tail = NULL;
  store->totalItems = 0;

  insertItem(store, "Acetaminophen", 100);
  insertItem(store, "Ibuprofen", 50);
  insertItem(store, "Tylenol", 20);

  printItems(store);

  return 0;
}
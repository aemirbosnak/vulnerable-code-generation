//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[20];
  int quantity;
  double price;
  struct Item* next;
} Item;

Item* insertItem(Item* head, char* name, int quantity, double price) {
  Item* newNode = (Item*)malloc(sizeof(Item));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Item* tail = head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = newNode;
  }

  return head;
}

void printItems(Item* head) {
  Item* current = head;
  while (current) {
    printf("%s: %d, $%.2f\n", current->name, current->quantity, current->price);
    current = current->next;
  }
}

int main() {
  Item* head = NULL;

  head = insertItem(head, "Apple", 10, 1.2);
  head = insertItem(head, "Banana", 20, 0.8);
  head = insertItem(head, "Orange", 30, 1.0);
  head = insertItem(head, "Grape", 40, 0.9);

  printItems(head);

  return 0;
}
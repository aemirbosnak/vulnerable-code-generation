//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char name[20];
  int quantity;
  float price;
  struct Item* next;
};

struct Item* insertItem(struct Item* head, char* name, int quantity, float price) {
  struct Item* newNode = (struct Item*)malloc(sizeof(struct Item));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Item* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

struct Item* searchItem(struct Item* head, char* name) {
  struct Item* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      return temp;
    }
    temp = temp->next;
  }

  return NULL;
}

int main() {
  struct Item* head = NULL;
  head = insertItem(head, "Apple", 10, 1.2);
  head = insertItem(head, "Banana", 5, 0.8);
  head = insertItem(head, "Orange", 7, 1.0);
  head = insertItem(head, "Grape", 3, 0.9);

  struct Item* item = searchItem(head, "Orange");
  if (item) {
    printf("Item: %s, Quantity: %d, Price: %.2f\n", item->name, item->quantity, item->price);
  } else {
    printf("Item not found.\n");
  }

  return 0;
}
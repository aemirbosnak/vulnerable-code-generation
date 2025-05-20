//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char name[20];
  int quantity;
  struct Node* next;
} Node;

typedef struct Coffee {
  char name[20];
  int price;
  struct Coffee* next;
} Coffee;

Node* insertNode(Node* head, char* name, int quantity) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

Coffee* insertCoffee(Coffee* head, char* name, int price) {
  Coffee* newCoffee = (Coffee*)malloc(sizeof(Coffee));
  strcpy(newCoffee->name, name);
  newCoffee->price = price;
  newCoffee->next = NULL;

  if (head == NULL) {
    head = newCoffee;
  } else {
    head->next = newCoffee;
  }

  return head;
}

int main() {
  Node* head = NULL;
  Coffee* coffeeHead = NULL;

  insertNode(head, "John Doe", 2);
  insertNode(head, "Jane Doe", 3);
  insertCoffee(coffeeHead, "Cappuccino", 5);
  insertCoffee(coffeeHead, "Latte", 7);

  printf("Customers:");
  for (Node* current = head; current; current = current->next) {
    printf("\n%s has %d items.", current->name, current->quantity);
  }

  printf("\nCoffee:");
  for (Coffee* current = coffeeHead; current; current = current->next) {
    printf("\n%s costs %d.", current->name, current->price);
  }

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Coffee {
  char name[20];
  double price;
  int quantity;
  struct Coffee* next;
} Coffee;

Coffee* createCoffee(char* name, double price, int quantity) {
  Coffee* coffee = malloc(sizeof(Coffee));
  strcpy(coffee->name, name);
  coffee->price = price;
  coffee->quantity = quantity;
  coffee->next = NULL;
  return coffee;
}

Coffee* addToCoffeeList(Coffee* head, char* name, double price, int quantity) {
  Coffee* newCoffee = createCoffee(name, price, quantity);
  if (head == NULL) {
    head = newCoffee;
  } else {
    Coffee* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newCoffee;
  }
  return head;
}

void printCoffeeList(Coffee* head) {
  Coffee* temp = head;
  while (temp) {
    printf("%s - %.2lf - %d\n", temp->name, temp->price, temp->quantity);
    temp = temp->next;
  }
}

double calculateTotal(Coffee* head) {
  double total = 0.0;
  Coffee* temp = head;
  while (temp) {
    total += temp->price * temp->quantity;
    temp = temp->next;
  }
  return total;
}

int main() {
  Coffee* head = NULL;
  addToCoffeeList(head, "Cappuccino", 5.0, 2);
  addToCoffeeList(head, "Latte", 4.0, 3);
  addToCoffeeList(head, "Americano", 3.0, 1);
  printCoffeeList(head);
  double total = calculateTotal(head);
  printf("Total: %.2lf\n", total);
  return 0;
}
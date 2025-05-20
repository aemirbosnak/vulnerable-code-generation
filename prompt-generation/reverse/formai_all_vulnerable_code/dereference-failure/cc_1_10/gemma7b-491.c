//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 10

typedef struct Order {
  char name[50];
  int quantity;
  double price;
  struct Order* next;
} Order;

Order* head = NULL;

void addOrder(char* name, int quantity, double price) {
  Order* newOrder = malloc(sizeof(Order));
  strcpy(newOrder->name, name);
  newOrder->quantity = quantity;
  newOrder->price = price;
  newOrder->next = NULL;

  if (head == NULL) {
    head = newOrder;
  } else {
    Order* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newOrder;
  }
}

void printOrders() {
  Order* temp = head;
  while (temp) {
    printf("%s, %d, %.2lf\n", temp->name, temp->quantity, temp->price);
    temp = temp->next;
  }
}

double calculateTotal() {
  Order* temp = head;
  double total = 0.0;
  while (temp) {
    total += temp->quantity * temp->price;
    temp = temp->next;
  }
  return total;
}

int main() {
  addOrder("Coffee", 5, 2.5);
  addOrder("Tea", 2, 3.0);
  addOrder("Juice", 3, 4.0);

  printOrders();

  double total = calculateTotal();
  printf("Total: %.2lf\n", total);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10
#define MAX_ITEMS 20

typedef struct Customer {
  char name[50];
  int tableNo;
  double totalBill;
  struct Customer* next;
} Customer;

typedef struct Item {
  char name[50];
  double price;
  struct Item* next;
} Item;

Customer* headCustomer = NULL;
Item* headItem = NULL;

void addItem(char* itemName, double itemPrice) {
  Item* newItem = (Item*)malloc(sizeof(Item));
  strcpy(newItem->name, itemName);
  newItem->price = itemPrice;
  newItem->next = headItem;
  headItem = newItem;
}

void addCustomer(char* customerName, int tableNo) {
  Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
  strcpy(newCustomer->name, customerName);
  newCustomer->tableNo = tableNo;
  newCustomer->totalBill = 0.0;
  newCustomer->next = headCustomer;
  headCustomer = newCustomer;
}

void calculateBill(Customer* customer) {
  double totalBill = 0.0;
  Item* item = headItem;
  while (item) {
    if (item->name[0] == customer->name[0]) {
      totalBill += item->price;
    }
  }
  customer->totalBill = totalBill;
}

void printBill(Customer* customer) {
  printf("Customer Name: %s\n", customer->name);
  printf("Table No: %d\n", customer->tableNo);
  printf("Total Bill: %.2lf\n", customer->totalBill);
}

int main() {
  addItem("Coffee", 2.5);
  addItem("Tea", 3.0);
  addItem("Juice", 4.0);

  addCustomer("John Doe", 1);
  addCustomer("Jane Doe", 2);

  calculateBill(headCustomer);

  printBill(headCustomer);

  return 0;
}
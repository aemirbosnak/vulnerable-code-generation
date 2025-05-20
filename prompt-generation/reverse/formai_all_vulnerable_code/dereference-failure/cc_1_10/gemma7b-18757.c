//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAFF 10
#define MAX_ITEM 100

typedef struct Staff {
  char name[50];
  int id;
  struct Staff* next;
} Staff;

typedef struct Item {
  char name[50];
  int quantity;
  double price;
  struct Item* next;
} Item;

Staff* staff_head = NULL;
Item* item_head = NULL;

void add_staff(char* name, int id) {
  Staff* new_staff = (Staff*)malloc(sizeof(Staff));
  strcpy(new_staff->name, name);
  new_staff->id = id;
  new_staff->next = staff_head;
  staff_head = new_staff;
}

void add_item(char* name, int quantity, double price) {
  Item* new_item = (Item*)malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->price = price;
  new_item->next = item_head;
  item_head = new_item;
}

void check_inventory() {
  Item* current_item = item_head;
  while (current_item) {
    printf("%s: %d units, $%.2lf\n", current_item->name, current_item->quantity, current_item->price);
    current_item = current_item->next;
  }
}

void audit_staff() {
  Staff* current_staff = staff_head;
  while (current_staff) {
    printf("%s (ID: %d)\n", current_staff->name, current_staff->id);
    current_staff = current_staff->next;
  }
}

int main() {
  add_staff("John Doe", 123);
  add_staff("Jane Doe", 456);
  add_item("Paracetamol", 10, 2.50);
  add_item("Ibuprofen", 20, 3.25);
  check_inventory();
  audit_staff();

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
  char name[50];
  int quantity;
  double price;
  struct Medicine *next;
};

struct Pharmacy {
  struct Medicine *head;
  struct Pharmacy *next;
};

void insert_medicine(struct Pharmacy *pharmacy, char *name, int quantity, double price) {
  struct Medicine *new_medicine = malloc(sizeof(struct Medicine));
  strcpy(new_medicine->name, name);
  new_medicine->quantity = quantity;
  new_medicine->price = price;
  new_medicine->next = NULL;

  if (pharmacy->head == NULL) {
    pharmacy->head = new_medicine;
  } else {
    pharmacy->head->next = new_medicine;
  }
}

void print_medicines(struct Pharmacy *pharmacy) {
  struct Medicine *current_medicine = pharmacy->head;
  while (current_medicine) {
    printf("%s, %d, %.2lf\n", current_medicine->name, current_medicine->quantity, current_medicine->price);
    current_medicine = current_medicine->next;
  }
}

int main() {
  struct Pharmacy *pharmacy = malloc(sizeof(struct Pharmacy));
  pharmacy->head = NULL;
  pharmacy->next = NULL;

  insert_medicine(pharmacy, "Acetaminophen", 100, 2.50);
  insert_medicine(pharmacy, "Ibuprofen", 50, 3.25);
  insert_medicine(pharmacy, "Tylenol", 75, 2.75);

  print_medicines(pharmacy);

  return 0;
}
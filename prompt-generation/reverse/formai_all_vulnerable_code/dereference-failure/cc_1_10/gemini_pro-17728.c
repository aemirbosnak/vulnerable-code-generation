//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
  char name[50];
  char manufacturer[50];
  int quantity;
  float price;
};

struct Node {
  struct Medicine medicine;
  struct Node *next;
};

struct Node *head = NULL;

void insert_medicine(struct Medicine medicine) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->medicine = medicine;
  new_node->next = head;
  head = new_node;
}

void delete_medicine(char *name) {
  struct Node *current = head;
  struct Node *previous = NULL;

  while (current != NULL) {
    if (strcmp(current->medicine.name, name) == 0) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void update_medicine(char *name, struct Medicine new_medicine) {
  struct Node *current = head;

  while (current != NULL) {
    if (strcmp(current->medicine.name, name) == 0) {
      current->medicine = new_medicine;
      return;
    }
    current = current->next;
  }
}

void search_medicine(char *name) {
  struct Node *current = head;

  while (current != NULL) {
    if (strcmp(current->medicine.name, name) == 0) {
      printf("Medicine found:\n");
      printf("Name: %s\n", current->medicine.name);
      printf("Manufacturer: %s\n", current->medicine.manufacturer);
      printf("Quantity: %d\n", current->medicine.quantity);
      printf("Price: %f\n", current->medicine.price);
      return;
    }
    current = current->next;
  }

  printf("Medicine not found.\n");
}

void print_all_medicines() {
  struct Node *current = head;

  while (current != NULL) {
    printf("Medicine:\n");
    printf("Name: %s\n", current->medicine.name);
    printf("Manufacturer: %s\n", current->medicine.manufacturer);
    printf("Quantity: %d\n", current->medicine.quantity);
    printf("Price: %f\n", current->medicine.price);
    printf("\n");
    current = current->next;
  }
}

int main() {
  struct Medicine medicine1 = {"Paracetamol", "Cipla", 100, 10.0};
  struct Medicine medicine2 = {"Ibuprofen", "Advil", 50, 15.0};
  struct Medicine medicine3 = {"Aspirin", "Bayer", 25, 5.0};

  insert_medicine(medicine1);
  insert_medicine(medicine2);
  insert_medicine(medicine3);

  print_all_medicines();

  search_medicine("Paracetamol");

  struct Medicine updated_medicine = {"Paracetamol", "Cipla", 150, 10.0};
  update_medicine("Paracetamol", updated_medicine);

  print_all_medicines();

  delete_medicine("Ibuprofen");

  print_all_medicines();

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
struct Element {
  char name[20];
  int atomic_number;
  float atomic_mass;
  char symbol[2];
  struct Element *next;
};

// Function to insert an element into the periodic table
void insert_element(struct Element **head, char *name, int atomic_number, float atomic_mass, char *symbol) {
  struct Element *new_element = (struct Element *)malloc(sizeof(struct Element));
  strcpy(new_element->name, name);
  new_element->atomic_number = atomic_number;
  new_element->atomic_mass = atomic_mass;
  strcpy(new_element->symbol, symbol);
  new_element->next = NULL;

  if (*head == NULL) {
    *head = new_element;
  } else {
    (*head)->next = new_element;
  }
}

// Function to print the periodic table
void print_elements(struct Element *head) {
  struct Element *current = head;
  while (current) {
    printf("%s (%c) - Atomic Number: %d, Atomic Mass: %.2f\n", current->name, current->symbol, current->atomic_number, current->atomic_mass);
    current = current->next;
  }
}

int main() {
  struct Element *head = NULL;

  // Insert elements into the periodic table
  insert_element(&head, "Hydrogen", 1, 1.008, "H");
  insert_element(&head, "Helium", 2, 4.0026, "He");
  insert_element(&head, "Lithium", 3, 6.940, "Li");
  insert_element(&head, "Sodium", 11, 22.989, "Na");

  // Print the periodic table
  print_elements(head);

  return 0;
}
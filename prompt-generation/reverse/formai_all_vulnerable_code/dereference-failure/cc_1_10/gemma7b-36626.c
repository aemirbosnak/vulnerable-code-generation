//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 17
#define COLS 18

typedef struct Element {
  char name[20];
  int atomic_number;
  float atomic_mass;
  struct Element *next;
} Element;

Element *head = NULL;

void insert_element(char *name, int atomic_number, float atomic_mass) {
  Element *new_element = malloc(sizeof(Element));
  strcpy(new_element->name, name);
  new_element->atomic_number = atomic_number;
  new_element->atomic_mass = atomic_mass;
  new_element->next = NULL;

  if (head == NULL) {
    head = new_element;
  } else {
    Element *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_element;
  }
}

void print_elements() {
  Element *current = head;
  printf("------------------------------------------------------------------------\n");
  printf("  # | Name | Atomic Number | Atomic Mass |\n");
  printf("------------------------------------------------------------------------\n");
  while (current) {
    printf("  %-2d | %-20s | %-4d | %.2f |\n", current->atomic_number, current->name, current->atomic_number, current->atomic_mass);
    current = current->next;
  }
  printf("------------------------------------------------------------------------\n");
}

int main() {
  insert_element("Hydrogen", 1, 1.008);
  insert_element("Helium", 2, 4.0026);
  insert_element("Lithium", 3, 6.9409);
  insert_element("Sodium", 11, 22.9898);
  print_elements();

  return 0;
}
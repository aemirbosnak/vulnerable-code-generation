//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
struct element {
  char name[20];
  int atomic_number;
  float atomic_mass;
  char state;
  struct element* next;
};

// Create a linked list of elements
struct element* create_element_list() {
  struct element* head = malloc(sizeof(struct element));
  head->name[0] = '\0';
  head->atomic_number = 0;
  head->atomic_mass = 0.0f;
  head->state = 'N';
  head->next = NULL;
  return head;
}

// Insert an element into the list
void insert_element(struct element* head, char* name, int atomic_number, float atomic_mass, char state) {
  struct element* new_element = malloc(sizeof(struct element));
  new_element->name[0] = '\0';
  new_element->atomic_number = atomic_number;
  new_element->atomic_mass = atomic_mass;
  new_element->state = state;
  new_element->next = NULL;

  if (head->name[0] == '\0') {
    head = new_element;
  } else {
    struct element* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_element;
  }
}

int main() {
  struct element* head = create_element_list();

  // Insert some elements
  insert_element(head, "Hydrogen", 1, 1.008, 'G');
  insert_element(head, "Helium", 2, 4.0026, 'G');
  insert_element(head, "Lithium", 3, 6.940, 'S');

  // Print the elements
  struct element* current = head;
  while (current) {
    printf("%s (%d) - %f, State: %c\n", current->name, current->atomic_number, current->atomic_mass, current->state);
    current = current->next;
  }

  return 0;
}
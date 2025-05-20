//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118

struct Element {
  char name[20];
  int atomic_number;
  float atomic_mass;
  char symbol[2];
  char block_number;
  char type;
  struct Element* next;
};

struct Element* head = NULL;

void insertElement(char* name, int atomic_number, float atomic_mass, char symbol, char block_number, char type) {
  struct Element* newElement = malloc(sizeof(struct Element));
  strcpy(newElement->name, name);
  newElement->atomic_number = atomic_number;
  newElement->atomic_mass = atomic_mass;
  strcpy(newElement->symbol, symbol);
  newElement->block_number = block_number;
  newElement->type = type;
  newElement->next = NULL;

  if (head == NULL) {
    head = newElement;
  } else {
    struct Element* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newElement;
  }
}

void printElement(struct Element* element) {
  printf("Name: %s\n", element->name);
  printf("Atomic Number: %d\n", element->atomic_number);
  printf("Atomic Mass: %.2f\n", element->atomic_mass);
  printf("Symbol: %s\n", element->symbol);
  printf("Block Number: %c\n", element->block_number);
  printf("Type: %c\n", element->type);
  printf("\n");
}

int main() {
  insertElement("Hydrogen", 1, 1.008, "H", '1', ' alkali metal');
  insertElement("Helium", 2, 4.0026, "He", '2', 'noble gas');
  insertElement("Lithium", 3, 6.940, "Li", '1', ' alkali metal');

  printElement(head);

  return 0;
}
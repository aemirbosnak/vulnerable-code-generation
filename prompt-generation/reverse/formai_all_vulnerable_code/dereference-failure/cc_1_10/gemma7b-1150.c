//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
#define PT_SIZE 118

struct Element {
  char name[20];
  int atomicNum;
  float mass;
  char symbol[2];
  struct Element* next;
};

struct Element* head = NULL;

void insertElement(char* name, int atomicNum, float mass, char* symbol) {
  struct Element* newNode = (struct Element*)malloc(sizeof(struct Element));
  strcpy(newNode->name, name);
  newNode->atomicNum = atomicNum;
  newNode->mass = mass;
  strcpy(newNode->symbol, symbol);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Element* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void printTable() {
  struct Element* current = head;
  printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
  printf("   | Name | Atomic Number | Mass | Symbol |\n");
  printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
  while (current) {
    printf("   | %s | %d | %.2f | %s |\n", current->name, current->atomicNum, current->mass, current->symbol);
    current = current->next;
  }
  printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
}

int main() {
  insertElement("Hydrogen", 1, 1.008, "H");
  insertElement("Helium", 2, 4.0026, "He");
  insertElement("Lithium", 3, 6.940, "Li");
  insertElement("Sodium", 11, 22.989, "Na");
  insertElement("Gold", 79, 196.966, "Au");

  printTable();

  return 0;
}
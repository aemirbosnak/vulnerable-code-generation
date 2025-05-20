//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 118

typedef struct Element {
  char name[20];
  int atomicNumber;
  double mass;
  struct Element* next;
} Element;

Element* head = NULL;

void insertElement(char* name, int atomicNumber, double mass) {
  Element* newNode = malloc(sizeof(Element));
  strcpy(newNode->name, name);
  newNode->atomicNumber = atomicNumber;
  newNode->mass = mass;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Element* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void printTable() {
  Element* current = head;
  printf("<table>\n");
  printf("  <thead>\n");
  printf("    <tr>\n");
  printf("      <th>Name</th>\n");
  printf("      <th>Atomic Number</th>\n");
  printf("      <th>Mass</th>\n");
  printf("    </tr>\n");
  printf("  </thead>\n");
  printf("  <tbody>\n");
  while (current) {
    printf("    <tr>\n");
    printf("      <td>%s</td>\n", current->name);
    printf("      <td>%d</td>\n", current->atomicNumber);
    printf("      <td>%.2lf</td>\n", current->mass);
    printf("    </tr>\n");
    current = current->next;
  }
  printf("  </tbody>\n");
  printf("</table>\n");
}

int main() {
  insertElement("Hydrogen", 1, 1.008);
  insertElement("Helium", 2, 4.0026);
  insertElement("Lithium", 3, 6.940) ;
  insertElement("Sodium", 11, 22.989);
  insertElement("Gold", 79, 196.966);

  printTable();

  return 0;
}
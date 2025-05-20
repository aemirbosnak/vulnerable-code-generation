//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Element {
  char name[20];
  int atomic_number;
  double mass;
  struct Element* next;
} Element;

Element* insertElement(Element* head, char* name, int atomic_number, double mass) {
  Element* newNode = (Element*)malloc(sizeof(Element));
  strcpy(newNode->name, name);
  newNode->atomic_number = atomic_number;
  newNode->mass = mass;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Element* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

void printElements(Element* head) {
  Element* temp = head;
  while (temp) {
    printf("%s (%d) - %.2lf\n", temp->name, temp->atomic_number, temp->mass);
    temp = temp->next;
  }
}

int main() {
  Element* head = NULL;
  head = insertElement(head, "Hydrogen", 1, 1.008);
  head = insertElement(head, "Helium", 2, 4.0026);
  head = insertElement(head, "Lithium", 3, 6.940);
  head = insertElement(head, "Sodium", 11, 22.989);

  printElements(head);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 118

struct Element {
  char name[20];
  int atomicNum;
  float mass;
  char state;
  struct Element* next;
};

void displayTable(struct Element* head) {
  while (head) {
    printf("%-20s | %d | %.2f | %c |", head->name, head->atomicNum, head->mass, head->state);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct Element* head = NULL;
  struct Element* tail = NULL;

  // Create a few elements
  struct Element* element1 = malloc(sizeof(struct Element));
  strcpy(element1->name, "Hydrogen");
  element1->atomicNum = 1;
  element1->mass = 1.00784;
  element1->state = 'G';

  struct Element* element2 = malloc(sizeof(struct Element));
  strcpy(element2->name, "Helium");
  element2->atomicNum = 2;
  element2->mass = 4.002602;
  element2->state = 'G';

  struct Element* element3 = malloc(sizeof(struct Element));
  strcpy(element3->name, "Lithium");
  element3->atomicNum = 3;
  element3->mass = 6.93848222831;
  element3->state = 'S';

  // Add elements to the table
  if (head == NULL) {
    head = element1;
    tail = element1;
  } else {
    tail->next = element1;
    tail = element1;
  }

  if (head->next) {
    tail->next = element2;
    tail = element2;
  }

  if (head->next->next) {
    tail->next = element3;
    tail = element3;
  }

  // Display the table
  displayTable(head);

  return 0;
}
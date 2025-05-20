//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SURVIVORS 5

typedef struct Survivor {
  char name[20];
  int health;
  int inventory[MAX_SURVIVORS];
  struct Survivor* next;
} Survivor;

Survivor* head = NULL;

void addSurvivor(char* name, int health) {
  Survivor* newSurvivor = (Survivor*)malloc(sizeof(Survivor));

  strcpy(newSurvivor->name, name);
  newSurvivor->health = health;
  newSurvivor->inventory[0] = 0;
  newSurvivor->next = NULL;

  if (head == NULL) {
    head = newSurvivor;
  } else {
    Survivor* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newSurvivor;
  }
}

void printInventory(Survivor* survivor) {
  printf("Inventory of %s:\n", survivor->name);
  for (int i = 0; survivor->inventory[i] != 0; i++) {
    printf("%d. %s\n", survivor->inventory[i], "N/A");
  }
}

int main() {
  addSurvivor("John", 100);
  addSurvivor("Mary", 80);
  addSurvivor("Bob", 60);
  addSurvivor("Alice", 40);
  addSurvivor("Tom", 20);

  printInventory(head);

  return 0;
}
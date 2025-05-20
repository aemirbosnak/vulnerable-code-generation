//Gemma-7B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Knight {
  char name[MAX_NAME_LENGTH];
  int strength;
  int agility;
  int wisdom;
  struct Knight *next;
} Knight;

int main() {
  Knight *head = NULL;
  Knight *current = NULL;

  // Create a few knights
  Knight *new_knight = malloc(sizeof(Knight));
  strcpy(new_knight->name, "Sir Robin");
  new_knight->strength = 18;
  new_knight->agility = 16;
  new_knight->wisdom = 12;
  new_knight->next = NULL;

  Knight *new_knight2 = malloc(sizeof(Knight));
  strcpy(new_knight2->name, "Sir Gareth");
  new_knight2->strength = 16;
  new_knight2->agility = 14;
  new_knight2->wisdom = 10;
  new_knight2->next = NULL;

  Knight *new_knight3 = malloc(sizeof(Knight));
  strcpy(new_knight3->name, "Sir Baldwin");
  new_knight3->strength = 14;
  new_knight3->agility = 12;
  new_knight3->wisdom = 8;
  new_knight3->next = NULL;

  // Append the knights to the linked list
  if (head == NULL) {
    head = new_knight;
    current = head;
  } else {
    current->next = new_knight;
    current = new_knight;
  }

  // Query the knights
  printf("List of knights:\n");
  current = head;
  while (current) {
    printf("%s, Strength: %d, Agility: %d, Wisdom: %d\n", current->name, current->strength, current->agility, current->wisdom);
    current = current->next;
  }

  // Free the knights
  free(new_knight);
  free(new_knight2);
  free(new_knight3);

  return 0;
}
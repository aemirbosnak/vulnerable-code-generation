//Gemma-7B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Knight {
  char name[MAX_NAME_LENGTH];
  int strength;
  int wisdom;
  struct Knight *next;
} Knight;

Knight *insertKnight(Knight *head, char *name, int strength, int wisdom) {
  Knight *newKnight = malloc(sizeof(Knight));
  strcpy(newKnight->name, name);
  newKnight->strength = strength;
  newKnight->wisdom = wisdom;
  newKnight->next = head;
  return newKnight;
}

Knight *findKnight(Knight *head, char *name) {
  Knight *currentKnight = head;
  while (currentKnight) {
    if (strcmp(currentKnight->name, name) == 0) {
      return currentKnight;
    }
    currentKnight = currentKnight->next;
  }
  return NULL;
}

int main() {
  Knight *head = NULL;
  head = insertKnight(head, "Sir Robin", 15, 12);
  head = insertKnight(head, "Lady Elaine", 10, 14);
  head = insertKnight(head, "The Black Knight", 12, 10);

  Knight *knight = findKnight(head, "Sir Robin");
  if (knight) {
    printf("Name: %s\n", knight->name);
    printf("Strength: %d\n", knight->strength);
    printf("Wisdom: %d\n", knight->wisdom);
  } else {
    printf("Knight not found.\n");
  }

  return 0;
}
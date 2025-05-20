//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Knight {
  char name[MAX_NAME_LENGTH];
  int strength;
  struct Knight* next;
} Knight;

Knight* insertKnight(Knight* head, char* name, int strength) {
  Knight* newKnight = malloc(sizeof(Knight));
  strcpy(newKnight->name, name);
  newKnight->strength = strength;
  newKnight->next = NULL;

  if (head == NULL) {
    head = newKnight;
  } else {
    Knight* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newKnight;
  }

  return head;
}

Knight* searchKnight(Knight* head, char* name) {
  Knight* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      return temp;
    }
    temp = temp->next;
  }

  return NULL;
}

int main() {
  Knight* head = NULL;
  head = insertKnight(head, "Sir Robin", 15);
  head = insertKnight(head, "Sir Ivan", 12);
  head = insertKnight(head, "Sir Gareth", 13);

  Knight* foundKnight = searchKnight(head, "Sir Ivan");

  if (foundKnight) {
    printf("Found knight: %s\n", foundKnight->name);
  } else {
    printf("Knight not found.\n");
  }

  return 0;
}
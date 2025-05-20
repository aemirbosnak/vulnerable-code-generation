//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 200

typedef struct Knight {
  char name[MAX_NAME_LENGTH];
  char message[MAX_MESSAGE_LENGTH];
  struct Knight* next;
} Knight;

Knight* createKnight(char* name, char* message) {
  Knight* knight = malloc(sizeof(Knight));
  strcpy(knight->name, name);
  strcpy(knight->message, message);
  knight->next = NULL;
  return knight;
}

void addToKnightList(Knight* knightList, Knight* newKnight) {
  if (knightList == NULL) {
    knightList = newKnight;
  } else {
    knightList->next = newKnight;
    knightList = knightList->next;
  }
}

void printKnightList(Knight* knightList) {
  Knight* currentKnight = knightList;
  while (currentKnight) {
    printf("%s: %s\n", currentKnight->name, currentKnight->message);
    currentKnight = currentKnight->next;
  }
}

int main() {
  Knight* knightList = NULL;

  Knight* newKnight = createKnight("Sir Robin", "I have a secret message for you.");
  addToKnightList(knightList, newKnight);

  newKnight = createKnight("Lady Alice", "The cat is coming!");
  addToKnightList(knightList, newKnight);

  newKnight = createKnight("Sir Gareth", "Prepare for battle!");
  addToKnightList(knightList, newKnight);

  printKnightList(knightList);

  return 0;
}
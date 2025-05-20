//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100

typedef struct Knight {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  int level;
  struct Knight *next;
} Knight;

Knight *head = NULL;

void addKnight(char *name, char *description, int level) {
  Knight *newKnight = malloc(sizeof(Knight));
  strcpy(newKnight->name, name);
  strcpy(newKnight->description, description);
  newKnight->level = level;
  newKnight->next = NULL;

  if (head == NULL) {
    head = newKnight;
  } else {
    Knight *currentKnight = head;
    while (currentKnight->next != NULL) {
      currentKnight = currentKnight->next;
    }
    currentKnight->next = newKnight;
  }
}

void printKnights() {
  Knight *currentKnight = head;
  while (currentKnight) {
    printf("%s: %s (Level: %d)\n", currentKnight->name, currentKnight->description, currentKnight->level);
    currentKnight = currentKnight->next;
  }
}

int main() {
  addKnight("Sir Robin", "A valiant knight with a strong heart and a sharp sword.", 5);
  addKnight("Lady Morgana", "A cunning sorceress with a wicked reputation.", 3);
  addKnight("The Dragon", "A fierce dragon with a fiery breath.", 7);

  printKnights();

  return 0;
}
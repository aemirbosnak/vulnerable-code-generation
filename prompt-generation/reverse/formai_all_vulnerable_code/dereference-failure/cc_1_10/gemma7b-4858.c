//Gemma-7B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_LENGTH 32

typedef struct Warrior {
  char name[20];
  char password[PASSWORD_LENGTH];
  struct Warrior *next;
} Warrior;

Warrior *createWarrior(char *name, char *password) {
  Warrior *warrior = malloc(sizeof(Warrior));
  strcpy(warrior->name, name);
  strcpy(warrior->password, password);
  warrior->next = NULL;
  return warrior;
}

void addWarrior(Warrior *head, char *name, char *password) {
  Warrior *newWarrior = createWarrior(name, password);
  if (head == NULL) {
    head = newWarrior;
  } else {
    head->next = newWarrior;
  }
  head = newWarrior;
}

int authenticateWarrior(Warrior *head, char *name, char *password) {
  for (Warrior *warrior = head; warrior; warrior = warrior->next) {
    if (strcmp(warrior->name, name) == 0 && strcmp(warrior->password, password) == 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
  Warrior *head = NULL;
  addWarrior(head, "Sir Robin", "The Boldest");
  addWarrior(head, "The Dragon", "Fire and Fury");
  addWarrior(head, "Sir William", "The Strongest");

  if (authenticateWarrior(head, "Sir Robin", "The Boldest") == 1) {
    printf("Welcome, Sir Robin!\n");
  } else {
    printf("Authentication failed.\n");
  }

  return 0;
}
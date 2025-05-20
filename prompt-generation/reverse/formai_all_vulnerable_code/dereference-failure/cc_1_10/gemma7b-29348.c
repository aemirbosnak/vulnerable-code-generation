//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the two families
#define FAMILY_RED 1
#define FAMILY_GREEN 2

// Define the characters
#define RICKY_RED 1
#define JULIA_GREEN 2
#define BEN_RED 3
#define TYLER_GREEN 4

// Define the relationship between characters
#define FRIEND 0
#define ENEMY 1
#define LOVE 2

// Create a database of characters
struct Character {
  char name[20];
  int family;
  int relationship[2];
  struct Character* next;
};

// Function to add a character to the database
void addCharacter(struct Character** head, char* name, int family, int relationship) {
  struct Character* newCharacter = malloc(sizeof(struct Character));
  strcpy(newCharacter->name, name);
  newCharacter->family = family;
  newCharacter->relationship[0] = FRIEND;
  newCharacter->relationship[1] = ENEMY;
  newCharacter->relationship[2] = LOVE;
  newCharacter->next = NULL;

  if (*head == NULL) {
    *head = newCharacter;
  } else {
    (*head)->next = newCharacter;
  }
}

// Function to print the characters
void printCharacters(struct Character* head) {
  struct Character* currentCharacter = head;
  while (currentCharacter) {
    printf("%s (%d) - ", currentCharacter->name, currentCharacter->family);
    for (int i = 0; i < 3; i++) {
      switch (currentCharacter->relationship[i]) {
        case FRIEND:
          printf("Friend ");
          break;
        case ENEMY:
          printf("Enemy ");
          break;
        case LOVE:
          printf("Love ");
          break;
      }
    }
    printf("\n");
    currentCharacter = currentCharacter->next;
  }
}

int main() {
  struct Character* head = NULL;

  // Add characters to the database
  addCharacter(&head, "Ricky", FAMILY_RED, FRIEND);
  addCharacter(&head, "Julia", FAMILY_GREEN, FRIEND);
  addCharacter(&head, "Ben", FAMILY_RED, ENEMY);
  addCharacter(&head, "Tyler", FAMILY_GREEN, ENEMY);

  // Print the characters
  printCharacters(head);

  return 0;
}
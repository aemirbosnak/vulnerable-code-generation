//Gemma-7B DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* head = NULL;

void addPlayer() {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  newPlayer->next = NULL;

  if (head == NULL) {
    head = newPlayer;
  } else {
    head->next = newPlayer;
    head = newPlayer;
  }
}

void removePlayer(char* name) {
  Player* current = head;
  Player* previous = NULL;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }

  printf("Player not found.\n");
}

int main() {
  addPlayer();
  addPlayer();
  addPlayer();
  addPlayer();

  removePlayer("John");

  Player* current = head;
  while (current) {
    printf("%s, %d\n", current->name, current->score);
    current = current->next;
  }

  return 0;
}
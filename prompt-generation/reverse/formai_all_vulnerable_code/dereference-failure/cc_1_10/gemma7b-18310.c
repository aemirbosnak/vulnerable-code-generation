//Gemma-7B DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 2

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* CreatePlayer(char* name) {
  Player* player = malloc(sizeof(Player));
  strcpy(player->name, name);
  player->score = 0;
  player->next = NULL;
  return player;
}

void AddPlayer(Player* head, char* name) {
  Player* newPlayer = CreatePlayer(name);
  if (head == NULL) {
    head = newPlayer;
  } else {
    head->next = newPlayer;
  }
  head = newPlayer;
}

void PlayGame() {
  Player* head = NULL;
  AddPlayer(head, "Alice");
  AddPlayer(head, "Bob");

  // Game logic
  // ...

  // Print scores
  Player* currentPlayer = head;
  while (currentPlayer) {
    printf("%s's score: %d\n", currentPlayer->name, currentPlayer->score);
    currentPlayer = currentPlayer->next;
  }
}

int main() {
  PlayGame();
  return 0;
}
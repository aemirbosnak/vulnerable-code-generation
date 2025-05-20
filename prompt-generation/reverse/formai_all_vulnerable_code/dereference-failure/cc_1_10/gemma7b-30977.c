//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* createPlayer(char* name) {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->score = 0;
  newPlayer->next = NULL;
  return newPlayer;
}

void addPlayer(Player* head, char* name) {
  Player* newPlayer = createPlayer(name);
  if (head == NULL) {
    head = newPlayer;
  } else {
    head->next = newPlayer;
  }
  head = newPlayer;
}

void printPlayers(Player* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->score);
    head = head->next;
  }
}

int main() {
  Player* head = NULL;
  char name[20];

  // Add players
  addPlayer(head, "John");
  addPlayer(head, "Mary");
  addPlayer(head, "Bob");
  addPlayer(head, "Alice");

  // Print players
  printPlayers(head);

  // Play the game
  // (e.g., have players compete in a game, update their scores, etc.)

  // Print players again after the game
  printPlayers(head);

  return 0;
}
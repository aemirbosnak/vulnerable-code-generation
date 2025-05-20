//Gemma-7B DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* createPlayer(char* name, int score) {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->score = score;
  newPlayer->next = NULL;
  return newPlayer;
}

void addPlayer(Player* head, char* name, int score) {
  Player* newPlayer = createPlayer(name, score);
  if (head) {
    head->next = newPlayer;
  } else {
    head = newPlayer;
  }
  head = newPlayer;
}

void playGame() {
  Player* head = NULL;
  addPlayer(head, "John", 10);
  addPlayer(head, "Mary", 20);
  addPlayer(head, "Bob", 30);
  addPlayer(head, "Alice", 40);

  printf("Welcome to the game, folks!\n");
  printf("Let's see who can get the highest score:\n");

  Player* currentPlayer = head;
  while (currentPlayer) {
    printf("%s: %d\n", currentPlayer->name, currentPlayer->score);
    currentPlayer = currentPlayer->next;
  }

  printf("The winner is: %s!\n", head->next->name);
}

int main() {
  playGame();
  return 0;
}
//Gemma-7B DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_PLAYER 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void initGame(Player** head) {
  *head = NULL;
}

void addPlayer(Player** head, char* name) {
  Player* newPlayer = malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->score = 0;
  newPlayer->next = NULL;

  if (*head == NULL) {
    *head = newPlayer;
  } else {
    (*head)->next = newPlayer;
  }
}

void playGame(Player** head) {
  // Implement game logic here
  // For example, roll a die, calculate points, update scores, etc.
}

int main() {
  Player** head = NULL;
  initGame(head);

  // Add players
  addPlayer(head, "John");
  addPlayer(head, "Mary");
  addPlayer(head, "Bob");

  // Play the game
  playGame(head);

  // Print final scores
  Player* currentPlayer = head;
  while (currentPlayer) {
    printf("%s's score: %d\n", currentPlayer->name, currentPlayer->score);
    currentPlayer = currentPlayer->next;
  }

  return 0;
}
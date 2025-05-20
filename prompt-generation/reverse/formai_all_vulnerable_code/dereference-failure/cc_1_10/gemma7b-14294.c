//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 2

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* head = NULL;

void addPlayer(char* name) {
  Player* newPlayer = malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->score = 0;
  newPlayer->next = NULL;

  if (head == NULL) {
    head = newPlayer;
  } else {
    head->next = newPlayer;
    head = newPlayer;
  }
}

void playGame() {
  int i, roll, total, winner = -1;
  Player* currentPlayer = head;

  for (i = 0; i < MAX_PLAYERS && currentPlayer; i++) {
    roll = rand() % 6 + 1;
    total = currentPlayer->score + roll;

    printf("%s rolled a %d, total is %d\n", currentPlayer->name, roll, total);

    if (total >= 20) {
      winner = currentPlayer->score;
      break;
    }

    currentPlayer = currentPlayer->next;
  }

  if (winner != -1) {
    printf("The winner is: %s with a score of %d\n", head->name, winner);
  } else {
    printf("No winner!\n");
  }
}

int main() {
  addPlayer("Alice");
  addPlayer("Bob");
  playGame();

  return 0;
}
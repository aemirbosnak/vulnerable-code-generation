//Gemma-7B DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 2

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* createPlayer(char* name, int score) {
  Player* newPlayer = malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->score = score;
  newPlayer->next = NULL;

  return newPlayer;
}

void addPlayer(Player* head, char* name, int score) {
  Player* newPlayer = createPlayer(name, score);

  if (head == NULL) {
    head = newPlayer;
  } else {
    head->next = newPlayer;
  }

  head = newPlayer;
}

void playGame() {
  Player* head = NULL;
  addPlayer(head, "John", 10);
  addPlayer(head, "Mary", 8);
  addPlayer(head, "Bob", 12);

  for (Player* currentPlayer = head; currentPlayer; currentPlayer = currentPlayer->next) {
    printf("%s's turn: ", currentPlayer->name);
    int move = rand() % 6 + 1;
    currentPlayer->score += move;
    printf("Moved %d, score is now %d\n", move, currentPlayer->score);
  }

  for (Player* currentPlayer = head; currentPlayer; currentPlayer = currentPlayer->next) {
    printf("%s's final score: %d\n", currentPlayer->name, currentPlayer->score);
  }

  printf("The winner is: %s\n", head->next->name);
}

int main() {
  playGame();

  return 0;
}
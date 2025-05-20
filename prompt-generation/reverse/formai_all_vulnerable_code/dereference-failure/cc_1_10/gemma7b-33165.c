//Gemma-7B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_PLAYERS 2

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* createPlayer(char* name, int score) {
  Player* player = (Player*)malloc(sizeof(Player));
  strcpy(player->name, name);
  player->score = score;
  player->next = NULL;
  return player;
}

void addPlayer(Player* head, char* name, int score) {
  Player* newPlayer = createPlayer(name, score);
  if (head == NULL) {
    head = newPlayer;
  } else {
    Player* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newPlayer;
  }
}

void playGame() {
  Player* head = NULL;
  addPlayer(head, "John", 10);
  addPlayer(head, "Mary", 20);
  addPlayer(head, "Bob", 30);

  // Game logic
  // ...

  // Print scores
  Player* currentPlayer = head;
  while (currentPlayer) {
    printf("%s: %d\n", currentPlayer->name, currentPlayer->score);
    currentPlayer = currentPlayer->next;
  }
}

int main() {
  playGame();
  return 0;
}
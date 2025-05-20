//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4

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

void startGame(Player* head) {
  time_t t = time(NULL);
  srand(t);
  int numPlayers = 0;
  for (Player* current = head; current; current = current->next) {
    numPlayers++;
  }
  int rounds = numPlayers * 2;
  for (int i = 0; i < rounds; i++) {
    for (Player* current = head; current; current = current->next) {
      int roll = rand() % 6 + 1;
      current->score += roll;
    }
  }
  for (Player* current = head; current; current = current->next) {
    printf("%s's score is %d\n", current->name, current->score);
  }
}

int main() {
  Player* head = NULL;
  addPlayer(head, "John");
  addPlayer(head, "Mary");
  addPlayer(head, "Bob");
  addPlayer(head, "Alice");

  startGame(head);

  return 0;
}
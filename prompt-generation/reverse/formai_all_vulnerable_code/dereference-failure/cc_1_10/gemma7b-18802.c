//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* head = NULL;

void addPlayer() {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  newPlayer->next = head;
  head = newPlayer;
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

  return;
}

void updateScores() {
  time_t t = time(NULL);
  int i = 0;

  for (Player* current = head; current; current++) {
    current->score = rand() % 100;
    fprintf(stderr, "%s: %d\n", current->name, current->score);
  }

  fprintf(stderr, "\nTime elapsed: %d seconds\n", t);
}

int main() {
  addPlayer();
  addPlayer();
  addPlayer();

  updateScores();

  removePlayer("Player 2");

  updateScores();

  return 0;
}
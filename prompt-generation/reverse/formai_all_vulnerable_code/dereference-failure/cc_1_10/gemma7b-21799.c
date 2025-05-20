//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void joinGame(Player** head) {
  Player* newPlayer = malloc(sizeof(Player));
  printf("Enter your name: ");
  scanf("%s", newPlayer->name);
  newPlayer->score = 0;
  newPlayer->next = NULL;

  if (*head == NULL) {
    *head = newPlayer;
  } else {
    (*head)->next = newPlayer;
  }
}

void showPlayers(Player* head) {
  printf("Players in the game:\n");
  while (head) {
    printf("%s (Score: %d)\n", head->name, head->score);
    head = head->next;
  }
}

int main() {
  Player* head = NULL;
  int numPlayers = 0;

  printf("Welcome to the C HTML Beautifier!\n");
  printf("Enter the number of players: ");
  scanf("%d", &numPlayers);

  for (int i = 0; i < numPlayers; i++) {
    joinGame(&head);
  }

  showPlayers(head);

  return 0;
}
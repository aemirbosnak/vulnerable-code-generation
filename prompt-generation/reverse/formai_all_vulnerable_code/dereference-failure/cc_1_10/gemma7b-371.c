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

Player* createPlayer(char* name, int score) {
  Player* player = malloc(sizeof(Player));
  strcpy(player->name, name);
  player->score = score;
  player->next = NULL;
  return player;
}

void addPlayer(Player** head, char* name, int score) {
  Player* newPlayer = createPlayer(name, score);
  if (*head == NULL) {
    *head = newPlayer;
  } else {
    (*head)->next = newPlayer;
  }
}

void printPlayers(Player* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->score);
    head = head->next;
  }
}

int main() {
  Player* head = NULL;
  int numPlayers = 0;

  // Join the game
  printf("Enter your name: ");
  char name[20];
  scanf("%s", name);

  // Create a new player
  addPlayer(&head, name, 0);
  numPlayers++;

  // Invite other players
  for (int i = 0; i < MAX_Players - 1; i++) {
    printf("Enter the name of the next player: ");
    scanf("%s", name);

    // Create a new player
    addPlayer(&head, name, 0);
    numPlayers++;
  }

  // Print the players
  printPlayers(head);

  return 0;
}
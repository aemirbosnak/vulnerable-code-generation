//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 10

typedef struct Player {
  char name[20];
  int id;
  struct Player* next;
} Player;

void joinGame(Player** head, char* name) {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->id = (*head)->id + 1;
  newPlayer->next = NULL;

  if (*head == NULL) {
    *head = newPlayer;
  } else {
    ((*head)->next = newPlayer);
  }
}

void displayPlayers(Player* head) {
  Player* current = head;
  while (current) {
    printf("%s (ID: %d)\n", current->name, current->id);
    current = current->next;
  }
}

int main() {
  Player* head = NULL;

  // Multiplayer loop
  while (1) {
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    joinGame(&head, name);

    displayPlayers(head);

    printf("Press any key to continue...");
    getchar();
  }

  return 0;
}
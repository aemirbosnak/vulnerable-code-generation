//Gemma-7B DATASET v1.0 Category: System administration ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void initialize_game(Player** head) {
  *head = NULL;
  for (int i = 0; i < MAX_Players; i++) {
    *head = malloc(sizeof(Player));
    (*head)->name[0] = '\0';
    (*head)->score = 0;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void join_game(Player** head, char* name) {
  Player* new_player = malloc(sizeof(Player));
  strcpy(new_player->name, name);
  new_player->score = 0;
  new_player->next = NULL;

  if (*head == NULL) {
    *head = new_player;
  } else {
    (*head)->next = new_player;
  }
  *head = new_player;
}

void start_game(Player** head) {
  // Implement game logic here
  for (Player* player = head; player; player = player->next) {
    printf("%s, your turn!", player->name);
  }
}

int main() {
  Player* head = NULL;

  initialize_game(&head);

  join_game(&head, "John");
  join_game(&head, "Mary");
  join_game(&head, "Bob");
  join_game(&head, "Alice");

  start_game(&head);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: System administration ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

struct Player {
  char name[20];
  int score;
  int online;
  struct Player* next;
};

void initialize_game(struct Player** head) {
  *head = NULL;
  for (int i = 0; i < MAX_Players; i++) {
    struct Player* new_player = malloc(sizeof(struct Player));
    new_player->name[0] = '\0';
    new_player->score = 0;
    new_player->online = 0;
    new_player->next = NULL;
    if (*head == NULL) {
      *head = new_player;
    } else {
      ((*head)->next = new_player)->next = new_player;
    }
  }
}

void join_game(struct Player** head, char* name) {
  struct Player* new_player = malloc(sizeof(struct Player));
  new_player->name[0] = '\0';
  new_player->score = 0;
  new_player->online = 1;
  new_player->next = NULL;
  for (struct Player* player = *head; player; player = player->next) {
    if (strcmp(player->name, name) == 0) {
      return;
    }
  }
  if (*head == NULL) {
    *head = new_player;
  } else {
    ((*head)->next = new_player)->next = new_player;
  }
}

void print_players(struct Player* head) {
  for (struct Player* player = head; player; player = player->next) {
    printf("%s (%d) - Online: %d\n", player->name, player->score, player->online);
  }
}

int main() {
  struct Player* head = NULL;
  initialize_game(&head);
  join_game(&head, "John");
  join_game(&head, "Alice");
  join_game(&head, "Bob");
  join_game(&head, "Charlie");
  print_players(head);
  return 0;
}
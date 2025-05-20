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

void init_game(Player** head) {
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
  for (Player* p = *head; p; p = p->next) {
    if (strcmp(p->name, name) == 0) {
      return;
    }
  }

  *head = malloc(sizeof(Player));
  (*head)->name[0] = '\0';
  strcpy((*head)->name, name);
  (*head)->score = 0;
  (*head)->next = NULL;
  head = &((*head)->next);
  *head = NULL;
}

void play_game(Player** head) {
  for (Player* p = *head; p; p = p->next) {
    printf("%s: %d\n", p->name, p->score);
  }
}

int main() {
  Player* head = NULL;
  init_game(&head);
  join_game(&head, "John");
  join_game(&head, "Mary");
  join_game(&head, "Bob");
  play_game(&head);

  return 0;
}
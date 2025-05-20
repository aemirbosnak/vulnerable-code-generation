//Gemma-7B DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Players 4

struct Player {
  int score;
  char name[20];
  int is_active;
  struct Player* next;
};

void initialize_players(struct Player** head) {
  *head = NULL;
  for (int i = 0; i < MAX_Players; i++) {
    struct Player* new_player = malloc(sizeof(struct Player));
    new_player->score = 0;
    strcpy(new_player->name, "");
    new_player->is_active = 1;
    new_player->next = *head;
    *head = new_player;
  }
}

void display_players(struct Player* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->score);
    head = head->next;
  }
}

int main() {
  struct Player* head = NULL;
  initialize_players(&head);

  // Simulate some game rounds
  for (int i = 0; i < 10; i++) {
    // Randomly select two players
    struct Player* player1 = head->next;
    struct Player* player2 = head->next->next;

    // Have player1 increase their score
    player1->score++;

    // Have player2 decrease their score
    player2->score--;
  }

  display_players(head);

  return 0;
}
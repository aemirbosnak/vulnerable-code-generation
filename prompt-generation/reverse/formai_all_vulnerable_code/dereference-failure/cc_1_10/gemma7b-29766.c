//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void join_game(Player** head) {
  Player* new_player = (Player*)malloc(sizeof(Player));
  printf("Enter your name: ");
  scanf("%s", new_player->name);
  new_player->score = 0;
  new_player->next = NULL;

  if (*head == NULL) {
    *head = new_player;
  } else {
    (*head)->next = new_player;
  }
}

void play_game(Player* head) {
  Player* current_player = head;

  while (current_player) {
    printf("Your turn, %s: ", current_player->name);
    int choice = scanf("Enter your choice (1-3): ");

    switch (choice) {
      case 1:
        current_player->score++;
        printf("You have won a point!\n");
        break;
      case 2:
        current_player->score--;
        printf("You have lost a point.\n");
        break;
      case 3:
        printf("You have chosen to pass.\n");
        break;
      default:
        printf("Invalid choice.\n");
    }

    current_player = current_player->next;
  }

  printf("Game over!\n");
  for (current_player = head; current_player; current_player = current_player->next) {
    printf("%s's score: %d\n", current_player->name, current_player->score);
  }
}

int main() {
  Player* head = NULL;

  // Join the game
  join_game(&head);

  // Play the game
  play_game(head);

  return 0;
}
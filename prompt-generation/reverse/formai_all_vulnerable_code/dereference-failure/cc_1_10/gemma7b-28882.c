//Gemma-7B DATASET v1.0 Category: Data mining ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void join_game(Player** head) {
  Player* new_player = malloc(sizeof(Player));
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
    printf("%s's turn:\n", current_player->name);
    int guess_number;
    printf("Enter your guess: ");
    scanf("%d", &guess_number);

    // Check if the guess is correct
    if (guess_number == current_player->score) {
      printf("Congratulations! You win!\n");
      current_player->score++;
    } else {
      printf("Sorry, your guess is incorrect.\n");
    }

    current_player = current_player->next;
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
//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

Player* head = NULL;

void addPlayer() {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  printf("Enter your name: ");
  scanf("%s", newPlayer->name);
  newPlayer->score = 0;
  newPlayer->next = NULL;

  if (head == NULL) {
    head = newPlayer;
  } else {
    head->next = newPlayer;
    head = newPlayer;
  }
}

void playGame() {
  int numPlayers = 0;
  Player* currentPlayer = head;

  while (currentPlayer) {
    printf("Current Player: %s\n", currentPlayer->name);
    printf("Enter your move: ");
    char move = getchar();

    switch (move) {
      case 'w':
        currentPlayer->score++;
        printf("You moved forward and scored a point!\n");
        break;
      case 'a':
        currentPlayer->score--;
        printf("You moved left and lost a point!\n");
        break;
      case 's':
        currentPlayer->score += 2;
        printf("You moved back and scored two points!\n");
        break;
      case 'd':
        currentPlayer->score -= 2;
        printf("You moved right and lost two points!\n");
        break;
      default:
        printf("Invalid move!\n");
    }

    numPlayers++;
    currentPlayer = currentPlayer->next;
  }

  printf("Game Over! The winner is: %s\n", head->name);
  printf("The final score is: %d\n", head->score);
}

int main() {
  addPlayer();
  addPlayer();
  addPlayer();
  addPlayer();

  playGame();

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void initGame(Player** head) {
  *head = NULL;
}

void addPlayer(Player** head, char* name) {
  Player* newPlayer = malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->score = 0;
  newPlayer->next = NULL;

  if (*head == NULL) {
    *head = newPlayer;
  } else {
    (*head)->next = newPlayer;
  }
}

void playGame(Player* head) {
  // Implement game logic here
  while (head) {
    printf("%s's turn: ", head->name);
    int roll = rand() % 6 + 1;
    head->score += roll;
    printf("Roll: %d, Score: %d\n", roll, head->score);
    head = head->next;
  }
}

int main() {
  Player* head = NULL;
  initGame(&head);

  // Add players
  addPlayer(&head, "John");
  addPlayer(&head, "Mary");
  addPlayer(&head, "Bob");
  addPlayer(&head, "Alice");

  // Play the game
  playGame(head);

  // Print final scores
  printf("Final Scores:\n");
  head = head->next;
  while (head) {
    printf("%s: %d\n", head->name, head->score);
    head = head->next;
  }

  return 0;
}
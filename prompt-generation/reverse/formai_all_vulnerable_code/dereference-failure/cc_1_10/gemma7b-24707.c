//Gemma-7B DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 25
#define MAX_GAME_LENGTH 10

typedef struct Game {
  char name[MAX_NAME_LENGTH];
  int score;
  struct Game* next;
} Game;

void CreateGame(Game** head) {
  *head = malloc(sizeof(Game));
  (*head)->name[0] = '\0';
  (*head)->score = 0;
  (*head)->next = NULL;
}

void AddGame(Game** head, char* name, int score) {
  Game* newGame = malloc(sizeof(Game));
  strcpy(newGame->name, name);
  newGame->score = score;
  newGame->next = NULL;

  if (*head) {
    (*head)->next = newGame;
  } else {
    *head = newGame;
  }
}

void PrintGames(Game* head) {
  while (head) {
    printf("%s - %d\n", head->name, head->score);
    head = head->next;
  }
}

int main() {
  Game* head = NULL;

  CreateGame(&head);
  AddGame(&head, "John Doe", 100);
  AddGame(&head, "Jane Doe", 200);
  AddGame(&head, "Peter Pan", 300);

  PrintGames(head);

  return 0;
}
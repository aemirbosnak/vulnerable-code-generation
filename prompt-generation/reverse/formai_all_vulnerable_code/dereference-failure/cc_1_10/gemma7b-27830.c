//Gemma-7B DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Players 2

typedef struct Player {
  char name[20];
  int score;
  struct Node* next;
} Player;

typedef struct Node {
  Player* player;
  struct Node* next;
} Node;

void initGame(Node** head) {
  *head = NULL;
  for (int i = 0; i < MAX_Players; i++) {
    Player* player = malloc(sizeof(Player));
    player->name[0] = '\0';
    player->score = 0;
    player->next = NULL;

    Node* node = malloc(sizeof(Node));
    node->player = player;
    node->next = NULL;

    if (*head == NULL) {
      *head = node;
    } else {
      (*head)->next = node;
      *head = node;
    }
  }
}

void playRound(Node* head) {
  for (Node* node = head; node; node = node->next) {
    printf("%s's turn:\n", node->player->name);
    int roll = rand() % 6 + 1;
    node->player->score += roll;
    printf("You rolled a %d and your score is now %d.\n", roll, node->player->score);
  }
}

int main() {
  Node* head = NULL;
  initGame(&head);
  playRound(head);
  return 0;
}
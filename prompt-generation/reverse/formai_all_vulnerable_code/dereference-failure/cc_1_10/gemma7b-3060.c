//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4

typedef struct Player {
  char name[20];
  int score;
  struct Node* next;
} Player;

typedef struct Node {
  Player* player;
  struct Node* next;
} Node;

Node* head = NULL;

void addPlayer(char* name) {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  strcpy(newPlayer->name, name);
  newPlayer->score = 0;
  newPlayer->next = NULL;

  if (head == NULL) {
    head = (Node*)malloc(sizeof(Node));
    head->player = newPlayer;
    head->next = NULL;
  } else {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->player = newPlayer;
    newNode->next = NULL;
    head->next = newNode;
  }
}

void updateScore(char* name, int score) {
  Player* player = findPlayer(name);
  if (player) {
    player->score = score;
  }
}

int findPlayer(char* name) {
  Node* current = head;
  while (current) {
    if (strcmp(current->player->name, name) == 0) {
      return current->player;
    }
    current = current->next;
  }
  return NULL;
}

int main() {
  addPlayer("John");
  addPlayer("Jane");
  addPlayer("Jack");
  addPlayer("Jill");

  updateScore("John", 100);
  updateScore("Jane", 200);
  updateScore("Jack", 300);

  Player* player = findPlayer("Jack");
  printf("Player: %s, Score: %d\n", player->name, player->score);

  return 0;
}
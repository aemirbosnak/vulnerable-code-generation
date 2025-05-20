//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Players 5

struct Player {
  char name[20];
  int portfolio[100];
  int cash;
  int numStocks;
  int buySellFlag;
  int buySellTime;
  char buySellOrder[20];
  struct Player* next;
};

struct Player* createPlayer(char* name) {
  struct Player* newPlayer = malloc(sizeof(struct Player));
  strcpy(newPlayer->name, name);
  newPlayer->cash = 100000;
  newPlayer->numStocks = 0;
  newPlayer->buySellFlag = 0;
  newPlayer->buySellTime = 0;
  newPlayer->buySellOrder[0] = '\0';
  newPlayer->next = NULL;
  return newPlayer;
}

void addPlayer(struct Player* head, char* name) {
  struct Player* newPlayer = createPlayer(name);
  if (head == NULL) {
    head = newPlayer;
  } else {
    newPlayer->next = head;
    head = newPlayer;
  }
}

void printPlayers(struct Player* head) {
  struct Player* current = head;
  while (current) {
    printf("%s, Cash: %d, Stocks: %d\n", current->name, current->cash, current->numStocks);
    current = current->next;
  }
}

int main() {
  struct Player* head = NULL;
  addPlayer(head, "John");
  addPlayer(head, "Mary");
  addPlayer(head, "Bob");
  addPlayer(head, "Alice");
  addPlayer(head, "Tom");

  printPlayers(head);

  return 0;
}
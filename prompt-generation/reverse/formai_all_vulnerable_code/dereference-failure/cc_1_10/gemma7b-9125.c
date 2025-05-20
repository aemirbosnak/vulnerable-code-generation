//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int heartRate;
  int stepsTaken;
  int caloriesBurned;
} Player;

void initializePlayers(Player **players, int numPlayers) {
  for (int i = 0; i < numPlayers; i++) {
    players[i] = malloc(sizeof(Player));
    players[i]->name[0] = '\0';
    players[i]->heartRate = 0;
    players[i]->stepsTaken = 0;
    players[i]->caloriesBurned = 0;
  }
}

void calculateCalories(Player *player) {
  int minutes = player->stepsTaken / 10;
  player->caloriesBurned = minutes * 10;
}

void displayPlayerStatus(Player *player) {
  printf("Name: %s\n", player->name);
  printf("Heart Rate: %d\n", player->heartRate);
  printf("Steps Taken: %d\n", player->stepsTaken);
  printf("Calories Burned: %d\n", player->caloriesBurned);
  printf("\n");
}

int main() {
  int numPlayers;
  printf("Enter the number of players: ");
  scanf("%d", &numPlayers);

  Player **players = NULL;
  initializePlayers(&players, numPlayers);

  // Simulate some activity
  for (int i = 0; i < numPlayers; i++) {
    players[i]->heartRate = rand() % 120;
    players[i]->stepsTaken = rand() % 1000;
  }

  // Calculate calories burned for each player
  for (int i = 0; i < numPlayers; i++) {
    calculateCalories(players[i]);
  }

  // Display player status
  for (int i = 0; i < numPlayers; i++) {
    displayPlayerStatus(players[i]);
  }

  return 0;
}
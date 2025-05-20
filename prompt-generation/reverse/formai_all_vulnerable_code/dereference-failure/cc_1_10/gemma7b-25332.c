//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 99

void generateBingoCard(int **card, int numPlayers) {
  for (int i = 0; i < numPlayers; i++) {
    card[i] = (int *)malloc(sizeof(int) * MAX_NUM);
    for (int j = 0; j < MAX_NUM; j++) {
      card[i][j] = 0;
    }
  }
}

void playBingo(int **card, int numPlayers) {
  time_t t = time(NULL);
  srand(t);
  for (int i = 0; i < MAX_NUM; i++) {
    int num = rand() % MAX_NUM + 1;
    for (int j = 0; j < numPlayers; j++) {
      if (card[j][num] == 0) {
        card[j][num] = 1;
      }
    }
  }

  for (int i = 0; i < numPlayers; i++) {
    int wins = 0;
    for (int j = 0; j < MAX_NUM; j++) {
      if (card[i][j] == 1) {
        wins++;
      }
    }

    if (wins == MAX_NUM) {
      printf("Player %d won!\n", i);
    }
  }
}

int main() {
  int numPlayers = 5;
  int **card = NULL;

  generateBingoCard(card, numPlayers);
  playBingo(card, numPlayers);

  return 0;
}
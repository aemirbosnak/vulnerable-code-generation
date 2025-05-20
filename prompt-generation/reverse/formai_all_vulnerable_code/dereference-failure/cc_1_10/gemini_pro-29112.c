//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bingo card size
#define CARD_SIZE 5

// number of players
#define NUM_PLAYERS 4

// maximum number to be drawn
#define MAX_NUM 75

// function to generate a random number
int generateRandomNumber() {
  return rand() % MAX_NUM + 1;
}

// function to create a bingo card
int** createBingoCard() {
  int** card = (int**)malloc(CARD_SIZE * sizeof(int*));
  for (int i = 0; i < CARD_SIZE; i++) {
    card[i] = (int*)malloc(CARD_SIZE * sizeof(int));
    for (int j = 0; j < CARD_SIZE; j++) {
      card[i][j] = generateRandomNumber();
    }
  }
  return card;
}

// function to print a bingo card
void printBingoCard(int** card) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      printf("%d ", card[i][j]);
    }
    printf("\n");
  }
}

// function to check if a number is on a bingo card
int checkNumberOnCard(int** card, int number) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card[i][j] == number) {
        return 1;
      }
    }
  }
  return 0;
}

// function to check if a player has won bingo
int checkForBingo(int** card, int* numbersDrawn) {
  // check rows
  for (int i = 0; i < CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < CARD_SIZE; j++) {
      if (checkNumberOnCard(card, numbersDrawn[j])) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // check columns
  for (int i = 0; i < CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < CARD_SIZE; j++) {
      if (checkNumberOnCard(card, numbersDrawn[i + j * CARD_SIZE])) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // check diagonals
  int count = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (checkNumberOnCard(card, numbersDrawn[i + i * CARD_SIZE])) {
      count++;
    }
  }
  if (count == CARD_SIZE) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (checkNumberOnCard(card, numbersDrawn[i + (CARD_SIZE - 1 - i) * CARD_SIZE])) {
      count++;
    }
  }
  if (count == CARD_SIZE) {
    return 1;
  }

  return 0;
}

int main() {
  // initialize random number generator
  srand(time(NULL));

  // create bingo cards for each player
  int*** cards = (int***)malloc(NUM_PLAYERS * sizeof(int**));
  for (int i = 0; i < NUM_PLAYERS; i++) {
    cards[i] = createBingoCard();
  }

  // print bingo cards
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("Player %d's Bingo Card:\n", i + 1);
    printBingoCard(cards[i]);
    printf("\n");
  }

  // draw numbers until someone wins
  int numbersDrawn[MAX_NUM];
  int numDrawn = 0;
  while (numDrawn < MAX_NUM) {
    int number = generateRandomNumber();
    if (numbersDrawn[number] == 0) {
      numbersDrawn[number] = 1;
      numDrawn++;

      // check if any player has won
      for (int i = 0; i < NUM_PLAYERS; i++) {
        if (checkForBingo(cards[i], numbersDrawn)) {
          printf("Player %d has won!\n", i + 1);
          return 0;
        }
      }
    }
  }

  // no one won
  printf("No one won!\n");
  return 0;
}
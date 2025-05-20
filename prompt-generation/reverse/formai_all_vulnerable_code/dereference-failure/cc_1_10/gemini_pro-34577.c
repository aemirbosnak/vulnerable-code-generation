//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card size
#define CARD_SIZE 5

// Number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Function to generate a random number between 1 and 90
int generateRandomNumber() {
  return (rand() % 90) + 1;
}

// Function to create a new bingo card
int** createBingoCard() {
  int** card = (int**)malloc(sizeof(int*) * ROWS);
  for (int i = 0; i < ROWS; i++) {
    card[i] = (int*)malloc(sizeof(int) * COLS);
    for (int j = 0; j < COLS; j++) {
      card[i][j] = generateRandomNumber();
    }
  }
  return card;
}

// Function to print a bingo card
void printBingoCard(int** card) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", card[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is on the bingo card
int checkNumberOnCard(int** card, int number) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (card[i][j] == number) {
        return 1;
      }
    }
  }
  return 0;
}

// Function to mark a number on the bingo card
void markNumberOnCard(int** card, int number) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (card[i][j] == number) {
        card[i][j] = -1;
      }
    }
  }
}

// Function to check if a bingo card has won
int checkBingo(int** card) {
  // Check rows
  for (int i = 0; i < ROWS; i++) {
    int count = 0;
    for (int j = 0; j < COLS; j++) {
      if (card[i][j] == -1) {
        count++;
      }
    }
    if (count == COLS) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < COLS; j++) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
      if (card[i][j] == -1) {
        count++;
      }
    }
    if (count == ROWS) {
      return 1;
    }
  }

  // Check diagonals
  int count1 = 0;
  for (int i = 0; i < ROWS; i++) {
    if (card[i][i] == -1) {
      count1++;
    }
  }
  if (count1 == ROWS) {
    return 1;
  }

  int count2 = 0;
  for (int i = 0, j = ROWS - 1; i < ROWS; i++, j--) {
    if (card[i][j] == -1) {
      count2++;
    }
  }
  if (count2 == ROWS) {
    return 1;
  }

  return 0;
}

// Function to play bingo
void playBingo(int** card) {
  int number;
  while (!checkBingo(card)) {
    // Generate a random number
    number = generateRandomNumber();

    // Check if the number is on the card
    if (checkNumberOnCard(card, number)) {
      // Mark the number on the card
      markNumberOnCard(card, number);

      // Print the card
      printBingoCard(card);
    }
  }

  // Print the winning message
  printf("Bingo!\n");
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new bingo card
  int** card = createBingoCard();

  // Print the card
  printBingoCard(card);

  // Play bingo
  playBingo(card);

  return 0;
}
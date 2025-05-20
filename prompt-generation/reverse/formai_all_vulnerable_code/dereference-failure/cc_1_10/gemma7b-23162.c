//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Bingo Card structure
typedef struct BingoCard {
  int numbers[5][5];
  int freeSpaces[25];
  int wins;
  char name[20];
} BingoCard;

// Function to generate a Bingo card
BingoCard *generateBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));

  // Generate the numbers for the card
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      card->numbers[i][j] = rand() % 90 + 1;
    }
  }

  // Calculate the free spaces
  for (int i = 0; i < 25; i++) {
    card->freeSpaces[i] = 1;
  }

  // Reset wins and name
  card->wins = 0;
  card->name[0] = '\0';

  return card;
}

// Function to mark a number on a Bingo card
void markNumber(BingoCard *card, int number) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (card->numbers[i][j] == number) {
        card->freeSpaces[i * 5 + j] = 0;
      }
    }
  }
}

// Function to check if a Bingo card has won
int hasWon(BingoCard *card) {
  // Check rows
  for (int i = 0; i < 5; i++) {
    if (card->freeSpaces[i * 5] == 0) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < 5; j++) {
    if (card->freeSpaces[j] == 0) {
      return 1;
    }
  }

  // Check diagonals
  if (card->freeSpaces[0] == 0 && card->freeSpaces[6] == 0) {
    return 1;
  }

  return 0;
}

// Main game loop
int main() {
  // Create a list of Bingo cards
  BingoCard *cards[10];

  // Generate the cards
  for (int i = 0; i < 10; i++) {
    cards[i] = generateBingoCard();
  }

  // Draw the numbers
  for (int i = 0; i < 100; i++) {
    int number = rand() % 90 + 1;

    // Mark the number on each card
    for (int j = 0; j < 10; j++) {
      markNumber(cards[j], number);
    }

    // Check if any card has won
    for (int j = 0; j < 10; j++) {
      if (hasWon(cards[j])) {
        cards[j]->wins++;
        printf("%s has won!\n", cards[j]->name);
      }
    }
  }

  return 0;
}
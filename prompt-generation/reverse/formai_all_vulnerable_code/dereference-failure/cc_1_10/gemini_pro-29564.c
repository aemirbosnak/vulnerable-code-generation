//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Clean up the terminal
void clearScreen(void) {
  #ifdef __linux__
    system("clear");
  #endif
  #ifdef _WIN32
    system("cls");
  #endif
}
// Display the Welcome message
void welcomeMessage(void) {
  printf("Welcome to the Grateful Bingo Simulator!\n");
  printf("--------------------------------------\n");
  printf("May fortune smile upon your virtual cards!\n");
}
// Generate a random number between min and max
int randomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}
// Create a bingo card with random numbers
int** createBingoCard(int rows, int columns) {
  int** bingoCard = malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    bingoCard[i] = malloc(columns * sizeof(int));
    for (int j = 0; j < columns; j++) {
      bingoCard[i][j] = randomNumber(1, 99);
    }
  }
  return bingoCard;
}
// Display the bingo card
void displayBingoCard(int** bingoCard, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%2d ", bingoCard[i][j]);
    }
    printf("\n");
  }
}
// Check if the number is present on a row
int checkRow(int** bingoCard, int row, int number) {
  for (int i = 0; i < 5; i++) {
    if (bingoCard[row][i] == number) {
      return 1;
    }
  }
  return 0;
}
// Check if the number is present on a column
int checkColumn(int** bingoCard, int column, int number) {
  for (int i = 0; i < 5; i++) {
    if (bingoCard[i][column] == number) {
      return 1;
    }
  }
  return 0;
}
// Check if the number is present on the main diagonal
int checkMainDiagonal(int** bingoCard, int number) {
  for (int i = 0; i < 5; i++) {
    if (bingoCard[i][i] == number) {
      return 1;
    }
  }
  return 0;
}
// Check if the number is present on the secondary diagonal
int checkSecondaryDiagonal(int** bingoCard, int number) {
  for (int i = 0; i < 5; i++) {
    if (bingoCard[i][4 - i] == number) {
      return 1;
    }
  }
  return 0;
}
// Check if the number is present on the bingo card
int checkBingoCard(int** bingoCard, int number) {
  for (int i = 0; i < 5; i++) {
    if (checkRow(bingoCard, i, number) || checkColumn(bingoCard, i, number) || checkMainDiagonal(bingoCard, number) || checkSecondaryDiagonal(bingoCard, number)) {
      return 1;
    }
  }
  return 0;
}
// Play a round of bingo
void playBingo(int** bingoCard) {
  int number;
  while (1) {
    number = randomNumber(1, 99);
    clearScreen();
    printf("The drawn number is: %d\n", number);
    if (checkBingoCard(bingoCard, number)) {
      printf("Congratulations! You have a BINGO!\n");
      break;
    } else {
      printf("Keep playing!\n");
    }
    displayBingoCard(bingoCard, 5, 5);
  }
}
// Free the allocated memory
void freeBingoCard(int** bingoCard, int rows) {
  for (int i = 0; i < rows; i++) {
    free(bingoCard[i]);
  }
  free(bingoCard);
}
// Main function
int main() {
  srand(time(NULL));
  welcomeMessage();
  int** bingoCard = createBingoCard(5, 5);
  displayBingoCard(bingoCard, 5, 5);
  playBingo(bingoCard);
  freeBingoCard(bingoCard, 5);
  return 0;
}
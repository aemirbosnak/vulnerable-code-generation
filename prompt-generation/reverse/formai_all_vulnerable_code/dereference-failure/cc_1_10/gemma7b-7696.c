//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

int main() {

  // Create a 5x5 grid of numbers
  int **bingoCard = malloc(5 * sizeof(int *)), i, j;
  for (i = 0; i < 5; i++) {
    bingoCard[i] = malloc(5 * sizeof(int));
  }

  // Fill the grid with random numbers
  srand(time(NULL));
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      bingoCard[i][j] = rand() % 90 + 1;
    }
  }

  // Create a list of called numbers
  int calledNumbers[90] = {0};

  // Simulate the bingo game
  int rounds = 0;
  while (!isBingo(bingoCard, calledNumbers)) {
    // Call a number
    calledNumbers[rand() % 90] = 1;

    // Increment the round number
    rounds++;
  }

  // Print the winning card
  printf("Winner! Round %d\n", rounds);
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%d ", bingoCard[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (i = 0; i < 5; i++) {
    free(bingoCard[i]);
  }
  free(bingoCard);

  return 0;
}

int isBingo(int **bingoCard, int calledNumbers[]) {
  // Check if the caller has won a row or column
  for (int i = 0; i < 5; i++) {
    // Check if the caller has won a row
    for (int j = 0; j < 5; j++) {
      if (bingoCard[i][j] == calledNumbers[j]) {
        return 1;
      }
    }

    // Check if the caller has won a column
    for (int j = 0; j < 5; j++) {
      if (bingoCard[j][i] == calledNumbers[j]) {
        return 1;
      }
    }
  }

  // Check if the caller has won the diagonal
  if (bingoCard[0][0] == calledNumbers[0] && bingoCard[2][2] == calledNumbers[0]) {
    return 1;
  }

  // If the caller has not won, return 0
  return 0;
}
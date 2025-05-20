//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shock_bingo(int **board, int rows, int cols) {
  int i, j, num, rand_num;
  time_t t;

  t = time(NULL);
  srand(t);

  // Generate a random number between 1 and 9
  rand_num = rand() % 9 + 1;

  // Mark the number on the card
  board[rows][cols] = rand_num;

  // Print the number
  printf("Number drawn: %d\n", rand_num);

  // Check if the number is the winner
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (board[i][j] == rand_num) {
        printf("You won!\n");
        return;
      }
    }
  }

  // If no winner, print the next number
  printf("Next number: %d\n", rand_num);
}

int main() {
  int rows, cols, num_players;

  // Get the number of rows, columns, and players
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  printf("Enter the number of players: ");
  scanf("%d", &num_players);

  // Create the bingo card
  int **board = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    board[i] = (int *)malloc(cols * sizeof(int));
  }

  // Play the game
  for (int i = 0; i < num_players; i++) {
    shock_bingo(board, rows, cols);
  }

  // Free the memory
  for (int i = 0; i < rows; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}
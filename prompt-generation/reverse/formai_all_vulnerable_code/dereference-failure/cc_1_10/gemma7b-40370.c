//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_bingo_card(int **card, int rows, int cols)
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      card[r][c] = rand() % 90 + 1;
    }
  }
}

int main()
{
  int rows = 5;
  int cols = 5;
  int **card = NULL;

  // Allocate memory for the bingo card
  card = (int**)malloc(rows * sizeof(int*));
  for (int r = 0; r < rows; r++)
  {
    card[r] = (int*)malloc(cols * sizeof(int));
  }

  // Draw the bingo card
  draw_bingo_card(card, rows, cols);

  // Print the bingo card
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      printf("%d ", card[r][c]);
    }
    printf("\n");
  }

  // Free the memory allocated for the bingo card
  for (int r = 0; r < rows; r++)
  {
    free(card[r]);
  }
  free(card);

  return 0;
}
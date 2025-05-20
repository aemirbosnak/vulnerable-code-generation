//Gemma-7B DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_board(int **board, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      board[i][j] = 0;
    }
  }
}

void place_piece(int **board, int size, int player, int x, int y)
{
  if (board[x][y] == 0 && x >= 0 && x < size && y >= 0 && y < size)
  {
    board[x][y] = player;
  }
}

int check_win(int **board, int size, int player)
{
  for (int i = 0; i < size; i++)
  {
    // Check for win in rows
    for (int j = 0; j < size; j++)
    {
      if (board[i][j] == player && board[i][j] == board[i][j-1] && board[i][j] == board[i][j-2] && board[i][j] == board[i][j-3])
      {
        return 1;
      }
    }

    // Check for win in columns
    for (int j = 0; j < size; j++)
    {
      if (board[j][0] == player && board[j][1] == player && board[j][2] == player && board[j][3] == player)
      {
        return 1;
      }
    }

    // Check for win in diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player)
    {
      return 1;
    }

    // Check for win in reverse diagonals
    if (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player)
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  int size = 4;
  int board[size][size];
  initialize_board(board, size);

  int player = 1;
  int x, y;

  while (!check_win(board, size, player) && board[x][y] == 0)
  {
    printf("Enter the coordinates (x, y): ");
    scanf("%d %d", &x, &y);
    place_piece(board, size, player, x, y);
    player = (player == 1) ? 2 : 1;
  }

  if (check_win(board, size, player))
  {
    printf("Congratulations! You won!");
  }
  else
  {
    printf("It's a draw!");
  }

  return 0;
}
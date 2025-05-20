//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>

void display_board(char board[3][3]);
void player_move(char board[3][3], int player);
int check_win(char board[3][3]);
int check_draw(char board[3][3]);

int main()
{
   char board[3][3] = { {'.', '.', '.'},
                        {'.', '.', '.'},
                        {'.', '.', '.'} };
   int player = 1, winner = 0;

   printf("Welcome to Tic Tac Toe!\n");

   do {
      display_board(board);
      player_move(board, player);
      winner = check_win(board);

      if (winner == 0)
      {
         player = (player == 1) ? 2 : 1;
      }
   } while (winner == 0 && check_draw(board) == 0);

   display_board(board);

   if (winner == 1)
   {
      printf("Player 1 wins!\n");
   }
   else if (winner == 2)
   {
      printf("Player 2 wins!\n");
   }
   else
   {
      printf("Draw!\n");
   }

   return 0;
}

void display_board(char board[3][3])
{
   printf("\n\n");
   printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
   printf("-----------\n");
   printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
   printf("-----------\n");
   printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

void player_move(char board[3][3], int player)
{
   int row, col;

   printf("Player %d, enter your move (row col): ", player);
   scanf("%d %d", &row, &col);

   while (board[row][col] != '.')
   {
      printf("Invalid move. Please try again.\n");
      printf("Player %d, enter your move (row col): ", player);
      scanf("%d %d", &row, &col);
   }

   board[row][col] = (player == 1) ? 'X' : 'O';
}

int check_win(char board[3][3])
{
   int i;

   // check rows
   for (i = 0; i < 3; i++)
   {
      if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
      {
         return (board[i][0] == 'X') ? 1 : 2;
      }
   }

   // check columns
   for (i = 0; i < 3; i++)
   {
      if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
      {
         return (board[0][i] == 'X') ? 1 : 2;
      }
   }

   // check diagonals
   if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
   {
      return (board[0][0] == 'X') ? 1 : 2;
   }

   if (board[2][0] != '.' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
   {
      return (board[2][0] == 'X') ? 1 : 2;
   }

   return 0;
}

int check_draw(char board[3][3])
{
   int row, col;

   for (row = 0; row < 3; row++)
   {
      for (col = 0; col < 3; col++)
      {
         if (board[row][col] == '.')
         {
            return 0;
         }
      }
   }

   return 1;
}
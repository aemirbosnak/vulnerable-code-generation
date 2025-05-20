//FormAI DATASET v1.0 Category: Chess engine ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the size of the chess board
#define SIZE 8

// Define function prototypes
void initialize_board(char board[SIZE][SIZE]);
void display_board(char board[SIZE][SIZE]);
void move_piece(char board[SIZE][SIZE], int current_pos[2], int new_pos[2]);

// Define the main function
int main()
{
   // Declare and initialize variables and arrays
   char board[SIZE][SIZE];
   int i, j;
   int current_pos[2];
   int new_pos[2];

   // Initialize the chess board
   initialize_board(board);

   // Display the chess board
   display_board(board);

   // Get the current position of the piece
   printf("Enter the current position (row, column): ");
   scanf("%d %d", &current_pos[0], &current_pos[1]);

   // Get the new position of the piece
   printf("Enter the new position (row, column): ");
   scanf("%d %d", &new_pos[0], &new_pos[1]);

   // Move the piece on the chess board
   move_piece(board, current_pos, new_pos);

   // Display the updated chess board
   display_board(board);

   return 0;
}

// Define the function to initialize the chess board
void initialize_board(char board[SIZE][SIZE])
{
   int i, j;

   for(i = 0; i < SIZE; i++)
   {
      for(j = 0; j < SIZE; j++)
      {
         board[i][j] = '-';
      }
   }

   board[0][0] = 'R';
   board[0][1] = 'N';
   board[0][2] = 'B';
   board[0][3] = 'Q';
   board[0][4] = 'K';
   board[0][5] = 'B';
   board[0][6] = 'N';
   board[0][7] = 'R';

   for(i = 0; i < SIZE; i++)
   {
      board[1][i] = 'P';
      board[6][i] = 'p';
   }

   board[7][0] = 'r';
   board[7][1] = 'n';
   board[7][2] = 'b';
   board[7][3] = 'q';
   board[7][4] = 'k';
   board[7][5] = 'b';
   board[7][6] = 'n';
   board[7][7] = 'r';
}

// Define the function to display the chess board
void display_board(char board[SIZE][SIZE])
{
   int i, j;

   printf("\n");
   for(i = 0; i < SIZE; i++)
   {
      for(j = 0; j < SIZE; j++)
      {
         printf("%c ", board[i][j]);
      }
      printf("\n");
   }
}

// Define the function to move the piece on the chess board
void move_piece(char board[SIZE][SIZE], int current_pos[2], int new_pos[2])
{
   char temp = board[current_pos[0]][current_pos[1]];
   board[current_pos[0]][current_pos[1]] = '-';
   board[new_pos[0]][new_pos[1]] = temp;
}
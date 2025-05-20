//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 9

const int winningCombinations[8][3] = {
  {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
  {0, 3, 6},
  {1, 4, 7},
  {2, 5, 8},
  {0, 4, 8},
  {2, 4, 6}
};

void print_board(char board[]) {
  printf(" %c | %c | %c \n", board[0], board[1], board[2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[3], board[4], board[5]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

int is_valid_move(char board[], int position) {
  if (board[position] == ' ')
    return 1;
  
  return 0;
}

int is_game_over(char board[]) {
  int i, j;
  for (i = 0; i < 8; i++) {
    if (board[winningCombinations[i][0]] != ' ' &&
        board[winningCombinations[i][0]] == board[winningCombinations[i][1]] &&
        board[winningCombinations[i][0]] == board[winningCombinations[i][2]])
      return 1;
  }
  
  for (i = 0; i < 9; i++)
    if (board[i] == ' ')
      return 0;

  return 2;
}

int minimax(char board[], int depth, int maximizingPlayer) {
  int i, score, max_score = -2, min_score = 2;
  int winner = is_game_over(board);

  if (winner != 0)
    return winner;

  if (depth == MAX_DEPTH)
    return 0;

  for (i = 0; i < 9; i++) {
    if (is_valid_move(board, i)) {
      board[i] = maximizingPlayer ? 'O' : 'X';
      score = minimax(board, depth + 1, !maximizingPlayer);
      board[i] = ' ';

      if (score > max_score)
        max_score = score;

      if (score < min_score)
        min_score = score;
    }
  }

  return maximizingPlayer ? max_score : min_score;
}

int get_best_move(char board[]) {
  int i, best_score = -2, score, move = -1;

  for (i = 0; i < 9; i++) {
    if (is_valid_move(board, i)) {
      board[i] = 'O';
      score = minimax(board, 0, 0);
      board[i] = ' ';
      
      if (score > best_score) {
        best_score = score;
        move = i;
      }
    }
  }

  return move;
}

int main() {
  char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  int playerMove, cpuMove, winner = 0;
  
  while (winner == 0) {
    printf("\n");
    print_board(board);
    printf("\n");

    printf("Enter your move (1-9): ");
    scanf("%d", &playerMove);
    playerMove--;

    if (!is_valid_move(board, playerMove)) {
      printf("Invalid move!\n");
      continue;
    }
      
    board[playerMove] = 'X';

    winner = is_game_over(board);
    if (winner != 0)
      break;

    cpuMove = get_best_move(board);
    printf("CPU move: %d\n", cpuMove + 1);
    board[cpuMove] = 'O';

    winner = is_game_over(board);
  }

  printf("\n");
  print_board(board);
  printf("\n");

  if (winner == 1)
    printf("Congratulations, you won!\n");
  else if (winner == 2)
    printf("It's a tie.\n");
  else
    printf("Sorry, the CPU won.\n");

  return 0;
}
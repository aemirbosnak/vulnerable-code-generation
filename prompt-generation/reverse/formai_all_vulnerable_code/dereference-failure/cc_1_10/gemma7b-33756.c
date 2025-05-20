//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(struct Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void playTicTacToeAI(char** board, int turn) {
  int move_made = 0;
  Node* head = NULL;

  // Generate move
  while (!move_made) {
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;

    // Check if move is valid
    if (board[x][y] == ' ' && head == NULL) {
      move_made = 1;
      head = createNode(x, y);
    }
  }

  // Make move
  board[head->x][head->y] = turn;
  head->next = NULL;
}

int main() {
  char** board = malloc(sizeof(char*) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = malloc(sizeof(char) * BOARD_SIZE);
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Seed random number generator
  srand(time(NULL));

  // Play game
  int turn = 'X';
  for (int i = 0; i < 9; i++) {
    playTicTacToeAI(board, turn);
    turn = (turn == 'X') ? 'O' : 'X';
  }

  // Print winner or draw
  if (board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
    board[1][0] == board[1][1] && board[1][0] == board[1][2] ||
    board[2][0] == board[2][1] && board[2][0] == board[2][2] ||
    board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
    board[0][1] == board[1][1] && board[0][1] == board[2][1] ||
    board[0][2] == board[1][2] && board[0][2] == board[2][2] ||
    board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
    board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    printf("Winner: %c\n", turn);
  } else {
    printf("Draw\n");
  }

  return 0;
}
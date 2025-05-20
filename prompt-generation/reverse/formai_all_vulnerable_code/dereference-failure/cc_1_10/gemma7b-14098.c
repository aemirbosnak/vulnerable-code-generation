//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insertNode(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void solveSudoku(int** board) {

  Node* head = NULL;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (board[i][j] == 0) {
        insertNode(head, i * MAX + j);
      }
    }
  }

  while (head) {
    int index = head->data;
    int row = index / MAX;
    int col = index % MAX;
    board[row][col] = 1;

    head = head->next;
  }
}

int main() {

  int board[MAX][MAX] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                           {6, 0, 0, 1, 9, 5, 0, 0, 0},
                           {0, 9, 8, 0, 0, 0, 0, 0, 0},
                           {8, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 4},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0}};

  solveSudoku(board);

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_SQUARE_LENGTH 10

struct Knight {
  char name[MAX_NAME_LENGTH];
  int square[MAX_SQUARE_LENGTH];
};

void initializeSquare(struct Knight *knight) {
  int i;
  for (i = 0; i < MAX_SQUARE_LENGTH; i++) {
    knight->square[i] = 0;
  }
}

void addToSquare(struct Knight *knight, int row, int col, int value) {
  if (row < 0 || row >= MAX_SQUARE_LENGTH || col < 0 || col >= MAX_SQUARE_LENGTH) {
    printf("Invalid coordinates! Knight not placed.\n");
    return;
  }
  knight->square[row * MAX_SQUARE_LENGTH + col] = value;
}

void printSquare(struct Knight *knight) {
  int i, j;
  for (i = 0; i < MAX_SQUARE_LENGTH; i++) {
    for (j = 0; j < MAX_SQUARE_LENGTH; j++) {
      if (knight->square[i * MAX_SQUARE_LENGTH + j] != 0) {
        printf("%d ", knight->square[i * MAX_SQUARE_LENGTH + j]);
      }
    }
    printf("\n");
  }
}

int main() {
  struct Knight knight;

  // Initialize square
  initializeSquare(&knight);

  // Add knight to square
  addToSquare(&knight, 3, 4, 5);
  addToSquare(&knight, 1, 2, 3);
  addToSquare(&knight, 2, 1, 4);

  // Print square
  printSquare(&knight);

  return 0;
}
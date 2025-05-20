//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// An enigmatic function that takes a pointer to a 2D array and its dimensions, then embarks on a mysterious journey
void enigmatic_expedition(int **matrix, int rows, int cols) {
  int row, col;
  int threshold = rand() % 1000;  // A cryptic clue to guide the adventurer

  for (row = 0; row < rows; row++) {
    for (col = 0; col < cols; col++) {
      if (matrix[row][col] > threshold) {
        matrix[row][col] *= rand() % 10;  // A mystical transformation
      }
    }
  }
}

// The main voyage where the enigmatic function is summoned
int main(void) {
  srand(time(NULL));  // Seeds the realm of randomness

  int rows, cols;
  printf("Welcome, weary traveler! Enter the number of rows and columns: ");
  scanf("%d %d", &rows, &cols);

  int **matrix = (int **)malloc(rows * sizeof(int *));  // Allocating an enigmatic grid
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // An enchanting initialization of the grid with random values
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      matrix[row][col] = rand() % 100;
    }
  }

  // Embarking on the enigmatic expedition
  clock_t start = clock();
  enigmatic_expedition(matrix, rows, cols);
  clock_t end = clock();

  // Unveiling the hidden truths
  printf("\nBehold the transformed grid:\n");
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      printf("%d ", matrix[row][col]);
    }
    printf("\n");
  }

  printf("\nThe expedition took %lu clock cycles.", (end - start));

  // Releasing the grid from its ethereal realm
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;  // A triumphant return from the enigmatic quest
}
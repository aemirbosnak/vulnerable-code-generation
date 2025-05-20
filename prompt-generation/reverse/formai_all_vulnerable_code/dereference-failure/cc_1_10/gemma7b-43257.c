//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct Cell {
  char **data;
  int rows;
  int cols;
} Cell;

Cell *create_cell(int rows, int cols) {
  Cell *cell = malloc(sizeof(Cell));
  cell->rows = rows;
  cell->cols = cols;
  cell->data = malloc(sizeof(char *) * rows);
  for (int r = 0; r < rows; r++) {
    cell->data[r] = malloc(sizeof(char *) * cols);
  }
  return cell;
}

void read_csv(Cell *cell, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return;
  }

  char line[MAX_LINES];
  int line_num = 0;
  while (fgets(line, MAX_LINES, fp) != NULL) {
    line_num++;
    char **cols = cell->data[line_num - 1] = malloc(sizeof(char *) * cell->cols);
    int col_num = 0;
    for (char *column = strtok(line, ","); column; column = strtok(NULL, ",")) {
      cols[col_num++] = strdup(column);
    }
  }

  fclose(fp);
}

int main() {
  Cell *cell = create_cell(5, 3);
  read_csv(cell, "data.csv");

  for (int r = 0; r < cell->rows; r++) {
    for (int c = 0; c < cell->cols; c++) {
      printf("%s ", cell->data[r][c]);
    }
    printf("\n");
  }

  return 0;
}
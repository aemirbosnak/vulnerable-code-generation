//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct CSV_ROW {
  char **cells;
  int num_cells;
} CSV_ROW;

CSV_ROW *read_csv(char *filename) {
  CSV_ROW *row = malloc(sizeof(CSV_ROW));
  row->cells = NULL;
  row->num_cells = 0;

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    char **cells = malloc((row->num_cells + 1) * sizeof(char *));
    cells[row->num_cells] = NULL;

    char *cell = strtok(line, ",");
    while (cell) {
      cells[row->num_cells++] = cell;
      cell = strtok(NULL, ",");
    }

    row->cells = cells;
  }

  fclose(fp);

  return row;
}

int main() {
  CSV_ROW *row = read_csv("data.csv");

  for (int i = 0; i < row->num_cells; i++) {
    printf("%s,", row->cells[i]);
  }

  printf("\n");

  free(row);

  return 0;
}
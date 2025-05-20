//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
  char **cols;
  int num_cols;
} CSVRow;

CSVRow *read_csv_row(char *line) {
  CSVRow *row = malloc(sizeof(CSVRow));
  row->cols = NULL;
  row->num_cols = 0;

  char *col = strtok(line, ",");
  while (col != NULL) {
    row->cols = realloc(row->cols, (row->num_cols + 1) * sizeof(char *));
    row->cols[row->num_cols] = strdup(col);
    row->num_cols++;
    col = strtok(NULL, ",");
  }

  return row;
}

void free_csv_row(CSVRow *row) {
  for (int i = 0; i < row->num_cols; i++) {
    free(row->cols[i]);
  }
  free(row->cols);
  free(row);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LEN];
  while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
    CSVRow *row = read_csv_row(line);
    for (int i = 0; i < row->num_cols; i++) {
      printf("%s\t", row->cols[i]);
    }
    printf("\n");
    free_csv_row(row);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
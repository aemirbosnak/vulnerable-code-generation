//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader_S {
  char **data;
  int rows;
  int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->data = malloc(rows * sizeof(char *));
  for (int r = 0; r < rows; r++) {
    reader->data[r] = malloc(cols * sizeof(char));
  }
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_free(CSV_Reader *reader) {
  for (int r = 0; r < reader->rows; r++) {
    free(reader->data[r]);
  }
  free(reader->data);
  free(reader);
}

int csv_reader_read(CSV_Reader *reader, char **line) {
  int cols = reader->cols;
  *line = malloc(cols * sizeof(char));
  for (int c = 0; c < cols; c++) {
    (*line)[c] = reader->data[reader->rows - 1][c];
  }
  return reader->rows++;
}

int main() {
  CSV_Reader *reader = csv_reader_init(MAX_ROWS, MAX_COLS);
  char **line = NULL;
  int i = 0;
  while (csv_reader_read(reader, line) > 0) {
    printf("Line %d: ", i);
    for (int c = 0; line[c] != '\0'; c++) {
      printf("%c ", line[c]);
    }
    printf("\n");
    i++;
  }
  csv_reader_free(reader);
  return 0;
}
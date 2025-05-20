//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
  char ***data;
  int rows;
  int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->rows = rows;
  reader->cols = cols;
  reader->data = malloc(sizeof(char ***) * rows);
  for (int r = 0; r < rows; r++) {
    reader->data[r] = malloc(sizeof(char **) * cols);
    for (int c = 0; c < cols; c++) {
      reader->data[r][c] = NULL;
    }
  }
  return reader;
}

void csv_reader_free(CSV_Reader *reader) {
  for (int r = 0; r < reader->rows; r++) {
    for (int c = 0; c < reader->cols; c++) {
      free(reader->data[r][c]);
    }
    free(reader->data[r]);
  }
  free(reader->data);
  free(reader);
}

void csv_reader_set_value(CSV_Reader *reader, int row, int col, char *value) {
  reader->data[row][col] = strdup(value);
}

char *csv_reader_get_value(CSV_Reader *reader, int row, int col) {
  return reader->data[row][col];
}

int main() {
  CSV_Reader *reader = csv_reader_init(5, 3);
  csv_reader_set_value(reader, 2, 1, "Donald Knuth");
  printf("%s\n", csv_reader_get_value(reader, 2, 1));
  csv_reader_free(reader);
  return 0;
}
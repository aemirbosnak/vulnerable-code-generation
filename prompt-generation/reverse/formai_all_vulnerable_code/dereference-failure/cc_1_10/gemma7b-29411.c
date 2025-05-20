//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
  char ***data;
  int rows;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char ***) * rows);
  for (int r = 0; r < rows; r++) {
    reader->data[r] = malloc(sizeof(char **) * cols);
    for (int c = 0; c < cols; c++) {
      reader->data[r][c] = NULL;
    }
  }
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_add_data(CSVReader *reader, char *data) {
  char **row = reader->data[reader->rows - 1];
  if (row == NULL) {
    reader->data = realloc(reader->data, sizeof(char ***) * (reader->rows + 1));
    reader->data[reader->rows - 1] = malloc(sizeof(char **) * reader->cols);
  }
  row[reader->cols - 1] = data;
  reader->rows++;
}

void csv_reader_free(CSVReader *reader) {
  for (int r = 0; r < reader->rows; r++) {
    for (int c = 0; c < reader->cols; c++) {
      free(reader->data[r][c]);
    }
    free(reader->data[r]);
  }
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader *reader = csv_reader_init(10, 20);
  csv_reader_add_data(reader, "John Doe");
  csv_reader_add_data(reader, "Jane Doe");
  csv_reader_add_data(reader, "Peter Pan");
  csv_reader_add_data(reader, "Mary Poppins");

  for (int r = 0; r < reader->rows; r++) {
    for (int c = 0; c < reader->cols; c++) {
      printf("%s ", reader->data[r][c]);
    }
    printf("\n");
  }

  csv_reader_free(reader);

  return 0;
}
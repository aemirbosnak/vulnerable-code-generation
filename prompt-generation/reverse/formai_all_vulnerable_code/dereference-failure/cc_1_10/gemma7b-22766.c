//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
  char **data;
  int rows;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * rows);
  for (int i = 0; i < rows; i++) {
    reader->data[i] = malloc(sizeof(char *) * cols);
  }
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_add_row(CSVReader *reader, char **values) {
  reader->data[reader->rows++] = values;
}

void csv_reader_free(CSVReader *reader) {
  for (int i = 0; i < reader->rows; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader *reader = csv_reader_init(5, 3);
  char **values = malloc(sizeof(char *) * 3);
  values[0] = "John Doe";
  values[1] = "New York";
  values[2] = "Software Engineer";
  csv_reader_add_row(reader, values);

  values = malloc(sizeof(char *) * 3);
  values[0] = "Jane Doe";
  values[1] = "Los Angeles";
  values[2] = "Teacher";
  csv_reader_add_row(reader, values);

  csv_reader_free(reader);

  return 0;
}
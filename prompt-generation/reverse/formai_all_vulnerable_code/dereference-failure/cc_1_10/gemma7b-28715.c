//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSVReader {
  char **data;
  int lines;
  int cols;
} CSVReader;

CSVReader* csv_reader_init(int lines, int cols) {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char*) * lines);
  for (int i = 0; i < lines; i++) {
    reader->data[i] = malloc(sizeof(char) * cols);
  }
  reader->lines = lines;
  reader->cols = cols;
  return reader;
}

void csv_reader_add_row(CSVReader* reader, char** row) {
  int i = reader->lines++;
  reader->data[i] = malloc(sizeof(char) * reader->cols);
  memcpy(reader->data[i], row, reader->cols * sizeof(char));
}

void csv_reader_print(CSVReader* reader) {
  for (int i = 0; i < reader->lines; i++) {
    for (int j = 0; j < reader->cols; j++) {
      printf("%s,", reader->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  CSVReader* reader = csv_reader_init(5, 3);
  char** row1 = {"John Doe", "New York", "123 Main St"};
  csv_reader_add_row(reader, row1);

  char** row2 = {"Jane Doe", "Los Angeles", "456 Oak Ave"};
  csv_reader_add_row(reader, row2);

  csv_reader_print(reader);

  free(reader->data);
  free(reader);

  return 0;
}
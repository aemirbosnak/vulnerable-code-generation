//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
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
    reader->data[i] = malloc(sizeof(char) * cols);
  }
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_add_data(CSVReader *reader, char **data) {
  for (int i = 0; i < reader->rows; i++) {
    for (int j = 0; j < reader->cols; j++) {
      reader->data[i][j] = data[i][j];
    }
  }
}

void csv_reader_print(CSVReader *reader) {
  for (int i = 0; i < reader->rows; i++) {
    for (int j = 0; j < reader->cols; j++) {
      printf("%s,", reader->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  CSVReader *reader = csv_reader_init(5, 3);
  char **data = malloc(sizeof(char *) * 5);
  for (int i = 0; i < 5; i++) {
    data[i] = malloc(sizeof(char) * 3);
  }
  data[0][0] = 'a';
  data[0][1] = 'b';
  data[0][2] = 'c';
  data[1][0] = 'd';
  data[1][1] = 'e';
  data[1][2] = 'f';
  csv_reader_add_data(reader, data);
  csv_reader_print(reader);
  free(data);
  free(reader);
  return 0;
}
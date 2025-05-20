//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
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

void csv_reader_free(CSVReader *reader) {
  for (int i = 0; i < reader->rows; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

int csv_reader_read(CSVReader *reader, char **line) {
  if (reader->rows == 0) {
    return -1;
  }
  int i = 0;
  line = malloc(sizeof(char) * (reader->cols + 1));
  for (int col = 0; col < reader->cols; col++) {
    line[i++] = reader->data[0][col];
  }
  line[i] = '\0';
  return 0;
}

int main() {
  CSVReader *reader = csv_reader_init(5, 3);
  reader->data[0][0] = 'a';
  reader->data[0][1] = 'b';
  reader->data[0][2] = 'c';
  reader->data[1][0] = 'd';
  reader->data[1][1] = 'e';
  reader->data[1][2] = 'f';

  char *line;
  csv_reader_read(reader, &line);
  printf("%s\n", line);

  csv_reader_free(reader);
  return 0;
}
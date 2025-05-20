//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 10
#define MAX_ROWS 100

typedef struct CSVReader {
  char **data;
  int numCols;
  int numRows;
} CSVReader;

CSVReader *csvReader_init(int numCols, int numRows) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * numRows);
  for (int r = 0; r < numRows; r++) {
    reader->data[r] = malloc(sizeof(char) * (numCols + 1));
  }
  reader->numCols = numCols;
  reader->numRows = numRows;
  return reader;
}

void csvReader_read(CSVReader *reader, char **line) {
  int i = 0;
  for (int col = 0; col < reader->numCols; col++) {
    reader->data[reader->numRows - 1][i++] = line[col + 1];
  }
  reader->numRows++;
}

void csvReader_finalize(CSVReader *reader) {
  for (int r = 0; r < reader->numRows; r++) {
    free(reader->data[r]);
  }
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader *reader = csvReader_init(5, 10);
  char **line = malloc(sizeof(char *) * 6);
  line[0] = 'a';
  line[1] = 'b';
  line[2] = 'c';
  line[3] = 'd';
  line[4] = 'e';
  line[5] = '\0';
  csvReader_read(reader, line);
  csvReader_read(reader, line);
  csvReader_finalize(reader);
  return 0;
}
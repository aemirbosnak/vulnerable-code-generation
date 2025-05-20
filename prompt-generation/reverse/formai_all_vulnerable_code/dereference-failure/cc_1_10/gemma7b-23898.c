//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
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

CSVReader *createCSVReader(int lines, int cols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * lines);
  for (int i = 0; i < lines; i++) {
    reader->data[i] = malloc(sizeof(char) * cols);
  }
  reader->lines = lines;
  reader->cols = cols;
  return reader;
}

void freeCSVReader(CSVReader *reader) {
  for (int i = 0; i < reader->lines; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader *reader = createCSVReader(5, 3);
  reader->data[0][0] = 'a';
  reader->data[0][1] = 'b';
  reader->data[0][2] = 'c';
  reader->data[1][0] = 'd';
  reader->data[1][1] = 'e';
  reader->data[1][2] = 'f';
  reader->data[2][0] = 'g';
  reader->data[2][1] = 'h';
  reader->data[2][2] = 'i';

  for (int i = 0; i < reader->lines; i++) {
    for (int j = 0; j < reader->cols; j++) {
      printf("%c ", reader->data[i][j]);
    }
    printf("\n");
  }

  freeCSVReader(reader);

  return 0;
}
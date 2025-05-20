//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSVReader {
  char **data;
  int numLines;
  int numCols;
} CSVReader;

CSVReader *csvReader_alloc(int numLines, int numCols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * numLines);
  for (int i = 0; i < numLines; i++) {
    reader->data[i] = malloc(sizeof(char) * numCols);
  }
  reader->numLines = numLines;
  reader->numCols = numCols;
  return reader;
}

void csvReader_free(CSVReader *reader) {
  for (int i = 0; i < reader->numLines; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

int csvReader_read(CSVReader *reader, char **line) {
  int lineNum = reader->numLines++;
  *line = malloc(sizeof(char) * MAX_COLS);
  int colsRead = 0;
  char ch;
  while ((ch = fgetc(stdin)) != '\n') {
    if (colsRead >= reader->numCols) {
      reader->numCols++;
      reader->data[lineNum] = realloc(reader->data[lineNum], sizeof(char) * reader->numCols);
    }
    (*line)[colsRead++] = ch;
  }
  (*line)[colsRead] = '\0';
  return lineNum;
}

int main() {
  CSVReader *reader = csvReader_alloc(MAX_LINES, MAX_COLS);
  char *line;
  int lineNum = csvReader_read(reader, &line);
  printf("Line %d: %s\n", lineNum, line);
  csvReader_free(reader);
  return 0;
}
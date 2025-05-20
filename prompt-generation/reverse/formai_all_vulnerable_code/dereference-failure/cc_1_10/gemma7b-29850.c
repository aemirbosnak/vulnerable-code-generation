//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct CSVReader {
  FILE *fp;
  char **lines;
  int numLines;
} CSVReader;

CSVReader *csvReader_init(char *filename) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fopen(filename, "r");
  reader->lines = NULL;
  reader->numLines = 0;

  return reader;
}

void csvReader_addLines(CSVReader *reader) {
  reader->lines = realloc(reader->lines, (reader->numLines + 1) * sizeof(char *));
  reader->lines[reader->numLines++] = malloc(MAX_LINES);
}

void csvReader_readLines(CSVReader *reader) {
  char line[MAX_LINES];

  while (fgets(line, MAX_LINES, reader->fp) != NULL) {
    csvReader_addLines(reader);
    strcpy(reader->lines[reader->numLines - 1], line);
  }
}

void csvReader_close(CSVReader *reader) {
  fclose(reader->fp);
  for (int i = 0; i < reader->numLines; i++) {
    free(reader->lines[i]);
  }
  free(reader->lines);
  free(reader);
}

int main() {
  CSVReader *reader = csvReader_init("data.csv");
  csvReader_readLines(reader);
  csvReader_close(reader);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

typedef struct CSVReader {
  FILE *fp;
  char **lines;
  int numLines;
  int lineSize;
} CSVReader;

CSVReader *csvReader_init(char *filename, int lines) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fopen(filename, "r");
  reader->lines = malloc(lines * sizeof(char *));
  reader->numLines = lines;
  reader->lineSize = 0;

  return reader;
}

void csvReader_readLines(CSVReader *reader) {
  char line[MAX_LINES];
  int i = 0;

  while (fgets(line, MAX_LINES, reader->fp) != NULL) {
    reader->lines[i] = strdup(line);
    i++;
  }

  reader->numLines = i;
}

void csvReader_free(CSVReader *reader) {
  fclose(reader->fp);
  free(reader->lines);
  free(reader);
}

int main() {
  CSVReader *reader = csvReader_init("data.csv", MAX_LINES);
  csvReader_readLines(reader);

  for (int i = 0; i < reader->numLines; i++) {
    printf("%s\n", reader->lines[i]);
  }

  csvReader_free(reader);

  return 0;
}
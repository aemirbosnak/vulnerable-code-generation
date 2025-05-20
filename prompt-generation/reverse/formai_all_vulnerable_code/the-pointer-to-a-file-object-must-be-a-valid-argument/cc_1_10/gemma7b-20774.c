//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct CSVReader {
  FILE *fp;
  char **lines;
  int numLines;
  int lineNum;
} CSVReader;

CSVReader *csvReaderCreate(const char *filename) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fopen(filename, "r");
  reader->lines = NULL;
  reader->numLines = 0;
  reader->lineNum = 0;

  return reader;
}

void csvReaderDestroy(CSVReader *reader) {
  fclose(reader->fp);
  free(reader->lines);
  free(reader);
}

void csvReaderReadNextLine(CSVReader *reader) {
  reader->lines = realloc(reader->lines, (reader->numLines + 1) * sizeof(char *));
  reader->lines[reader->numLines++] = strdup(fgets(NULL, MAX_LINES, reader->fp));
  reader->lineNum++;
}

char **csvReaderGetLine(CSVReader *reader, int lineNum) {
  if (lineNum < 0 || lineNum >= reader->numLines) {
    return NULL;
  }

  return reader->lines[lineNum];
}

int main() {
  CSVReader *reader = csvReaderCreate("example.csv");
  csvReaderReadNextLine(reader);
  char **line = csvReaderGetLine(reader, 0);
  printf("%s\n", line[0]);
  csvReaderDestroy(reader);

  return 0;
}
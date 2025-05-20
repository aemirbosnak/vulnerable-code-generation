//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

typedef struct CSVReader {
  FILE* file;
  char** data;
  int numLines;
  int numCols;
} CSVReader;

CSVReader* csvReader_init(char* filename) {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->file = fopen(filename, "r");
  reader->data = NULL;
  reader->numLines = 0;
  reader->numCols = 0;

  return reader;
}

void csvReader_read(CSVReader* reader) {
  char line[MAX_LINES];
  char** cols;
  int i, j;

  while (fgets(line, MAX_LINES, reader->file) != NULL) {
    reader->numLines++;

    cols = malloc((reader->numCols + 1) * sizeof(char*));
    for (i = 0; i <= reader->numCols; i++) {
      cols[i] = strdup(strtok(line, ","));
    }

    reader->data = realloc(reader->data, reader->numLines * sizeof(char*));
    reader->data[reader->numLines - 1] = cols;
  }

  reader->numCols++;
}

void csvReader_finalize(CSVReader* reader) {
  fclose(reader->file);
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader* reader = csvReader_init("example.csv");
  csvReader_read(reader);
  csvReader_finalize(reader);

  return 0;
}
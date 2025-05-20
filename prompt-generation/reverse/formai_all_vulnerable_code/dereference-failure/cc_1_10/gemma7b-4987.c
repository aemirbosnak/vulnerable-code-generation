//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
  FILE *file;
  char **buffer;
  int lines;
  int columns;
} CSVReader;

CSVReader *createCSVReader(char *filename) {
  CSVReader *reader = malloc(sizeof(CSVReader));

  reader->file = fopen(filename, "r");
  reader->buffer = NULL;
  reader->lines = 0;
  reader->columns = 0;

  return reader;
}

void readCSVLine(CSVReader *reader) {
  char **line = NULL;
  int lineSize = 0;

  reader->lines++;

  line = realloc(reader->buffer, reader->lines * MAX_BUFFER_SIZE);

  reader->buffer = line;

  fgets(line, MAX_BUFFER_SIZE, reader->file);

  char *column = strtok(line, ",");

  reader->columns = 0;

  while (column) {
    reader->columns++;
    column = strtok(NULL, ",");
  }
}

void destroyCSVReader(CSVReader *reader) {
  fclose(reader->file);
  free(reader->buffer);
  free(reader);
}

int main() {
  CSVReader *reader = createCSVReader("data.csv");

  readCSVLine(reader);

  printf("Number of lines: %d\n", reader->lines);
  printf("Number of columns: %d\n", reader->columns);

  destroyCSVReader(reader);

  return 0;
}
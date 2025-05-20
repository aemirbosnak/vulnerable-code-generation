//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
  FILE *fp;
  char **buffer;
  int capacity;
  int used;
} CSVReader;

CSVReader *csv_reader_init(char *filename) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fopen(filename, "r");
  reader->buffer = NULL;
  reader->capacity = 0;
  reader->used = 0;

  return reader;
}

void csv_reader_free(CSVReader *reader) {
  fclose(reader->fp);
  free(reader->buffer);
  free(reader);
}

int csv_reader_read(CSVReader *reader) {
  int n_cols = 0;
  char line[MAX_BUFFER_SIZE];

  // Read a line from the CSV file
  if (fgets(line, MAX_BUFFER_SIZE, reader->fp) == NULL) {
    return -1;
  }

  // Split the line into columns
  char *column = strtok(line, ",");
  while (column) {
    n_cols++;
    column = strtok(NULL, ",");
  }

  // Update the reader's capacity and used space
  if (n_cols > reader->capacity) {
    reader->capacity = n_cols;
    reader->buffer = realloc(reader->buffer, reader->capacity * sizeof(char *));
  }

  reader->used = n_cols;
  return n_cols;
}

int main() {
  CSVReader *reader = csv_reader_init("example.csv");
  int n_cols = csv_reader_read(reader);

  if (n_cols > 0) {
    // Process the columns
  }

  csv_reader_free(reader);

  return 0;
}
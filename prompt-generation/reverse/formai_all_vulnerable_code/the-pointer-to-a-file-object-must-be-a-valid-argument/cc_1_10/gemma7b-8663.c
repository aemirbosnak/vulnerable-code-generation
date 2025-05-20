//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1024
#define MAX_COLS 256

typedef struct CSVReader {
  FILE* file;
  int rows;
  int cols;
  char** data;
} CSVReader;

CSVReader* csv_reader_init(char* filename) {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->file = fopen(filename, "r");
  reader->rows = 0;
  reader->cols = 0;
  reader->data = NULL;

  return reader;
}

void csv_reader_free(CSVReader* reader) {
  fclose(reader->file);
  free(reader->data);
  free(reader);
}

int csv_reader_read(CSVReader* reader) {
  int nrows = reader->rows;
  char line[MAX_ROWS * MAX_COLS];

  if (fgets(line, MAX_ROWS * MAX_COLS, reader->file) == NULL) {
    return -1;
  }

  // Increment number of rows
  reader->rows++;

  // Allocate memory for data if necessary
  if (reader->data == NULL) {
    reader->data = malloc(sizeof(char*) * reader->rows);
  }

  // Store line in data
  reader->data[nrows] = strdup(line);

  return 0;
}

int main() {
  CSVReader* reader = csv_reader_init("example.csv");

  if (csv_reader_read(reader) == -1) {
    perror("Error reading CSV file");
    exit(1);
  }

  // Process data
  printf("%s\n", reader->data[0]);

  csv_reader_free(reader);

  return 0;
}
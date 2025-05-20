//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
  FILE* file_ptr;
  char** buffer;
  int rows, columns;
  int current_row, current_column;
} CSVReader;

CSVReader* csv_reader_init(char* file_path) {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->file_ptr = fopen(file_path, "r");
  reader->buffer = NULL;
  reader->rows = 0;
  reader->columns = 0;
  reader->current_row = -1;
  reader->current_column = -1;

  return reader;
}

void csv_reader_free(CSVReader* reader) {
  fclose(reader->file_ptr);
  free(reader->buffer);
  free(reader);
}

int csv_reader_read_next_row(CSVReader* reader) {
  char* line = NULL;
  int line_length = 0;

  if (reader->current_row == reader->rows - 1) {
    return 0;
  }

  reader->current_row++;

  line = fgets(line, MAX_BUFFER_SIZE, reader->file_ptr);

  if (line) {
    reader->buffer = realloc(reader->buffer, (reader->rows + 1) * MAX_BUFFER_SIZE);
    reader->buffer[reader->rows] = strdup(line);
    reader->rows++;
  }

  return 1;
}

int main() {
  CSVReader* reader = csv_reader_init("data.csv");

  while (csv_reader_read_next_row(reader)) {
    // Process each row
    char** data = reader->buffer[reader->current_row];
    for (int i = 0; i < reader->columns; i++) {
      // Access data in each column
      printf("%s,", data[i]);
    }
    printf("\n");
  }

  csv_reader_free(reader);

  return 0;
}
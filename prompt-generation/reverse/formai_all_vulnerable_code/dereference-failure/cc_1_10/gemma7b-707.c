//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CsvReader {
  char **buffer;
  int size;
  int pos;
  FILE *file;
} CsvReader;

CsvReader *csv_reader_init(FILE *file) {
  CsvReader *reader = malloc(sizeof(CsvReader));
  reader->buffer = NULL;
  reader->size = 0;
  reader->pos = 0;
  reader->file = file;

  return reader;
}

void csv_reader_free(CsvReader *reader) {
  free(reader->buffer);
  free(reader);
}

void csv_reader_read_next(CsvReader *reader) {
  char line[MAX_BUFFER_SIZE];
  int line_size = 0;

  // Read the next line from the file
  reader->pos = fgets(line, MAX_BUFFER_SIZE, reader->file);

  // If the line was read successfully, process it
  if (reader->pos) {
    line_size = strlen(line);

    // Allocate memory for the buffer if necessary
    if (reader->size == 0) {
      reader->buffer = malloc(line_size);
      reader->size = line_size;
    } else if (line_size > reader->size) {
      reader->buffer = realloc(reader->buffer, line_size);
      reader->size = line_size;
    }

    // Copy the line into the buffer
    memcpy(reader->buffer, line, line_size);

    // Increment the position
    reader->pos++;
  }
}

int main() {
  FILE *file = fopen("data.csv", "r");
  CsvReader *reader = csv_reader_init(file);

  // Read the next line from the CSV file
  csv_reader_read_next(reader);

  // Print the line
  printf("%s\n", reader->buffer);

  // Free the CSV reader
  csv_reader_free(reader);

  return 0;
}
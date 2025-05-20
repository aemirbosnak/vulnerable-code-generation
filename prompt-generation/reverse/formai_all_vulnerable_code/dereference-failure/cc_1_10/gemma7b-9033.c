//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CsvReader {
  char **buffer;
  int size;
  int capacity;
  int currentPos;
} CsvReader;

CsvReader *csvReader_init(int capacity) {
  CsvReader *reader = malloc(sizeof(CsvReader));
  reader->buffer = NULL;
  reader->size = 0;
  reader->capacity = capacity;
  reader->currentPos = 0;

  return reader;
}

void csvReader_append(CsvReader *reader, char *data) {
  if (reader->size >= reader->capacity) {
    reader->buffer = realloc(reader->buffer, reader->capacity * 2);
    reader->capacity *= 2;
  }

  reader->buffer[reader->size++] = data;
  reader->currentPos++;
}

void csvReader_finalize(CsvReader *reader) {
  free(reader->buffer);
  free(reader);
}

int main() {
  CsvReader *reader = csvReader_init(10);

  char *data = "abc,123,xyz";
  csvReader_append(reader, data);

  data = "abc,456,xyz";
  csvReader_append(reader, data);

  data = "def,789,xyz";
  csvReader_append(reader, data);

  csvReader_finalize(reader);

  return 0;
}
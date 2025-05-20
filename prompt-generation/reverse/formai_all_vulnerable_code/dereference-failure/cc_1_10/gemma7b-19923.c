//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
  FILE* file;
  char** buffer;
  int size;
  int capacity;
  int currentLine;
} CSVReader;

CSVReader* csvReader_init(char* filename) {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->file = fopen(filename, "r");
  reader->buffer = NULL;
  reader->size = 0;
  reader->capacity = MAX_BUFFER_SIZE;
  reader->currentLine = 0;

  return reader;
}

void csvReader_readNextLine(CSVReader* reader) {
  reader->currentLine++;
  if (reader->size == reader->capacity) {
    reader->buffer = realloc(reader->buffer, (reader->capacity * 2) * sizeof(char*));
    reader->capacity *= 2;
  }

  reader->buffer[reader->size++] = fgets(reader->file, MAX_BUFFER_SIZE, NULL);
}

void csvReader_finalize(CSVReader* reader) {
  fclose(reader->file);
  free(reader->buffer);
  free(reader);
}

int main() {
  CSVReader* reader = csvReader_init("data.csv");
  csvReader_readNextLine(reader);

  char* line = reader->buffer[0];
  printf("%s\n", line);

  csvReader_finalize(reader);

  return 0;
}
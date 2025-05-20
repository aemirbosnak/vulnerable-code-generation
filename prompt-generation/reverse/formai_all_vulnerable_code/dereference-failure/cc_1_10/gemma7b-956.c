//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
  FILE* file;
  char** buffer;
  int bufferSize;
  int currentLine;
} CSVReader;

CSVReader* csvReader_create(const char* filename) {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->file = fopen(filename, "r");
  reader->buffer = NULL;
  reader->bufferSize = MAX_BUFFER_SIZE;
  reader->currentLine = 0;

  return reader;
}

void csvReader_destroy(CSVReader* reader) {
  fclose(reader->file);
  free(reader->buffer);
  free(reader);
}

int csvReader_readNextLine(CSVReader* reader) {
  reader->currentLine++;

  if (reader->bufferSize <= reader->currentLine) {
    reader->bufferSize *= 2;
    reader->buffer = realloc(reader->buffer, reader->bufferSize * sizeof(char*));
  }

  char* line = fgets(reader->buffer[reader->currentLine - 1], reader->bufferSize, reader->file);
  if (line) {
    return 0;
  } else {
    return -1;
  }
}

char** csvReader_getLine(CSVReader* reader) {
  return reader->buffer[reader->currentLine - 1];
}

int main() {
  CSVReader* reader = csvReader_create("test.csv");

  while (csvReader_readNextLine(reader) == 0) {
    char** line = csvReader_getLine(reader);
    printf("Line %d: %s\n", reader->currentLine, line[0]);
  }

  csvReader_destroy(reader);

  return 0;
}
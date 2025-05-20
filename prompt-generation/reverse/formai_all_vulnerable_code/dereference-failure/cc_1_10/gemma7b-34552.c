//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_FIELDS 20

typedef struct CSVReader {
  char **lines;
  int numLines;
  char **fields;
  int numFields;
} CSVReader;

CSVReader* csvReader_create() {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->lines = NULL;
  reader->numLines = 0;
  reader->fields = NULL;
  reader->numFields = 0;
  return reader;
}

void csvReader_addLines(CSVReader* reader, char** lines, int numLines) {
  reader->lines = realloc(reader->lines, reader->numLines * MAX_LINES);
  reader->lines[reader->numLines++] = lines;
}

void csvReader_addFields(CSVReader* reader, char** fields, int numFields) {
  reader->fields = realloc(reader->fields, reader->numFields * MAX_FIELDS);
  reader->fields[reader->numFields++] = fields;
}

void csvReader_destroy(CSVReader* reader) {
  free(reader->lines);
  free(reader->fields);
  free(reader);
}

int main() {
  CSVReader* reader = csvReader_create();

  char** lines = malloc(sizeof(char*) * 3);
  lines[0] = "John Doe,123 Main St,New York,NY 10001";
  lines[1] = "Jane Doe,456 Oak Ave,Los Angeles,CA 90012";
  lines[2] = "Bob Smith,789 Park Ave,Chicago,IL 60601";

  csvReader_addLines(reader, lines, 3);

  char** fields = malloc(sizeof(char*) * 4);
  fields[0] = "Name";
  fields[1] = "Address";
  fields[2] = "City";
  fields[3] = "State";

  csvReader_addFields(reader, fields, 4);

  for (int i = 0; i < reader->numLines; i++) {
    for (int j = 0; j < reader->numFields; j++) {
      printf("%s: %s\n", reader->fields[j], reader->lines[i][j]);
    }
  }

  csvReader_destroy(reader);

  return 0;
}
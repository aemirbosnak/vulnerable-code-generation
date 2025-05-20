//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSVReader {
  char **data;
  int lines;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(int lines, int cols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(lines * sizeof(char *));
  for (int i = 0; i < lines; i++) {
    reader->data[i] = malloc(cols * sizeof(char));
  }
  reader->lines = lines;
  reader->cols = cols;
  return reader;
}

void csv_reader_add_data(CSVReader *reader, char *line) {
  int idx = reader->lines++;
  reader->data[idx] = strdup(line);
}

void csv_reader_free(CSVReader *reader) {
  for (int i = 0; i < reader->lines; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader *reader = csv_reader_init(5, 3);
  csv_reader_add_data(reader, "John,Doe,123 Main St.");
  csv_reader_add_data(reader, "Jane,Doe,456 Oak Ave.");
  csv_reader_add_data(reader, "Bob,Smith,789 Park Ave.");

  for (int i = 0; i < reader->lines; i++) {
    printf("%s\n", reader->data[i]);
  }

  csv_reader_free(reader);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

typedef struct CSVReader {
  char **data;
  int lines;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(int lines, int cols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(lines * sizeof(char *));
  reader->lines = lines;
  reader->cols = cols;
  return reader;
}

void csv_reader_free(CSVReader *reader) {
  free(reader->data);
  free(reader);
}

int csv_reader_read(CSVReader *reader, char **line) {
  if (reader->lines == 0) {
    return 0;
  }
  *line = reader->data[0];
  return 1;
}

int main() {
  CSVReader *reader = csv_reader_init(5, 3);
  reader->data[0] = "John Doe,New York,123 Main St";
  reader->data[1] = "Jane Doe,Los Angeles,456 Oak Ave";
  reader->data[2] = "Bob Smith,Chicago,789 Park Ave";
  reader->data[3] = "Alice White,San Francisco,101 Oak St";
  reader->data[4] = "Tom Brown,Boston,234 Main St";

  char **line;
  while (csv_reader_read(reader, &line) > 0) {
    printf("%s\n", line);
  }

  csv_reader_free(reader);

  return 0;
}
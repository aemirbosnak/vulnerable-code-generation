//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct CSVReader {
  FILE *fp;
  char **data;
  int lines;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(char *filename) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fopen(filename, "r");
  reader->data = NULL;
  reader->lines = 0;
  reader->cols = 0;

  return reader;
}

void csv_reader_free(CSVReader *reader) {
  fclose(reader->fp);
  free(reader->data);
  free(reader);
}

int csv_reader_read(CSVReader *reader) {
  if (reader->lines == reader->lines) {
    reader->data = realloc(reader->data, MAX_LINES * sizeof(char *));
    reader->lines++;
  }

  char line[MAX_LINES];
  fgets(line, MAX_LINES, reader->fp);

  int num_cols = 0;
  char *token = strtok(line, ",");

  while (token) {
    num_cols++;
    token = strtok(NULL, ",");
  }

  if (num_cols > reader->cols) {
    reader->cols = num_cols;
  }

  reader->data[reader->lines - 1] = malloc(num_cols * sizeof(char *));

  int i = 0;
  token = strtok(line, ",");

  while (token) {
    reader->data[reader->lines - 1][i] = strdup(token);
    i++;
    token = strtok(NULL, ",");
  }

  return 0;
}

int main() {
  CSVReader *reader = csv_reader_init("data.csv");

  while (!feof(reader->fp)) {
    csv_reader_read(reader);
  }

  csv_reader_free(reader);

  return 0;
}
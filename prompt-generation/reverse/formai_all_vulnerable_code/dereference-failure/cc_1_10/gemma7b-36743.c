//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
  FILE *fp;
  char **data;
  int rows;
  int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(char *filename) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->fp = fopen(filename, "r");
  reader->data = NULL;
  reader->rows = 0;
  reader->cols = 0;

  return reader;
}

void csv_reader_read(CSV_Reader *reader) {
  char line[MAX_ROWS];
  char **cols = NULL;

  while (fgets(line, MAX_ROWS, reader->fp) != NULL) {
    reader->rows++;

    if (cols == NULL) {
      cols = malloc(reader->cols * sizeof(char *));
    }

    cols[reader->rows - 1] = strdup(line);
  }

  reader->data = cols;
}

void csv_reader_free(CSV_Reader *reader) {
  fclose(reader->fp);
  free(reader->data);
  free(reader);
}

int main() {
  CSV_Reader *reader = csv_reader_init("example.csv");
  csv_reader_read(reader);
  csv_reader_free(reader);

  return 0;
}
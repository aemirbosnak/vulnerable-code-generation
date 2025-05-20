//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1024

typedef struct CSVReader {
  FILE *fp;
  char **data;
  int rows, cols;
} CSVReader;

CSVReader *csv_reader_init(const char *filename) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fopen(filename, "r");
  reader->data = NULL;
  reader->rows = reader->cols = 0;

  return reader;
}

void csv_reader_free(CSVReader *reader) {
  fclose(reader->fp);
  free(reader->data);
  free(reader);
}

int csv_reader_read(CSVReader *reader) {
  int num_cols = 0;
  char line[MAX_ROWS];
  char **data = NULL;

  if (reader->rows == 0) {
    reader->data = malloc(MAX_ROWS * sizeof(char *));
    for (int r = 0; r < MAX_ROWS; r++) {
      reader->data[r] = malloc(MAX_ROWS * sizeof(char));
    }
  }

  fgets(line, MAX_ROWS, reader->fp);
  char *ptr = line;
  while (*ptr) {
    char *cell = strchr(ptr, ',');
    if (cell) {
      reader->data[reader->rows][num_cols++] = strdup(ptr);
      ptr = cell + 1;
    } else {
      reader->data[reader->rows][num_cols++] = strdup(ptr);
      reader->rows++;
      ptr = NULL;
    }
  }

  return reader->rows;
}

int main() {
  CSVReader *reader = csv_reader_init("example.csv");
  int num_rows = csv_reader_read(reader);
  for (int r = 0; r < num_rows; r++) {
    for (int c = 0; c < reader->cols; c++) {
      printf("%s ", reader->data[r][c]);
    }
    printf("\n");
  }

  csv_reader_free(reader);

  return 0;
}
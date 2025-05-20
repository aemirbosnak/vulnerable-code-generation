//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSV_Reader {
  FILE *file;
  char **data;
  int rows;
  int cols;
} CSV_Reader;

CSV_Reader *create_csv_reader(char *filename) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->file = fopen(filename, "r");
  reader->data = NULL;
  reader->rows = 0;
  reader->cols = 0;
  return reader;
}

void read_csv_data(CSV_Reader *reader) {
  char line[1024];
  while (fgets(line, 1024, reader->file) != NULL) {
    reader->rows++;
    char **row = realloc(reader->data, reader->rows * sizeof(char *));
    reader->data = row;
    row = reader->data;
    char *cell = strtok(line, ",");
    reader->cols = 0;
    while (cell) {
      row[reader->cols++] = cell;
      cell = strtok(NULL, ",");
    }
    row[reader->cols] = NULL;
  }
}

void destroy_csv_reader(CSV_Reader *reader) {
  fclose(reader->file);
  free(reader->data);
  free(reader);
}

int main() {
  CSV_Reader *reader = create_csv_reader("example.csv");
  read_csv_data(reader);
  for (int i = 0; i < reader->rows; i++) {
    for (int j = 0; j < reader->cols; j++) {
      printf("%s ", reader->data[i][j]);
    }
    printf("\n");
  }
  destroy_csv_reader(reader);
  return 0;
}
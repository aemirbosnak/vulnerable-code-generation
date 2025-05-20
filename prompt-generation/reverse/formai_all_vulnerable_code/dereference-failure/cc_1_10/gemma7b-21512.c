//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSV_Reader_t {
  FILE* file;
  char** data;
  int rows;
  int cols;
} CSV_Reader_t;

CSV_Reader_t* csv_reader_init(const char* filename) {
  CSV_Reader_t* reader = malloc(sizeof(CSV_Reader_t));

  reader->file = fopen(filename, "r");
  reader->data = NULL;
  reader->rows = 0;
  reader->cols = 0;

  return reader;
}

void csv_reader_parse(CSV_Reader_t* reader) {
  char line[1024];
  char** columns;
  int i, j;

  while (fgets(line, 1024, reader->file) != NULL) {
    reader->rows++;

    columns = malloc((reader->cols + 1) * sizeof(char*));
    for (i = 0; i < reader->cols + 1; i++) {
      columns[i] = strdup(strtok(line, ","));
    }

    reader->data = realloc(reader->data, reader->rows * sizeof(char**));
    reader->data[reader->rows - 1] = columns;
  }

  reader->cols = columns ? columns[0] : 0;
}

void csv_reader_free(CSV_Reader_t* reader) {
  fclose(reader->file);
  free(reader->data);
  free(reader);
}

int main() {
  CSV_Reader_t* reader = csv_reader_init("data.csv");
  csv_reader_parse(reader);

  for (int i = 0; i < reader->rows; i++) {
    for (int j = 0; j < reader->cols; j++) {
      printf("%s,", reader->data[i][j]);
    }

    printf("\n");
  }

  csv_reader_free(reader);

  return 0;
}
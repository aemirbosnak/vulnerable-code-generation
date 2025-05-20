//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100

typedef struct CSV_Row {
  char **data;
  int num_cols;
} CSV_Row;

typedef struct CSV_Reader {
  CSV_Row **rows;
  int num_rows;
  FILE *fp;
} CSV_Reader;

CSV_Reader *csv_reader_init(FILE *fp) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->rows = NULL;
  reader->num_rows = 0;
  reader->fp = fp;
  return reader;
}

void csv_reader_add_row(CSV_Reader *reader, int num_cols, char **data) {
  CSV_Row *row = malloc(sizeof(CSV_Row));
  row->data = data;
  row->num_cols = num_cols;
  reader->rows = realloc(reader->rows, (reader->num_rows + 1) * sizeof(CSV_Row));
  reader->rows[reader->num_rows++] = row;
}

void csv_reader_close(CSV_Reader *reader) {
  for (int i = 0; i < reader->num_rows; i++) {
    free(reader->rows[i]->data);
    free(reader->rows[i]);
  }
  free(reader->rows);
  fclose(reader->fp);
  free(reader);
}

int main() {
  FILE *fp = fopen("test.csv", "r");
  CSV_Reader *reader = csv_reader_init(fp);

  char **data = malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    data[i] = malloc(20 * sizeof(char));
  }

  csv_reader_add_row(reader, 5, data);
  csv_reader_add_row(reader, 3, data);

  csv_reader_close(reader);

  for (int i = 0; i < reader->num_rows; i++) {
    for (int j = 0; j < reader->rows[i]->num_cols; j++) {
      printf("%s ", reader->rows[i]->data[j]);
    }
    printf("\n");
  }

  return 0;
}
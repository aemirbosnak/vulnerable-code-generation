//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_ROW {
  char **data;
  int num_cols;
} CSV_ROW;

typedef struct CSV_FILE {
  CSV_ROW **rows;
  int num_rows;
} CSV_FILE;

CSV_FILE *csv_file_init(int num_rows, int num_cols) {
  CSV_FILE *file = malloc(sizeof(CSV_FILE));
  file->rows = malloc(sizeof(CSV_ROW *) * num_rows);
  file->num_rows = num_rows;

  for (int i = 0; i < num_rows; i++) {
    file->rows[i] = malloc(sizeof(CSV_ROW));
    file->rows[i]->data = malloc(sizeof(char *) * num_cols);
    file->rows[i]->num_cols = num_cols;
  }

  return file;
}

void csv_file_add_row(CSV_FILE *file, char **data, int num_cols) {
  CSV_ROW *row = malloc(sizeof(CSV_ROW));
  row->data = malloc(sizeof(char *) * num_cols);
  row->num_cols = num_cols;

  for (int i = 0; i < num_cols; i++) {
    row->data[i] = strdup(data[i]);
  }

  file->rows[file->num_rows++] = row;
}

void csv_file_print(CSV_FILE *file) {
  for (int i = 0; i < file->num_rows; i++) {
    for (int j = 0; j < file->rows[i]->num_cols; j++) {
      printf("%s,", file->rows[i]->data[j]);
    }
    printf("\n");
  }
}

int main() {
  CSV_FILE *file = csv_file_init(5, 3);

  char **data = malloc(sizeof(char *) * 3);
  data[0] = "John Doe";
  data[1] = "Jane Doe";
  data[2] = "Bob Smith";

  csv_file_add_row(file, data, 3);

  data = malloc(sizeof(char *) * 3);
  data[0] = "Alice White";
  data[1] = "Bethany Pink";
  data[2] = "Charlie Brown";

  csv_file_add_row(file, data, 3);

  csv_file_print(file);

  return 0;
}
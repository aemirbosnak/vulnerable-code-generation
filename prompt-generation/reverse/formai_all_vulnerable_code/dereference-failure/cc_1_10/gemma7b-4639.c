//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_ROW {
  char **data;
  int num_cols;
} CSV_ROW;

typedef struct CSV_TABLE {
  CSV_ROW **rows;
  int num_rows;
} CSV_TABLE;

CSV_TABLE *csv_read(char *filename) {
  CSV_TABLE *table = malloc(sizeof(CSV_TABLE));
  table->rows = NULL;
  table->num_rows = 0;

  FILE *file = fopen(filename, "r");
  if (!file) {
    return NULL;
  }

  char buffer[MAX_BUFFER_SIZE];
  char *line = NULL;
  int line_num = 0;

  while (getline(&line, buffer, MAX_BUFFER_SIZE) != -1) {
    line_num++;
    CSV_ROW *row = malloc(sizeof(CSV_ROW));
    row->data = NULL;
    row->num_cols = 0;

    char *field = strtok(line, ",");
    while (field) {
      row->data = realloc(row->data, (row->num_cols + 1) * sizeof(char *));
      row->data[row->num_cols++] = strdup(field);
      field = strtok(NULL, ",");
    }

    table->rows = realloc(table->rows, (table->num_rows + 1) * sizeof(CSV_ROW *));
    table->rows[table->num_rows++] = row;
  }

  fclose(file);

  return table;
}

int main() {
  CSV_TABLE *table = csv_read("data.csv");

  for (int i = 0; i < table->num_rows; i++) {
    for (int j = 0; j < table->rows[i]->num_cols; j++) {
      printf("%s,", table->rows[i]->data[j]);
    }
    printf("\n");
  }

  return 0;
}
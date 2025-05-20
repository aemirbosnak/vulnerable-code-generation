//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_DATA {
  char **data;
  int rows;
  int cols;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
  CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
  csv_data->rows = 0;
  csv_data->cols = 0;
  csv_data->data = NULL;

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  char line[MAX_ROWS];
  while (fgets(line, MAX_ROWS, file) != NULL) {
    char **columns = NULL;
    int num_columns = 0;

    // Parse the line into columns
    char *column = strtok(line, ",");
    while (column) {
      columns = realloc(columns, (num_columns + 1) * sizeof(char *));
      columns[num_columns++] = strdup(column);
      column = strtok(NULL, ",");
    }

    // Update the CSV data
    csv_data->rows++;
    csv_data->cols = num_columns;
    csv_data->data = realloc(csv_data->data, csv_data->rows * sizeof(char **));
    csv_data->data[csv_data->rows - 1] = columns;
  }

  fclose(file);
  return csv_data;
}

int main() {
  char *filename = "test.csv";
  CSV_DATA *csv_data = read_csv(filename);

  // Print the CSV data
  for (int i = 0; i < csv_data->rows; i++) {
    for (int j = 0; j < csv_data->cols; j++) {
      printf("%s, ", csv_data->data[i][j]);
    }
    printf("\n");
  }

  free(csv_data->data);
  free(csv_data);

  return 0;
}
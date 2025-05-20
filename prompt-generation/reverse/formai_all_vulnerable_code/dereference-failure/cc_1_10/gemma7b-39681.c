//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_DATA {
  char **data;
  int num_rows;
  int num_cols;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
  CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
  csv_data->data = NULL;
  csv_data->num_rows = 0;
  csv_data->num_cols = 0;

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  // Read the number of rows and columns
  char line[MAX_LINES];
  int num_rows = 0;
  while (fgets(line, MAX_LINES, fp) != NULL) {
    num_rows++;
  }

  // Allocate memory for the data
  csv_data->data = malloc(num_rows * sizeof(char *));
  for (int i = 0; i < num_rows; i++) {
    csv_data->data[i] = malloc(MAX_COLS * sizeof(char));
  }

  // Read the data from the file
  rewind(fp);
  int num_cols = 0;
  while (fgets(line, MAX_LINES, fp) != NULL) {
    char *fields = strtok(line, ",");
    while (fields) {
      strcpy(csv_data->data[num_rows - 1][num_cols], fields);
      num_cols++;
      fields = strtok(NULL, ",");
    }
    num_cols = 0;
  }

  fclose(fp);
  return csv_data;
}

int main() {
  CSV_DATA *csv_data = read_csv("example.csv");
  if (csv_data) {
    printf("Number of rows: %d\n", csv_data->num_rows);
    printf("Number of columns: %d\n", csv_data->num_cols);
    for (int i = 0; i < csv_data->num_rows; i++) {
      for (int j = 0; j < csv_data->num_cols; j++) {
        printf("%s ", csv_data->data[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
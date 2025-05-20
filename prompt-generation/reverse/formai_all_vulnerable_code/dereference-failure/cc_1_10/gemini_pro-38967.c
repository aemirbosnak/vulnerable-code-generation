//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char **data;
  size_t num_rows;
  size_t num_cols;
} csv_t;

csv_t *csv_read(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    return NULL;
  }

  char line[MAX_LINE_LENGTH];
  size_t num_rows = 0;
  size_t num_cols = 0;

  while (fgets(line, sizeof(line), fp)) {
    num_rows++;

    char *token = strtok(line, ",");
    while (token) {
      num_cols++;
      token = strtok(NULL, ",");
    }
  }

  rewind(fp);

  csv_t *csv = malloc(sizeof(csv_t));
  csv->data = malloc(sizeof(char *) * num_rows);
  for (size_t i = 0; i < num_rows; i++) {
    csv->data[i] = malloc(sizeof(char) * (MAX_LINE_LENGTH + 1));
  }

  size_t row_index = 0;
  while (fgets(line, sizeof(line), fp)) {
    char *token = strtok(line, ",");
    size_t col_index = 0;
    while (token) {
      strcpy(csv->data[row_index][col_index], token);
      col_index++;
      token = strtok(NULL, ",");
    }
    row_index++;
  }

  fclose(fp);

  csv->num_rows = num_rows;
  csv->num_cols = num_cols;

  return csv;
}

void csv_free(csv_t *csv) {
  for (size_t i = 0; i < csv->num_rows; i++) {
    free(csv->data[i]);
  }
  free(csv->data);
  free(csv);
}

int main() {
  csv_t *csv = csv_read("data.csv");

  for (size_t i = 0; i < csv->num_rows; i++) {
    for (size_t j = 0; j < csv->num_cols; j++) {
      printf("%s ", csv->data[i][j]);
    }
    printf("\n");
  }

  csv_free(csv);

  return 0;
}
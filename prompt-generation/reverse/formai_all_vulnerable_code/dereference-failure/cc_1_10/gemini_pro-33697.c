//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 100
#define MAX_ROWS 1000

typedef struct {
  char *data[MAX_COLS];
  int num_cols;
  int num_rows;
} csv_t;

csv_t *csv_new() {
  csv_t *csv = malloc(sizeof(csv_t));
  if (!csv) {
    return NULL;
  }
  csv->num_cols = 0;
  csv->num_rows = 0;
  for (int i = 0; i < MAX_COLS; i++) {
    csv->data[i] = NULL;
  }
  return csv;
}

void csv_free(csv_t *csv) {
  for (int i = 0; i < MAX_COLS; i++) {
    free(csv->data[i]);
  }
  free(csv);
}

int csv_load(csv_t *csv, const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    return -1;
  }
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *token = strtok(line, ",");
    int col = 0;
    while (token) {
      csv->data[col] = strdup(token);
      token = strtok(NULL, ",");
      col++;
    }
    csv->num_cols = col;
    csv->num_rows++;
  }
  fclose(fp);
  return 0;
}

int main() {
  csv_t *csv = csv_new();
  csv_load(csv, "data.csv");
  for (int i = 0; i < csv->num_rows; i++) {
    for (int j = 0; j < csv->num_cols; j++) {
      printf("%s,", csv->data[j]);
    }
    printf("\n");
  }
  csv_free(csv);
  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
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

CSV_DATA *csv_read(char *filename) {
  CSV_DATA *csv = malloc(sizeof(CSV_DATA));
  csv->data = NULL;
  csv->num_rows = 0;
  csv->num_cols = 0;

  FILE *fp = fopen(filename, "r");
  if (!fp) {
    return NULL;
  }

  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    char *comma = strchr(line, ',');
    if (comma) {
      int num_cols = comma - line + 1;
      if (num_cols > csv->num_cols) {
        csv->num_cols = num_cols;
        csv->data = realloc(csv->data, sizeof(char *) * csv->num_rows * csv->num_cols);
      }

      csv->data[csv->num_rows++] = strdup(line);
    }
  }

  fclose(fp);
  return csv;
}

int main() {
  char *filename = "data.csv";
  CSV_DATA *csv = csv_read(filename);

  if (csv) {
    for (int i = 0; i < csv->num_rows; i++) {
      printf("%s\n", csv->data[i]);
    }

    free(csv->data);
    free(csv);
  } else {
    printf("Error reading CSV file.\n");
  }

  return 0;
}
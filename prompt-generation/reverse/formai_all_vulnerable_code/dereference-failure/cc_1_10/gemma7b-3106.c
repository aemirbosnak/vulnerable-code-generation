//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_DATA {
  char ***data;
  int num_lines;
  int num_cols;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
  CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
  csv_data->num_lines = 0;
  csv_data->num_cols = 0;
  csv_data->data = NULL;

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    char **cols = NULL;
    int num_cols = 0;
    char *ptr = line;
    while (ptr) {
      char *col = strchr(ptr, ',');
      if (col) {
        cols = realloc(cols, (num_cols + 1) * sizeof(char *));
        cols[num_cols++] = strdup(ptr);
        ptr = col + 1;
      } else {
        cols = realloc(cols, (num_cols + 1) * sizeof(char *));
        cols[num_cols++] = strdup(ptr);
        ptr = NULL;
      }
    }

    csv_data->data = realloc(csv_data->data, (csv_data->num_lines + 1) * sizeof(char ***));
    csv_data->data[csv_data->num_lines] = cols;
    csv_data->num_lines++;
  }

  fclose(fp);

  return csv_data;
}

int main() {
  char *filename = "data.csv";
  CSV_DATA *csv_data = read_csv(filename);

  if (csv_data) {
    printf("Number of lines: %d\n", csv_data->num_lines);
    printf("Number of columns: %d\n", csv_data->num_cols);

    for (int i = 0; i < csv_data->num_lines; i++) {
      for (int j = 0; j < csv_data->num_cols; j++) {
        printf("%s ", csv_data->data[i][j]);
      }
      printf("\n");
    }

    free(csv_data->data);
    free(csv_data);
  } else {
    printf("Error reading CSV file.\n");
  }

  return 0;
}
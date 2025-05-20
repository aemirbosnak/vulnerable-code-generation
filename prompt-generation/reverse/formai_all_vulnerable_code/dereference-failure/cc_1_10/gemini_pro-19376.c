//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  int num_rows;
  int num_cols;
  char **data;
} CSV;

CSV *csv_read(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  CSV *csv = malloc(sizeof(CSV));
  if (csv == NULL) {
    fclose(fp);
    return NULL;
  }

  csv->num_rows = 0;
  csv->num_cols = 0;
  csv->data = NULL;

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    // Count the number of columns in the line.
    int num_cols = 0;
    for (int i = 0; i < strlen(line); i++) {
      if (line[i] == ',') {
        num_cols++;
      }
    }

    // Allocate memory for the data in the line.
    char **data = malloc((num_cols + 1) * sizeof(char *));
    if (data == NULL) {
      fclose(fp);
      free(csv);
      return NULL;
    }

    // Parse the line into columns.
    int start = 0;
    int end = 0;
    for (int i = 0; i < num_cols + 1; i++) {
      // Find the end of the column.
      while (line[end] != ',' && line[end] != '\n') {
        end++;
      }

      // Allocate memory for the column.
      data[i] = malloc(end - start + 1);
      if (data[i] == NULL) {
        for (int j = 0; j < i; j++) {
          free(data[j]);
        }
        free(data);
        fclose(fp);
        free(csv);
        return NULL;
      }

      // Copy the column into the data.
      strncpy(data[i], line + start, end - start);
      data[i][end - start] = '\0';

      // Update the start and end of the column.
      start = end + 1;
      end = start;
    }

    // Add the data to the CSV.
    csv->data = realloc(csv->data, (csv->num_rows + 1) * sizeof(char **));
    if (csv->data == NULL) {
      for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
          free(csv->data[i][j]);
        }
        free(csv->data[i]);
      }
      for (int i = 0; i < num_cols + 1; i++) {
        free(data[i]);
      }
      free(data);
      fclose(fp);
      free(csv);
      return NULL;
    }
    csv->data[csv->num_rows] = data;
    csv->num_rows++;
    csv->num_cols = num_cols + 1;
  }

  fclose(fp);
  return csv;
}

void csv_free(CSV *csv) {
  for (int i = 0; i < csv->num_rows; i++) {
    for (int j = 0; j < csv->num_cols; j++) {
      free(csv->data[i][j]);
    }
    free(csv->data[i]);
  }
  free(csv->data);
  free(csv);
}

int main() {
  CSV *csv = csv_read("data.csv");
  if (csv == NULL) {
    return EXIT_FAILURE;
  }

  for (int i = 0; i < csv->num_rows; i++) {
    for (int j = 0; j < csv->num_cols; j++) {
      printf("%s", csv->data[i][j]);
      if (j < csv->num_cols - 1) {
        printf(",");
      }
    }
    printf("\n");
  }

  csv_free(csv);
  return EXIT_SUCCESS;
}
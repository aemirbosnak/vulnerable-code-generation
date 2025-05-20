//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 10

typedef struct {
  char *line;
  int num_columns;
  char *columns[MAX_NUM_COLUMNS];
} csv_row;

csv_row *csv_row_create(char *line) {
  csv_row *row = malloc(sizeof(csv_row));
  row->line = strdup(line);
  row->num_columns = 0;

  char *column = strtok(line, ",");
  while (column != NULL) {
    row->columns[row->num_columns++] = strdup(column);
    column = strtok(NULL, ",");
  }

  return row;
}

void csv_row_destroy(csv_row *row) {
  free(row->line);
  for (int i = 0; i < row->num_columns; i++) {
    free(row->columns[i]);
  }
  free(row);
}

int main() {
  // Open the CSV file
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the first line of the CSV file
  char line[MAX_LINE_LENGTH];
  if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
    perror("Error reading line");
    fclose(fp);
    return EXIT_FAILURE;
  }

  // Create a CSV row for the first line
  csv_row *row = csv_row_create(line);

  // Print the columns of the first row
  for (int i = 0; i < row->num_columns; i++) {
    printf("%s\n", row->columns[i]);
  }

  // Destroy the CSV row
  csv_row_destroy(row);

  // Close the CSV file
  fclose(fp);

  return EXIT_SUCCESS;
}
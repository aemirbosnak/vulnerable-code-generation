//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

typedef struct {
  char *fields[MAX_FIELDS];
  int num_fields;
} CSVRow;

CSVRow *read_csv_row(char *line) {
  CSVRow *row = malloc(sizeof(CSVRow));
  row->num_fields = 0;

  char *field = strtok(line, ",");
  while (field != NULL && row->num_fields < MAX_FIELDS) {
    row->fields[row->num_fields] = strdup(field);
    row->num_fields++;
    field = strtok(NULL, ",");
  }

  return row;
}

void free_csv_row(CSVRow *row) {
  for (int i = 0; i < row->num_fields; i++) {
    free(row->fields[i]);
  }
  free(row);
}

int main() {
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    CSVRow *row = read_csv_row(line);

    // Process the row here...

    free_csv_row(row);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
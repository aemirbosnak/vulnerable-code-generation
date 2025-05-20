//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
  char *fields[MAX_NUM_FIELDS];
  int num_fields;
} CSVRow;

CSVRow *read_csv_row(FILE *fp) {
  char line[MAX_LINE_LENGTH];
  if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
    return NULL;
  }

  CSVRow *row = malloc(sizeof(CSVRow));
  row->num_fields = 0;

  char *field = strtok(line, ",");
  while (field != NULL) {
    row->fields[row->num_fields++] = strdup(field);
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

  CSVRow *row;
  while ((row = read_csv_row(fp)) != NULL) {
    for (int i = 0; i < row->num_fields; i++) {
      printf("%s ", row->fields[i]);
    }
    printf("\n");

    free_csv_row(row);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
  char *fields[MAX_NUM_FIELDS];
  int num_fields;
} CSVRow;

CSVRow *CSVRow_create(char *line) {
  CSVRow *row = malloc(sizeof(CSVRow));
  row->num_fields = 0;

  char *field = strtok(line, ",");
  while (field != NULL) {
    row->fields[row->num_fields++] = strdup(field);
    field = strtok(NULL, ",");
  }

  return row;
}

void CSVRow_free(CSVRow *row) {
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
    CSVRow *row = CSVRow_create(line);

    for (int i = 0; i < row->num_fields; i++) {
      printf("%s\n", row->fields[i]);
    }

    CSVRow_free(row);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}
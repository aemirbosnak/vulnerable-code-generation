//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **fields;
  int nfields;
} csv_row;

csv_row *read_csv_row(FILE *fp) {
  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    return NULL;
  }

  csv_row *row = malloc(sizeof(csv_row));
  row->nfields = 0;
  row->fields = NULL;

  char *field = strtok(line, ",");
  while (field != NULL) {
    row->fields = realloc(row->fields, (row->nfields + 1) * sizeof(char *));
    row->fields[row->nfields++] = strdup(field);
    field = strtok(NULL, ",");
  }

  return row;
}

void free_csv_row(csv_row *row) {
  for (int i = 0; i < row->nfields; i++) {
    free(row->fields[i]);
  }
  free(row->fields);
  free(row);
}

int main() {
  FILE *fp = fopen("example.csv", "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  csv_row *row;
  while ((row = read_csv_row(fp)) != NULL) {
    for (int i = 0; i < row->nfields; i++) {
      printf("%s", row->fields[i]);
      if (i < row->nfields - 1) {
        printf(",");
      }
    }
    printf("\n");
    free_csv_row(row);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
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

  char *p = line;
  while (*p != '\0') {
    if (*p == ',') {
      *p = '\0';
      row->fields[row->num_fields++] = strdup(p + 1);
    }
    p++;
  }

  return row;
}

void free_csv_row(CSVRow *row) {
  for (int i = 0; i < row->num_fields; i++) {
    free(row->fields[i]);
  }
  free(row);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
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
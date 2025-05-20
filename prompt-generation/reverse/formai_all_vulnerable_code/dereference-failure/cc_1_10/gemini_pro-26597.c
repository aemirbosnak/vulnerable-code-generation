//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
  char *fields[MAX_NUM_FIELDS];
  int num_fields;
} csv_row;

csv_row *csv_row_new() {
  csv_row *row = malloc(sizeof(csv_row));
  row->num_fields = 0;
  for (int i = 0; i < MAX_NUM_FIELDS; i++) {
    row->fields[i] = NULL;
  }
  return row;
}

void csv_row_free(csv_row *row) {
  for (int i = 0; i < row->num_fields; i++) {
    free(row->fields[i]);
  }
  free(row);
}

int csv_row_add_field(csv_row *row, char *field) {
  if (row->num_fields >= MAX_NUM_FIELDS) {
    return -1;
  }
  row->fields[row->num_fields] = strdup(field);
  row->num_fields++;
  return 0;
}

char *csv_row_get_field(csv_row *row, int index) {
  if (index < 0 || index >= row->num_fields) {
    return NULL;
  }
  return row->fields[index];
}

int csv_read_line(FILE *fp, csv_row *row) {
  char line[MAX_LINE_LENGTH];
  if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
    return -1;
  }
  char *field = strtok(line, ",");
  while (field != NULL) {
    csv_row_add_field(row, field);
    field = strtok(NULL, ",");
  }
  return 0;
}

int main() {
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  csv_row *row = csv_row_new();
  while (csv_read_line(fp, row) != -1) {
    for (int i = 0; i < row->num_fields; i++) {
      printf("%s ", csv_row_get_field(row, i));
    }
    printf("\n");
  }

  csv_row_free(row);
  fclose(fp);

  return EXIT_SUCCESS;
}
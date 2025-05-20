//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 100

typedef struct {
  char *fields[MAX_NUM_FIELDS];
  int num_fields;
} CSVRow;

CSVRow* CSVRow_new() {
  CSVRow *row = malloc(sizeof(CSVRow));
  row->num_fields = 0;
  return row;
}

void CSVRow_free(CSVRow *row) {
  for (int i = 0; i < row->num_fields; i++) {
    free(row->fields[i]);
  }
  free(row);
}

int CSVRow_add_field(CSVRow *row, char *field) {
  if (row->num_fields >= MAX_NUM_FIELDS) {
    return -1;
  }
  row->fields[row->num_fields++] = strdup(field);
  return 0;
}

char* CSVRow_get_field(CSVRow *row, int index) {
  if (index < 0 || index >= row->num_fields) {
    return NULL;
  }
  return row->fields[index];
}

int CSVRow_print(CSVRow *row) {
  for (int i = 0; i < row->num_fields; i++) {
    printf("%s", row->fields[i]);
    if (i < row->num_fields - 1) {
      printf(",");
    }
  }
  printf("\n");
  return 0;
}

CSVRow* CSVRow_parse(char *line) {
  CSVRow *row = CSVRow_new();
  char *field = strtok(line, ",");
  while (field != NULL) {
    CSVRow_add_field(row, field);
    field = strtok(NULL, ",");
  }
  return row;
}

int main() {
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    CSVRow *row = CSVRow_parse(line);
    CSVRow_print(row);
    CSVRow_free(row);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
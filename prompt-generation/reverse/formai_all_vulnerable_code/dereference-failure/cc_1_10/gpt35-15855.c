//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FIELDS 50
#define MAX_FIELD_LENGTH 50
#define CSV_DELIM ","

typedef struct {
  char fields[MAX_NUM_FIELDS][MAX_FIELD_LENGTH];
  int num_fields;
} CsvRow;

CsvRow* get_csv_row(FILE* file) {
  CsvRow* row = malloc(sizeof(CsvRow));
  row->num_fields = 0;
  char line[MAX_LINE_LENGTH];
  char* field;
  fgets(line, MAX_LINE_LENGTH, file);
  field = strtok(line, CSV_DELIM);

  while (field != NULL) {
    strcpy(row->fields[row->num_fields], field);
    row->num_fields++;
    field = strtok(NULL, CSV_DELIM);
  }

  if (row->num_fields > 0) {
    return row;
  } else {
    free(row);
    return NULL;
  }
}

void free_csv_row(CsvRow* row) {
  free(row);
}

int main(int argc, char *argv[]) {
  FILE* file;
  CsvRow* row;
  char* filename = argv[1];

  if (argc < 2) {
    printf("Usage: %s [filename]\n", argv[0]);
    return 1;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return 1;
  }

  while ((row = get_csv_row(file)) != NULL) {
    for (int i = 0; i < row->num_fields; i++) {
      printf("%s, ", row->fields[i]);
    }
    printf("\n");
    free_csv_row(row);
  }

  fclose(file);
  return 0;
}
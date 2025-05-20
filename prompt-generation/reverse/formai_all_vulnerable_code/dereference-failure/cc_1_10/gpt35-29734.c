//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10

typedef struct {
  char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
  int num_fields;
} csv_row;

int read_csv_file(char* filename, csv_row** rows);
int parse_csv_line(char* line, csv_row* row);

int main() {
  csv_row* rows;
  int num_rows;

  num_rows = read_csv_file("example.csv", &rows);

  for (int i = 0; i < num_rows; i++) {
    csv_row row = rows[i];
    for (int j = 0; j < row.num_fields; j++) {
      printf("%s, ", row.fields[j]);
    }
    printf("\n");
  }

  free(rows);
  return 0;
}

int read_csv_file(char* filename, csv_row** rows) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    printf("Failed to open file: %s", filename);
    return -1;
  }

  int max_rows = 10;
  int num_rows = 0;
  *rows = (csv_row*)malloc(max_rows * sizeof(csv_row));

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    csv_row* row = &((*rows)[num_rows]);
    int fields_parsed = parse_csv_line(line, row);

    if (fields_parsed > 0) {
      num_rows++;
    }

    if (num_rows == max_rows) {
      max_rows *= 2;
      *rows = (csv_row*)realloc(*rows, max_rows * sizeof(csv_row));
    }
  }

  fclose(file);
  return num_rows;
}

int parse_csv_line(char* line, csv_row* row) {
  if (strlen(line) == 0) {
    return 0;
  }

  char* field = strtok(line, ",");
  int field_num = 0;

  while (field != NULL) {
    if (strlen(field) > MAX_FIELD_LENGTH) {
      printf("Field \"%s\" is too long!", field);
      return -1;
    }

    strcpy(row->fields[field_num], field);
    field_num++;

    if (field_num == MAX_FIELDS) {
      printf("Too many fields in row!");
      return -1;
    }

    field = strtok(NULL, ",");
  }

  row->num_fields = field_num;
  return field_num;
}
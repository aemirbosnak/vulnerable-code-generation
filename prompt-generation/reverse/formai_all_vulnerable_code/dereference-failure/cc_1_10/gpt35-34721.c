//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

typedef struct {
  char **fields;
  int num_fields;
} csv_row;

typedef struct {
  csv_row *rows;
  int num_rows;
  int max_rows;
} csv_data;

int read_csv_file(FILE *fp, csv_data *csv) {
  int num_rows = 0;
  int max_rows = 10;
  char line[MAX_LINE_LENGTH];
  char *field;
  csv->rows = (csv_row *)malloc(sizeof(csv_row) * max_rows);
  csv->num_rows = 0;
  csv->max_rows = max_rows;
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    if (num_rows >= max_rows) {
      max_rows *= 2;
      csv->rows = (csv_row *)realloc(csv->rows, sizeof(csv_row) * max_rows);
    }
    // Split line into fields
    char *saveptr;
    csv_row *row = &(csv->rows[num_rows]);
    row->fields = (char **)malloc(sizeof(char *) * MAX_FIELD_LENGTH);
    row->num_fields = 0;
    field = strtok_r(line, ",", &saveptr);
    while (field) {
      if (row->num_fields >= MAX_FIELD_LENGTH) {
        printf("Error: too many fields in row.\n");
        return -1;
      }
      if ((strcmp(field, "\n") == 0) || (strcmp(field, "\r\n") == 0)) {
        // Empty field
        row->fields[row->num_fields] = "";
      } else {
        // Remove trailing newline
        field[strcspn(field, "\r\n")] = 0;
        row->fields[row->num_fields] = (char *)malloc(strlen(field) + 1);
        strcpy(row->fields[row->num_fields], field);
      }
      row->num_fields++;
      field = strtok_r(NULL, ",", &saveptr);
    }
    num_rows++;
  }
  csv->num_rows = num_rows;
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Error: missing CSV file name.\n");
    return 1;
  }
  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Error: could not open file %s\n", argv[1]);
    return 1;
  }
  csv_data csv;
  int ret = read_csv_file(fp, &csv);
  fclose(fp);
  if (ret == 0) {
    // Print CSV data
    for (int i = 0; i < csv.num_rows; i++) {
      csv_row row = csv.rows[i];
      for (int j = 0; j < row.num_fields; j++) {
        printf("%s,", row.fields[j]);
      }
      printf("\n");
    }
  }
  // Free CSV data
  for (int i = 0; i < csv.num_rows; i++) {
    csv_row row = csv.rows[i];
    for (int j = 0; j < row.num_fields; j++) {
      free(row.fields[j]);
    }
    free(row.fields);
  }
  free(csv.rows);
  return 0;
}
//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 50

typedef struct {
  char **fields;
  int num_fields;
} CSVRow;

typedef struct {
  char **headers;
  int num_headers;
  CSVRow *rows;
  int num_rows;
} CSVData;

CSVData *read_csv_file(char *filename) {
  CSVData *csv_data = malloc(sizeof(CSVData));
  csv_data->headers = NULL;
  csv_data->num_headers = 0;
  csv_data->rows = NULL;
  csv_data->num_rows = 0;

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open file \"%s\"\n", filename);
    return NULL;
  }

  // Read headers
  char line[MAX_LINE_LEN];
  if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
    printf("Error: File \"%s\" is empty\n", filename);
    return NULL;
  }
  char *ptr = strtok(line, ",");
  while (ptr != NULL) {
    if (csv_data->num_headers == MAX_FIELDS) {
      printf("Error: Too many headers (max is %d)\n", MAX_FIELDS);
      return NULL;
    }
    csv_data->headers = realloc(csv_data->headers, (csv_data->num_headers + 1) * sizeof(char *));
    csv_data->headers[csv_data->num_headers] = strdup(ptr);
    csv_data->num_headers++;
    ptr = strtok(NULL, ",");
  }

  // Read rows
  while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
    CSVRow row;
    row.fields = malloc(csv_data->num_headers * sizeof(char *));
    row.num_fields = 0;
    ptr = strtok(line, ",");
    while (ptr != NULL) {
      if (row.num_fields == csv_data->num_headers) {
        printf("Error: Row has too many fields\n");
        return NULL;
      }
      row.fields[row.num_fields] = strdup(ptr);
      row.num_fields++;
      ptr = strtok(NULL, ",");
    }
    if (row.num_fields != csv_data->num_headers) {
      printf("Error: Row has too few fields\n");
      return NULL;
    }
    csv_data->rows = realloc(csv_data->rows, (csv_data->num_rows + 1) * sizeof(CSVRow));
    csv_data->rows[csv_data->num_rows] = row;
    csv_data->num_rows++;
  }

  fclose(fp);

  return csv_data;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: csv_reader <filename>\n");
    return EXIT_FAILURE;
  }

  CSVData *csv_data = read_csv_file(argv[1]);
  if (csv_data == NULL) {
    printf("Error: Failed to read CSV file\n");
    return EXIT_FAILURE;
  }

  // Print headers
  printf("Headers:\n");
  for (int i = 0; i < csv_data->num_headers; i++) {
    printf("%s", csv_data->headers[i]);
    if (i < csv_data->num_headers - 1) {
      printf(", ");
    }
  }
  printf("\n\n");

  // Print rows
  printf("Rows:\n");
  for (int i = 0; i < csv_data->num_rows; i++) {
    CSVRow row = csv_data->rows[i];
    for (int j = 0; j < row.num_fields; j++) {
      printf("%s", row.fields[j]);
      if (j < row.num_fields - 1) {
        printf(", ");
      }
    }
    printf("\n");
  }

  // Free memory
  for (int i = 0; i < csv_data->num_headers; i++) {
    free(csv_data->headers[i]);
  }
  free(csv_data->headers);
  for (int i = 0; i < csv_data->num_rows; i++) {
    CSVRow row = csv_data->rows[i];
    for (int j = 0; j < row.num_fields; j++) {
      free(row.fields[j]);
    }
    free(row.fields);
  }
  free(csv_data->rows);
  free(csv_data);

  return EXIT_SUCCESS;
}
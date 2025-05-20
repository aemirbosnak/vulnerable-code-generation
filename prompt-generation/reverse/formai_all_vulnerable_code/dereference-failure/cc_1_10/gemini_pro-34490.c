//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000

// Structure to represent a CSV file
typedef struct CSVFile {
  char **data;
  int num_rows;
  int num_columns;
} CSVFile;

// Function to create a new CSV file
CSVFile *new_csv_file() {
  CSVFile *csv = malloc(sizeof(CSVFile));
  csv->data = malloc(MAX_ROWS * sizeof(char *));
  for (int i = 0; i < MAX_ROWS; i++) {
    csv->data[i] = malloc(MAX_COLUMNS * sizeof(char));
  }
  csv->num_rows = 0;
  csv->num_columns = 0;
  return csv;
}

// Function to free the memory allocated to a CSV file
void free_csv_file(CSVFile *csv) {
  for (int i = 0; i < csv->num_rows; i++) {
    free(csv->data[i]);
  }
  free(csv->data);
  free(csv);
}

// Function to read a CSV file from a file
CSVFile *read_csv_file(const char *filename) {
  CSVFile *csv = new_csv_file();
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *p = strtok(line, ",");
    int col = 0;
    while (p) {
      strcpy(csv->data[csv->num_rows][col++], p);
      p = strtok(NULL, ",");
    }
    csv->num_columns = col;
    csv->num_rows++;
  }

  fclose(fp);
  return csv;
}

// Function to print a CSV file to the console
void print_csv_file(CSVFile *csv) {
  for (int i = 0; i < csv->num_rows; i++) {
    for (int j = 0; j < csv->num_columns; j++) {
      printf("%s,", csv->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  CSVFile *csv = read_csv_file("data.csv");
  if (csv == NULL) {
    return 1;
  }

  print_csv_file(csv);
  free_csv_file(csv);
  return 0;
}
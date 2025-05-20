//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rows and columns in the CSV file
#define MAX_ROWS 1000
#define MAX_COLS 100

// Define the maximum length of a line in the CSV file
#define MAX_LINE_LENGTH 1000

// Define the delimiter used in the CSV file
#define DELIMITER ','

// Define the structure of a CSV file
typedef struct {
  int num_rows;
  int num_cols;
  char **data;
} csv_file;

// Function to read a CSV file into memory
csv_file *read_csv_file(char *filename) {
  // Allocate memory for the CSV file structure
  csv_file *csv = malloc(sizeof(csv_file));

  // Open the CSV file for reading
  FILE *fp = fopen(filename, "r");

  // Check if the file was opened successfully
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Read the first line of the CSV file to get the number of columns
  char line[MAX_LINE_LENGTH];
  fgets(line, MAX_LINE_LENGTH, fp);
  csv->num_cols = 0;
  char *tok = strtok(line, DELIMITER);
  while (tok != NULL) {
    csv->num_cols++;
    tok = strtok(NULL, DELIMITER);
  }

  // Read the rest of the lines of the CSV file to get the number of rows
  csv->num_rows = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    csv->num_rows++;
  }

  // Allocate memory for the data array
  csv->data = malloc(csv->num_rows * sizeof(char *));
  for (int i = 0; i < csv->num_rows; i++) {
    csv->data[i] = malloc(csv->num_cols * sizeof(char));
  }

  // Read the data from the CSV file into the data array
  fseek(fp, 0, SEEK_SET);
  for (int i = 0; i < csv->num_rows; i++) {
    fgets(line, MAX_LINE_LENGTH, fp);
    tok = strtok(line, DELIMITER);
    for (int j = 0; j < csv->num_cols; j++) {
      strcpy(csv->data[i][j], tok);
      tok = strtok(NULL, DELIMITER);
    }
  }

  // Close the CSV file
  fclose(fp);

  // Return the CSV file structure
  return csv;
}

// Function to free the memory allocated for a CSV file
void free_csv_file(csv_file *csv) {
  // Free the memory allocated for the data array
  for (int i = 0; i < csv->num_rows; i++) {
    free(csv->data[i]);
  }

  // Free the memory allocated for the CSV file structure
  free(csv);
}

// Function to print a CSV file
void print_csv_file(csv_file *csv) {
  // Print the number of rows and columns in the CSV file
  printf("Number of rows: %d\n", csv->num_rows);
  printf("Number of columns: %d\n", csv->num_cols);

  // Print the data in the CSV file
  for (int i = 0; i < csv->num_rows; i++) {
    for (int j = 0; j < csv->num_cols; j++) {
      printf("%s ", csv->data[i][j]);
    }
    printf("\n");
  }
}

// Function to main
int main(int argc, char *argv[]) {
  // Read the CSV file into memory
  csv_file *csv = read_csv_file("data.csv");

  // Print the CSV file
  print_csv_file(csv);

  // Free the memory allocated for the CSV file
  free_csv_file(csv);

  return 0;
}
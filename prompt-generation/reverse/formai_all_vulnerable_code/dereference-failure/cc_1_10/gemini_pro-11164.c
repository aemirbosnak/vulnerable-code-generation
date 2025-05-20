//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV row
#define MAX_COLUMNS 10

// Define the maximum length of a CSV field
#define MAX_FIELD_LENGTH 100

// Define the delimiter used to separate fields in a CSV row
#define DELIMITER ','

// Define the newline character used to separate rows in a CSV file
#define NEWLINE '\n'

// Define the structure of a CSV row
typedef struct csv_row {
  char *fields[MAX_COLUMNS];
  int num_fields;
} csv_row;

// Define the structure of a CSV file
typedef struct csv_file {
  csv_row *rows;
  int num_rows;
} csv_file;

// Function to read a CSV file
csv_file *read_csv_file(char *filename) {
  // Open the CSV file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Create a new CSV file struct
  csv_file *csv = malloc(sizeof(csv_file));
  if (csv == NULL) {
    fprintf(stderr, "Error allocating memory for CSV file\n");
    fclose(fp);
    return NULL;
  }

  // Read the first line of the CSV file to get the number of columns
  char line[MAX_FIELD_LENGTH];
  if (fgets(line, MAX_FIELD_LENGTH, fp) == NULL) {
    fprintf(stderr, "Error reading first line of CSV file\n");
    fclose(fp);
    free(csv);
    return NULL;
  }

  // Split the first line of the CSV file into fields
  char *fields[MAX_COLUMNS];
  int num_fields = 0;
  char *field = strtok(line, DELIMITER);
  while (field != NULL) {
    fields[num_fields++] = field;
    field = strtok(NULL, DELIMITER);
  }

  // Allocate memory for the rows of the CSV file
  csv->rows = malloc(sizeof(csv_row) * num_fields);
  if (csv->rows == NULL) {
    fprintf(stderr, "Error allocating memory for CSV file rows\n");
    fclose(fp);
    free(csv);
    return NULL;
  }

  // Read the remaining lines of the CSV file
  int row_num = 0;
  while (fgets(line, MAX_FIELD_LENGTH, fp) != NULL) {
    // Split the line of the CSV file into fields
    field = strtok(line, DELIMITER);
    num_fields = 0;
    while (field != NULL) {
      csv->rows[row_num].fields[num_fields++] = field;
      field = strtok(NULL, DELIMITER);
    }

    // Increment the row number
    row_num++;
  }

  // Close the CSV file
  fclose(fp);

  // Set the number of rows in the CSV file
  csv->num_rows = row_num;

  // Return the CSV file struct
  return csv;
}

// Function to free the memory allocated for a CSV file
void free_csv_file(csv_file *csv) {
  // Free the memory allocated for the rows of the CSV file
  for (int i = 0; i < csv->num_rows; i++) {
    for (int j = 0; j < csv->rows[i].num_fields; j++) {
      free(csv->rows[i].fields[j]);
    }
  }
  free(csv->rows);

  // Free the memory allocated for the CSV file struct
  free(csv);
}

// Function to print a CSV file
void print_csv_file(csv_file *csv) {
  // Print the header of the CSV file
  for (int i = 0; i < csv->rows[0].num_fields; i++) {
    printf("%s,", csv->rows[0].fields[i]);
  }
  printf("\n");

  // Print the data of the CSV file
  for (int i = 1; i < csv->num_rows; i++) {
    for (int j = 0; j < csv->rows[i].num_fields; j++) {
      printf("%s,", csv->rows[i].fields[j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Read the CSV file
  csv_file *csv = read_csv_file("data.csv");
  if (csv == NULL) {
    return 1;
  }

  // Print the CSV file
  print_csv_file(csv);

  // Free the memory allocated for the CSV file
  free_csv_file(csv);

  return 0;
}
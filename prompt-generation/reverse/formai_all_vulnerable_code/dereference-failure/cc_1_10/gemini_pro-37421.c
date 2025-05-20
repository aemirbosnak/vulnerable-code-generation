//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields in a CSV record
#define MAX_FIELDS 10

// Define the maximum length of a field in a CSV record
#define MAX_FIELD_LENGTH 100

// Define the delimiter used to separate fields in a CSV record
#define DELIMITER ','

// Create a structure to represent a CSV record
typedef struct {
  char *fields[MAX_FIELDS];
  int num_fields;
} csv_record;

// Create a function to read a CSV file and return a list of CSV records
csv_record *read_csv_file(char *filename) {
  // Open the CSV file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Allocate memory for the list of CSV records
  csv_record *records = malloc(sizeof(csv_record));
  if (records == NULL) {
    fclose(file);
    return NULL;
  }

  // Read the first line of the CSV file to get the number of fields
  char line[MAX_FIELD_LENGTH];
  if (fgets(line, MAX_FIELD_LENGTH, file) == NULL) {
    fclose(file);
    free(records);
    return NULL;
  }

  // Parse the first line to get the number of fields
  char *field;
  int num_fields = 0;
  field = strtok(line, DELIMITER);
  while (field != NULL) {
    num_fields++;
    field = strtok(NULL, DELIMITER);
  }

  // Allocate memory for the fields in each CSV record
  for (int i = 0; i < num_fields; i++) {
    records->fields[i] = malloc(MAX_FIELD_LENGTH);
    if (records->fields[i] == NULL) {
      fclose(file);
      free(records);
      return NULL;
    }
  }

  // Read the rest of the CSV file and store the records in the list
  int record_index = 0;
  while (fgets(line, MAX_FIELD_LENGTH, file) != NULL) {
    // Parse the line to get the fields
    field = strtok(line, DELIMITER);
    int field_index = 0;
    while (field != NULL) {
      strcpy(records->fields[field_index], field);
      field_index++;
      field = strtok(NULL, DELIMITER);
    }

    // Increment the record index
    record_index++;
  }

  // Close the CSV file
  fclose(file);

  // Return the list of CSV records
  return records;
}

// Create a function to free the memory allocated for a list of CSV records
void free_csv_records(csv_record *records, int num_records) {
  // Free the memory allocated for the fields in each CSV record
  for (int i = 0; i < num_records; i++) {
    for (int j = 0; j < records[i].num_fields; j++) {
      free(records[i].fields[j]);
    }
  }

  // Free the memory allocated for the list of CSV records
  free(records);
}

// Create a function to print a list of CSV records
void print_csv_records(csv_record *records, int num_records) {
  // Print the header
  for (int i = 0; i < records[0].num_fields; i++) {
    printf("%s", records[0].fields[i]);
    if (i < records[0].num_fields - 1) {
      printf(",");
    }
  }
  printf("\n");

  // Print the records
  for (int i = 1; i < num_records; i++) {
    for (int j = 0; j < records[0].num_fields; j++) {
      printf("%s", records[i].fields[j]);
      if (j < records[0].num_fields - 1) {
        printf(",");
      }
    }
    printf("\n");
  }
}

// Create a function to test the CSV reader
int main() {
  // Read the CSV file
  csv_record *records = read_csv_file("data.csv");
  if (records == NULL) {
    printf("Error reading CSV file.\n");
    return 1;
  }

  // Print the CSV records
  print_csv_records(records, 10);

  // Free the memory allocated for the CSV records
  free_csv_records(records, 10);

  return 0;
}
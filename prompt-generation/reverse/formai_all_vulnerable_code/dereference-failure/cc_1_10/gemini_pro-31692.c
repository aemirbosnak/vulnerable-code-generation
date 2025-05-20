//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields in a CSV line
#define MAX_FIELDS 100

// Define the maximum length of a field in a CSV line
#define MAX_FIELD_LENGTH 1000

// Define the delimiter used to separate fields in a CSV line
#define DELIMITER ','

// Define the newline character used to terminate a CSV line
#define NEWLINE '\n'

// Define the structure of a CSV record
typedef struct {
  char *fields[MAX_FIELDS];
  int num_fields;
} CSVRecord;

// Create a new CSV record
CSVRecord *new_csv_record() {
  CSVRecord *record = malloc(sizeof(CSVRecord));
  record->num_fields = 0;
  return record;
}

// Free a CSV record
void free_csv_record(CSVRecord *record) {
  for (int i = 0; i < record->num_fields; i++) {
    free(record->fields[i]);
  }
  free(record);
}

// Read a CSV line from a file
CSVRecord *read_csv_line(FILE *file) {
  CSVRecord *record = new_csv_record();

  // Read the line from the file
  char line[MAX_FIELD_LENGTH];
  if (fgets(line, MAX_FIELD_LENGTH, file) == NULL) {
    return NULL;
  }

  // Parse the line into fields
  char *field = strtok(line, DELIMITER);
  while (field != NULL) {
    // Allocate memory for the field
    record->fields[record->num_fields] = malloc(strlen(field) + 1);

    // Copy the field into the record
    strcpy(record->fields[record->num_fields], field);

    // Increment the number of fields
    record->num_fields++;

    // Get the next field
    field = strtok(NULL, DELIMITER);
  }

  // Return the record
  return record;
}

// Print a CSV record to the console
void print_csv_record(CSVRecord *record) {
  for (int i = 0; i < record->num_fields; i++) {
    printf("%s", record->fields[i]);
    if (i < record->num_fields - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

// Read a CSV file and print the records to the console
void read_csv_file(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  // Read the lines from the file
  CSVRecord *record;
  while ((record = read_csv_line(file)) != NULL) {
    // Print the record to the console
    print_csv_record(record);

    // Free the record
    free_csv_record(record);
  }

  // Close the file
  fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was specified
  if (argc < 2) {
    printf("Error: no filename specified\n");
    return 1;
  }

  // Read the CSV file and print the records to the console
  read_csv_file(argv[1]);

  return 0;
}
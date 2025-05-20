//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV file
#define MAX_COLUMNS 100

// Define the maximum length of a line in a CSV file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of characters in a field in a CSV file
#define MAX_FIELD_LENGTH 100

// Define the delimiter character for CSV files
#define DELIMITER ','

// Define the newline character for CSV files
#define NEWLINE '\n'

// Define the structure of a CSV record
typedef struct csv_record {
  char *fields[MAX_COLUMNS];
  int num_fields;
} csv_record;

// Define the structure of a CSV reader
typedef struct csv_reader {
  FILE *file;
  char line[MAX_LINE_LENGTH];
  char *fields[MAX_COLUMNS];
  int num_fields;
  int line_number;
} csv_reader;

// Create a new CSV reader
csv_reader *csv_reader_new(FILE *file) {
  csv_reader *reader = malloc(sizeof(csv_reader));
  reader->file = file;
  reader->line_number = 0;
  return reader;
}

// Free a CSV reader
void csv_reader_free(csv_reader *reader) {
  free(reader);
}

// Read the next line from a CSV file
int csv_reader_read_line(csv_reader *reader) {
  // Read the next line from the file
  if (fgets(reader->line, MAX_LINE_LENGTH, reader->file) == NULL) {
    return 0;
  }

  // Increment the line number
  reader->line_number++;

  // Parse the line into fields
  reader->num_fields = 0;
  char *field = strtok(reader->line, DELIMITER);
  while (field != NULL) {
    reader->fields[reader->num_fields++] = field;
    field = strtok(NULL, DELIMITER);
  }

  // Return the number of fields in the line
  return reader->num_fields;
}

// Get the value of a field in a CSV record
char *csv_record_get_field(csv_record *record, int index) {
  if (index < 0 || index >= record->num_fields) {
    return NULL;
  }
  return record->fields[index];
}

// Print a CSV record to the console
void csv_record_print(csv_record *record) {
  for (int i = 0; i < record->num_fields; i++) {
    printf("%s", record->fields[i]);
    if (i < record->num_fields - 1) {
      printf(",");
    }
  }
  printf("\n");
}

// Read a CSV file and print the records to the console
void csv_reader_print_records(csv_reader *reader) {
  // Read each line from the file
  while (csv_reader_read_line(reader) > 0) {
    // Create a new record
    csv_record *record = malloc(sizeof(csv_record));
    record->num_fields = reader->num_fields;
    for (int i = 0; i < reader->num_fields; i++) {
      record->fields[i] = reader->fields[i];
    }

    // Print the record to the console
    csv_record_print(record);

    // Free the record
    free(record);
  }
}

// Main function
int main() {
  // Open the CSV file
  FILE *file = fopen("data.csv", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Create a new CSV reader
  csv_reader *reader = csv_reader_new(file);

  // Read and print the records from the file
  csv_reader_print_records(reader);

  // Free the CSV reader and close the file
  csv_reader_free(reader);
  fclose(file);

  return EXIT_SUCCESS;
}
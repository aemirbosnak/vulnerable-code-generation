//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields in a CSV record
#define MAX_FIELDS 100

// Define the maximum length of a field in a CSV record
#define MAX_FIELD_LENGTH 1000

// Declare the CSV reader struct
typedef struct csv_reader {
  FILE *file;
  char *line;
  size_t line_length;
  char *fields[MAX_FIELDS];
  int num_fields;
} csv_reader;

// Create a new CSV reader
csv_reader *csv_reader_new(FILE *file) {
  csv_reader *reader = malloc(sizeof(csv_reader));
  reader->file = file;
  reader->line = NULL;
  reader->line_length = 0;
  reader->num_fields = 0;
  return reader;
}

// Free a CSV reader
void csv_reader_free(csv_reader *reader) {
  if (reader->line != NULL) {
    free(reader->line);
  }
  free(reader);
}

// Read the next line from a CSV file
int csv_reader_next_line(csv_reader *reader) {
  // Get the next line from the file
  ssize_t line_length = getline(&reader->line, &reader->line_length, reader->file);

  // Check if we reached the end of the file
  if (line_length == -1) {
    return 0;
  }

  // Parse the line into fields
  reader->num_fields = 0;
  char *field_start = reader->line;
  char *field_end = reader->line;
  while (*field_end != '\0') {
    // Skip leading whitespace
    while (*field_start == ' ') {
      field_start++;
    }

    // Find the end of the field
    field_end = field_start;
    while (*field_end != '\0' && *field_end != ',' && *field_end != '\n') {
      field_end++;
    }

    // Copy the field into the fields array
    if (field_end - field_start > 0) {
      reader->fields[reader->num_fields] = malloc(field_end - field_start + 1);
      strncpy(reader->fields[reader->num_fields], field_start, field_end - field_start);
      reader->fields[reader->num_fields][field_end - field_start] = '\0';
      reader->num_fields++;
    }

    // Skip trailing whitespace and the comma
    field_start = field_end;
    while (*field_start == ' ' || *field_start == ',') {
      field_start++;
    }
  }

  return 1;
}

// Get the value of a field by index
char *csv_reader_get_field(csv_reader *reader, int index) {
  if (index < 0 || index >= reader->num_fields) {
    return NULL;
  }

  return reader->fields[index];
}

// Print the CSV reader
void csv_reader_print(csv_reader *reader) {
  for (int i = 0; i < reader->num_fields; i++) {
    printf("%s", reader->fields[i]);
    if (i < reader->num_fields - 1) {
      printf(",");
    }
  }
  printf("\n");
}

// Main function
int main() {
  // Open the CSV file
  FILE *file = fopen("data.csv", "r");

  // Create a new CSV reader
  csv_reader *reader = csv_reader_new(file);

  // Read the CSV file line by line
  while (csv_reader_next_line(reader)) {
    // Print the CSV reader
    csv_reader_print(reader);
  }

  // Free the CSV reader
  csv_reader_free(reader);

  // Close the CSV file
  fclose(file);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields in a CSV line
#define MAX_FIELDS 10

// Define the maximum length of a field in a CSV line
#define MAX_FIELD_LENGTH 100

// Define the delimiter used in the CSV file
#define DELIMITER ','

// Define the newline character used in the CSV file
#define NEWLINE '\n'

// Define the function to read a line from a CSV file
char* read_line(FILE* fp) {
  // Allocate memory for the line
  char* line = malloc(MAX_FIELD_LENGTH * MAX_FIELDS);

  // Read the line from the file
  fgets(line, MAX_FIELD_LENGTH * MAX_FIELDS, fp);

  // Return the line
  return line;
}

// Define the function to parse a line from a CSV file
char** parse_line(char* line) {
  // Allocate memory for the fields
  char** fields = malloc(MAX_FIELDS * sizeof(char*));

  // Initialize the fields
  for (int i = 0; i < MAX_FIELDS; i++) {
    fields[i] = NULL;
  }

  // Parse the line
  char* field = strtok(line, DELIMITER);
  int field_index = 0;
  while (field) {
    // Allocate memory for the field
    fields[field_index] = malloc(strlen(field) + 1);

    // Copy the field into the array
    strcpy(fields[field_index], field);

    // Increment the field index
    field_index++;

    // Get the next field
    field = strtok(NULL, DELIMITER);
  }

  // Return the fields
  return fields;
}

// Define the function to print the fields from a CSV line
void print_fields(char** fields) {
  // Print the fields
  for (int i = 0; i < MAX_FIELDS; i++) {
    if (fields[i]) {
      printf("%s\n", fields[i]);
    }
  }
}

// Define the function to free the memory allocated for the fields
void free_fields(char** fields) {
  // Free the memory allocated for each field
  for (int i = 0; i < MAX_FIELDS; i++) {
    if (fields[i]) {
      free(fields[i]);
    }
  }

  // Free the memory allocated for the array of fields
  free(fields);
}

// Define the main function
int main() {
  // Open the CSV file
  FILE* fp = fopen("data.csv", "r");

  // Read the lines from the CSV file
  char* line;
  while ((line = read_line(fp))) {
    // Parse the line
    char** fields = parse_line(line);

    // Print the fields
    printf("line: %s\n", line);
    print_fields(fields);

    // Free the memory allocated for the fields
    free_fields(fields);

    // Free the memory allocated for the line
    free(line);
  }

  // Close the CSV file
  fclose(fp);

  return 0;
}
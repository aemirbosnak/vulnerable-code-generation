//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields in a CSV record
#define MAX_FIELDS 10

// Define the maximum length of a field in a CSV record
#define MAX_FIELD_LENGTH 100

// Define the delimiter character used to separate fields in a CSV record
#define DELIMITER ','

// Define the newline character used to separate records in a CSV file
#define NEWLINE '\n'

// Define the structure of a CSV record
typedef struct csv_record {
  char *fields[MAX_FIELDS];
  int num_fields;
} csv_record;

// Function to read a line from a CSV file
char *readline(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  // Read a line from the file
  nread = getline(&line, &len, fp);

  // Check for errors
  if (nread == -1) {
    return NULL;
  }

  // Remove the newline character from the end of the line
  if (nread > 0 && line[nread - 1] == NEWLINE) {
    line[nread - 1] = '\0';
  }

  // Return the line
  return line;
}

// Function to parse a CSV record
csv_record *parse_record(char *line) {
  csv_record *record = malloc(sizeof(csv_record));

  // Initialize the record
  record->num_fields = 0;
  for (int i = 0; i < MAX_FIELDS; i++) {
    record->fields[i] = NULL;
  }

  // Tokenize the line
  char *token = strtok(line, DELIMITER);

  // Loop through the tokens
  while (token != NULL) {
    // Add the token to the record
    record->fields[record->num_fields] = malloc(strlen(token) + 1);
    strcpy(record->fields[record->num_fields], token);
    record->num_fields++;

    // Get the next token
    token = strtok(NULL, DELIMITER);
  }

  // Return the record
  return record;
}

// Function to print a CSV record
void print_record(csv_record *record) {
  // Loop through the fields
  for (int i = 0; i < record->num_fields; i++) {
    // Print the field
    printf("%s", record->fields[i]);

    // Print a comma after the field
    if (i < record->num_fields - 1) {
      printf(", ");
    }
  }

  // Print a newline after the record
  printf("\n");
}

// Function to free the memory allocated for a CSV record
void free_record(csv_record *record) {
  // Loop through the fields
  for (int i = 0; i < record->num_fields; i++) {
    // Free the memory allocated for the field
    free(record->fields[i]);
  }

  // Free the memory allocated for the record
  free(record);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a filename
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Open the CSV file
  FILE *fp = fopen(argv[1], "r");

  // Check if the file was opened successfully
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  // Read the lines from the file
  char *line;
  while ((line = readline(fp)) != NULL) {
    // Parse the record
    csv_record *record = parse_record(line);

    // Print the record
    print_record(record);

    // Free the memory allocated for the record
    free_record(record);

    // Free the memory allocated for the line
    free(line);
  }

  // Close the file
  fclose(fp);

  return 0;
}
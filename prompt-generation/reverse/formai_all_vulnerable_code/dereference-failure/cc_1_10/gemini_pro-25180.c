//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line in the CSV file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of fields in a line in the CSV file
#define MAX_FIELDS 100

// Define the maximum length of a field in a line in the CSV file
#define MAX_FIELD_LENGTH 1024

// Define the delimiter used in the CSV file
#define DELIMITER ','

// Define the number of lines to skip at the beginning of the CSV file
#define SKIP_LINES 1

// Define the function to read a line from the CSV file
char *readLine(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  // Read a line from the CSV file
  nread = getline(&line, &len, fp);

  // Check if the line was read successfully
  if (nread == -1) {
    return NULL;
  }

  // Remove the newline character from the line
  line[strlen(line) - 1] = '\0';

  // Return the line
  return line;
}

// Define the function to split a line into fields
char **splitLine(char *line) {
  char **fields = NULL;
  int numFields = 0;
  char *field;

  // Allocate memory for the fields
  fields = malloc(MAX_FIELDS * sizeof(char *));

  // Split the line into fields
  field = strtok(line, DELIMITER);
  while (field != NULL) {
    // Allocate memory for the field
    fields[numFields] = malloc(MAX_FIELD_LENGTH * sizeof(char));

    // Copy the field into the fields array
    strcpy(fields[numFields], field);

    // Increment the number of fields
    numFields++;

    // Get the next field
    field = strtok(NULL, DELIMITER);
  }

  // Return the fields
  return fields;
}

// Define the function to free the memory allocated for the fields
void freeFields(char **fields) {
  int i;

  // Free the memory allocated for each field
  for (i = 0; i < MAX_FIELDS; i++) {
    free(fields[i]);
  }

  // Free the memory allocated for the fields array
  free(fields);
}

// Define the main function
int main(int argc, char **argv) {
  FILE *fp;
  char *line;
  char **fields;
  int i, j;

  // Check if the number of arguments is correct
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the CSV file
  fp = fopen(argv[1], "r");

  // Check if the CSV file was opened successfully
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Skip the lines at the beginning of the CSV file
  for (i = 0; i < SKIP_LINES; i++) {
    line = readLine(fp);
  }

  // Read the lines from the CSV file
  while ((line = readLine(fp)) != NULL) {
    // Split the line into fields
    fields = splitLine(line);

    // Print the fields
    for (j = 0; j < MAX_FIELDS; j++) {
      printf("%s ", fields[j]);
    }
    printf("\n");

    // Free the memory allocated for the fields
    freeFields(fields);
  }

  // Close the CSV file
  fclose(fp);

  return EXIT_SUCCESS;
}
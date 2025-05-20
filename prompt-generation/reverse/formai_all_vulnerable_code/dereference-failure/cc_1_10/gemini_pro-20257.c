//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line in the CSV file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of fields in a line of the CSV file
#define MAX_NUM_FIELDS 100

// Define the maximum length of a field in the CSV file
#define MAX_FIELD_LENGTH 1024

// Read a line from the CSV file
char *read_line(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  if ((read = getline(&line, &len, fp)) != -1) {
    // Remove the newline character from the end of the line
    if (line[read - 1] == '\n') {
      line[read - 1] = '\0';
    }
  }

  return line;
}

// Split a line into fields
char **split_line(char *line) {
  char **fields = NULL;
  int num_fields = 0;
  char *field;

  // Allocate memory for the fields array
  fields = malloc(sizeof(char *) * MAX_NUM_FIELDS);
  if (fields == NULL) {
    return NULL;
  }

  // Tokenize the line into fields
  field = strtok(line, ",");
  while (field != NULL) {
    // Allocate memory for the field
    fields[num_fields] = malloc(sizeof(char) * MAX_FIELD_LENGTH);
    if (fields[num_fields] == NULL) {
      return NULL;
    }

    // Copy the field into the array
    strcpy(fields[num_fields], field);
    num_fields++;

    // Get the next field
    field = strtok(NULL, ",");
  }

  return fields;
}

// Free the memory allocated for the fields
void free_fields(char **fields, int num_fields) {
  for (int i = 0; i < num_fields; i++) {
    free(fields[i]);
  }
  free(fields);
}

// Print the fields
void print_fields(char **fields, int num_fields) {
  for (int i = 0; i < num_fields; i++) {
    printf("%s", fields[i]);
    if (i < num_fields - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

// Read the CSV file
void read_csv_file(char *filename) {
  FILE *fp;
  char *line;
  char **fields;
  int num_fields;

  // Open the CSV file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening CSV file");
    return;
  }

  // Read the lines from the CSV file
  while ((line = read_line(fp)) != NULL) {
    // Split the line into fields
    fields = split_line(line);
    if (fields == NULL) {
      perror("Error splitting line");
      return;
    }

    // Get the number of fields
    num_fields = 0;
    while (fields[num_fields] != NULL) {
      num_fields++;
    }

    // Print the fields
    print_fields(fields, num_fields);

    // Free the memory allocated for the fields
    free_fields(fields, num_fields);

    // Free the line
    free(line);
  }

  // Close the CSV file
  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Read the CSV file
  read_csv_file(argv[1]);

  return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters per line in the CSV file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of fields per line in the CSV file
#define MAX_NUM_FIELDS 10

// Create a function to read a line of text from a file
char *read_line(FILE *file) {
  // Allocate memory for the line of text
  char *line = malloc(MAX_LINE_LENGTH);

  // Read the line of text from the file
  fgets(line, MAX_LINE_LENGTH, file);

  // Return the line of text
  return line;
}

// Create a function to split a line of text into an array of fields
char **split_line(char *line) {
  // Allocate memory for the array of fields
  char **fields = malloc(MAX_NUM_FIELDS * sizeof(char *));

  // Split the line of text into an array of fields
  int num_fields = 0;
  char *field = strtok(line, ",");
  while (field != NULL) {
    fields[num_fields] = field;
    num_fields++;
    field = strtok(NULL, ",");
  }

  // Return the array of fields
  return fields;
}

// Create a function to print an array of fields
void print_fields(char **fields, int num_fields) {
  // Print the array of fields
  for (int i = 0; i < num_fields; i++) {
    printf("%s", fields[i]);
    if (i < num_fields - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

// Create a function to read a CSV file and print its contents
void read_csv_file(char *filename) {
  // Open the CSV file
  FILE *file = fopen(filename, "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }

  // Read the lines of text from the file
  char *line;
  while ((line = read_line(file)) != NULL) {
    // Split the line of text into an array of fields
    char **fields = split_line(line);

    // Print the array of fields
    print_fields(fields, MAX_NUM_FIELDS);

    // Free the memory allocated for the array of fields
    free(fields);

    // Free the memory allocated for the line of text
    free(line);
  }

  // Close the file
  fclose(file);
}

// Create a function to test the CSV reader
int main() {
  // Read the CSV file
  read_csv_file("data.csv");

  // Return 0 to indicate that the program ran successfully
  return 0;
}
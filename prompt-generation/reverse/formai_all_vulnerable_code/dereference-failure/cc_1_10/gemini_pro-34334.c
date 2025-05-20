//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in the CSV file.
#define MAX_COLS 100

// Define the maximum length of a line in the CSV file.
#define MAX_LINE_LENGTH 1000

// Define the structure of a CSV record.
typedef struct {
  char *data[MAX_COLS];
  int num_cols;
} csv_record;

// Read a line from a CSV file and parse it into a CSV record.
csv_record *read_csv_line(FILE *fp) {
  char line[MAX_LINE_LENGTH];
  char *token;
  char *delim = ",";
  csv_record *record = malloc(sizeof(csv_record));

  if (record == NULL) {
    return NULL;
  }

  // Read a line from the CSV file.
  if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
    free(record);
    return NULL;
  }

  // Parse the line into tokens.
  token = strtok(line, delim);
  while (token != NULL) {
    // Add the token to the record.
    record->data[record->num_cols] = strdup(token);
    record->num_cols++;

    // Get the next token.
    token = strtok(NULL, delim);
  }

  // Return the record.
  return record;
}

// Free the memory allocated for a CSV record.
void free_csv_record(csv_record *record) {
  int i;

  // Free the data for each column.
  for (i = 0; i < record->num_cols; i++) {
    free(record->data[i]);
  }

  // Free the record itself.
  free(record);
}

// Print a CSV record to the console.
void print_csv_record(csv_record *record) {
  int i;

  // Print the data for each column.
  for (i = 0; i < record->num_cols; i++) {
    printf("%s", record->data[i]);

    // Print a comma after each column except the last one.
    if (i < record->num_cols - 1) {
      printf(",");
    }
  }

  // Print a newline character.
  printf("\n");
}

// Read a CSV file and print its contents to the console.
void read_csv_file(char *filename) {
  FILE *fp;
  csv_record *record;

  // Open the CSV file.
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Read each line from the CSV file and parse it into a CSV record.
  while ((record = read_csv_line(fp)) != NULL) {
    // Print the CSV record to the console.
    print_csv_record(record);

    // Free the memory allocated for the CSV record.
    free_csv_record(record);
  }

  // Close the CSV file.
  fclose(fp);
}

// Main function.
int main(int argc, char *argv[]) {
  // Check if the user has specified a CSV file to read.
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Read the CSV file and print its contents to the console.
  read_csv_file(argv[1]);

  return 0;
}
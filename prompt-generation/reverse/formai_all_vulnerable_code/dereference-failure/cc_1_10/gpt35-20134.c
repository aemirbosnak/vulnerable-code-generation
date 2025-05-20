//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_COLUMN_LENGTH 50
#define MAX_RECORDS 100

int main() {
  // Initialize variables
  char filename[MAX_COLUMN_LENGTH];
  char column_names[MAX_COLUMNS][MAX_COLUMN_LENGTH];
  char records[MAX_RECORDS][MAX_COLUMNS][MAX_COLUMN_LENGTH];
  int num_columns, num_records;

  // Prompt user for filename
  printf("Enter the name of the CSV file: ");
  fgets(filename, MAX_COLUMN_LENGTH, stdin);
  strtok(filename, "\n"); // Remove newline character

  // Open file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read first line of file to get column names
  char line[MAX_COLUMNS * MAX_COLUMN_LENGTH];
  fgets(line, MAX_COLUMNS * MAX_COLUMN_LENGTH, fp);
  char *token = strtok(line, ",");
  while (token != NULL) {
    strcpy(column_names[num_columns], token);
    num_columns++;
    token = strtok(NULL, ",");
  }

  // Read remaining lines of file to get records
  while (fgets(line, MAX_COLUMNS * MAX_COLUMN_LENGTH, fp) != NULL && num_records < MAX_RECORDS) {
    token = strtok(line, ",");
    int column_index = 0;
    while (token != NULL && column_index < num_columns) {
      strcpy(records[num_records][column_index], token);
      column_index++;
      token = strtok(NULL, ",");
    }
    num_records++;
  }

  // Close file
  fclose(fp);

  // Print column names
  for (int i = 0; i < num_columns; i++) {
    printf("%s\t", column_names[i]);
  }
  printf("\n");

  // Print records
  for (int i = 0; i < num_records; i++) {
    for (int j = 0; j < num_columns; j++) {
      printf("%s\t", records[i][j]);
    }
    printf("\n");
  }

  return 0;
}
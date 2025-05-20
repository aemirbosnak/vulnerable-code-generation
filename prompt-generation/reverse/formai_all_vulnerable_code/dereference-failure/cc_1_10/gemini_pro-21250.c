//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for the number of columns and the maximum length of a line
#define NUM_COLUMNS 5
#define MAX_LINE_LENGTH 1024

// Function to read a line from the CSV file
char *readLine(FILE *fp) {
  // Allocate memory for the line
  char *line = malloc(MAX_LINE_LENGTH);

  // Read the line from the file
  if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
    return NULL;
  }

  // Strip the newline character from the end of the line
  line[strlen(line) - 1] = '\0';

  return line;
}

// Function to split a line into columns
char **splitLine(char *line) {
  // Allocate memory for the columns
  char **columns = malloc(NUM_COLUMNS * sizeof(char *));

  // Split the line into columns using the comma as a delimiter
  char *token = strtok(line, ",");
  for (int i = 0; i < NUM_COLUMNS; i++) {
    columns[i] = token;
    token = strtok(NULL, ",");
  }

  return columns;
}

// Function to print the columns
void printColumns(char **columns) {
  for (int i = 0; i < NUM_COLUMNS; i++) {
    printf("%s\t", columns[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Open the CSV file
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return EXIT_FAILURE;
  }

  // Read the first line of the file
  char *line = readLine(fp);
  while (line != NULL) {
    // Split the line into columns
    char **columns = splitLine(line);

    // Print the columns
    printColumns(columns);

    // Free the memory allocated for the columns
    for (int i = 0; i < NUM_COLUMNS; i++) {
      free(columns[i]);
    }
    free(columns);

    // Read the next line of the file
    line = readLine(fp);
  }

  // Close the file
  fclose(fp);

  return EXIT_SUCCESS;
}
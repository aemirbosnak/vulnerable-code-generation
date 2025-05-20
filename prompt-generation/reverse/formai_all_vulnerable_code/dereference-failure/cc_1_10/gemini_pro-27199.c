//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM ","

int main() {
  // Open the CSV file
  FILE *fp = fopen("input.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the first line to get the number of columns
  char line[1024];
  fgets(line, sizeof(line), fp);
  int num_cols = 0;
  char *ptr = strtok(line, DELIM);
  while (ptr != NULL) {
    num_cols++;
    ptr = strtok(NULL, DELIM);
  }

  // Allocate memory for the data
  char **data = malloc(sizeof(char *) * num_cols);
  for (int i = 0; i < num_cols; i++) {
    data[i] = malloc(sizeof(char) * 1024);
  }

  // Read the rest of the lines and store the data
  int row = 0;
  while (fgets(line, sizeof(line), fp)) {
    ptr = strtok(line, DELIM);
    int col = 0;
    while (ptr != NULL) {
      strcpy(data[col], ptr);
      col++;
      ptr = strtok(NULL, DELIM);
    }
    row++;
  }

  // Close the file
  fclose(fp);

  // Print the data
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < num_cols; j++) {
      printf("%s ", data[j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < num_cols; i++) {
    free(data[i]);
  }
  free(data);

  return EXIT_SUCCESS;
}
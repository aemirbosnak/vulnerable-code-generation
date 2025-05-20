//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Open the CSV file
  FILE *file = fopen("data.csv", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the header line
  char line[1024];
  if (fgets(line, sizeof(line), file) == NULL) {
    perror("Error reading header line");
    fclose(file);
    return EXIT_FAILURE;
  }

  // Get the number of columns
  int num_columns = 0;
  char *token = strtok(line, ",");
  while (token != NULL) {
    num_columns++;
    token = strtok(NULL, ",");
  }

  // Allocate memory for the data
  char **data = malloc(sizeof(char *) * num_columns);
  for (int i = 0; i < num_columns; i++) {
    data[i] = malloc(sizeof(char) * 1024);
  }

  // Read the data lines
  int row = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    // Get the tokens
    token = strtok(line, ",");
    for (int i = 0; i < num_columns; i++) {
      strcpy(data[i][row], token);
      token = strtok(NULL, ",");
    }
    row++;
  }

  // Close the file
  fclose(file);

  // Print the data
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < num_columns; j++) {
      printf("%s ", data[j][i]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < num_columns; i++) {
    free(data[i]);
  }
  free(data);

  return EXIT_SUCCESS;
}
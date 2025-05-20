//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char line[1024];
  char *token;
  int num_cols = 0;
  int num_rows = 0;
  int i, j;

  // Open the CSV file
  fp = fopen("data.csv", "r");

  // Read the first line of the file
  fgets(line, 1024, fp);

  // Get the number of columns
  token = strtok(line, ",");
  while (token != NULL) {
    num_cols++;
    token = strtok(NULL, ",");
  }

  // Get the number of rows
  num_rows = 1;
  while (fgets(line, 1024, fp) != NULL) {
    num_rows++;
  }

  // Allocate memory for the data
  double **data = malloc(num_rows * sizeof(double *));
  for (i = 0; i < num_rows; i++) {
    data[i] = malloc(num_cols * sizeof(double));
  }

  // Read the data from the file
  rewind(fp);
  fgets(line, 1024, fp); // Skip the first line
  i = 0;
  while (fgets(line, 1024, fp) != NULL) {
    token = strtok(line, ",");
    j = 0;
    while (token != NULL) {
      data[i][j] = atof(token);
      j++;
      token = strtok(NULL, ",");
    }
    i++;
  }

  // Print the data
  for (i = 0; i < num_rows; i++) {
    for (j = 0; j < num_cols; j++) {
      printf("%lf ", data[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (i = 0; i < num_rows; i++) {
    free(data[i]);
  }
  free(data);

  // Close the file
  fclose(fp);

  return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DATA_FILE "data.csv"

// Function to read data from CSV file
void read_data(char **data, int *num_rows, int *num_cols) {
  int i, j, k;
  FILE *file = fopen(DATA_FILE, "r");
  char line[1024];

  *num_rows = 0;
  *num_cols = 0;

  while (fgets(line, 1024, file)) {
    // Ignore header row
    if (strcmp(line, "") == 0) continue;

    // Tokenize the line
    char *token = strtok(line, ",");
    int num_tokens = 0;
    while (token != NULL && num_tokens < 10) {
      num_tokens++;
      token = strtok(NULL, ",");
    }

    // Allocate memory for the row
    *num_rows = *num_rows + 1;
    *num_cols = num_tokens;

    // Create a 2D array to store the data
    data[*num_rows - 1] = (char *)malloc((*num_cols) * sizeof(char));

    // Populate the data
    for (i = 0; i < num_tokens; i++) {
      data[*num_rows - 1][i] = token[i];
    }
  }

  fclose(file);
}

// Function to print the data
void print_data(char **data, int num_rows, int num_cols) {
  int i, j;

  for (i = 0; i < num_rows; i++) {
    for (j = 0; j < num_cols; j++) {
      printf("%c", data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char **data;
  int num_rows, num_cols;

  // Read data from CSV file
  read_data(&data, &num_rows, &num_cols);

  // Print the data
  print_data(data, num_rows, num_cols);

  return 0;
}